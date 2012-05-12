# -*- coding: utf-8 -*- 

###########################################################################
## Python code generated with wxFormBuilder (version Apr 11 2012)
## http://www.wxformbuilder.org/
##
## PLEASE DO "NOT" EDIT THIS FILE!
###########################################################################

import wx
import wx.xrc
import wx.richtext
#include "../System/wxControls/wxTimeline.h"

ID_LOAD_FRAGMENT = 1000
ID_SAVE_FRAGMENT = 1001
ID_LOAD_VERTEX = 1002
ID_SAVE_VERTEX = 1003
ID_COMPILE = 1004
ID_LOAD = 1005
ID_PHONG_EDITOR = 1006
ID_SHOW_EDITOR = 1007

###########################################################################
## Class fPhongEditor
###########################################################################

class fPhongEditor ( wx.Frame ):
	
	def __init__( self, parent ):
		wx.Frame.__init__ ( self, parent, id = wx.ID_ANY, title = u"Phong Editor", pos = wx.DefaultPosition, size = wx.Size( 600,650 ), style = wx.DEFAULT_FRAME_STYLE|wx.TAB_TRAVERSAL, name = u"PhongEditor" )
		
		self.SetSizeHintsSz( wx.DefaultSize, wx.DefaultSize )
		
		gSizer1 = wx.GridSizer( 2, 2, 0, 0 )
		
		self.m_staticText1 = wx.StaticText( self, wx.ID_ANY, u"Shininess", wx.DefaultPosition, wx.DefaultSize, 0 )
		self.m_staticText1.Wrap( -1 )
		gSizer1.Add( self.m_staticText1, 1, wx.ALL, 5 )
		
		self.sliderShininess = wx.Slider( self, wx.ID_ANY, 50, 0, 255, wx.DefaultPosition, wx.Size( 255,-1 ), wx.SL_HORIZONTAL )
		gSizer1.Add( self.sliderShininess, 0, wx.ALL, 5 )
		
		self.m_staticText2 = wx.StaticText( self, wx.ID_ANY, u"AmbientColor", wx.DefaultPosition, wx.DefaultSize, 0 )
		self.m_staticText2.Wrap( -1 )
		gSizer1.Add( self.m_staticText2, 0, wx.ALL, 5 )
		
		bSizer51 = wx.BoxSizer( wx.VERTICAL )
		
		self.sliderColorAmbientRed = wx.Slider( self, wx.ID_ANY, 2, 0, 255, wx.DefaultPosition, wx.DefaultSize, wx.SL_HORIZONTAL )
		self.sliderColorAmbientRed.SetMinSize( wx.Size( 255,-1 ) )
		
		bSizer51.Add( self.sliderColorAmbientRed, 0, wx.ALL, 5 )
		
		self.sliderColorAmbientGreen = wx.Slider( self, wx.ID_ANY, 2, 0, 255, wx.DefaultPosition, wx.DefaultSize, wx.SL_HORIZONTAL )
		self.sliderColorAmbientGreen.SetMinSize( wx.Size( 255,-1 ) )
		
		bSizer51.Add( self.sliderColorAmbientGreen, 0, wx.ALL, 5 )
		
		self.sliderColorAmbientBlue = wx.Slider( self, wx.ID_ANY, 2, 0, 255, wx.DefaultPosition, wx.DefaultSize, wx.SL_HORIZONTAL )
		self.sliderColorAmbientBlue.SetMinSize( wx.Size( 255,-1 ) )
		
		bSizer51.Add( self.sliderColorAmbientBlue, 0, wx.ALL, 5 )
		
		self.colourPickerAmbient = wx.ColourPickerCtrl( self, wx.ID_ANY, wx.Colour( 32, 32, 32 ), wx.DefaultPosition, wx.DefaultSize, wx.CLRP_DEFAULT_STYLE )
		bSizer51.Add( self.colourPickerAmbient, 0, wx.ALL, 5 )
		
		
		gSizer1.Add( bSizer51, 1, wx.EXPAND, 5 )
		
		self.m_staticText3 = wx.StaticText( self, wx.ID_ANY, u"DiffuseColor", wx.DefaultPosition, wx.DefaultSize, 0 )
		self.m_staticText3.Wrap( -1 )
		gSizer1.Add( self.m_staticText3, 0, wx.ALL, 5 )
		
		bSizer5 = wx.BoxSizer( wx.VERTICAL )
		
		self.sliderColorRed = wx.Slider( self, wx.ID_ANY, 127, 0, 255, wx.DefaultPosition, wx.DefaultSize, wx.SL_HORIZONTAL )
		self.sliderColorRed.SetMinSize( wx.Size( 255,-1 ) )
		
		bSizer5.Add( self.sliderColorRed, 0, wx.ALL, 5 )
		
		self.sliderColorGreen = wx.Slider( self, wx.ID_ANY, 127, 0, 255, wx.DefaultPosition, wx.DefaultSize, wx.SL_HORIZONTAL )
		self.sliderColorGreen.SetMinSize( wx.Size( 255,-1 ) )
		
		bSizer5.Add( self.sliderColorGreen, 0, wx.ALL, 5 )
		
		self.sliderColorBlue = wx.Slider( self, wx.ID_ANY, 127, 0, 255, wx.DefaultPosition, wx.DefaultSize, wx.SL_HORIZONTAL )
		self.sliderColorBlue.SetMinSize( wx.Size( 255,-1 ) )
		
		bSizer5.Add( self.sliderColorBlue, 0, wx.ALL, 5 )
		
		self.colourPickerDiffuse = wx.ColourPickerCtrl( self, wx.ID_ANY, wx.Colour( 128, 128, 128 ), wx.DefaultPosition, wx.DefaultSize, wx.CLRP_DEFAULT_STYLE )
		bSizer5.Add( self.colourPickerDiffuse, 0, wx.ALL, 5 )
		
		
		gSizer1.Add( bSizer5, 1, wx.EXPAND, 5 )
		
		self.m_staticText21 = wx.StaticText( self, wx.ID_ANY, u"SpecularColor", wx.DefaultPosition, wx.DefaultSize, 0 )
		self.m_staticText21.Wrap( -1 )
		gSizer1.Add( self.m_staticText21, 0, wx.ALL, 5 )
		
		bSizer52 = wx.BoxSizer( wx.VERTICAL )
		
		self.sliderColorSpecularRed = wx.Slider( self, wx.ID_ANY, 255, 0, 255, wx.DefaultPosition, wx.DefaultSize, wx.SL_HORIZONTAL )
		self.sliderColorSpecularRed.SetMinSize( wx.Size( 255,-1 ) )
		
		bSizer52.Add( self.sliderColorSpecularRed, 0, wx.ALL, 5 )
		
		self.sliderColorSpecularGreen = wx.Slider( self, wx.ID_ANY, 255, 0, 255, wx.DefaultPosition, wx.DefaultSize, wx.SL_HORIZONTAL )
		self.sliderColorSpecularGreen.SetMinSize( wx.Size( 255,-1 ) )
		
		bSizer52.Add( self.sliderColorSpecularGreen, 0, wx.ALL, 5 )
		
		self.sliderColorSpecularBlue = wx.Slider( self, wx.ID_ANY, 255, 0, 255, wx.DefaultPosition, wx.DefaultSize, wx.SL_HORIZONTAL )
		self.sliderColorSpecularBlue.SetMinSize( wx.Size( 255,-1 ) )
		
		bSizer52.Add( self.sliderColorSpecularBlue, 0, wx.ALL, 5 )
		
		self.colourPickerSpecular = wx.ColourPickerCtrl( self, wx.ID_ANY, wx.Colour( 255, 255, 255 ), wx.DefaultPosition, wx.DefaultSize, wx.CLRP_DEFAULT_STYLE )
		bSizer52.Add( self.colourPickerSpecular, 0, wx.ALL, 5 )
		
		
		gSizer1.Add( bSizer52, 1, wx.EXPAND, 5 )
		
		
		self.SetSizer( gSizer1 )
		self.Layout()
		
		# Connect Events
		self.Bind( wx.EVT_IDLE, self.OnIdle )
		self.sliderColorAmbientRed.Bind( wx.EVT_SCROLL, self.OnScrollAmbient )
		self.sliderColorAmbientGreen.Bind( wx.EVT_SCROLL, self.OnScrollAmbient )
		self.sliderColorAmbientBlue.Bind( wx.EVT_SCROLL, self.OnScrollAmbient )
		self.colourPickerAmbient.Bind( wx.EVT_COLOURPICKER_CHANGED, self.OnAmbientColorChanged )
		self.sliderColorRed.Bind( wx.EVT_SCROLL, self.OnScrollDiffuse )
		self.sliderColorGreen.Bind( wx.EVT_SCROLL, self.OnScrollDiffuse )
		self.sliderColorBlue.Bind( wx.EVT_SCROLL, self.OnScrollDiffuse )
		self.colourPickerDiffuse.Bind( wx.EVT_COLOURPICKER_CHANGED, self.OnDiffuseColorChanged )
		self.sliderColorSpecularRed.Bind( wx.EVT_SCROLL, self.OnScrollSpecular )
		self.sliderColorSpecularGreen.Bind( wx.EVT_SCROLL, self.OnScrollSpecular )
		self.sliderColorSpecularBlue.Bind( wx.EVT_SCROLL, self.OnScrollSpecular )
		self.colourPickerSpecular.Bind( wx.EVT_COLOURPICKER_CHANGED, self.OnSpecularColorChanged )
	
	def __del__( self ):
		pass
	
	
	# Virtual event handlers, overide them in your derived class
	def OnIdle( self, event ):
		event.Skip()
	
	def OnScrollAmbient( self, event ):
		event.Skip()
	
	
	
	def OnAmbientColorChanged( self, event ):
		event.Skip()
	
	def OnScrollDiffuse( self, event ):
		event.Skip()
	
	
	
	def OnDiffuseColorChanged( self, event ):
		event.Skip()
	
	def OnScrollSpecular( self, event ):
		event.Skip()
	
	
	
	def OnSpecularColorChanged( self, event ):
		event.Skip()
	

###########################################################################
## Class fShaderEditor
###########################################################################

class fShaderEditor ( wx.Frame ):
	
	def __init__( self, parent ):
		wx.Frame.__init__ ( self, parent, id = wx.ID_ANY, title = u"Shader Editor", pos = wx.DefaultPosition, size = wx.Size( 995,757 ), style = wx.CAPTION|wx.DEFAULT_FRAME_STYLE|wx.TAB_TRAVERSAL )
		
		self.SetSizeHintsSz( wx.DefaultSize, wx.DefaultSize )
		
		bSizer5 = wx.BoxSizer( wx.VERTICAL )
		
		bSizer38 = wx.BoxSizer( wx.HORIZONTAL )
		
		bSizer38.SetMinSize( wx.Size( -1,40 ) ) 
		self.m_staticText13 = wx.StaticText( self, wx.ID_ANY, u"Select Shader", wx.DefaultPosition, wx.DefaultSize, 0 )
		self.m_staticText13.Wrap( -1 )
		bSizer38.Add( self.m_staticText13, 0, wx.ALL, 5 )
		
		choiceShadersChoices = []
		self.choiceShaders = wx.Choice( self, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize, choiceShadersChoices, 0 )
		self.choiceShaders.SetSelection( 0 )
		bSizer38.Add( self.choiceShaders, 1, wx.ALL, 5 )
		
		
		bSizer5.Add( bSizer38, 0, wx.EXPAND, 5 )
		
		self.m_notebook1 = wx.Notebook( self, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize, 0 )
		self.m_panel1 = wx.Panel( self.m_notebook1, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize, wx.TAB_TRAVERSAL )
		bSizer6 = wx.BoxSizer( wx.VERTICAL )
		
		# WARNING: wxPython code generation isn't supported for this widget yet.
		self.scVertex = wx.Window( self.m_panel1 )
		bSizer6.Add( self.scVertex, 1, wx.EXPAND|wx.BOTTOM|wx.RIGHT|wx.LEFT, 5 )
		
		bSizer141 = wx.BoxSizer( wx.HORIZONTAL )
		
		self.fpVertex = wx.FilePickerCtrl( self.m_panel1, wx.ID_ANY, wx.EmptyString, u"Select a file", u"*.vert", wx.DefaultPosition, wx.Size( 200,-1 ), wx.FLP_DEFAULT_STYLE )
		self.fpVertex.SetMaxSize( wx.Size( -1,30 ) )
		
		bSizer141.Add( self.fpVertex, 1, wx.ALL|wx.EXPAND, 5 )
		
		self.bSaveVertex = wx.BitmapButton( self.m_panel1, wx.ID_ANY, wx.NullBitmap, wx.DefaultPosition, wx.DefaultSize, wx.BU_AUTODRAW )
		bSizer141.Add( self.bSaveVertex, 0, wx.ALL, 5 )
		
		self.bLoadVertex = wx.BitmapButton( self.m_panel1, wx.ID_ANY, wx.NullBitmap, wx.DefaultPosition, wx.DefaultSize, wx.BU_AUTODRAW )
		bSizer141.Add( self.bLoadVertex, 0, wx.ALL, 5 )
		
		
		bSizer6.Add( bSizer141, 0, wx.EXPAND, 5 )
		
		
		self.m_panel1.SetSizer( bSizer6 )
		self.m_panel1.Layout()
		bSizer6.Fit( self.m_panel1 )
		self.m_notebook1.AddPage( self.m_panel1, u"Vertex Shader", False )
		self.m_panel21 = wx.Panel( self.m_notebook1, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize, wx.TAB_TRAVERSAL )
		bSizer612 = wx.BoxSizer( wx.VERTICAL )
		
		# WARNING: wxPython code generation isn't supported for this widget yet.
		self.scTessellationControl = wx.Window( self.m_panel21 )
		bSizer612.Add( self.scTessellationControl, 1, wx.EXPAND |wx.ALL, 5 )
		
		bSizer152 = wx.BoxSizer( wx.HORIZONTAL )
		
		self.fpTessellationControl = wx.FilePickerCtrl( self.m_panel21, wx.ID_ANY, wx.EmptyString, u"Select a file", u"*.tessc", wx.DefaultPosition, wx.DefaultSize, wx.FLP_DEFAULT_STYLE )
		bSizer152.Add( self.fpTessellationControl, 1, wx.ALL|wx.EXPAND, 5 )
		
		self.bSaveTessellationControl = wx.BitmapButton( self.m_panel21, wx.ID_ANY, wx.NullBitmap, wx.DefaultPosition, wx.DefaultSize, wx.BU_AUTODRAW )
		bSizer152.Add( self.bSaveTessellationControl, 0, wx.ALL, 5 )
		
		self.bLoadTessellationControl = wx.BitmapButton( self.m_panel21, wx.ID_ANY, wx.NullBitmap, wx.DefaultPosition, wx.DefaultSize, wx.BU_AUTODRAW )
		bSizer152.Add( self.bLoadTessellationControl, 0, wx.ALL, 5 )
		
		
		bSizer612.Add( bSizer152, 0, wx.EXPAND, 5 )
		
		
		self.m_panel21.SetSizer( bSizer612 )
		self.m_panel21.Layout()
		bSizer612.Fit( self.m_panel21 )
		self.m_notebook1.AddPage( self.m_panel21, u"Tessellation Control Shader", False )
		self.m_panel11 = wx.Panel( self.m_notebook1, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize, wx.TAB_TRAVERSAL )
		bSizer62 = wx.BoxSizer( wx.VERTICAL )
		
		# WARNING: wxPython code generation isn't supported for this widget yet.
		self.scTessellationEvaluation = wx.Window( self.m_panel11 )
		bSizer62.Add( self.scTessellationEvaluation, 1, wx.EXPAND|wx.BOTTOM|wx.RIGHT|wx.LEFT, 5 )
		
		bSizer1411 = wx.BoxSizer( wx.HORIZONTAL )
		
		self.fpTessellationEvaluation = wx.FilePickerCtrl( self.m_panel11, wx.ID_ANY, wx.EmptyString, u"Select a file", u"*.tesse", wx.DefaultPosition, wx.Size( 200,-1 ), wx.FLP_DEFAULT_STYLE )
		self.fpTessellationEvaluation.SetMaxSize( wx.Size( -1,30 ) )
		
		bSizer1411.Add( self.fpTessellationEvaluation, 1, wx.ALL|wx.EXPAND, 5 )
		
		self.bSaveTessellationEvaluation = wx.BitmapButton( self.m_panel11, wx.ID_ANY, wx.NullBitmap, wx.DefaultPosition, wx.DefaultSize, wx.BU_AUTODRAW )
		bSizer1411.Add( self.bSaveTessellationEvaluation, 0, wx.ALL, 5 )
		
		self.bLoadTessellationEvaluation = wx.BitmapButton( self.m_panel11, wx.ID_ANY, wx.NullBitmap, wx.DefaultPosition, wx.DefaultSize, wx.BU_AUTODRAW )
		bSizer1411.Add( self.bLoadTessellationEvaluation, 0, wx.ALL, 5 )
		
		
		bSizer62.Add( bSizer1411, 0, wx.EXPAND, 5 )
		
		
		self.m_panel11.SetSizer( bSizer62 )
		self.m_panel11.Layout()
		bSizer62.Fit( self.m_panel11 )
		self.m_notebook1.AddPage( self.m_panel11, u"Tessellation Evaluation Shader", False )
		self.m_panel22 = wx.Panel( self.m_notebook1, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize, wx.TAB_TRAVERSAL )
		bSizer611 = wx.BoxSizer( wx.VERTICAL )
		
		# WARNING: wxPython code generation isn't supported for this widget yet.
		self.scGeometry = wx.Window( self.m_panel22 )
		bSizer611.Add( self.scGeometry, 1, wx.EXPAND |wx.ALL, 5 )
		
		bSizer151 = wx.BoxSizer( wx.HORIZONTAL )
		
		self.fpGeometry = wx.FilePickerCtrl( self.m_panel22, wx.ID_ANY, wx.EmptyString, u"Select a file", u"*.geom", wx.DefaultPosition, wx.DefaultSize, wx.FLP_DEFAULT_STYLE )
		bSizer151.Add( self.fpGeometry, 1, wx.ALL|wx.EXPAND, 5 )
		
		self.bSaveGeometry = wx.BitmapButton( self.m_panel22, wx.ID_ANY, wx.NullBitmap, wx.DefaultPosition, wx.DefaultSize, wx.BU_AUTODRAW )
		bSizer151.Add( self.bSaveGeometry, 0, wx.ALL, 5 )
		
		self.bLoadGeometry = wx.BitmapButton( self.m_panel22, wx.ID_ANY, wx.NullBitmap, wx.DefaultPosition, wx.DefaultSize, wx.BU_AUTODRAW )
		bSizer151.Add( self.bLoadGeometry, 0, wx.ALL, 5 )
		
		
		bSizer611.Add( bSizer151, 0, wx.EXPAND, 5 )
		
		
		self.m_panel22.SetSizer( bSizer611 )
		self.m_panel22.Layout()
		bSizer611.Fit( self.m_panel22 )
		self.m_notebook1.AddPage( self.m_panel22, u"Geometry Shader", False )
		self.m_panel2 = wx.Panel( self.m_notebook1, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize, wx.TAB_TRAVERSAL )
		bSizer61 = wx.BoxSizer( wx.VERTICAL )
		
		# WARNING: wxPython code generation isn't supported for this widget yet.
		self.scFragment = wx.Window( self.m_panel2 )
		bSizer61.Add( self.scFragment, 1, wx.EXPAND |wx.ALL, 5 )
		
		bSizer15 = wx.BoxSizer( wx.HORIZONTAL )
		
		self.fpFragment = wx.FilePickerCtrl( self.m_panel2, wx.ID_ANY, wx.EmptyString, u"Select a file", u"*.frag", wx.DefaultPosition, wx.DefaultSize, wx.FLP_DEFAULT_STYLE )
		bSizer15.Add( self.fpFragment, 1, wx.ALL|wx.EXPAND, 5 )
		
		self.bSaveFragment = wx.BitmapButton( self.m_panel2, wx.ID_ANY, wx.NullBitmap, wx.DefaultPosition, wx.DefaultSize, wx.BU_AUTODRAW )
		bSizer15.Add( self.bSaveFragment, 0, wx.ALL, 5 )
		
		self.bLoadFragment = wx.BitmapButton( self.m_panel2, wx.ID_ANY, wx.NullBitmap, wx.DefaultPosition, wx.DefaultSize, wx.BU_AUTODRAW )
		bSizer15.Add( self.bLoadFragment, 0, wx.ALL, 5 )
		
		
		bSizer61.Add( bSizer15, 0, wx.EXPAND, 5 )
		
		
		self.m_panel2.SetSizer( bSizer61 )
		self.m_panel2.Layout()
		bSizer61.Fit( self.m_panel2 )
		self.m_notebook1.AddPage( self.m_panel2, u"Fragment Shader", True )
		self.m_panel13 = wx.Panel( self.m_notebook1, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize, wx.TAB_TRAVERSAL )
		bSizer14 = wx.BoxSizer( wx.VERTICAL )
		
		self.m_richText5 = wx.richtext.RichTextCtrl( self.m_panel13, wx.ID_ANY, wx.EmptyString, wx.DefaultPosition, wx.DefaultSize, 0|wx.VSCROLL|wx.HSCROLL|wx.NO_BORDER|wx.WANTS_CHARS )
		self.m_richText5.SetFont( wx.Font( 8, 76, 90, 90, False, "Monospace" ) )
		
		bSizer14.Add( self.m_richText5, 1, wx.EXPAND |wx.ALL, 5 )
		
		
		self.m_panel13.SetSizer( bSizer14 )
		self.m_panel13.Layout()
		bSizer14.Fit( self.m_panel13 )
		self.m_notebook1.AddPage( self.m_panel13, u"Quick Reference", False )
		
		bSizer5.Add( self.m_notebook1, 1, wx.ALL|wx.EXPAND, 5 )
		
		# WARNING: wxPython code generation isn't supported for this widget yet.
		self.scLog = wx.Window( self )
		bSizer5.Add( self.scLog, 1, wx.ALL|wx.EXPAND, 5 )
		
		self.m_button1 = wx.Button( self, wx.ID_ANY, u"&Compile", wx.DefaultPosition, wx.DefaultSize, 0 )
		bSizer5.Add( self.m_button1, 0, wx.ALL, 5 )
		
		
		self.SetSizer( bSizer5 )
		self.Layout()
		self.m_menubar2 = wx.MenuBar( 0 )
		self.shader = wx.Menu()
		self.loadFragment = wx.MenuItem( self.shader, ID_LOAD_FRAGMENT, u"Load Fragment", wx.EmptyString, wx.ITEM_NORMAL )
		self.shader.AppendItem( self.loadFragment )
		
		self.saveFragment = wx.MenuItem( self.shader, ID_SAVE_FRAGMENT, u"Save Fragment", wx.EmptyString, wx.ITEM_NORMAL )
		self.shader.AppendItem( self.saveFragment )
		
		self.loadVertex = wx.MenuItem( self.shader, ID_LOAD_VERTEX, u"Load Vertex", wx.EmptyString, wx.ITEM_NORMAL )
		self.shader.AppendItem( self.loadVertex )
		
		self.saveVertex = wx.MenuItem( self.shader, ID_SAVE_VERTEX, u"Save Vertex", wx.EmptyString, wx.ITEM_NORMAL )
		self.shader.AppendItem( self.saveVertex )
		
		self.compile = wx.MenuItem( self.shader, ID_COMPILE, u"Compile", wx.EmptyString, wx.ITEM_NORMAL )
		self.shader.AppendItem( self.compile )
		
		self.m_menubar2.Append( self.shader, u"Shader" ) 
		
		self.SetMenuBar( self.m_menubar2 )
		
		
		# Connect Events
		self.choiceShaders.Bind( wx.EVT_CHOICE, self.OnChoiceShader )
		self.fpVertex.Bind( wx.EVT_FILEPICKER_CHANGED, self.OnVertexFileChanged )
		self.bSaveVertex.Bind( wx.EVT_BUTTON, self.OnButtonVertexLoad )
		self.bLoadVertex.Bind( wx.EVT_BUTTON, self.OnButtonVertexSave )
		self.fpTessellationControl.Bind( wx.EVT_FILEPICKER_CHANGED, self.OnTessellationControlFileChanged )
		self.bSaveTessellationControl.Bind( wx.EVT_BUTTON, self.OnButtonTessellationLoad )
		self.bLoadTessellationControl.Bind( wx.EVT_BUTTON, self.OnButtonTessellationControlLoad )
		self.fpTessellationEvaluation.Bind( wx.EVT_FILEPICKER_CHANGED, self.OnTessellationEvaluationFileChanged )
		self.bSaveTessellationEvaluation.Bind( wx.EVT_BUTTON, self.OnButtonTessellationEvaluationLoad )
		self.bLoadTessellationEvaluation.Bind( wx.EVT_BUTTON, self.OnButtonTessellationEvaluationSave )
		self.fpGeometry.Bind( wx.EVT_FILEPICKER_CHANGED, self.OnGeometryFileChanged )
		self.bSaveGeometry.Bind( wx.EVT_BUTTON, self.OnButtonGeometryLoad )
		self.bLoadGeometry.Bind( wx.EVT_BUTTON, self.OnButtonGeometryLoad )
		self.fpFragment.Bind( wx.EVT_FILEPICKER_CHANGED, self.OnFragmentFileChanged )
		self.bSaveFragment.Bind( wx.EVT_BUTTON, self.OnButtonFragmentLoad )
		self.bLoadFragment.Bind( wx.EVT_BUTTON, self.OnButtonFragmentLoad )
		self.scLog.Bind( wx.EVT_LEFT_DCLICK, self.OnLogLeftDClick )
		self.m_button1.Bind( wx.EVT_BUTTON, self.OnCompileClick )
		self.Bind( wx.EVT_MENU, self.OnCompileClick, id = self.compile.GetId() )
	
	def __del__( self ):
		pass
	
	
	# Virtual event handlers, overide them in your derived class
	def OnChoiceShader( self, event ):
		event.Skip()
	
	def OnVertexFileChanged( self, event ):
		event.Skip()
	
	def OnButtonVertexLoad( self, event ):
		event.Skip()
	
	def OnButtonVertexSave( self, event ):
		event.Skip()
	
	def OnTessellationControlFileChanged( self, event ):
		event.Skip()
	
	def OnButtonTessellationLoad( self, event ):
		event.Skip()
	
	def OnButtonTessellationControlLoad( self, event ):
		event.Skip()
	
	def OnTessellationEvaluationFileChanged( self, event ):
		event.Skip()
	
	def OnButtonTessellationEvaluationLoad( self, event ):
		event.Skip()
	
	def OnButtonTessellationEvaluationSave( self, event ):
		event.Skip()
	
	def OnGeometryFileChanged( self, event ):
		event.Skip()
	
	def OnButtonGeometryLoad( self, event ):
		event.Skip()
	
	
	def OnFragmentFileChanged( self, event ):
		event.Skip()
	
	def OnButtonFragmentLoad( self, event ):
		event.Skip()
	
	
	def OnLogLeftDClick( self, event ):
		event.Skip()
	
	def OnCompileClick( self, event ):
		event.Skip()
	
	

###########################################################################
## Class fPostProcessEditor
###########################################################################

class fPostProcessEditor ( wx.Frame ):
	
	def __init__( self, parent ):
		wx.Frame.__init__ ( self, parent, id = wx.ID_ANY, title = u"Post Process", pos = wx.DefaultPosition, size = wx.Size( 557,500 ), style = wx.DEFAULT_FRAME_STYLE|wx.TAB_TRAVERSAL )
		
		self.SetSizeHintsSz( wx.DefaultSize, wx.DefaultSize )
		
		bSizer7 = wx.BoxSizer( wx.VERTICAL )
		
		bSizer8 = wx.BoxSizer( wx.VERTICAL )
		
		self.m_notebook2 = wx.Notebook( self, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize, 0 )
		self.m_panel3 = wx.Panel( self.m_notebook2, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize, wx.TAB_TRAVERSAL )
		gSizer2 = wx.GridSizer( 2, 2, 0, 0 )
		
		self.m_staticText5 = wx.StaticText( self.m_panel3, wx.ID_ANY, u"Brightness", wx.DefaultPosition, wx.DefaultSize, 0 )
		self.m_staticText5.Wrap( -1 )
		gSizer2.Add( self.m_staticText5, 0, wx.ALL, 5 )
		
		self.brightnessSlider = wx.Slider( self.m_panel3, wx.ID_ANY, 256, 0, 1024, wx.DefaultPosition, wx.Size( 200,-1 ), wx.SL_HORIZONTAL )
		gSizer2.Add( self.brightnessSlider, 0, wx.ALL, 5 )
		
		self.m_staticText51 = wx.StaticText( self.m_panel3, wx.ID_ANY, u"Saturation", wx.DefaultPosition, wx.DefaultSize, 0 )
		self.m_staticText51.Wrap( -1 )
		gSizer2.Add( self.m_staticText51, 0, wx.ALL, 5 )
		
		self.saturationSlider = wx.Slider( self.m_panel3, wx.ID_ANY, 1, 0, 255, wx.DefaultPosition, wx.Size( 200,-1 ), wx.SL_HORIZONTAL )
		gSizer2.Add( self.saturationSlider, 0, wx.ALL, 5 )
		
		
		self.m_panel3.SetSizer( gSizer2 )
		self.m_panel3.Layout()
		gSizer2.Fit( self.m_panel3 )
		self.m_notebook2.AddPage( self.m_panel3, u"Color Correction", False )
		self.m_panel11 = wx.Panel( self.m_notebook2, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize, wx.TAB_TRAVERSAL )
		bSizer18 = wx.BoxSizer( wx.VERTICAL )
		
		self.m_panel12 = wx.Panel( self.m_panel11, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize, wx.TAB_TRAVERSAL )
		bSizer19 = wx.BoxSizer( wx.HORIZONTAL )
		
		self.m_textCtrl2 = wx.TextCtrl( self.m_panel12, wx.ID_ANY, wx.EmptyString, wx.DefaultPosition, wx.DefaultSize, 0 )
		bSizer19.Add( self.m_textCtrl2, 0, wx.ALL, 5 )
		
		self.m_slider14 = wx.Slider( self.m_panel12, wx.ID_ANY, 50, 0, 512, wx.DefaultPosition, wx.DefaultSize, wx.SL_HORIZONTAL )
		bSizer19.Add( self.m_slider14, 1, wx.ALL, 5 )
		
		
		self.m_panel12.SetSizer( bSizer19 )
		self.m_panel12.Layout()
		bSizer19.Fit( self.m_panel12 )
		bSizer18.Add( self.m_panel12, 1, wx.EXPAND |wx.ALL, 5 )
		
		self.m_panel121 = wx.Panel( self.m_panel11, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize, wx.TAB_TRAVERSAL )
		bSizer191 = wx.BoxSizer( wx.HORIZONTAL )
		
		self.m_textCtrl21 = wx.TextCtrl( self.m_panel121, wx.ID_ANY, wx.EmptyString, wx.DefaultPosition, wx.DefaultSize, 0 )
		bSizer191.Add( self.m_textCtrl21, 0, wx.ALL, 5 )
		
		self.m_slider141 = wx.Slider( self.m_panel121, wx.ID_ANY, 50, 0, 512, wx.DefaultPosition, wx.DefaultSize, wx.SL_HORIZONTAL )
		bSizer191.Add( self.m_slider141, 1, wx.ALL, 5 )
		
		
		self.m_panel121.SetSizer( bSizer191 )
		self.m_panel121.Layout()
		bSizer191.Fit( self.m_panel121 )
		bSizer18.Add( self.m_panel121, 1, wx.EXPAND |wx.ALL, 5 )
		
		self.m_panel122 = wx.Panel( self.m_panel11, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize, wx.TAB_TRAVERSAL )
		bSizer192 = wx.BoxSizer( wx.HORIZONTAL )
		
		self.m_textCtrl22 = wx.TextCtrl( self.m_panel122, wx.ID_ANY, wx.EmptyString, wx.DefaultPosition, wx.DefaultSize, 0 )
		bSizer192.Add( self.m_textCtrl22, 0, wx.ALL, 5 )
		
		self.m_slider142 = wx.Slider( self.m_panel122, wx.ID_ANY, 50, 0, 512, wx.DefaultPosition, wx.DefaultSize, wx.SL_HORIZONTAL )
		bSizer192.Add( self.m_slider142, 1, wx.ALL, 5 )
		
		
		self.m_panel122.SetSizer( bSizer192 )
		self.m_panel122.Layout()
		bSizer192.Fit( self.m_panel122 )
		bSizer18.Add( self.m_panel122, 1, wx.EXPAND |wx.ALL, 5 )
		
		self.m_panel123 = wx.Panel( self.m_panel11, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize, wx.TAB_TRAVERSAL )
		bSizer193 = wx.BoxSizer( wx.HORIZONTAL )
		
		self.m_textCtrl23 = wx.TextCtrl( self.m_panel123, wx.ID_ANY, wx.EmptyString, wx.DefaultPosition, wx.DefaultSize, 0 )
		bSizer193.Add( self.m_textCtrl23, 0, wx.ALL, 5 )
		
		self.m_slider143 = wx.Slider( self.m_panel123, wx.ID_ANY, 50, 0, 512, wx.DefaultPosition, wx.DefaultSize, wx.SL_HORIZONTAL )
		bSizer193.Add( self.m_slider143, 1, wx.ALL, 5 )
		
		
		self.m_panel123.SetSizer( bSizer193 )
		self.m_panel123.Layout()
		bSizer193.Fit( self.m_panel123 )
		bSizer18.Add( self.m_panel123, 1, wx.EXPAND |wx.ALL, 5 )
		
		self.m_panel124 = wx.Panel( self.m_panel11, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize, wx.TAB_TRAVERSAL )
		bSizer194 = wx.BoxSizer( wx.HORIZONTAL )
		
		self.m_textCtrl24 = wx.TextCtrl( self.m_panel124, wx.ID_ANY, wx.EmptyString, wx.DefaultPosition, wx.DefaultSize, 0 )
		bSizer194.Add( self.m_textCtrl24, 0, wx.ALL, 5 )
		
		self.m_slider144 = wx.Slider( self.m_panel124, wx.ID_ANY, 50, 0, 512, wx.DefaultPosition, wx.DefaultSize, wx.SL_HORIZONTAL )
		bSizer194.Add( self.m_slider144, 1, wx.ALL, 5 )
		
		
		self.m_panel124.SetSizer( bSizer194 )
		self.m_panel124.Layout()
		bSizer194.Fit( self.m_panel124 )
		bSizer18.Add( self.m_panel124, 1, wx.EXPAND |wx.ALL, 5 )
		
		self.m_panel125 = wx.Panel( self.m_panel11, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize, wx.TAB_TRAVERSAL )
		bSizer195 = wx.BoxSizer( wx.HORIZONTAL )
		
		self.m_textCtrl25 = wx.TextCtrl( self.m_panel125, wx.ID_ANY, wx.EmptyString, wx.DefaultPosition, wx.DefaultSize, 0 )
		bSizer195.Add( self.m_textCtrl25, 0, wx.ALL, 5 )
		
		self.m_slider145 = wx.Slider( self.m_panel125, wx.ID_ANY, 50, 0, 512, wx.DefaultPosition, wx.DefaultSize, wx.SL_HORIZONTAL )
		bSizer195.Add( self.m_slider145, 1, wx.ALL, 5 )
		
		
		self.m_panel125.SetSizer( bSizer195 )
		self.m_panel125.Layout()
		bSizer195.Fit( self.m_panel125 )
		bSizer18.Add( self.m_panel125, 1, wx.EXPAND |wx.ALL, 5 )
		
		self.m_panel126 = wx.Panel( self.m_panel11, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize, wx.TAB_TRAVERSAL )
		bSizer196 = wx.BoxSizer( wx.HORIZONTAL )
		
		self.m_textCtrl26 = wx.TextCtrl( self.m_panel126, wx.ID_ANY, wx.EmptyString, wx.DefaultPosition, wx.DefaultSize, 0 )
		bSizer196.Add( self.m_textCtrl26, 0, wx.ALL, 5 )
		
		self.m_slider146 = wx.Slider( self.m_panel126, wx.ID_ANY, 50, 0, 512, wx.DefaultPosition, wx.DefaultSize, wx.SL_HORIZONTAL )
		bSizer196.Add( self.m_slider146, 1, wx.ALL, 5 )
		
		
		self.m_panel126.SetSizer( bSizer196 )
		self.m_panel126.Layout()
		bSizer196.Fit( self.m_panel126 )
		bSizer18.Add( self.m_panel126, 1, wx.EXPAND |wx.ALL, 5 )
		
		self.m_panel127 = wx.Panel( self.m_panel11, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize, wx.TAB_TRAVERSAL )
		bSizer197 = wx.BoxSizer( wx.HORIZONTAL )
		
		self.m_textCtrl27 = wx.TextCtrl( self.m_panel127, wx.ID_ANY, wx.EmptyString, wx.DefaultPosition, wx.DefaultSize, 0 )
		bSizer197.Add( self.m_textCtrl27, 0, wx.ALL, 5 )
		
		self.m_slider147 = wx.Slider( self.m_panel127, wx.ID_ANY, 50, 0, 512, wx.DefaultPosition, wx.DefaultSize, wx.SL_HORIZONTAL )
		bSizer197.Add( self.m_slider147, 1, wx.ALL, 5 )
		
		
		self.m_panel127.SetSizer( bSizer197 )
		self.m_panel127.Layout()
		bSizer197.Fit( self.m_panel127 )
		bSizer18.Add( self.m_panel127, 1, wx.EXPAND |wx.ALL, 5 )
		
		
		self.m_panel11.SetSizer( bSizer18 )
		self.m_panel11.Layout()
		bSizer18.Fit( self.m_panel11 )
		self.m_notebook2.AddPage( self.m_panel11, u"Manual Uniforms", True )
		
		bSizer8.Add( self.m_notebook2, 1, wx.EXPAND |wx.ALL, 5 )
		
		
		bSizer7.Add( bSizer8, 1, wx.EXPAND, 5 )
		
		
		self.SetSizer( bSizer7 )
		self.Layout()
		
		# Connect Events
		self.brightnessSlider.Bind( wx.EVT_SCROLL, self.onBrightnessChange )
		self.saturationSlider.Bind( wx.EVT_SCROLL, self.onSaturationChange )
	
	def __del__( self ):
		pass
	
	
	# Virtual event handlers, overide them in your derived class
	def onBrightnessChange( self, event ):
		event.Skip()
	
	def onSaturationChange( self, event ):
		event.Skip()
	

###########################################################################
## Class fMainEditor
###########################################################################

class fMainEditor ( wx.Frame ):
	
	def __init__( self, parent ):
		wx.Frame.__init__ ( self, parent, id = wx.ID_ANY, title = u"Shader Fiddler", pos = wx.DefaultPosition, size = wx.Size( 1024,768 ), style = wx.DEFAULT_FRAME_STYLE|wx.TAB_TRAVERSAL )
		
		self.SetSizeHintsSz( wx.DefaultSize, wx.DefaultSize )
		
		bSizer9 = wx.BoxSizer( wx.VERTICAL )
		
		gSizer3 = wx.GridSizer( 2, 2, 0, 0 )
		
		self.previewPanel = wx.Panel( self, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize, wx.TAB_TRAVERSAL )
		bSizer40 = wx.BoxSizer( wx.VERTICAL )
		
		gSizer5 = wx.GridSizer( 2, 2, 0, 0 )
		
		self.m_staticText15 = wx.StaticText( self.previewPanel, wx.ID_ANY, u"FPS:", wx.DefaultPosition, wx.DefaultSize, 0 )
		self.m_staticText15.Wrap( -1 )
		gSizer5.Add( self.m_staticText15, 0, wx.ALL, 5 )
		
		self.eFpsValue = wx.StaticText( self.previewPanel, wx.ID_ANY, u"FPSVALUE", wx.DefaultPosition, wx.DefaultSize, 0 )
		self.eFpsValue.Wrap( -1 )
		gSizer5.Add( self.eFpsValue, 0, wx.ALL, 5 )
		
		self.cbFPSLimiter = wx.CheckBox( self.previewPanel, wx.ID_ANY, u"FPS Limiter", wx.DefaultPosition, wx.DefaultSize, 0 )
		self.cbFPSLimiter.SetValue(True) 
		gSizer5.Add( self.cbFPSLimiter, 0, wx.ALL, 5 )
		
		self.cbAnimatedHorse = wx.CheckBox( self.previewPanel, wx.ID_ANY, u"Draw Animated Horse", wx.DefaultPosition, wx.DefaultSize, 0 )
		gSizer5.Add( self.cbAnimatedHorse, 0, wx.ALL, 5 )
		
		self.m_loadDemo = wx.Button( self.previewPanel, wx.ID_ANY, u"Load", wx.DefaultPosition, wx.DefaultSize, 0 )
		gSizer5.Add( self.m_loadDemo, 0, wx.ALL, 5 )
		
		self.m_saveDemo = wx.Button( self.previewPanel, wx.ID_ANY, u"Save", wx.DefaultPosition, wx.DefaultSize, 0 )
		gSizer5.Add( self.m_saveDemo, 0, wx.ALL, 5 )
		
		self.cbFullscreenImage1 = wx.CheckBox( self.previewPanel, wx.ID_ANY, u"Draw Fullscreen Image", wx.DefaultPosition, wx.DefaultSize, 0 )
		gSizer5.Add( self.cbFullscreenImage1, 0, wx.ALL, 5 )
		
		
		bSizer40.Add( gSizer5, 1, wx.EXPAND, 5 )
		
		bSizer401 = wx.BoxSizer( wx.VERTICAL )
		
		self.m_dirPickerSkybox = wx.DirPickerCtrl( self.previewPanel, wx.ID_ANY, wx.EmptyString, u"Select a folder", wx.DefaultPosition, wx.DefaultSize, wx.DIRP_DEFAULT_STYLE )
		bSizer401.Add( self.m_dirPickerSkybox, 0, wx.ALL, 5 )
		
		
		bSizer40.Add( bSizer401, 1, wx.EXPAND, 5 )
		
		
		self.previewPanel.SetSizer( bSizer40 )
		self.previewPanel.Layout()
		bSizer40.Fit( self.previewPanel )
		gSizer3.Add( self.previewPanel, 1, wx.EXPAND |wx.ALL, 5 )
		
		bSizer48 = wx.BoxSizer( wx.VERTICAL )
		
		bSizer49 = wx.BoxSizer( wx.HORIZONTAL )
		
		self.m_staticText18 = wx.StaticText( self, wx.ID_ANY, u"Scene:", wx.DefaultPosition, wx.DefaultSize, 0 )
		self.m_staticText18.Wrap( -1 )
		bSizer49.Add( self.m_staticText18, 0, wx.ALL, 5 )
		
		m_choiceSceneChoices = []
		self.m_choiceScene = wx.Choice( self, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize, m_choiceSceneChoices, 0 )
		self.m_choiceScene.SetSelection( 0 )
		bSizer49.Add( self.m_choiceScene, 1, wx.ALL, 5 )
		
		
		bSizer48.Add( bSizer49, 0, wx.ALIGN_TOP|wx.EXPAND|wx.TOP|wx.RIGHT|wx.LEFT, 2 )
		
		self.m_SceneTree = wx.TreeCtrl( self, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize, wx.TR_DEFAULT_STYLE )
		self.m_menuSceneGraph = wx.Menu()
		self.m_menuItemDeleteNode = wx.MenuItem( self.m_menuSceneGraph, wx.ID_ANY, u"Delete Node", wx.EmptyString, wx.ITEM_NORMAL )
		self.m_menuSceneGraph.AppendItem( self.m_menuItemDeleteNode )
		
		self.m_menuItemAddNode = wx.MenuItem( self.m_menuSceneGraph, wx.ID_ANY, u"AddNode", wx.EmptyString, wx.ITEM_NORMAL )
		self.m_menuSceneGraph.AppendItem( self.m_menuItemAddNode )
		
		self.m_menuItem11 = wx.MenuItem( self.m_menuSceneGraph, wx.ID_ANY, u"MyMenuItem", wx.EmptyString, wx.ITEM_NORMAL )
		self.m_menuSceneGraph.AppendItem( self.m_menuItem11 )
		
		self.m_SceneTree.Bind( wx.EVT_RIGHT_DOWN, self.m_SceneTreeOnContextMenu ) 
		
		bSizer48.Add( self.m_SceneTree, 1, wx.ALL|wx.EXPAND, 5 )
		
		
		gSizer3.Add( bSizer48, 1, wx.EXPAND, 5 )
		
		
		bSizer9.Add( gSizer3, 1, wx.EXPAND, 5 )
		
		self.notebook = wx.Notebook( self, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize, 0 )
		self.pLayers = wx.Panel( self.notebook, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize, wx.TAB_TRAVERSAL )
		bSizer10 = wx.BoxSizer( wx.VERTICAL )
		
		self.m_listCtrl4 = wx.ListCtrl( self.pLayers, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize, wx.LC_ICON )
		bSizer10.Add( self.m_listCtrl4, 1, wx.ALL|wx.EXPAND, 5 )
		
		
		self.pLayers.SetSizer( bSizer10 )
		self.pLayers.Layout()
		bSizer10.Fit( self.pLayers )
		self.notebook.AddPage( self.pLayers, u"Layer", False )
		self.mCurves = wx.Panel( self.notebook, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize, wx.TAB_TRAVERSAL )
		bSizer29 = wx.BoxSizer( wx.VERTICAL )
		
		bSizer30 = wx.BoxSizer( wx.HORIZONTAL )
		
		self.m_listCtrl3 = wx.ListCtrl( self.mCurves, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize, wx.LC_ICON )
		bSizer30.Add( self.m_listCtrl3, 0, wx.ALL|wx.EXPAND, 5 )
		
		bSizer41 = wx.BoxSizer( wx.VERTICAL )
		
		bSizer42 = wx.BoxSizer( wx.HORIZONTAL )
		
		self.m_staticText16 = wx.StaticText( self.mCurves, wx.ID_ANY, u"Zoom", wx.DefaultPosition, wx.DefaultSize, 0 )
		self.m_staticText16.Wrap( -1 )
		bSizer42.Add( self.m_staticText16, 0, wx.ALL, 5 )
		
		self.m_sliderZoomCurvesX = wx.Slider( self.mCurves, wx.ID_ANY, 100, 25, 700, wx.DefaultPosition, wx.DefaultSize, wx.SL_HORIZONTAL )
		bSizer42.Add( self.m_sliderZoomCurvesX, 1, wx.ALL, 5 )
		
		
		bSizer41.Add( bSizer42, 0, wx.EXPAND, 5 )
		
		#m_Timeline = new wxTimeline(mCurves, wxID_ANY, wxT("Test"));
		#bSizer41.Add( self.m_Timeline, 1, wx.ALL|wx.EXPAND, 5 )
		
		
		bSizer30.Add( bSizer41, 1, wx.EXPAND, 5 )
		
		self.m_sliderZoomCurvesY = wx.Slider( self.mCurves, wx.ID_ANY, 100, 25, 700, wx.DefaultPosition, wx.DefaultSize, wx.SL_VERTICAL )
		bSizer30.Add( self.m_sliderZoomCurvesY, 0, wx.ALL|wx.EXPAND, 5 )
		
		
		bSizer29.Add( bSizer30, 1, wx.EXPAND, 5 )
		
		bSizer31 = wx.BoxSizer( wx.HORIZONTAL )
		
		self.bNewCurve = wx.Button( self.mCurves, wx.ID_ANY, u"New Curve", wx.DefaultPosition, wx.DefaultSize, 0 )
		bSizer31.Add( self.bNewCurve, 0, wx.ALL, 5 )
		
		self.bLoadCurve = wx.Button( self.mCurves, wx.ID_ANY, u"Load Curve", wx.DefaultPosition, wx.DefaultSize, 0 )
		bSizer31.Add( self.bLoadCurve, 0, wx.ALL, 5 )
		
		self.bSaveCurve = wx.Button( self.mCurves, wx.ID_ANY, u"Save Curve", wx.DefaultPosition, wx.DefaultSize, 0 )
		bSizer31.Add( self.bSaveCurve, 0, wx.ALL, 5 )
		
		
		bSizer29.Add( bSizer31, 0, wx.EXPAND, 5 )
		
		
		self.mCurves.SetSizer( bSizer29 )
		self.mCurves.Layout()
		bSizer29.Fit( self.mCurves )
		self.notebook.AddPage( self.mCurves, u"Curves", False )
		self.pPostProcessing = wx.Panel( self.notebook, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize, wx.TAB_TRAVERSAL )
		bSizer12 = wx.BoxSizer( wx.VERTICAL )
		
		gSizer4 = wx.GridSizer( 3, 3, 0, 0 )
		
		
		bSizer12.Add( gSizer4, 1, wx.EXPAND, 5 )
		
		
		self.pPostProcessing.SetSizer( bSizer12 )
		self.pPostProcessing.Layout()
		bSizer12.Fit( self.pPostProcessing )
		self.notebook.AddPage( self.pPostProcessing, u"PostProcessing", True )
		self.m_panel10 = wx.Panel( self.notebook, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize, wx.TAB_TRAVERSAL )
		bSizer16 = wx.BoxSizer( wx.HORIZONTAL )
		
		self.listTextures = wx.ListCtrl( self.m_panel10, wx.ID_ANY, wx.DefaultPosition, wx.Size( 700,-1 ), wx.LC_ICON|wx.LC_VRULES )
		bSizer16.Add( self.listTextures, 0, wx.ALL|wx.EXPAND, 5 )
		
		bSizer17 = wx.BoxSizer( wx.VERTICAL )
		
		self.bLoadTexture = wx.Button( self.m_panel10, wx.ID_ANY, u"Load Texture", wx.DefaultPosition, wx.DefaultSize, 0 )
		bSizer17.Add( self.bLoadTexture, 0, wx.ALL, 5 )
		
		self.m_staticline2 = wx.StaticLine( self.m_panel10, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize, wx.LI_HORIZONTAL )
		bSizer17.Add( self.m_staticline2, 0, wx.EXPAND |wx.ALL, 5 )
		
		self.bTextureFirst = wx.Button( self.m_panel10, wx.ID_ANY, u"First", wx.DefaultPosition, wx.DefaultSize, 0 )
		bSizer17.Add( self.bTextureFirst, 0, wx.ALL, 5 )
		
		self.bTextureUp	= wx.Button( self.m_panel10, wx.ID_ANY, u"Up", wx.DefaultPosition, wx.DefaultSize, 0 ) 
		bSizer17.Add( self.bTextureUp , 0, wx.ALL, 5 )
		
		self.bTextureDown = wx.Button( self.m_panel10, wx.ID_ANY, u"Down", wx.DefaultPosition, wx.DefaultSize, 0 )
		bSizer17.Add( self.bTextureDown, 0, wx.ALL, 5 )
		
		self.bTextureLast = wx.Button( self.m_panel10, wx.ID_ANY, u"Last", wx.DefaultPosition, wx.DefaultSize, 0 )
		bSizer17.Add( self.bTextureLast, 0, wx.ALL, 5 )
		
		self.m_staticline1 = wx.StaticLine( self.m_panel10, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize, wx.LI_HORIZONTAL )
		bSizer17.Add( self.m_staticline1, 0, wx.EXPAND |wx.ALL, 5 )
		
		self.mTextureDelete = wx.Button( self.m_panel10, wx.ID_ANY, u"Delete Texture", wx.DefaultPosition, wx.DefaultSize, 0 )
		bSizer17.Add( self.mTextureDelete, 0, wx.ALL, 5 )
		
		
		bSizer16.Add( bSizer17, 1, wx.EXPAND, 5 )
		
		
		self.m_panel10.SetSizer( bSizer16 )
		self.m_panel10.Layout()
		bSizer16.Fit( self.m_panel10 )
		self.notebook.AddPage( self.m_panel10, u"Textures", False )
		self.m_panel28 = wx.Panel( self.notebook, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize, wx.TAB_TRAVERSAL )
		bSizer32 = wx.BoxSizer( wx.VERTICAL )
		
		bSizer33 = wx.BoxSizer( wx.HORIZONTAL )
		
		bSizer34 = wx.BoxSizer( wx.HORIZONTAL )
		
		self.m_staticText8 = wx.StaticText( self.m_panel28, wx.ID_ANY, u"Pos", wx.DefaultPosition, wx.DefaultSize, 0 )
		self.m_staticText8.Wrap( -1 )
		bSizer34.Add( self.m_staticText8, 0, wx.ALL, 5 )
		
		self.m_staticText9 = wx.StaticText( self.m_panel28, wx.ID_ANY, u"x", wx.DefaultPosition, wx.DefaultSize, 0 )
		self.m_staticText9.Wrap( -1 )
		bSizer34.Add( self.m_staticText9, 0, wx.ALL, 5 )
		
		self.mLightPosX = wx.TextCtrl( self.m_panel28, wx.ID_ANY, u"5", wx.DefaultPosition, wx.DefaultSize, 0 )
		bSizer34.Add( self.mLightPosX, 0, wx.ALL, 5 )
		
		self.m_staticText10 = wx.StaticText( self.m_panel28, wx.ID_ANY, u"y", wx.DefaultPosition, wx.DefaultSize, 0 )
		self.m_staticText10.Wrap( -1 )
		bSizer34.Add( self.m_staticText10, 0, wx.ALL, 5 )
		
		self.mLightPosY = wx.TextCtrl( self.m_panel28, wx.ID_ANY, u"5", wx.DefaultPosition, wx.DefaultSize, 0 )
		bSizer34.Add( self.mLightPosY, 0, wx.ALL, 5 )
		
		self.m_staticText11 = wx.StaticText( self.m_panel28, wx.ID_ANY, u"z", wx.DefaultPosition, wx.DefaultSize, 0 )
		self.m_staticText11.Wrap( -1 )
		bSizer34.Add( self.m_staticText11, 0, wx.ALL, 5 )
		
		self.mLightPosZ = wx.TextCtrl( self.m_panel28, wx.ID_ANY, u"5", wx.DefaultPosition, wx.DefaultSize, 0 )
		bSizer34.Add( self.mLightPosZ, 0, wx.ALL, 5 )
		
		
		bSizer33.Add( bSizer34, 1, wx.EXPAND, 5 )
		
		bSizer36 = wx.BoxSizer( wx.VERTICAL )
		
		self.m_staticText12 = wx.StaticText( self.m_panel28, wx.ID_ANY, u"Size", wx.DefaultPosition, wx.DefaultSize, 0 )
		self.m_staticText12.Wrap( -1 )
		bSizer36.Add( self.m_staticText12, 0, wx.ALL, 5 )
		
		self.eLightSize = wx.TextCtrl( self.m_panel28, wx.ID_ANY, u"1", wx.DefaultPosition, wx.DefaultSize, 0 )
		bSizer36.Add( self.eLightSize, 0, wx.ALL, 5 )
		
		self.m_staticText121 = wx.StaticText( self.m_panel28, wx.ID_ANY, u"Color", wx.DefaultPosition, wx.DefaultSize, 0 )
		self.m_staticText121.Wrap( -1 )
		bSizer36.Add( self.m_staticText121, 0, wx.ALL, 5 )
		
		self.colourPickerLight = wx.ColourPickerCtrl( self.m_panel28, wx.ID_ANY, wx.Colour( 255, 255, 255 ), wx.DefaultPosition, wx.DefaultSize, wx.CLRP_DEFAULT_STYLE )
		bSizer36.Add( self.colourPickerLight, 0, wx.ALL, 5 )
		
		
		bSizer33.Add( bSizer36, 1, wx.EXPAND, 5 )
		
		
		bSizer32.Add( bSizer33, 1, wx.EXPAND, 5 )
		
		
		self.m_panel28.SetSizer( bSizer32 )
		self.m_panel28.Layout()
		bSizer32.Fit( self.m_panel28 )
		self.notebook.AddPage( self.m_panel28, u"Light", False )
		self.m_panel21 = wx.Panel( self.notebook, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize, wx.TAB_TRAVERSAL )
		bSizer341 = wx.BoxSizer( wx.HORIZONTAL )
		
		bSizer35 = wx.BoxSizer( wx.VERTICAL )
		
		self.mLoadModel = wx.Button( self.m_panel21, wx.ID_ANY, u"Load Model", wx.DefaultPosition, wx.DefaultSize, 0 )
		bSizer35.Add( self.mLoadModel, 0, wx.ALL, 5 )
		
		self.mDeleteModel = wx.Button( self.m_panel21, wx.ID_ANY, u"Delete", wx.DefaultPosition, wx.DefaultSize, 0 )
		bSizer35.Add( self.mDeleteModel, 0, wx.ALL, 5 )
		
		self.listModels = wx.ListCtrl( self.m_panel21, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize, wx.LC_ICON )
		bSizer35.Add( self.listModels, 1, wx.ALL|wx.EXPAND, 5 )
		
		
		bSizer341.Add( bSizer35, 1, wx.EXPAND, 5 )
		
		
		self.m_panel21.SetSizer( bSizer341 )
		self.m_panel21.Layout()
		bSizer341.Fit( self.m_panel21 )
		self.notebook.AddPage( self.m_panel21, u"Models", False )
		self.m_panel22 = wx.Panel( self.notebook, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize, wx.TAB_TRAVERSAL )
		bSizer37 = wx.BoxSizer( wx.HORIZONTAL )
		
		self.m_richText5 = wx.richtext.RichTextCtrl( self.m_panel22, wx.ID_ANY, wx.EmptyString, wx.DefaultPosition, wx.DefaultSize, 0|wx.VSCROLL|wx.HSCROLL|wx.NO_BORDER|wx.WANTS_CHARS )
		bSizer37.Add( self.m_richText5, 1, wx.ALL|wx.EXPAND, 5 )
		
		bSizer38 = wx.BoxSizer( wx.VERTICAL )
		
		self.buttonLuaCompile = wx.Button( self.m_panel22, wx.ID_ANY, u"Compile", wx.DefaultPosition, wx.DefaultSize, 0 )
		bSizer38.Add( self.buttonLuaCompile, 0, wx.ALL, 5 )
		
		self.m_button16 = wx.Button( self.m_panel22, wx.ID_ANY, u"MyButton", wx.DefaultPosition, wx.DefaultSize, 0 )
		bSizer38.Add( self.m_button16, 0, wx.ALL, 5 )
		
		
		bSizer37.Add( bSizer38, 0, 0, 5 )
		
		
		self.m_panel22.SetSizer( bSizer37 )
		self.m_panel22.Layout()
		bSizer37.Fit( self.m_panel22 )
		self.notebook.AddPage( self.m_panel22, u"LUA Scripts", False )
		
		bSizer9.Add( self.notebook, 1, wx.EXPAND |wx.ALL, 5 )
		
		
		self.SetSizer( bSizer9 )
		self.Layout()
		self.m_menubar1 = wx.MenuBar( 0 )
		self.ressources = wx.Menu()
		self.load = wx.MenuItem( self.ressources, ID_LOAD, u"Load", wx.EmptyString, wx.ITEM_NORMAL )
		self.ressources.AppendItem( self.load )
		
		self.m_menubar1.Append( self.ressources, u"Ressources" ) 
		
		self.lighting = wx.Menu()
		self.phongEditor = wx.MenuItem( self.lighting, ID_PHONG_EDITOR, u"Phong Editor", wx.EmptyString, wx.ITEM_NORMAL )
		self.lighting.AppendItem( self.phongEditor )
		
		self.m_menubar1.Append( self.lighting, u"Lighting" ) 
		
		self.shader = wx.Menu()
		self.showEditor = wx.MenuItem( self.shader, ID_SHOW_EDITOR, u"Show Editor", wx.EmptyString, wx.ITEM_NORMAL )
		self.shader.AppendItem( self.showEditor )
		
		self.m_menubar1.Append( self.shader, u"Shader" ) 
		
		self.SetMenuBar( self.m_menubar1 )
		
		self.m_statusBar1 = self.CreateStatusBar( 1, wx.ST_SIZEGRIP, wx.ID_ANY )
		
		# Connect Events
		self.m_loadDemo.Bind( wx.EVT_BUTTON, self.OnLoadDemoClick )
		self.m_saveDemo.Bind( wx.EVT_BUTTON, self.OnSaveDemoClick )
		self.m_dirPickerSkybox.Bind( wx.EVT_DIRPICKER_CHANGED, self.OnSkyboxDirChanged )
		self.m_choiceScene.Bind( wx.EVT_CHOICE, self.OnSceneSelectionChoice )
		self.m_SceneTree.Bind( wx.EVT_RIGHT_DOWN, self.OnSceneGraphTreeRightDown )
		self.mCurves.Bind( wx.EVT_LEFT_DOWN, self.OnCurveEditorLeftDown )
		self.m_sliderZoomCurvesX.Bind( wx.EVT_SCROLL, self.OnScrollZoomCurvesX )
		self.m_sliderZoomCurvesY.Bind( wx.EVT_SCROLL, self.OnScrollZoomCurvesY )
		self.bNewCurve.Bind( wx.EVT_BUTTON, self.OnNewCurveClick )
		self.bLoadCurve.Bind( wx.EVT_BUTTON, self.OnLoadCurveClick )
		self.bSaveCurve.Bind( wx.EVT_BUTTON, self.OnSaveCurveClick )
		self.bLoadTexture.Bind( wx.EVT_BUTTON, self.OnLoadTextureClick )
		self.bTextureFirst.Bind( wx.EVT_BUTTON, self.OnFirstTextureClick )
		self.bTextureUp.Bind( wx.EVT_BUTTON, self.OnUpTextureClick )
		self.bTextureDown.Bind( wx.EVT_BUTTON, self.OnDownTextureClick )
		self.bTextureLast.Bind( wx.EVT_BUTTON, self.OnLastTextureClick )
		self.mTextureDelete.Bind( wx.EVT_BUTTON, self.OnDeleteTextureClick )
		self.mLoadModel.Bind( wx.EVT_BUTTON, self.OnLoadModelClick )
		self.mDeleteModel.Bind( wx.EVT_BUTTON, self.OnDeleteModelClick )
		self.Bind( wx.EVT_MENU, self.OnMenuLoadRessources, id = self.load.GetId() )
		self.Bind( wx.EVT_MENU, self.onMenuPhongEditor, id = self.phongEditor.GetId() )
		self.Bind( wx.EVT_MENU, self.OnMenuShaderEditor, id = self.showEditor.GetId() )
	
	def __del__( self ):
		pass
	
	
	# Virtual event handlers, overide them in your derived class
	def OnLoadDemoClick( self, event ):
		event.Skip()
	
	def OnSaveDemoClick( self, event ):
		event.Skip()
	
	def OnSkyboxDirChanged( self, event ):
		event.Skip()
	
	def OnSceneSelectionChoice( self, event ):
		event.Skip()
	
	def OnSceneGraphTreeRightDown( self, event ):
		event.Skip()
	
	def OnCurveEditorLeftDown( self, event ):
		event.Skip()
	
	def OnScrollZoomCurvesX( self, event ):
		event.Skip()
	
	def OnScrollZoomCurvesY( self, event ):
		event.Skip()
	
	def OnNewCurveClick( self, event ):
		event.Skip()
	
	def OnLoadCurveClick( self, event ):
		event.Skip()
	
	def OnSaveCurveClick( self, event ):
		event.Skip()
	
	def OnLoadTextureClick( self, event ):
		event.Skip()
	
	def OnFirstTextureClick( self, event ):
		event.Skip()
	
	def OnUpTextureClick( self, event ):
		event.Skip()
	
	def OnDownTextureClick( self, event ):
		event.Skip()
	
	def OnLastTextureClick( self, event ):
		event.Skip()
	
	def OnDeleteTextureClick( self, event ):
		event.Skip()
	
	def OnLoadModelClick( self, event ):
		event.Skip()
	
	def OnDeleteModelClick( self, event ):
		event.Skip()
	
	def OnMenuLoadRessources( self, event ):
		event.Skip()
	
	def onMenuPhongEditor( self, event ):
		event.Skip()
	
	def OnMenuShaderEditor( self, event ):
		event.Skip()
	
	def m_SceneTreeOnContextMenu( self, event ):
		self.m_SceneTree.PopupMenu( self.m_menuSceneGraph, event.GetPosition() )
		

