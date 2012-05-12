/*============================================================================


                     NVIDIA FXAA III.8 by TIMOTHY LOTTES


------------------------------------------------------------------------------                       
COPYRIGHT (C) 2010, 2011 NVIDIA CORPORATION. ALL RIGHTS RESERVED.
------------------------------------------------------------------------------                       
TO THE MAXIMUM EXTENT PERMITTED BY APPLICABLE LAW, THIS SOFTWARE IS PROVIDED 
*AS IS* AND NVIDIA AND ITS SUPPLIERS DISCLAIM ALL WARRANTIES, EITHER EXPRESS 
OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF 
MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT SHALL NVIDIA 
OR ITS SUPPLIERS BE LIABLE FOR ANY SPECIAL, INCIDENTAL, INDIRECT, OR 
CONSEQUENTIAL DAMAGES WHATSOEVER (INCLUDING, WITHOUT LIMITATION, DAMAGES FOR 
LOSS OF BUSINESS PROFITS, BUSINESS INTERRUPTION, LOSS OF BUSINESS INFORMATION, 
OR ANY OTHER PECUNIARY LOSS) ARISING OUT OF THE USE OF OR INABILITY TO USE 
THIS SOFTWARE, EVEN IF NVIDIA HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH 
DAMAGES.


------------------------------------------------------------------------------
                            INTEGRATION CHECKLIST
------------------------------------------------------------------------------
(1.) 
In the shader source,
setup defines for the desired configuration. 
Example,

  #define FXAA_PC 1
  #define FXAA_HLSL_3 1
  #define FXAA_LINEAR 1

(2.) 
Then include this file,

  #include "Fxaa3.h"

(3.) 
Then call the FXAA pixel shader from within your desired shader,

  return FxaaPixelShader(pos, posPos, tex, rcpFrame, rcpFrameOpt);

(4.) 
Insure pass prior to FXAA outputs RGBL.
See next section.

(5.) 
Setup engine to provide "rcpFrame" and "rcpFrameOpt" constants.
Not using constants will result in a performance loss.

  // {x_} = 1.0/screenWidthInPixels
  // {_y} = 1.0/screenHeightInPixels
  float2 rcpFrame

  // This must be from a constant/uniform.
  // {x___} = 2.0/screenWidthInPixels
  // {_y__} = 2.0/screenHeightInPixels
  // {__z_} = 0.5/screenWidthInPixels
  // {___w} = 0.5/screenHeightInPixels
  float4 rcpFrameOpt 
    
(6.) 
Have FXAA vertex shader run as a full screen triangle,
and output "pos" and "posPos" such that inputs in the pixel shader provide,
  
  // {xy} = center of pixel
  float2 pos,
    
  // {xy__} = upper left of pixel
  // {__zw} = lower right of pixel
  float4 posPos,

(7.) 
Insure the texture sampler used by FXAA is set to bilinear filtering.


------------------------------------------------------------------------------
                     INTEGRATION - RGBL AND COLORSPACE
------------------------------------------------------------------------------
FXAA3 requires RGBL as input.

RGB should be LDR (low dynamic range). 
Specifically do FXAA after tonemapping.

RGB data as returned by a texture fetch can be linear or non-linear.
Note an "sRGB format" texture counts as linear, 
because the result of a texture fetch is linear data.
Regular "RGBA8" textures in the sRGB colorspace are non-linear.
If a texture fetch results linear data the following is required, 

  #define FXAA_LINEAR 1 

Otherwise,

  #define FXAA_LINEAR 0

Luma must be stored in the alpha channel prior to running FXAA.
This luma value must be gamma 2.0 encoded if using FXAA_LINEAR 1.
If using FXAA_LINEAR 0, luma should match the perceptual space used for RGB.

Example pass before FXAA where output is gamma 2.0 encoded,

  color.rgb = ToneMap(color.rgb); // linear color output
  color.rgb = sqrt(color.rgb);    // gamma 2.0 color output
  return color;

To use FXAA,

  color.rgb = ToneMap(color.rgb);  // linear color output
  color.rgb = sqrt(color.rgb);     // gamma 2.0 color output
  color.a = dot(color.rgb, float3(0.299, 0.587, 0.114)); // compute luma
  return color;

Another example where output is linear encoded,
say for instance writing to an sRGB formated render target,
where the render target does the conversion back to sRGB after blending,

  color.rgb = ToneMap(color.rgb); // linear color output
  return color;

To use FXAA,

  color.rgb = ToneMap(color.rgb); // linear color output
  color.a = sqrt(dot(color.rgb, float3(0.299, 0.587, 0.114))); // compute luma
  return color;

Getting luma correct is required for the algorithm to work correctly.


------------------------------------------------------------------------------
                            COMPLEX INTEGRATION
------------------------------------------------------------------------------
Q. What if the engine is blending into RGB before wanting to run FXAA?

A. In the last opaque pass prior to FXAA,
   have the pass write out luma into alpha.
   Then blend into RGB only.
   FXAA should be able to run ok 
   assuming the blending pass did not any add aliasing.
   This should be the common case for particles and common blending passes.

============================================================================*/

/*============================================================================

                            INTEGRATION KNOBS

============================================================================*/
//
// FXAA_PS3 and FXAA_360 choose the console algorithm (FXAA3 CONSOLE).
//
// 1 = Use API.
// 0 = Don't use API.
//
/*--------------------------------------------------------------------------*/
#ifndef FXAA_PS3
    #define FXAA_PS3 0
#endif
/*--------------------------------------------------------------------------*/
#ifndef FXAA_360
    #define FXAA_360 0
#endif
/*==========================================================================*/
#ifndef FXAA_PC
    //
    // FXAA Quality 
    // The high quality PC algorithm.
    //
    #define FXAA_PC 0
#endif
/*--------------------------------------------------------------------------*/
#ifndef FXAA_PC_CONSOLE
    //
    // The console algorithm for PC is included 
    // for developers targeting really low spec machines.
    //
    #define FXAA_PC_CONSOLE 0
#endif
/*--------------------------------------------------------------------------*/
#ifndef FXAA_GLSL_120
    #define FXAA_GLSL_120 0
#endif
/*--------------------------------------------------------------------------*/
#ifndef FXAA_GLSL_130
    #define FXAA_GLSL_130 0
#endif
/*--------------------------------------------------------------------------*/
#ifndef FXAA_HLSL_3
    #define FXAA_HLSL_3 0
#endif
/*--------------------------------------------------------------------------*/
#ifndef FXAA_HLSL_4
    #define FXAA_HLSL_4 0
#endif    
/*--------------------------------------------------------------------------*/
#ifndef FXAA_HLSL_5
    #define FXAA_HLSL_5 0
#endif    
/*==========================================================================*/
#ifndef FXAA_EARLY_EXIT
    // 
    // Controls algorithm's early exit path.
    // On PS3 turning this on adds 2 cycles to the shader.
    // On 360 turning this off adds 10ths of a millisecond to the shader.
    // Turning this off on console will result in a more blurry image.
    // So this defaults to on.
    // 
    // 1 = On.
    // 0 = Off.
    // 
    #define FXAA_EARLY_EXIT 1
#endif
/*--------------------------------------------------------------------------*/
#ifndef FXAA_DISCARD
    // 
    // Only valid for PC OpenGL currently.
    // 
    // 1 = Use discard on pixels which don't need AA.
    //     For APIs which enable concurrent TEX+ROP from same surface.
    // 0 = Return unchanged color on pixels which don't need AA.
    // 
    #define FXAA_DISCARD 0
#endif    
/*--------------------------------------------------------------------------*/
#ifndef FXAA_LINEAR
    //
    // 0 = Work in non-linear color space.
    //     Use this for standard 32-bit RGBA formats.
    //
    // 1 = Work in RGB=linear, A=non-linear luma.
    //     Use this for sRGB and FP16 formats. 
    //     Works with either FXAA_ALGORITHM = 1 or 0. 
    //
    #define FXAA_LINEAR 0
#endif
/*--------------------------------------------------------------------------*/
#ifndef FXAA_FAST_PIXEL_OFFSET
    //
    // Used for GLSL 120 only.
    //
    // 1 = GL API supports fast pixel offsets
    // 0 = do not use fast pixel offsets
    // 
    #ifdef GL_EXT_gpu_shader4
        #define FXAA_FAST_PIXEL_OFFSET 1
    #endif
    #ifdef GL_NV_gpu_shader5
        #define FXAA_FAST_PIXEL_OFFSET 1
    #endif
    #ifdef GL_ARB_gpu_shader5
        #define FXAA_FAST_PIXEL_OFFSET 1
    #endif
    #ifndef FXAA_FAST_PIXEL_OFFSET
        #define FXAA_FAST_PIXEL_OFFSET 0
    #endif
#endif
/*--------------------------------------------------------------------------*/
#ifndef FXAA_GATHER4_ALPHA
    //
    // 1 = API supports gather4 on alpha channel.
    // 0 = API does not support gather4 on alpha channel.
    //
    #if (FXAA_HLSL_5 == 1)
        #define FXAA_GATHER4_ALPHA 1
    #endif
    #ifdef GL_ARB_gpu_shader5
        #define FXAA_GATHER4_ALPHA 1
    #endif
    #ifdef GL_NV_gpu_shader5
        #define FXAA_GATHER4_ALPHA 1
    #endif
    #ifndef FXAA_GATHER4_ALPHA
        #define FXAA_GATHER4_ALPHA 0
    #endif
#endif

/*============================================================================
                         FXAA CONSOLE - TUNING KNOBS
============================================================================*/
#ifndef FXAA_CONSOLE__EDGE_SHARPNESS
    //
    // Consoles the sharpness of edges.
    // 
    // Due to the PS3 being ALU bound, 
    // there are only two safe values here: 4 and 8.
    // These options use the shaders ability to a free *|/ by 4|8.
    //
    // 8.0 is sharper
    // 4.0 is softer
    //
    #if 1 
        #define FXAA_CONSOLE__EDGE_SHARPNESS 8.0
    #else
        #define FXAA_CONSOLE__EDGE_SHARPNESS 4.0
    #endif
#endif
/*--------------------------------------------------------------------------*/
#ifndef FXAA_CONSOLE__EDGE_THRESHOLD
    //
    // The minimum amount of local contrast required to apply algorithm.
    // The console setting has a different mapping than the quality setting.
    //
    // This only applies when FXAA_EARLY_EXIT is 1.
    //
    // Due to the PS3 being ALU bound, 
    // there are only two safe values here: 0.25 and 0.125.
    // These options use the shaders ability to a free *|/ by 4|8.
    //
    // 0.125 leaves less aliasing, but is softer
    // 0.25 leaves more aliasing, and is sharper
    //
    #if 1
        #define FXAA_CONSOLE__EDGE_THRESHOLD 0.125
    #else
        #define FXAA_CONSOLE__EDGE_THRESHOLD 0.25
    #endif        
#endif
/*--------------------------------------------------------------------------*/
#ifndef FXAA_CONSOLE__EDGE_THRESHOLD_MIN
    //
    // Trims the algorithm from processing darks.
    // The console setting has a different mapping than the quality setting.
    //
    // This only applies when FXAA_EARLY_EXIT is 1.
    //
    // This does not apply to PS3.
    // PS3 was simplified to avoid more shader instructions.
    // 
    #define FXAA_CONSOLE__EDGE_THRESHOLD_MIN 0.05
#endif

/*============================================================================
                         FXAA QUALITY - TUNING KNOBS
============================================================================*/
#ifndef FXAA_QUALITY__EDGE_THRESHOLD
    //
    // The minimum amount of local contrast required to apply algorithm.
    //
    // 1/3 - too little
    // 1/4 - low quality
    // 1/6 - default
    // 1/8 - high quality
    // 1/16 - overkill
    //
    #define FXAA_QUALITY__EDGE_THRESHOLD (1.0/6.0)
#endif
/*--------------------------------------------------------------------------*/
#ifndef FXAA_QUALITY__EDGE_THRESHOLD_MIN
    //
    // Trims the algorithm from processing darks.
    //
    // 1/32 - visible limit
    // 1/16 - high quality
    // 1/12 - upper limit (default, the start of visible unfiltered edges)
    //
    #define FXAA_QUALITY__EDGE_THRESHOLD_MIN (1.0/12.0)
#endif
/*--------------------------------------------------------------------------*/
#ifndef FXAA_QUALITY__SUBPIX_CAP
    //
    // Insures fine detail is not completely removed.
    // This partly overrides FXAA_SUBPIX_TRIM.
    //
    // 3/4 - default amount of filtering
    // 7/8 - high amount of filtering
    // 1 - no capping of filtering
    //
    #define FXAA_QUALITY__SUBPIX_CAP (3.0/4.0)
#endif
/*--------------------------------------------------------------------------*/
#ifndef FXAA_QUALITY__SUBPIX_TRIM
    //
    // Controls removal of sub-pixel aliasing,
    //
    // 1/2 - low removal (sharper but more sub-pixel aliasing)
    // 1/3 - medium removal
    // 1/4 - default removal
    // 1/8 - high removal
    // 0 - complete removal (softer but less sub-pixel aliasing)
    //
    #define FXAA_QUALITY__SUBPIX_TRIM (1.0/4.0)
#endif


/*============================================================================

                                 API PORTING
                                 
============================================================================*/
#if FXAA_GLSL_120
    // Requires,
    //  #version 120
    // And at least,
    //  #extension GL_EXT_gpu_shader4 : enable
    //  (or set FXAA_FAST_PIXEL_OFFSET 1 to work like DX9) 
    #define half float
    #define half2 vec2
    #define half3 vec3
    #define half4 vec4
    #define int2 ivec2
    #define float2 vec2
    #define float3 vec3
    #define float4 vec4
    #define FxaaInt2 ivec2
    #define FxaaFloat2 vec2
    #define FxaaFloat3 vec3
    #define FxaaFloat4 vec4
    #define FxaaDiscard discard
    #define FxaaDot3(a, b) dot(a, b)
    #define FxaaSat(x) clamp(x, 0.0, 1.0)
    #define FxaaLerp(x,y,s) mix(x,y,s)
    #define FxaaTex sampler2D
    #define FxaaTexTop(t, p) texture2DLod(t, p, 0.0)
    #if (FXAA_FAST_PIXEL_OFFSET == 1)
        #define FxaaTexOff(t, p, o, r) texture2DLodOffset(t, p, 0.0, o)
    #else
        #define FxaaTexOff(t, p, o, r) texture2DLod(t, p + (o * r), 0.0)
    #endif
    #if (FXAA_GATHER4_ALPHA == 1)
        // use #extension GL_ARB_gpu_shader5 : enable
        #define FxaaTexAlpha4(t, p, r) textureGather(t, p, 3)
        #define FxaaTexOffAlpha4(t, p, o, r) textureGatherOffset(t, p, o, 3)
    #endif        
#endif
/*--------------------------------------------------------------------------*/
#if FXAA_GLSL_130
    // Requires "#version 130" or better
    #define half float
    #define half2 vec2
    #define half3 vec3
    #define half4 vec4
    #define int2 ivec2
    #define float2 vec2
    #define float3 vec3
    #define float4 vec4
    #define FxaaInt2 ivec2
    #define FxaaFloat2 vec2
    #define FxaaFloat3 vec3
    #define FxaaFloat4 vec4
    #define FxaaDiscard discard
    #define FxaaDot3(a, b) dot(a, b)
    #define FxaaSat(x) clamp(x, 0.0, 1.0)
    #define FxaaLerp(x,y,s) mix(x,y,s)
    #define FxaaTex sampler2D
    #define FxaaTexTop(t, p) textureLod(t, p, 0.0)
    #define FxaaTexOff(t, p, o, r) textureLodOffset(t, p, 0.0, o)
    #if (FXAA_GATHER4_ALPHA == 1)
        // use #extension GL_ARB_gpu_shader5 : enable
        #define FxaaTexAlpha4(t, p, r) textureGather(t, p, 3)
        #define FxaaTexOffAlpha4(t, p, o, r) textureGatherOffset(t, p, o, 3)
    #endif        
#endif
/*--------------------------------------------------------------------------*/





/*============================================================================

        FXAA3 CONSOLE - OPTIMIZED PS3 PIXEL SHADER (WITH EARLY EXIT)

==============================================================================
The code mostly matches the assembly.
I have a feeling that 14 cycles is possible, but was not able to get there.
Might have to increase register count to get full performance.
Note this shader does not use perspective interpolation.

Use the following cgc options,

  --fenable-bx2 --fastmath --fastprecision --nofloatbindings

------------------------------------------------------------------------------
                              NVSHADERPERF OUTPUT
------------------------------------------------------------------------------
For reference and to aid in debug, output of NVShaderPerf should match this,

Shader to schedule:
   0: texpkb h0.w(TRUE), v5.zyxx, #0
   2: addh h2.y(TRUE), h0.w, constant(0.001953, 0.000000, 0.000000, 0.000000).x
   4: texpkb h1.w(TRUE), v5.xwxx, #0
   6: addh h0.x(TRUE), h1.w, -h2.y
   7: texpkb h2.w(TRUE), v5.zwzz, #0
   9: minh h4.w(TRUE), h2.y, h2
  10: maxh h5.x(TRUE), h2.y, h2.w
  11: texpkb h0.w(TRUE), v5, #0
  13: addh h3.w(TRUE), -h0, h0.x
  14: addh h0.x(TRUE), h0.w, h0
  15: addh h0.z(TRUE), -h2.w, h0.x
  16: addh h0.x(TRUE), h2.w, h3.w
  17: minh h5.y(TRUE), h0.w, h1.w
  18: nrmh h2.xz(TRUE), h0_n
  19: minh_m8 h2.w(TRUE), |h2.x|, |h2.z|
  20: divx h4.xy(TRUE), h2_n.xzzw, h2_n.w
  21: movr r1.zw(TRUE), v4.xxxy
  22: maxh h2.w(TRUE), h0, h1
  23: fenct TRUE
  24: madr r0.xy(TRUE), -h2.xzzw, constant(cConst5.x, cConst5.y, cConst5.z, cConst5.w).zwzz, r1.zwzz
  26: texpkb h0(TRUE), r0, #0
  28: maxh h5.x(TRUE), h2.w, h5
  29: minh h5.w(TRUE), h5.y, h4
  30: madr r1.xy(TRUE), h2.xzzw, constant(cConst5.x, cConst5.y, cConst5.z, cConst5.w).zwzz, r1.zwzz
  32: texpkb h2(TRUE), r1, #0
  34: addh_d2 h2(TRUE), h0, h2
  35: texpkb h1(TRUE), v4, #0
  37: maxh h5.y(TRUE), h5.x, h1.w
  38: minh h4.w(TRUE), h1, h5
  39: madr r0.xy(TRUE), -h4, constant(cConst5.x, cConst5.y, cConst5.z, cConst5.w).xyxx, r1.zwzz
  41: texpkb h0(TRUE), r0, #0
  43: addh_m8 h5.z(TRUE), h5.y, -h4.w
  44: madr r2.xy(TRUE), h4, constant(cConst5.x, cConst5.y, cConst5.z, cConst5.w).xyxx, r1.zwzz
  46: texpkb h3(TRUE), r2, #0
  48: addh_d2 h0(TRUE), h0, h3
  49: addh_d2 h3(TRUE), h0, h2
  50: movh h0(TRUE), h3
  51: slth h3.x(TRUE), h3.w, h5.w
  52: sgth h3.w(TRUE), h3, h5.x
  53: addx.c0 rc(TRUE), h3.x, h3
  54: slth.c0 rc(TRUE), h5.z, h5
  55: movh h0(c0.NE.w), h2
  56: movh h0(c0.NE.x), h1

IPU0 ------ Simplified schedule: --------
Pass |  Unit  |  uOp |  PC:  Op
-----+--------+------+-------------------------
   1 | SCT0/1 |  mov |   0:  TXLr h0.w, g[TEX1].zyxx, const.xxxx, TEX0;
     |    TEX |  txl |   0:  TXLr h0.w, g[TEX1].zyxx, const.xxxx, TEX0;
     |   SCB0 |  add |   2:  ADDh h2.y, h0.-w--, const.-x--;
     |        |      |
   2 | SCT0/1 |  mov |   4:  TXLr h1.w, g[TEX1].xwxx, const.xxxx, TEX0;
     |    TEX |  txl |   4:  TXLr h1.w, g[TEX1].xwxx, const.xxxx, TEX0;
     |   SCB0 |  add |   6:  ADDh h0.x, h1.w---,-h2.y---;
     |        |      |
   3 | SCT0/1 |  mov |   7:  TXLr h2.w, g[TEX1].zwzz, const.xxxx, TEX0;
     |    TEX |  txl |   7:  TXLr h2.w, g[TEX1].zwzz, const.xxxx, TEX0;
     |   SCB0 |  max |  10:  MAXh h5.x, h2.y---, h2.w---;
     |   SCB1 |  min |   9:  MINh h4.w, h2.---y, h2;
     |        |      |
   4 | SCT0/1 |  mov |  11:  TXLr h0.w, g[TEX1], const.xxxx, TEX0;
     |    TEX |  txl |  11:  TXLr h0.w, g[TEX1], const.xxxx, TEX0;
     |   SCB0 |  add |  14:  ADDh h0.x, h0.w---, h0;
     |   SCB1 |  add |  13:  ADDh h3.w,-h0, h0.---x;
     |        |      |
   5 |   SCT0 |  mad |  16:  ADDh h0.x, h2.w---, h3.w---;
     |   SCT1 |  mad |  15:  ADDh h0.z,-h2.--w-, h0.--x-;
     |   SCB0 |  min |  17:  MINh h5.y, h0.-w--, h1.-w--;
     |        |      |
   6 |   SCT1 |  mov |  18:  NRMh h2.xz, h0;
     |    SRB |  nrm |  18:  NRMh h2.xz, h0;
     |   SCB1 |  min |  19:  MINh*8 h2.w, |h2.---x|, |h2.---z|;
     |        |      |
   7 |   SCT0 |  div |  20:  DIVx h4.xy, h2.xz--, h2.ww--;
     |   SCT1 |  mov |  21:  MOVr r1.zw, g[TEX0].--xy;
     |   SCB1 |  max |  22:  MAXh h2.w, h0, h1;
     |        |      |
   8 |   SCT0 |  mad |  24:  MADr r0.xy,-h2.xz--, const.zw--, r1.zw--;
     |   SCT1 |  mov |  26:  TXLr h0, r0, const.xxxx, TEX0;
     |    TEX |  txl |  26:  TXLr h0, r0, const.xxxx, TEX0;
     |   SCB0 |  max |  28:  MAXh h5.x, h2.w---, h5;
     |   SCB1 |  min |  29:  MINh h5.w, h5.---y, h4;
     |        |      |
   9 |   SCT0 |  mad |  30:  MADr r1.xy, h2.xz--, const.zw--, r1.zw--;
     |   SCT1 |  mov |  32:  TXLr h2, r1, const.xxxx, TEX0;
     |    TEX |  txl |  32:  TXLr h2, r1, const.xxxx, TEX0;
     | SCB0/1 |  add |  34:  ADDh/2 h2, h0, h2;
     |        |      |
  10 | SCT0/1 |  mov |  35:  TXLr h1, g[TEX0], const.xxxx, TEX0;
     |    TEX |  txl |  35:  TXLr h1, g[TEX0], const.xxxx, TEX0;
     |   SCB0 |  max |  37:  MAXh h5.y, h5.-x--, h1.-w--;
     |   SCB1 |  min |  38:  MINh h4.w, h1, h5;
     |        |      |
  11 |   SCT0 |  mad |  39:  MADr r0.xy,-h4, const.xy--, r1.zw--;
     |   SCT1 |  mov |  41:  TXLr h0, r0, const.zzzz, TEX0;
     |    TEX |  txl |  41:  TXLr h0, r0, const.zzzz, TEX0;
     |   SCB0 |  mad |  44:  MADr r2.xy, h4, const.xy--, r1.zw--;
     |   SCB1 |  add |  43:  ADDh*8 h5.z, h5.--y-,-h4.--w-;
     |        |      |
  12 | SCT0/1 |  mov |  46:  TXLr h3, r2, const.xxxx, TEX0;
     |    TEX |  txl |  46:  TXLr h3, r2, const.xxxx, TEX0;
     | SCB0/1 |  add |  48:  ADDh/2 h0, h0, h3;
     |        |      |
  13 | SCT0/1 |  mad |  49:  ADDh/2 h3, h0, h2;
     | SCB0/1 |  mul |  50:  MOVh h0, h3;
     |        |      |
  14 |   SCT0 |  set |  51:  SLTh h3.x, h3.w---, h5.w---;
     |   SCT1 |  set |  52:  SGTh h3.w, h3, h5.---x;
     |   SCB0 |  set |  54:  SLThc0 rc, h5.z---, h5;
     |   SCB1 |  add |  53:  ADDxc0_s rc, h3.---x, h3;
     |        |      |
  15 | SCT0/1 |  mul |  55:  MOVh h0(NE0.wwww), h2;
     | SCB0/1 |  mul |  56:  MOVh h0(NE0.xxxx), h1;

Pass   SCT  TEX  SCB
   1:   0% 100%  25%
   2:   0% 100%  25%
   3:   0% 100%  50%
   4:   0% 100%  50%
   5:  50%   0%  25%
   6:   0%   0%  25%
   7: 100%   0%  25%
   8:   0% 100%  50%
   9:   0% 100% 100%
  10:   0% 100%  50%
  11:   0% 100%  75%
  12:   0% 100% 100%
  13: 100%   0% 100%
  14:  50%   0%  50%
  15: 100%   0% 100%

MEAN:  26%  60%  56%

Pass   SCT0  SCT1   TEX  SCB0  SCB1
   1:    0%    0%  100%  100%    0%
   2:    0%    0%  100%  100%    0%
   3:    0%    0%  100%  100%  100%
   4:    0%    0%  100%  100%  100%
   5:  100%  100%    0%  100%    0%
   6:    0%    0%    0%    0%  100%
   7:  100%  100%    0%    0%  100%
   8:    0%    0%  100%  100%  100%
   9:    0%    0%  100%  100%  100%
  10:    0%    0%  100%  100%  100%
  11:    0%    0%  100%  100%  100%
  12:    0%    0%  100%  100%  100%
  13:  100%  100%    0%  100%  100%
  14:  100%  100%    0%  100%  100%
  15:  100%  100%    0%  100%  100%

MEAN:   33%   33%   60%   86%   80%
Fragment Performance Setup: Driver RSX Compiler, GPU RSX, Flags 0x5
Results 15 cycles, 3 r regs, 800,000,000 pixels/s
============================================================================*/
#if (FXAA_PS3 == 1) && (FXAA_EARLY_EXIT == 1)
/*--------------------------------------------------------------------------*/
#pragma disablepc all
#pragma option O2
#pragma option OutColorPrec=fp16
#pragma texformat default RGBA8
/*==========================================================================*/
half4 FxaaPixelShader(
    // {xy} = center of pixel
    float2 pos,
    // {xy__} = upper left of pixel
    // {__zw} = lower right of pixel
    float4 posPos,
    // {rgb_} = color in linear or perceptual color space
    // {___a} = luma in perceptual color space (not linear) 
    sampler2D tex,
    // This must be from a constant/uniform.
    // {xy} = rcpFrame not used on PS3
    float2 rcpFrame,
    // This must be from a constant/uniform.
    // {x___} = 2.0/screenWidthInPixels
    // {_y__} = 2.0/screenHeightInPixels
    // {__z_} = 0.5/screenWidthInPixels
    // {___w} = 0.5/screenHeightInPixels
    float4 rcpFrameOpt 
) { 
/*--------------------------------------------------------------------------*/
// (1)
    half4 rgbyNe = h4tex2Dlod(tex, half4(posPos.zy, 0, 0)); 
    half lumaNe = rgbyNe.w + half(1.0/512.0);
/*--------------------------------------------------------------------------*/
// (2)
    half4 lumaSw = h4tex2Dlod(tex, half4(posPos.xw, 0, 0));
    half lumaSwNegNe = lumaSw.w - lumaNe;
/*--------------------------------------------------------------------------*/
// (3)
    half4 lumaNw = h4tex2Dlod(tex, half4(posPos.xy, 0, 0));
    half lumaMaxNwSw = max(lumaNw.w, lumaSw.w);
    half lumaMinNwSw = min(lumaNw.w, lumaSw.w);
/*--------------------------------------------------------------------------*/
// (4)
    half4 lumaSe = h4tex2Dlod(tex, half4(posPos.zw, 0, 0));
    half dirZ =  lumaNw.w + lumaSwNegNe; 
    half dirX = -lumaNw.w + lumaSwNegNe; 
/*--------------------------------------------------------------------------*/
// (5)
    half3 dir;
    dir.y = 0.0;
    dir.x =  lumaSe.w + dirX;
    dir.z = -lumaSe.w + dirZ;
    half lumaMinNeSe = min(lumaNe, lumaSe.w);
/*--------------------------------------------------------------------------*/
// (6)
    half4 dir1_pos;
    dir1_pos.xy = normalize(dir).xz;
    half dirAbsMinTimes8 = min(abs(dir1_pos.x), abs(dir1_pos.y)) * half(FXAA_CONSOLE__EDGE_SHARPNESS);
/*--------------------------------------------------------------------------*/
// (7)
    half4 dir2_pos;
    dir2_pos.xy = clamp(dir1_pos.xy / dirAbsMinTimes8, half(-2.0), half(2.0));
    dir1_pos.zw = pos.xy;
    dir2_pos.zw = pos.xy;
    half lumaMaxNeSe = max(lumaNe, lumaSe.w);
/*--------------------------------------------------------------------------*/
// (8)
    half4 temp1N;
    temp1N.xy = dir1_pos.zw - dir1_pos.xy * rcpFrameOpt.zw;
    temp1N = h4tex2Dlod(tex, half4(temp1N.xy, 0.0, 0.0)); 
    half lumaMax = max(lumaMaxNwSw, lumaMaxNeSe);
    half lumaMin = min(lumaMinNwSw, lumaMinNeSe);
/*--------------------------------------------------------------------------*/
// (9)
    half4 rgby1;
    rgby1.xy = dir1_pos.zw + dir1_pos.xy * rcpFrameOpt.zw;
    rgby1 = h4tex2Dlod(tex, half4(rgby1.xy, 0.0, 0.0)); 
    rgby1 = (temp1N + rgby1) * 0.5;
/*--------------------------------------------------------------------------*/
// (10)
    half4 rgbyM = h4tex2Dlod(tex, half4(pos.xy, 0.0, 0.0));
    half lumaMaxM = max(lumaMax, rgbyM.w);
    half lumaMinM = min(lumaMin, rgbyM.w);
/*--------------------------------------------------------------------------*/
// (11)
    half4 temp2N;
    temp2N.xy = dir2_pos.zw - dir2_pos.xy * rcpFrameOpt.xy;
    temp2N = h4tex2Dlod(tex, half4(temp2N.xy, 0.0, 0.0));
    half4 rgby2;
    rgby2.xy = dir2_pos.zw + dir2_pos.xy * rcpFrameOpt.xy;
    half lumaRangeM = (lumaMaxM - lumaMinM) / FXAA_CONSOLE__EDGE_THRESHOLD;
/*--------------------------------------------------------------------------*/
// (12)
    rgby2 = h4tex2Dlod(tex, half4(rgby2.xy, 0.0, 0.0));
    rgby2 = (temp2N + rgby2) * 0.5; 
/*--------------------------------------------------------------------------*/
// (13)
    rgby2 = (rgby2 + rgby1) * 0.5;
/*--------------------------------------------------------------------------*/
// (14)
    bool twoTapLt = rgby2.w < lumaMin;
    bool twoTapGt = rgby2.w > lumaMax;
    bool earlyExit = lumaRangeM < lumaMax;
    bool twoTap = twoTapLt || twoTapGt;
/*--------------------------------------------------------------------------*/
// (15)
    if(twoTap) rgby2 = rgby1;
    if(earlyExit) rgby2 = rgbyM;
/*--------------------------------------------------------------------------*/
    return rgby2; }
/*==========================================================================*/
#endif



/*============================================================================

                      FXAA3 CONSOLE - PC PIXEL SHADER

------------------------------------------------------------------------------
Using a modified version of the PS3 version here to best target old hardware.
============================================================================*/
#if (FXAA_PC_CONSOLE == 1)
/*--------------------------------------------------------------------------*/
half4 FxaaPixelShader(
    // {xy} = center of pixel
    float2 pos,
    // {xy__} = upper left of pixel
    // {__zw} = lower right of pixel
    float4 posPos,
    // {rgb_} = color in linear or perceptual color space
    // {___a} = alpha output is junk value
    FxaaTex tex,
    // This must be from a constant/uniform.
    // {xy} = rcpFrame not used on PC version of FXAA Console
    float2 rcpFrame,
    // This must be from a constant/uniform.
    // {x___} = 2.0/screenWidthInPixels
    // {_y__} = 2.0/screenHeightInPixels
    // {__z_} = 0.5/screenWidthInPixels
    // {___w} = 0.5/screenHeightInPixels
    float4 rcpFrameOpt 
) {
/*--------------------------------------------------------------------------*/
    half4 dir;
    dir.y = 0.0;
    half4 lumaNe = FxaaTexTop(tex, posPos.zy); 
    lumaNe.w += half(1.0/384.0);
    dir.x = -lumaNe.w;
    dir.z = -lumaNe.w;
/*--------------------------------------------------------------------------*/
    half4 lumaSw = FxaaTexTop(tex, posPos.xw);
    dir.x += lumaSw.w;
    dir.z += lumaSw.w;
/*--------------------------------------------------------------------------*/
    half4 lumaNw = FxaaTexTop(tex, posPos.xy);
    dir.x -= lumaNw.w;
    dir.z += lumaNw.w;
/*--------------------------------------------------------------------------*/
    half4 lumaSe = FxaaTexTop(tex, posPos.zw);
    dir.x += lumaSe.w;
    dir.z -= lumaSe.w;
/*==========================================================================*/
    #if (FXAA_EARLY_EXIT == 1)
        half4 rgbyM = FxaaTexTop(tex, pos.xy);
/*--------------------------------------------------------------------------*/
        half lumaMin = min(min(lumaNw.w, lumaSw.w), min(lumaNe.w, lumaSe.w));
        half lumaMax = max(max(lumaNw.w, lumaSw.w), max(lumaNe.w, lumaSe.w));
/*--------------------------------------------------------------------------*/
        half lumaMinM = min(lumaMin, rgbyM.w); 
        half lumaMaxM = max(lumaMax, rgbyM.w); 
/*--------------------------------------------------------------------------*/
        if((lumaMaxM - lumaMinM) < max(FXAA_CONSOLE__EDGE_THRESHOLD_MIN, lumaMax * FXAA_CONSOLE__EDGE_THRESHOLD))
            #if (FXAA_DISCARD == 1)
                FxaaDiscard;
            #else
                return rgbyM;
            #endif
    #endif
/*==========================================================================*/
    half4 dir1_pos;
    dir1_pos.xy = normalize(dir.xyz).xz;
    half dirAbsMinTimesC = min(abs(dir1_pos.x), abs(dir1_pos.y)) * half(FXAA_CONSOLE__EDGE_SHARPNESS);
/*--------------------------------------------------------------------------*/
    half4 dir2_pos;
    dir2_pos.xy = clamp(dir1_pos.xy / dirAbsMinTimesC, half(-2.0), half(2.0));
    dir1_pos.zw = pos.xy;
    dir2_pos.zw = pos.xy;
    half4 temp1N;
    temp1N.xy = dir1_pos.zw - dir1_pos.xy * rcpFrameOpt.zw;
/*--------------------------------------------------------------------------*/
    temp1N = FxaaTexTop(tex, temp1N.xy); 
    half4 rgby1;
    rgby1.xy = dir1_pos.zw + dir1_pos.xy * rcpFrameOpt.zw;
/*--------------------------------------------------------------------------*/
    rgby1 = FxaaTexTop(tex, rgby1.xy); 
    rgby1 = (temp1N + rgby1) * 0.5;
/*--------------------------------------------------------------------------*/
    half4 temp2N;
    temp2N.xy = dir2_pos.zw - dir2_pos.xy * rcpFrameOpt.xy;
    temp2N = FxaaTexTop(tex, temp2N.xy); 
/*--------------------------------------------------------------------------*/
    half4 rgby2;
    rgby2.xy = dir2_pos.zw + dir2_pos.xy * rcpFrameOpt.xy;
    rgby2 = FxaaTexTop(tex, rgby2.xy);
    rgby2 = (temp2N + rgby2) * 0.5; 
/*--------------------------------------------------------------------------*/
    #if (FXAA_EARLY_EXIT == 0)
        half lumaMin = min(min(lumaNw.w, lumaSw.w), min(lumaNe.w, lumaSe.w));
        half lumaMax = max(max(lumaNw.w, lumaSw.w), max(lumaNe.w, lumaSe.w));
    #endif
    rgby2 = (rgby2 + rgby1) * 0.5;
/*--------------------------------------------------------------------------*/
    bool twoTapLt = rgby2.w < lumaMin; 
    bool twoTapGt = rgby2.w > lumaMax; 
/*--------------------------------------------------------------------------*/
    if(twoTapLt || twoTapGt) rgby2 = rgby1;
/*--------------------------------------------------------------------------*/
    return rgby2; }
/*==========================================================================*/
#endif



/*============================================================================

                              FXAA3 QUALITY - PC

============================================================================*/
#if (FXAA_PC == 1)
/*--------------------------------------------------------------------------*/
float4 FxaaPixelShader(
    // {xy} = center of pixel
    float2 pos,
    // {xyzw} = not used on FXAA3 Quality
    float4 posPos,       
    // {rgb_} = color in linear or perceptual color space
    // {___a} = luma in perceptual color space (not linear) 
    FxaaTex tex,
    // This must be from a constant/uniform.
    // {x_} = 1.0/screenWidthInPixels
    // {_y} = 1.0/screenHeightInPixels
    float2 rcpFrame,
    // {xyzw} = not used on FXAA3 Quality
    float4 rcpFrameOpt 
) {   
/*--------------------------------------------------------------------------*/
    #if (FXAA_GATHER4_ALPHA == 1)
        float4 luma4A = FxaaTexOffAlpha4(tex, pos.xy, FxaaInt2(-1, -1), rcpFrame.xy);
        #if (FXAA_DISCARD == 0)
            float4 rgbyM = FxaaTexTop(tex, pos.xy);
        #endif
        float4 luma4B = FxaaTexAlpha4(tex, pos.xy, rcpFrame.xy);
        float lumaNE = FxaaTexOff(tex, pos.xy, FxaaInt2(1, -1), rcpFrame.xy).w;
        float lumaSW = FxaaTexOff(tex, pos.xy, FxaaInt2(-1, 1), rcpFrame.xy).w;
        float lumaNW = luma4A.w;
        float lumaN  = luma4A.z;
        float lumaW  = luma4A.x;
        float lumaM  = luma4A.y;
        float lumaE  = luma4B.z;
        float lumaS  = luma4B.x;
        float lumaSE = luma4B.y;
    #else
        float lumaN = FxaaTexOff(tex, pos.xy, FxaaInt2(0, -1), rcpFrame.xy).w;
        float lumaW = FxaaTexOff(tex, pos.xy, FxaaInt2(-1, 0), rcpFrame.xy).w;
        float4 rgbyM = FxaaTexTop(tex, pos.xy);
        float lumaE = FxaaTexOff(tex, pos.xy, FxaaInt2( 1, 0), rcpFrame.xy).w;
        float lumaS = FxaaTexOff(tex, pos.xy, FxaaInt2( 0, 1), rcpFrame.xy).w;
        float lumaM = rgbyM.w;
    #endif
/*--------------------------------------------------------------------------*/
    float rangeMin = min(lumaM, min(min(lumaN, lumaW), min(lumaS, lumaE)));
    float rangeMax = max(lumaM, max(max(lumaN, lumaW), max(lumaS, lumaE)));
    float range = rangeMax - rangeMin;
/*--------------------------------------------------------------------------*/
    if(range < max(FXAA_QUALITY__EDGE_THRESHOLD_MIN, rangeMax * FXAA_QUALITY__EDGE_THRESHOLD))
        #if (FXAA_DISCARD == 1)
            FxaaDiscard;
        #else
            return rgbyM;
        #endif
/*--------------------------------------------------------------------------*/
    #if (FXAA_GATHER4_ALPHA == 0) 
        float lumaNW = FxaaTexOff(tex, pos.xy, FxaaInt2(-1,-1), rcpFrame.xy).w;
        float lumaNE = FxaaTexOff(tex, pos.xy, FxaaInt2( 1,-1), rcpFrame.xy).w;
        float lumaSW = FxaaTexOff(tex, pos.xy, FxaaInt2(-1, 1), rcpFrame.xy).w;
        float lumaSE = FxaaTexOff(tex, pos.xy, FxaaInt2( 1, 1), rcpFrame.xy).w;
    #endif
/*--------------------------------------------------------------------------*/
    #define FXAA_QUALITY__SUBPIX_TRIM_SCALE  (1.0/(1.0 - FXAA_QUALITY__SUBPIX_TRIM))
/*--------------------------------------------------------------------------*/
    float lumaL = (lumaN + lumaW + lumaE + lumaS) * 0.25;
    float rangeL = abs(lumaL - lumaM);
    float blendL = FxaaSat((rangeL / range) - FXAA_QUALITY__SUBPIX_TRIM) * FXAA_QUALITY__SUBPIX_TRIM_SCALE; 
    blendL = min(FXAA_QUALITY__SUBPIX_CAP, blendL);
/*--------------------------------------------------------------------------*/
    float edgeVert = 
              abs(lumaNW + (-2.0 * lumaN) + lumaNE) +
        2.0 * abs(lumaW  + (-2.0 * lumaM) + lumaE ) +
              abs(lumaSW + (-2.0 * lumaS) + lumaSE);
    float edgeHorz = 
              abs(lumaNW + (-2.0 * lumaW) + lumaSW) +
        2.0 * abs(lumaN  + (-2.0 * lumaM) + lumaS ) +
              abs(lumaNE + (-2.0 * lumaE) + lumaSE);
    bool horzSpan = edgeHorz >= edgeVert;
/*--------------------------------------------------------------------------*/
    float lengthSign = horzSpan ? -rcpFrame.y : -rcpFrame.x;
    if(!horzSpan) lumaN = lumaW;
    if(!horzSpan) lumaS = lumaE;
    float gradientN = abs(lumaN - lumaM);
    float gradientS = abs(lumaS - lumaM);
    lumaN = (lumaN + lumaM) * 0.5;
    lumaS = (lumaS + lumaM) * 0.5;
/*--------------------------------------------------------------------------*/
    bool pairN = gradientN >= gradientS;
    if(!pairN) lumaN = lumaS;
    if(!pairN) gradientN = gradientS;
    if(!pairN) lengthSign *= -1.0;
    float2 posN;
    posN.x = pos.x + (horzSpan ? 0.0 : lengthSign * 0.5);
    posN.y = pos.y + (horzSpan ? lengthSign * 0.5 : 0.0);
/*--------------------------------------------------------------------------*/
    #define FXAA_SEARCH_STEPS     6
    #define FXAA_SEARCH_THRESHOLD (1.0/4.0)
/*--------------------------------------------------------------------------*/
    gradientN *= FXAA_SEARCH_THRESHOLD;
/*--------------------------------------------------------------------------*/
    float2 posP = posN;
    float2 offNP = horzSpan ? 
        FxaaFloat2(rcpFrame.x, 0.0) :
        FxaaFloat2(0.0f, rcpFrame.y); 
    float lumaEndN;
    float lumaEndP;
    bool doneN = false;
    bool doneP = false;
    posN += offNP * (-1.5);
    posP += offNP * ( 1.5);
    for(int i = 0; i < FXAA_SEARCH_STEPS; i++) {
        lumaEndN = FxaaTexTop(tex, posN.xy).w;
        lumaEndP = FxaaTexTop(tex, posP.xy).w;
        bool doneN2 = abs(lumaEndN - lumaN) >= gradientN;
        bool doneP2 = abs(lumaEndP - lumaN) >= gradientN;
        if(doneN2 && !doneN) posN += offNP;
        if(doneP2 && !doneP) posP -= offNP;
        if(doneN2 && doneP2) break;
        doneN = doneN2;
        doneP = doneP2;
        if(!doneN) posN -= offNP * 2.0;
        if(!doneP) posP += offNP * 2.0; }
/*--------------------------------------------------------------------------*/
    float dstN = horzSpan ? pos.x - posN.x : pos.y - posN.y;
    float dstP = horzSpan ? posP.x - pos.x : posP.y - pos.y;
/*--------------------------------------------------------------------------*/
    bool directionN = dstN < dstP;
    lumaEndN = directionN ? lumaEndN : lumaEndP;
/*--------------------------------------------------------------------------*/
    if(((lumaM - lumaN) < 0.0) == ((lumaEndN - lumaN) < 0.0)) 
        lengthSign = 0.0;
/*--------------------------------------------------------------------------*/
    float spanLength = (dstP + dstN);
    dstN = directionN ? dstN : dstP;
    float subPixelOffset = 0.5 + (dstN * (-1.0/spanLength));
    subPixelOffset += blendL * (1.0/8.0);
    subPixelOffset *= lengthSign;
    float3 rgbF = FxaaTexTop(tex, FxaaFloat2(
        pos.x + (horzSpan ? 0.0 : subPixelOffset),
        pos.y + (horzSpan ? subPixelOffset : 0.0))).xyz;
/*--------------------------------------------------------------------------*/
    #if (FXAA_LINEAR == 1)
        lumaL *= lumaL;
    #endif
    float lumaF = dot(rgbF, float3(0.299, 0.587, 0.114)) + (1.0/(65536.0*256.0));
    float lumaB = FxaaLerp(lumaF, lumaL, blendL);
    float scale = min(4.0, lumaB/lumaF);
    rgbF *= scale;
    return float4(rgbF, lumaM); }
/*==========================================================================*/
#endif



