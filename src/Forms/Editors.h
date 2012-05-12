///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Apr 11 2012)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __EDITORS_H__
#define __EDITORS_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/slider.h>
#include <wx/clrpicker.h>
#include <wx/sizer.h>
#include <wx/frame.h>
#include <wx/choice.h>
#include <wx/wxScintilla/wxscintilla.h>
#ifdef __VISUALC__
#include <wx/link_additions.h>
#endif //__VISUALC__
#include <wx/filepicker.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/bmpbuttn.h>
#include <wx/button.h>
#include <wx/panel.h>
#include <wx/richtext/richtextctrl.h>
#include <wx/notebook.h>
#include <wx/menu.h>
#include <wx/textctrl.h>
#include <wx/checkbox.h>
#include <wx/treectrl.h>
#include <wx/listctrl.h>
#include "../System/wxControls/wxTimeline.h"
#include <wx/statline.h>
#include <wx/statusbr.h>

///////////////////////////////////////////////////////////////////////////

#define ID_LOAD_FRAGMENT 1000
#define ID_SAVE_FRAGMENT 1001
#define ID_LOAD_VERTEX 1002
#define ID_SAVE_VERTEX 1003
#define ID_COMPILE 1004
#define ID_LOAD 1005
#define ID_PHONG_EDITOR 1006
#define ID_SHOW_EDITOR 1007

///////////////////////////////////////////////////////////////////////////////
/// Class fPhongEditor
///////////////////////////////////////////////////////////////////////////////
class fPhongEditor : public wxFrame 
{
	private:
	
	protected:
		wxStaticText* m_staticText1;
		wxStaticText* m_staticText2;
		wxStaticText* m_staticText3;
		wxStaticText* m_staticText21;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnIdle( wxIdleEvent& event ) { event.Skip(); }
		virtual void OnScrollAmbient( wxScrollEvent& event ) { event.Skip(); }
		virtual void OnAmbientColorChanged( wxColourPickerEvent& event ) { event.Skip(); }
		virtual void OnScrollDiffuse( wxScrollEvent& event ) { event.Skip(); }
		virtual void OnDiffuseColorChanged( wxColourPickerEvent& event ) { event.Skip(); }
		virtual void OnScrollSpecular( wxScrollEvent& event ) { event.Skip(); }
		virtual void OnSpecularColorChanged( wxColourPickerEvent& event ) { event.Skip(); }
		
	
	public:
		wxSlider* sliderShininess;
		wxSlider* sliderColorAmbientRed;
		wxSlider* sliderColorAmbientGreen;
		wxSlider* sliderColorAmbientBlue;
		wxColourPickerCtrl* colourPickerAmbient;
		wxSlider* sliderColorRed;
		wxSlider* sliderColorGreen;
		wxSlider* sliderColorBlue;
		wxColourPickerCtrl* colourPickerDiffuse;
		wxSlider* sliderColorSpecularRed;
		wxSlider* sliderColorSpecularGreen;
		wxSlider* sliderColorSpecularBlue;
		wxColourPickerCtrl* colourPickerSpecular;
		
		fPhongEditor( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Phong Editor"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 600,650 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL, const wxString& name = wxT("PhongEditor") );
		
		~fPhongEditor();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class fShaderEditor
///////////////////////////////////////////////////////////////////////////////
class fShaderEditor : public wxFrame 
{
	private:
	
	protected:
		wxStaticText* m_staticText13;
		wxNotebook* m_notebook1;
		wxScintilla* scVertex;
		wxFilePickerCtrl* fpVertex;
		wxBitmapButton* bSaveVertex;
		wxBitmapButton* bLoadVertex;
		wxPanel* m_panel21;
		wxBitmapButton* bLoadTessellationControl;
		wxScintilla* scTessellationEvaluation;
		wxFilePickerCtrl* fpTessellationEvaluation;
		wxBitmapButton* bSaveTessellationEvaluation;
		wxBitmapButton* bLoadTessellationEvaluation;
		wxPanel* m_panel22;
		wxBitmapButton* bLoadGeometry;
		wxPanel* m_panel2;
		wxBitmapButton* bLoadFragment;
		wxPanel* m_panel13;
		wxRichTextCtrl* m_richText5;
		wxScintilla* scLog;
		wxButton* m_button1;
		wxMenuBar* m_menubar2;
		wxMenu* shader;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnChoiceShader( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnVertexFileChanged( wxFileDirPickerEvent& event ) { event.Skip(); }
		virtual void OnButtonVertexLoad( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonVertexSave( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnTessellationControlFileChanged( wxFileDirPickerEvent& event ) { event.Skip(); }
		virtual void OnButtonTessellationLoad( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonTessellationControlLoad( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnTessellationEvaluationFileChanged( wxFileDirPickerEvent& event ) { event.Skip(); }
		virtual void OnButtonTessellationEvaluationLoad( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonTessellationEvaluationSave( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnGeometryFileChanged( wxFileDirPickerEvent& event ) { event.Skip(); }
		virtual void OnButtonGeometryLoad( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnFragmentFileChanged( wxFileDirPickerEvent& event ) { event.Skip(); }
		virtual void OnButtonFragmentLoad( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnLogLeftDClick( wxMouseEvent& event ) { event.Skip(); }
		virtual void OnCompileClick( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		wxChoice* choiceShaders;
		wxPanel* m_panel1;
		wxScintilla* scTessellationControl;
		wxFilePickerCtrl* fpTessellationControl;
		wxBitmapButton* bSaveTessellationControl;
		wxPanel* m_panel11;
		wxScintilla* scGeometry;
		wxFilePickerCtrl* fpGeometry;
		wxBitmapButton* bSaveGeometry;
		wxScintilla* scFragment;
		wxFilePickerCtrl* fpFragment;
		wxBitmapButton* bSaveFragment;
		
		fShaderEditor( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Shader Editor"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 995,757 ), long style = wxCAPTION|wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~fShaderEditor();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class fPostProcessEditor
///////////////////////////////////////////////////////////////////////////////
class fPostProcessEditor : public wxFrame 
{
	private:
	
	protected:
		wxPanel* m_panel3;
		wxStaticText* m_staticText5;
		wxStaticText* m_staticText51;
		wxPanel* m_panel11;
		wxPanel* m_panel12;
		wxTextCtrl* m_textCtrl2;
		wxSlider* m_slider14;
		wxPanel* m_panel121;
		wxTextCtrl* m_textCtrl21;
		wxSlider* m_slider141;
		wxPanel* m_panel122;
		wxTextCtrl* m_textCtrl22;
		wxSlider* m_slider142;
		wxPanel* m_panel123;
		wxTextCtrl* m_textCtrl23;
		wxSlider* m_slider143;
		wxPanel* m_panel124;
		wxTextCtrl* m_textCtrl24;
		wxSlider* m_slider144;
		wxPanel* m_panel125;
		wxTextCtrl* m_textCtrl25;
		wxSlider* m_slider145;
		wxPanel* m_panel126;
		wxTextCtrl* m_textCtrl26;
		wxSlider* m_slider146;
		wxPanel* m_panel127;
		wxTextCtrl* m_textCtrl27;
		wxSlider* m_slider147;
		
		// Virtual event handlers, overide them in your derived class
		virtual void onBrightnessChange( wxScrollEvent& event ) { event.Skip(); }
		virtual void onSaturationChange( wxScrollEvent& event ) { event.Skip(); }
		
	
	public:
		wxNotebook* m_notebook2;
		wxSlider* brightnessSlider;
		wxSlider* saturationSlider;
		
		fPostProcessEditor( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Post Process"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 557,500 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~fPostProcessEditor();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class fMainEditor
///////////////////////////////////////////////////////////////////////////////
class fMainEditor : public wxFrame 
{
	private:
	
	protected:
		wxPanel* previewPanel;
		wxStaticText* m_staticText15;
		wxButton* m_loadDemo;
		wxButton* m_saveDemo;
		wxDirPickerCtrl* m_dirPickerSkybox;
		wxStaticText* m_staticText18;
		wxMenu* m_menuSceneGraph;
		wxNotebook* notebook;
		wxPanel* pLayers;
		wxListCtrl* m_listCtrl4;
		wxPanel* mCurves;
		wxListCtrl* m_listCtrl3;
		wxStaticText* m_staticText16;
		wxSlider* m_sliderZoomCurvesX;
		wxTimeline* m_Timeline;
		wxSlider* m_sliderZoomCurvesY;
		wxButton* bNewCurve;
		wxButton* bLoadCurve;
		wxButton* bSaveCurve;
		wxPanel* pPostProcessing;
		wxPanel* m_panel10;
		wxListCtrl* listTextures;
		wxButton* bLoadTexture;
		wxStaticLine* m_staticline2;
		wxButton* bTextureFirst;
		wxButton* bTextureUp
		;
		wxButton* bTextureDown;
		wxButton* bTextureLast;
		wxStaticLine* m_staticline1;
		wxButton* mTextureDelete;
		wxPanel* m_panel28;
		wxStaticText* m_staticText8;
		wxStaticText* m_staticText9;
		wxStaticText* m_staticText10;
		wxStaticText* m_staticText11;
		wxStaticText* m_staticText12;
		wxStaticText* m_staticText121;
		wxColourPickerCtrl* colourPickerLight;
		wxPanel* m_panel21;
		wxButton* mLoadModel;
		wxButton* mDeleteModel;
		wxListCtrl* listModels;
		wxPanel* m_panel22;
		wxRichTextCtrl* m_richText5;
		wxButton* m_button16;
		wxMenuBar* m_menubar1;
		wxMenu* ressources;
		wxMenu* lighting;
		wxMenu* shader;
		wxStatusBar* m_statusBar1;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnLoadDemoClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSaveDemoClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSkyboxDirChanged( wxFileDirPickerEvent& event ) { event.Skip(); }
		virtual void OnSceneSelectionChoice( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSceneGraphTreeRightDown( wxMouseEvent& event ) { event.Skip(); }
		virtual void OnCurveEditorLeftDown( wxMouseEvent& event ) { event.Skip(); }
		virtual void OnScrollZoomCurvesX( wxScrollEvent& event ) { event.Skip(); }
		virtual void OnScrollZoomCurvesY( wxScrollEvent& event ) { event.Skip(); }
		virtual void OnNewCurveClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnLoadCurveClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSaveCurveClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnLoadTextureClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnFirstTextureClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnUpTextureClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDownTextureClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnLastTextureClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDeleteTextureClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnLoadModelClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDeleteModelClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMenuLoadRessources( wxCommandEvent& event ) { event.Skip(); }
		virtual void onMenuPhongEditor( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMenuShaderEditor( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		wxStaticText* eFpsValue;
		wxCheckBox* cbFPSLimiter;
		wxCheckBox* cbAnimatedHorse;
		wxCheckBox* cbFullscreenImage1;
		wxChoice* m_choiceScene;
		wxTreeCtrl* m_SceneTree;
		wxTextCtrl* mLightPosX;
		wxTextCtrl* mLightPosY;
		wxTextCtrl* mLightPosZ;
		wxTextCtrl* eLightSize;
		wxButton* buttonLuaCompile;
		
		fMainEditor( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Shader Fiddler"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 1024,768 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~fMainEditor();
		
		void m_SceneTreeOnContextMenu( wxMouseEvent &event )
		{
			m_SceneTree->PopupMenu( m_menuSceneGraph, event.GetPosition() );
		}
	
};

#endif //__EDITORS_H__
