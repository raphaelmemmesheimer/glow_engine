cmake_minimum_required(VERSION 2.8)
#set( CMAKE_VERBOSE_MAKEFILE on )
project(glow)
set(CMAKE_CXX_FLAGS "-O0 -g3") #Debug
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)

set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
# option(WX_BACKEND 
execute_process(COMMAND ${CMAKE_C_COMPILER} -dumpversion OUTPUT_VARIABLE GCC_VERSION)
if (GCC_VERSION VERSION_GREATER 4.6 OR GCC_VERSION VERSION_EQUAL 4.6)
  message(STATUS "GCC Version >= 4.6")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wsuggest-attribute=const")
else()
  message(STATUS "GCC Version < 4.6, try to upgrade")
endif()

find_package(OpenGL)
if(NOT OPENGL_FOUND)
  message("ERROR: OpenGL not found")
endif(NOT OPENGL_FOUND)

#hack around cc_args
#bug -- always replaces incorrect .clang_complete file ... the wxIncludes are missing
#set (CMAKE_CXX_COMPILER /home/raphael/.vim/bin/cc_args.py)#${CMAKE_CXX_COMPILER})
#set (CMAKE_CXX_COMPILER_ARG1 g++)

#SET(wxWidgets_USE_LIBS)
FIND_PACKAGE(wxWidgets)
IF(wxWidgets_FOUND)
  INCLUDE("${wxWidgets_USE_FILE}")
  # and for each of your dependant executable/library targets:
  #TARGET_LINK_LIBRARIES(MyTest ${wxWidgets_LIBRARIES})
ELSE(wxWidgets_FOUND)
  # For convenience. When we cannot continue, inform the user
  MESSAGE("wxWidgets not found!")
ENDIF(wxWidgets_FOUND)

list(APPEND LIBS
  glfw 
  gl3w
  openctm
  #tinyxml
  pthread  
  X11 
  wx_gtk2u_core-2.8 
  wx_baseu-2.8 
  wx_gtk2u_richtext-2.8  
  wx_gtk2u_aui-2.8 
  wx_gtk2u_xrc-2.8 
  wx_gtk2u_qa-2.8 
  wx_gtk2u_html-2.8 
  wx_gtk2u_adv-2.8 
  wx_baseu_net-2.8 
  Xrandr 
  asound
  bass 
  rocket 
  opencv_core 
  opencv_highgui 
  wx_gtk2u_scintilla-2.8
)

file(GLOB_RECURSE Glow_SOURCES "src/*.cpp")
file(GLOB_RECURSE Glow_HEADERS "src/*.h")

set (Glow_INCLUDE_DIRS "")
foreach (_headerFile ${Foo_HEADERS})
    get_filename_component(_dir ${_headerFile} PATH)
    list (APPEND Glow_INCLUDE_DIRS ${_dir})
endforeach()
list(REMOVE_DUPLICATES Glow_INCLUDE_DIRS)

include_directories(${Glow_INCLUDE_DIRS})
add_executable (glow ${Glow_SOURCES})
target_link_libraries(glow ${LIBS} )

#message(${INCLUDE_DIRECTORIES} "hallo")
