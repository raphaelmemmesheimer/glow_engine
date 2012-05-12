///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Apr 11 2012)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "Editors.h"

///////////////////////////////////////////////////////////////////////////

fPhongEditor::fPhongEditor( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style, const wxString& name ) : wxFrame( parent, id, title, pos, size, style, name )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxGridSizer* gSizer1;
	gSizer1 = new wxGridSizer( 2, 2, 0, 0 );
	
	m_staticText1 = new wxStaticText( this, wxID_ANY, wxT("Shininess"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	gSizer1->Add( m_staticText1, 1, wxALL, 5 );
	
	sliderShininess = new wxSlider( this, wxID_ANY, 50, 0, 255, wxDefaultPosition, wxSize( 255,-1 ), wxSL_HORIZONTAL );
	gSizer1->Add( sliderShininess, 0, wxALL, 5 );
	
	m_staticText2 = new wxStaticText( this, wxID_ANY, wxT("AmbientColor"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	gSizer1->Add( m_staticText2, 0, wxALL, 5 );
	
	wxBoxSizer* bSizer51;
	bSizer51 = new wxBoxSizer( wxVERTICAL );
	
	sliderColorAmbientRed = new wxSlider( this, wxID_ANY, 2, 0, 255, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	sliderColorAmbientRed->SetMinSize( wxSize( 255,-1 ) );
	
	bSizer51->Add( sliderColorAmbientRed, 0, wxALL, 5 );
	
	sliderColorAmbientGreen = new wxSlider( this, wxID_ANY, 2, 0, 255, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	sliderColorAmbientGreen->SetMinSize( wxSize( 255,-1 ) );
	
	bSizer51->Add( sliderColorAmbientGreen, 0, wxALL, 5 );
	
	sliderColorAmbientBlue = new wxSlider( this, wxID_ANY, 2, 0, 255, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	sliderColorAmbientBlue->SetMinSize( wxSize( 255,-1 ) );
	
	bSizer51->Add( sliderColorAmbientBlue, 0, wxALL, 5 );
	
	colourPickerAmbient = new wxColourPickerCtrl( this, wxID_ANY, wxColour( 32, 32, 32 ), wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE );
	bSizer51->Add( colourPickerAmbient, 0, wxALL, 5 );
	
	
	gSizer1->Add( bSizer51, 1, wxEXPAND, 5 );
	
	m_staticText3 = new wxStaticText( this, wxID_ANY, wxT("DiffuseColor"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	gSizer1->Add( m_staticText3, 0, wxALL, 5 );
	
	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxVERTICAL );
	
	sliderColorRed = new wxSlider( this, wxID_ANY, 127, 0, 255, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	sliderColorRed->SetMinSize( wxSize( 255,-1 ) );
	
	bSizer5->Add( sliderColorRed, 0, wxALL, 5 );
	
	sliderColorGreen = new wxSlider( this, wxID_ANY, 127, 0, 255, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	sliderColorGreen->SetMinSize( wxSize( 255,-1 ) );
	
	bSizer5->Add( sliderColorGreen, 0, wxALL, 5 );
	
	sliderColorBlue = new wxSlider( this, wxID_ANY, 127, 0, 255, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	sliderColorBlue->SetMinSize( wxSize( 255,-1 ) );
	
	bSizer5->Add( sliderColorBlue, 0, wxALL, 5 );
	
	colourPickerDiffuse = new wxColourPickerCtrl( this, wxID_ANY, wxColour( 128, 128, 128 ), wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE );
	bSizer5->Add( colourPickerDiffuse, 0, wxALL, 5 );
	
	
	gSizer1->Add( bSizer5, 1, wxEXPAND, 5 );
	
	m_staticText21 = new wxStaticText( this, wxID_ANY, wxT("SpecularColor"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText21->Wrap( -1 );
	gSizer1->Add( m_staticText21, 0, wxALL, 5 );
	
	wxBoxSizer* bSizer52;
	bSizer52 = new wxBoxSizer( wxVERTICAL );
	
	sliderColorSpecularRed = new wxSlider( this, wxID_ANY, 255, 0, 255, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	sliderColorSpecularRed->SetMinSize( wxSize( 255,-1 ) );
	
	bSizer52->Add( sliderColorSpecularRed, 0, wxALL, 5 );
	
	sliderColorSpecularGreen = new wxSlider( this, wxID_ANY, 255, 0, 255, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	sliderColorSpecularGreen->SetMinSize( wxSize( 255,-1 ) );
	
	bSizer52->Add( sliderColorSpecularGreen, 0, wxALL, 5 );
	
	sliderColorSpecularBlue = new wxSlider( this, wxID_ANY, 255, 0, 255, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	sliderColorSpecularBlue->SetMinSize( wxSize( 255,-1 ) );
	
	bSizer52->Add( sliderColorSpecularBlue, 0, wxALL, 5 );
	
	colourPickerSpecular = new wxColourPickerCtrl( this, wxID_ANY, wxColour( 255, 255, 255 ), wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE );
	bSizer52->Add( colourPickerSpecular, 0, wxALL, 5 );
	
	
	gSizer1->Add( bSizer52, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( gSizer1 );
	this->Layout();
	
	// Connect Events
	this->Connect( wxEVT_IDLE, wxIdleEventHandler( fPhongEditor::OnIdle ) );
	sliderColorAmbientRed->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( fPhongEditor::OnScrollAmbient ), NULL, this );
	sliderColorAmbientRed->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( fPhongEditor::OnScrollAmbient ), NULL, this );
	sliderColorAmbientRed->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( fPhongEditor::OnScrollAmbient ), NULL, this );
	sliderColorAmbientRed->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( fPhongEditor::OnScrollAmbient ), NULL, this );
	sliderColorAmbientRed->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( fPhongEditor::OnScrollAmbient ), NULL, this );
	sliderColorAmbientRed->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( fPhongEditor::OnScrollAmbient ), NULL, this );
	sliderColorAmbientRed->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( fPhongEditor::OnScrollAmbient ), NULL, this );
	sliderColorAmbientRed->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( fPhongEditor::OnScrollAmbient ), NULL, this );
	sliderColorAmbientRed->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( fPhongEditor::OnScrollAmbient ), NULL, this );
	sliderColorAmbientGreen->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( fPhongEditor::OnScrollAmbient ), NULL, this );
	sliderColorAmbientGreen->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( fPhongEditor::OnScrollAmbient ), NULL, this );
	sliderColorAmbientGreen->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( fPhongEditor::OnScrollAmbient ), NULL, this );
	sliderColorAmbientGreen->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( fPhongEditor::OnScrollAmbient ), NULL, this );
	sliderColorAmbientGreen->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( fPhongEditor::OnScrollAmbient ), NULL, this );
	sliderColorAmbientGreen->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( fPhongEditor::OnScrollAmbient ), NULL, this );
	sliderColorAmbientGreen->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( fPhongEditor::OnScrollAmbient ), NULL, this );
	sliderColorAmbientGreen->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( fPhongEditor::OnScrollAmbient ), NULL, this );
	sliderColorAmbientGreen->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( fPhongEditor::OnScrollAmbient ), NULL, this );
	sliderColorAmbientBlue->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( fPhongEditor::OnScrollAmbient ), NULL, this );
	sliderColorAmbientBlue->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( fPhongEditor::OnScrollAmbient ), NULL, this );
	sliderColorAmbientBlue->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( fPhongEditor::OnScrollAmbient ), NULL, this );
	sliderColorAmbientBlue->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( fPhongEditor::OnScrollAmbient ), NULL, this );
	sliderColorAmbientBlue->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( fPhongEditor::OnScrollAmbient ), NULL, this );
	sliderColorAmbientBlue->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( fPhongEditor::OnScrollAmbient ), NULL, this );
	sliderColorAmbientBlue->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( fPhongEditor::OnScrollAmbient ), NULL, this );
	sliderColorAmbientBlue->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( fPhongEditor::OnScrollAmbient ), NULL, this );
	sliderColorAmbientBlue->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( fPhongEditor::OnScrollAmbient ), NULL, this );
	colourPickerAmbient->Connect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( fPhongEditor::OnAmbientColorChanged ), NULL, this );
	sliderColorRed->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( fPhongEditor::OnScrollDiffuse ), NULL, this );
	sliderColorRed->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( fPhongEditor::OnScrollDiffuse ), NULL, this );
	sliderColorRed->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( fPhongEditor::OnScrollDiffuse ), NULL, this );
	sliderColorRed->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( fPhongEditor::OnScrollDiffuse ), NULL, this );
	sliderColorRed->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( fPhongEditor::OnScrollDiffuse ), NULL, this );
	sliderColorRed->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( fPhongEditor::OnScrollDiffuse ), NULL, this );
	sliderColorRed->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( fPhongEditor::OnScrollDiffuse ), NULL, this );
	sliderColorRed->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( fPhongEditor::OnScrollDiffuse ), NULL, this );
	sliderColorRed->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( fPhongEditor::OnScrollDiffuse ), NULL, this );
	sliderColorGreen->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( fPhongEditor::OnScrollDiffuse ), NULL, this );
	sliderColorGreen->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( fPhongEditor::OnScrollDiffuse ), NULL, this );
	sliderColorGreen->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( fPhongEditor::OnScrollDiffuse ), NULL, this );
	sliderColorGreen->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( fPhongEditor::OnScrollDiffuse ), NULL, this );
	sliderColorGreen->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( fPhongEditor::OnScrollDiffuse ), NULL, this );
	sliderColorGreen->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( fPhongEditor::OnScrollDiffuse ), NULL, this );
	sliderColorGreen->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( fPhongEditor::OnScrollDiffuse ), NULL, this );
	sliderColorGreen->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( fPhongEditor::OnScrollDiffuse ), NULL, this );
	sliderColorGreen->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( fPhongEditor::OnScrollDiffuse ), NULL, this );
	sliderColorBlue->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( fPhongEditor::OnScrollDiffuse ), NULL, this );
	sliderColorBlue->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( fPhongEditor::OnScrollDiffuse ), NULL, this );
	sliderColorBlue->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( fPhongEditor::OnScrollDiffuse ), NULL, this );
	sliderColorBlue->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( fPhongEditor::OnScrollDiffuse ), NULL, this );
	sliderColorBlue->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( fPhongEditor::OnScrollDiffuse ), NULL, this );
	sliderColorBlue->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( fPhongEditor::OnScrollDiffuse ), NULL, this );
	sliderColorBlue->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( fPhongEditor::OnScrollDiffuse ), NULL, this );
	sliderColorBlue->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( fPhongEditor::OnScrollDiffuse ), NULL, this );
	sliderColorBlue->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( fPhongEditor::OnScrollDiffuse ), NULL, this );
	colourPickerDiffuse->Connect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( fPhongEditor::OnDiffuseColorChanged ), NULL, this );
	sliderColorSpecularRed->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( fPhongEditor::OnScrollSpecular ), NULL, this );
	sliderColorSpecularRed->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( fPhongEditor::OnScrollSpecular ), NULL, this );
	sliderColorSpecularRed->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( fPhongEditor::OnScrollSpecular ), NULL, this );
	sliderColorSpecularRed->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( fPhongEditor::OnScrollSpecular ), NULL, this );
	sliderColorSpecularRed->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( fPhongEditor::OnScrollSpecular ), NULL, this );
	sliderColorSpecularRed->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( fPhongEditor::OnScrollSpecular ), NULL, this );
	sliderColorSpecularRed->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( fPhongEditor::OnScrollSpecular ), NULL, this );
	sliderColorSpecularRed->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( fPhongEditor::OnScrollSpecular ), NULL, this );
	sliderColorSpecularRed->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( fPhongEditor::OnScrollSpecular ), NULL, this );
	sliderColorSpecularGreen->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( fPhongEditor::OnScrollSpecular ), NULL, this );
	sliderColorSpecularGreen->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( fPhongEditor::OnScrollSpecular ), NULL, this );
	sliderColorSpecularGreen->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( fPhongEditor::OnScrollSpecular ), NULL, this );
	sliderColorSpecularGreen->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( fPhongEditor::OnScrollSpecular ), NULL, this );
	sliderColorSpecularGreen->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( fPhongEditor::OnScrollSpecular ), NULL, this );
	sliderColorSpecularGreen->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( fPhongEditor::OnScrollSpecular ), NULL, this );
	sliderColorSpecularGreen->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( fPhongEditor::OnScrollSpecular ), NULL, this );
	sliderColorSpecularGreen->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( fPhongEditor::OnScrollSpecular ), NULL, this );
	sliderColorSpecularGreen->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( fPhongEditor::OnScrollSpecular ), NULL, this );
	sliderColorSpecularBlue->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( fPhongEditor::OnScrollSpecular ), NULL, this );
	sliderColorSpecularBlue->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( fPhongEditor::OnScrollSpecular ), NULL, this );
	sliderColorSpecularBlue->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( fPhongEditor::OnScrollSpecular ), NULL, this );
	sliderColorSpecularBlue->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( fPhongEditor::OnScrollSpecular ), NULL, this );
	sliderColorSpecularBlue->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( fPhongEditor::OnScrollSpecular ), NULL, this );
	sliderColorSpecularBlue->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( fPhongEditor::OnScrollSpecular ), NULL, this );
	sliderColorSpecularBlue->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( fPhongEditor::OnScrollSpecular ), NULL, this );
	sliderColorSpecularBlue->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( fPhongEditor::OnScrollSpecular ), NULL, this );
	sliderColorSpecularBlue->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( fPhongEditor::OnScrollSpecular ), NULL, this );
	colourPickerSpecular->Connect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( fPhongEditor::OnSpecularColorChanged ), NULL, this );
}

fPhongEditor::~fPhongEditor()
{
	// Disconnect Events
	this->Disconnect( wxEVT_IDLE, wxIdleEventHandler( fPhongEditor::OnIdle ) );
	sliderColorAmbientRed->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( fPhongEditor::OnScrollAmbient ), NULL, this );
	sliderColorAmbientRed->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( fPhongEditor::OnScrollAmbient ), NULL, this );
	sliderColorAmbientRed->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( fPhongEditor::OnScrollAmbient ), NULL, this );
	sliderColorAmbientRed->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( fPhongEditor::OnScrollAmbient ), NULL, this );
	sliderColorAmbientRed->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( fPhongEditor::OnScrollAmbient ), NULL, this );
	sliderColorAmbientRed->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( fPhongEditor::OnScrollAmbient ), NULL, this );
	sliderColorAmbientRed->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( fPhongEditor::OnScrollAmbient ), NULL, this );
	sliderColorAmbientRed->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( fPhongEditor::OnScrollAmbient ), NULL, this );
	sliderColorAmbientRed->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( fPhongEditor::OnScrollAmbient ), NULL, this );
	sliderColorAmbientGreen->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( fPhongEditor::OnScrollAmbient ), NULL, this );
	sliderColorAmbientGreen->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( fPhongEditor::OnScrollAmbient ), NULL, this );
	sliderColorAmbientGreen->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( fPhongEditor::OnScrollAmbient ), NULL, this );
	sliderColorAmbientGreen->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( fPhongEditor::OnScrollAmbient ), NULL, this );
	sliderColorAmbientGreen->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( fPhongEditor::OnScrollAmbient ), NULL, this );
	sliderColorAmbientGreen->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( fPhongEditor::OnScrollAmbient ), NULL, this );
	sliderColorAmbientGreen->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( fPhongEditor::OnScrollAmbient ), NULL, this );
	sliderColorAmbientGreen->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( fPhongEditor::OnScrollAmbient ), NULL, this );
	sliderColorAmbientGreen->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( fPhongEditor::OnScrollAmbient ), NULL, this );
	sliderColorAmbientBlue->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( fPhongEditor::OnScrollAmbient ), NULL, this );
	sliderColorAmbientBlue->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( fPhongEditor::OnScrollAmbient ), NULL, this );
	sliderColorAmbientBlue->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( fPhongEditor::OnScrollAmbient ), NULL, this );
	sliderColorAmbientBlue->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( fPhongEditor::OnScrollAmbient ), NULL, this );
	sliderColorAmbientBlue->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( fPhongEditor::OnScrollAmbient ), NULL, this );
	sliderColorAmbientBlue->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( fPhongEditor::OnScrollAmbient ), NULL, this );
	sliderColorAmbientBlue->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( fPhongEditor::OnScrollAmbient ), NULL, this );
	sliderColorAmbientBlue->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( fPhongEditor::OnScrollAmbient ), NULL, this );
	sliderColorAmbientBlue->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( fPhongEditor::OnScrollAmbient ), NULL, this );
	colourPickerAmbient->Disconnect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( fPhongEditor::OnAmbientColorChanged ), NULL, this );
	sliderColorRed->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( fPhongEditor::OnScrollDiffuse ), NULL, this );
	sliderColorRed->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( fPhongEditor::OnScrollDiffuse ), NULL, this );
	sliderColorRed->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( fPhongEditor::OnScrollDiffuse ), NULL, this );
	sliderColorRed->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( fPhongEditor::OnScrollDiffuse ), NULL, this );
	sliderColorRed->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( fPhongEditor::OnScrollDiffuse ), NULL, this );
	sliderColorRed->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( fPhongEditor::OnScrollDiffuse ), NULL, this );
	sliderColorRed->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( fPhongEditor::OnScrollDiffuse ), NULL, this );
	sliderColorRed->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( fPhongEditor::OnScrollDiffuse ), NULL, this );
	sliderColorRed->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( fPhongEditor::OnScrollDiffuse ), NULL, this );
	sliderColorGreen->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( fPhongEditor::OnScrollDiffuse ), NULL, this );
	sliderColorGreen->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( fPhongEditor::OnScrollDiffuse ), NULL, this );
	sliderColorGreen->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( fPhongEditor::OnScrollDiffuse ), NULL, this );
	sliderColorGreen->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( fPhongEditor::OnScrollDiffuse ), NULL, this );
	sliderColorGreen->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( fPhongEditor::OnScrollDiffuse ), NULL, this );
	sliderColorGreen->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( fPhongEditor::OnScrollDiffuse ), NULL, this );
	sliderColorGreen->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( fPhongEditor::OnScrollDiffuse ), NULL, this );
	sliderColorGreen->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( fPhongEditor::OnScrollDiffuse ), NULL, this );
	sliderColorGreen->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( fPhongEditor::OnScrollDiffuse ), NULL, this );
	sliderColorBlue->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( fPhongEditor::OnScrollDiffuse ), NULL, this );
	sliderColorBlue->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( fPhongEditor::OnScrollDiffuse ), NULL, this );
	sliderColorBlue->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( fPhongEditor::OnScrollDiffuse ), NULL, this );
	sliderColorBlue->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( fPhongEditor::OnScrollDiffuse ), NULL, this );
	sliderColorBlue->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( fPhongEditor::OnScrollDiffuse ), NULL, this );
	sliderColorBlue->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( fPhongEditor::OnScrollDiffuse ), NULL, this );
	sliderColorBlue->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( fPhongEditor::OnScrollDiffuse ), NULL, this );
	sliderColorBlue->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( fPhongEditor::OnScrollDiffuse ), NULL, this );
	sliderColorBlue->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( fPhongEditor::OnScrollDiffuse ), NULL, this );
	colourPickerDiffuse->Disconnect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( fPhongEditor::OnDiffuseColorChanged ), NULL, this );
	sliderColorSpecularRed->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( fPhongEditor::OnScrollSpecular ), NULL, this );
	sliderColorSpecularRed->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( fPhongEditor::OnScrollSpecular ), NULL, this );
	sliderColorSpecularRed->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( fPhongEditor::OnScrollSpecular ), NULL, this );
	sliderColorSpecularRed->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( fPhongEditor::OnScrollSpecular ), NULL, this );
	sliderColorSpecularRed->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( fPhongEditor::OnScrollSpecular ), NULL, this );
	sliderColorSpecularRed->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( fPhongEditor::OnScrollSpecular ), NULL, this );
	sliderColorSpecularRed->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( fPhongEditor::OnScrollSpecular ), NULL, this );
	sliderColorSpecularRed->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( fPhongEditor::OnScrollSpecular ), NULL, this );
	sliderColorSpecularRed->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( fPhongEditor::OnScrollSpecular ), NULL, this );
	sliderColorSpecularGreen->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( fPhongEditor::OnScrollSpecular ), NULL, this );
	sliderColorSpecularGreen->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( fPhongEditor::OnScrollSpecular ), NULL, this );
	sliderColorSpecularGreen->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( fPhongEditor::OnScrollSpecular ), NULL, this );
	sliderColorSpecularGreen->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( fPhongEditor::OnScrollSpecular ), NULL, this );
	sliderColorSpecularGreen->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( fPhongEditor::OnScrollSpecular ), NULL, this );
	sliderColorSpecularGreen->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( fPhongEditor::OnScrollSpecular ), NULL, this );
	sliderColorSpecularGreen->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( fPhongEditor::OnScrollSpecular ), NULL, this );
	sliderColorSpecularGreen->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( fPhongEditor::OnScrollSpecular ), NULL, this );
	sliderColorSpecularGreen->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( fPhongEditor::OnScrollSpecular ), NULL, this );
	sliderColorSpecularBlue->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( fPhongEditor::OnScrollSpecular ), NULL, this );
	sliderColorSpecularBlue->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( fPhongEditor::OnScrollSpecular ), NULL, this );
	sliderColorSpecularBlue->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( fPhongEditor::OnScrollSpecular ), NULL, this );
	sliderColorSpecularBlue->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( fPhongEditor::OnScrollSpecular ), NULL, this );
	sliderColorSpecularBlue->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( fPhongEditor::OnScrollSpecular ), NULL, this );
	sliderColorSpecularBlue->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( fPhongEditor::OnScrollSpecular ), NULL, this );
	sliderColorSpecularBlue->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( fPhongEditor::OnScrollSpecular ), NULL, this );
	sliderColorSpecularBlue->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( fPhongEditor::OnScrollSpecular ), NULL, this );
	sliderColorSpecularBlue->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( fPhongEditor::OnScrollSpecular ), NULL, this );
	colourPickerSpecular->Disconnect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( fPhongEditor::OnSpecularColorChanged ), NULL, this );
	
}

fShaderEditor::fShaderEditor( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer38;
	bSizer38 = new wxBoxSizer( wxHORIZONTAL );
	
	bSizer38->SetMinSize( wxSize( -1,40 ) ); 
	m_staticText13 = new wxStaticText( this, wxID_ANY, wxT("Select Shader"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText13->Wrap( -1 );
	bSizer38->Add( m_staticText13, 0, wxALL, 5 );
	
	wxArrayString choiceShadersChoices;
	choiceShaders = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, choiceShadersChoices, 0 );
	choiceShaders->SetSelection( 0 );
	bSizer38->Add( choiceShaders, 1, wxALL, 5 );
	
	
	bSizer5->Add( bSizer38, 0, wxEXPAND, 5 );
	
	m_notebook1 = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_panel1 = new wxPanel( m_notebook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxVERTICAL );
	
	scVertex = new wxScintilla( m_panel1, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, wxEmptyString );
	scVertex->SetUseTabs( true );
	scVertex->SetTabWidth( 4 );
	scVertex->SetIndent( 4 );
	scVertex->SetTabIndents( true );
	scVertex->SetBackSpaceUnIndents( true );
	scVertex->SetViewEOL( false );
	scVertex->SetViewWhiteSpace( false );
	scVertex->SetMarginWidth( 2, 0 );
	scVertex->SetIndentationGuides( true );
	scVertex->SetMarginType( 1, wxSCI_MARGIN_SYMBOL );
	scVertex->SetMarginMask( 1, wxSCI_MASK_FOLDERS );
	scVertex->SetMarginWidth( 1, 16);
	scVertex->SetMarginSensitive( 1, true );
	scVertex->SetProperty( wxT("fold"), wxT("1") );
	scVertex->SetFoldFlags( wxSCI_FOLDFLAG_LINEBEFORE_CONTRACTED | wxSCI_FOLDFLAG_LINEAFTER_CONTRACTED );
	scVertex->SetMarginType( 0, wxSCI_MARGIN_NUMBER );
	scVertex->SetMarginWidth( 0, scVertex->TextWidth( wxSCI_STYLE_LINENUMBER, wxT("_99999") ) );
	scVertex->MarkerDefine( wxSCI_MARKNUM_FOLDER, wxSCI_MARK_BOXPLUS );
	scVertex->MarkerSetBackground( wxSCI_MARKNUM_FOLDER, wxColour( wxT("BLACK") ) );
	scVertex->MarkerSetForeground( wxSCI_MARKNUM_FOLDER, wxColour( wxT("WHITE") ) );
	scVertex->MarkerDefine( wxSCI_MARKNUM_FOLDEROPEN, wxSCI_MARK_BOXMINUS );
	scVertex->MarkerSetBackground( wxSCI_MARKNUM_FOLDEROPEN, wxColour( wxT("BLACK") ) );
	scVertex->MarkerSetForeground( wxSCI_MARKNUM_FOLDEROPEN, wxColour( wxT("WHITE") ) );
	scVertex->MarkerDefine( wxSCI_MARKNUM_FOLDERSUB, wxSCI_MARK_EMPTY );
	scVertex->MarkerDefine( wxSCI_MARKNUM_FOLDEREND, wxSCI_MARK_BOXPLUS );
	scVertex->MarkerSetBackground( wxSCI_MARKNUM_FOLDEREND, wxColour( wxT("BLACK") ) );
	scVertex->MarkerSetForeground( wxSCI_MARKNUM_FOLDEREND, wxColour( wxT("WHITE") ) );
	scVertex->MarkerDefine( wxSCI_MARKNUM_FOLDEROPENMID, wxSCI_MARK_BOXMINUS );
	scVertex->MarkerSetBackground( wxSCI_MARKNUM_FOLDEROPENMID, wxColour( wxT("BLACK") ) );
	scVertex->MarkerSetForeground( wxSCI_MARKNUM_FOLDEROPENMID, wxColour( wxT("WHITE") ) );
	scVertex->MarkerDefine( wxSCI_MARKNUM_FOLDERMIDTAIL, wxSCI_MARK_EMPTY );
	scVertex->MarkerDefine( wxSCI_MARKNUM_FOLDERTAIL, wxSCI_MARK_EMPTY );
	scVertex->SetSelBackground( true, wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHT ) );
	scVertex->SetSelForeground( true, wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHTTEXT ) );
	bSizer6->Add( scVertex, 1, wxEXPAND|wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	wxBoxSizer* bSizer141;
	bSizer141 = new wxBoxSizer( wxHORIZONTAL );
	
	fpVertex = new wxFilePickerCtrl( m_panel1, wxID_ANY, wxEmptyString, wxT("Select a file"), wxT("*.vert"), wxDefaultPosition, wxSize( 200,-1 ), wxFLP_DEFAULT_STYLE );
	fpVertex->SetMaxSize( wxSize( -1,30 ) );
	
	bSizer141->Add( fpVertex, 1, wxALL|wxEXPAND, 5 );
	
	bSaveVertex = new wxBitmapButton( m_panel1, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer141->Add( bSaveVertex, 0, wxALL, 5 );
	
	bLoadVertex = new wxBitmapButton( m_panel1, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer141->Add( bLoadVertex, 0, wxALL, 5 );
	
	
	bSizer6->Add( bSizer141, 0, wxEXPAND, 5 );
	
	
	m_panel1->SetSizer( bSizer6 );
	m_panel1->Layout();
	bSizer6->Fit( m_panel1 );
	m_notebook1->AddPage( m_panel1, wxT("Vertex Shader"), false );
	m_panel21 = new wxPanel( m_notebook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer612;
	bSizer612 = new wxBoxSizer( wxVERTICAL );
	
	scTessellationControl = new wxScintilla( m_panel21, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, wxEmptyString );
	scTessellationControl->SetUseTabs( true );
	scTessellationControl->SetTabWidth( 4 );
	scTessellationControl->SetIndent( 4 );
	scTessellationControl->SetTabIndents( true );
	scTessellationControl->SetBackSpaceUnIndents( true );
	scTessellationControl->SetViewEOL( false );
	scTessellationControl->SetViewWhiteSpace( false );
	scTessellationControl->SetMarginWidth( 2, 0 );
	scTessellationControl->SetIndentationGuides( true );
	scTessellationControl->SetMarginType( 1, wxSCI_MARGIN_SYMBOL );
	scTessellationControl->SetMarginMask( 1, wxSCI_MASK_FOLDERS );
	scTessellationControl->SetMarginWidth( 1, 16);
	scTessellationControl->SetMarginSensitive( 1, true );
	scTessellationControl->SetProperty( wxT("fold"), wxT("1") );
	scTessellationControl->SetFoldFlags( wxSCI_FOLDFLAG_LINEBEFORE_CONTRACTED | wxSCI_FOLDFLAG_LINEAFTER_CONTRACTED );
	scTessellationControl->SetMarginType( 0, wxSCI_MARGIN_NUMBER );
	scTessellationControl->SetMarginWidth( 0, scTessellationControl->TextWidth( wxSCI_STYLE_LINENUMBER, wxT("_99999") ) );
	scTessellationControl->MarkerDefine( wxSCI_MARKNUM_FOLDER, wxSCI_MARK_BOXPLUS );
	scTessellationControl->MarkerSetBackground( wxSCI_MARKNUM_FOLDER, wxColour( wxT("BLACK") ) );
	scTessellationControl->MarkerSetForeground( wxSCI_MARKNUM_FOLDER, wxColour( wxT("WHITE") ) );
	scTessellationControl->MarkerDefine( wxSCI_MARKNUM_FOLDEROPEN, wxSCI_MARK_BOXMINUS );
	scTessellationControl->MarkerSetBackground( wxSCI_MARKNUM_FOLDEROPEN, wxColour( wxT("BLACK") ) );
	scTessellationControl->MarkerSetForeground( wxSCI_MARKNUM_FOLDEROPEN, wxColour( wxT("WHITE") ) );
	scTessellationControl->MarkerDefine( wxSCI_MARKNUM_FOLDERSUB, wxSCI_MARK_EMPTY );
	scTessellationControl->MarkerDefine( wxSCI_MARKNUM_FOLDEREND, wxSCI_MARK_BOXPLUS );
	scTessellationControl->MarkerSetBackground( wxSCI_MARKNUM_FOLDEREND, wxColour( wxT("BLACK") ) );
	scTessellationControl->MarkerSetForeground( wxSCI_MARKNUM_FOLDEREND, wxColour( wxT("WHITE") ) );
	scTessellationControl->MarkerDefine( wxSCI_MARKNUM_FOLDEROPENMID, wxSCI_MARK_BOXMINUS );
	scTessellationControl->MarkerSetBackground( wxSCI_MARKNUM_FOLDEROPENMID, wxColour( wxT("BLACK") ) );
	scTessellationControl->MarkerSetForeground( wxSCI_MARKNUM_FOLDEROPENMID, wxColour( wxT("WHITE") ) );
	scTessellationControl->MarkerDefine( wxSCI_MARKNUM_FOLDERMIDTAIL, wxSCI_MARK_EMPTY );
	scTessellationControl->MarkerDefine( wxSCI_MARKNUM_FOLDERTAIL, wxSCI_MARK_EMPTY );
	scTessellationControl->SetSelBackground( true, wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHT ) );
	scTessellationControl->SetSelForeground( true, wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHTTEXT ) );
	bSizer612->Add( scTessellationControl, 1, wxEXPAND | wxALL, 5 );
	
	wxBoxSizer* bSizer152;
	bSizer152 = new wxBoxSizer( wxHORIZONTAL );
	
	fpTessellationControl = new wxFilePickerCtrl( m_panel21, wxID_ANY, wxEmptyString, wxT("Select a file"), wxT("*.tessc"), wxDefaultPosition, wxDefaultSize, wxFLP_DEFAULT_STYLE );
	bSizer152->Add( fpTessellationControl, 1, wxALL|wxEXPAND, 5 );
	
	bSaveTessellationControl = new wxBitmapButton( m_panel21, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer152->Add( bSaveTessellationControl, 0, wxALL, 5 );
	
	bLoadTessellationControl = new wxBitmapButton( m_panel21, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer152->Add( bLoadTessellationControl, 0, wxALL, 5 );
	
	
	bSizer612->Add( bSizer152, 0, wxEXPAND, 5 );
	
	
	m_panel21->SetSizer( bSizer612 );
	m_panel21->Layout();
	bSizer612->Fit( m_panel21 );
	m_notebook1->AddPage( m_panel21, wxT("Tessellation Control Shader"), false );
	m_panel11 = new wxPanel( m_notebook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer62;
	bSizer62 = new wxBoxSizer( wxVERTICAL );
	
	scTessellationEvaluation = new wxScintilla( m_panel11, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, wxEmptyString );
	scTessellationEvaluation->SetUseTabs( true );
	scTessellationEvaluation->SetTabWidth( 4 );
	scTessellationEvaluation->SetIndent( 4 );
	scTessellationEvaluation->SetTabIndents( true );
	scTessellationEvaluation->SetBackSpaceUnIndents( true );
	scTessellationEvaluation->SetViewEOL( false );
	scTessellationEvaluation->SetViewWhiteSpace( false );
	scTessellationEvaluation->SetMarginWidth( 2, 0 );
	scTessellationEvaluation->SetIndentationGuides( true );
	scTessellationEvaluation->SetMarginType( 1, wxSCI_MARGIN_SYMBOL );
	scTessellationEvaluation->SetMarginMask( 1, wxSCI_MASK_FOLDERS );
	scTessellationEvaluation->SetMarginWidth( 1, 16);
	scTessellationEvaluation->SetMarginSensitive( 1, true );
	scTessellationEvaluation->SetProperty( wxT("fold"), wxT("1") );
	scTessellationEvaluation->SetFoldFlags( wxSCI_FOLDFLAG_LINEBEFORE_CONTRACTED | wxSCI_FOLDFLAG_LINEAFTER_CONTRACTED );
	scTessellationEvaluation->SetMarginType( 0, wxSCI_MARGIN_NUMBER );
	scTessellationEvaluation->SetMarginWidth( 0, scTessellationEvaluation->TextWidth( wxSCI_STYLE_LINENUMBER, wxT("_99999") ) );
	scTessellationEvaluation->MarkerDefine( wxSCI_MARKNUM_FOLDER, wxSCI_MARK_BOXPLUS );
	scTessellationEvaluation->MarkerSetBackground( wxSCI_MARKNUM_FOLDER, wxColour( wxT("BLACK") ) );
	scTessellationEvaluation->MarkerSetForeground( wxSCI_MARKNUM_FOLDER, wxColour( wxT("WHITE") ) );
	scTessellationEvaluation->MarkerDefine( wxSCI_MARKNUM_FOLDEROPEN, wxSCI_MARK_BOXMINUS );
	scTessellationEvaluation->MarkerSetBackground( wxSCI_MARKNUM_FOLDEROPEN, wxColour( wxT("BLACK") ) );
	scTessellationEvaluation->MarkerSetForeground( wxSCI_MARKNUM_FOLDEROPEN, wxColour( wxT("WHITE") ) );
	scTessellationEvaluation->MarkerDefine( wxSCI_MARKNUM_FOLDERSUB, wxSCI_MARK_EMPTY );
	scTessellationEvaluation->MarkerDefine( wxSCI_MARKNUM_FOLDEREND, wxSCI_MARK_BOXPLUS );
	scTessellationEvaluation->MarkerSetBackground( wxSCI_MARKNUM_FOLDEREND, wxColour( wxT("BLACK") ) );
	scTessellationEvaluation->MarkerSetForeground( wxSCI_MARKNUM_FOLDEREND, wxColour( wxT("WHITE") ) );
	scTessellationEvaluation->MarkerDefine( wxSCI_MARKNUM_FOLDEROPENMID, wxSCI_MARK_BOXMINUS );
	scTessellationEvaluation->MarkerSetBackground( wxSCI_MARKNUM_FOLDEROPENMID, wxColour( wxT("BLACK") ) );
	scTessellationEvaluation->MarkerSetForeground( wxSCI_MARKNUM_FOLDEROPENMID, wxColour( wxT("WHITE") ) );
	scTessellationEvaluation->MarkerDefine( wxSCI_MARKNUM_FOLDERMIDTAIL, wxSCI_MARK_EMPTY );
	scTessellationEvaluation->MarkerDefine( wxSCI_MARKNUM_FOLDERTAIL, wxSCI_MARK_EMPTY );
	scTessellationEvaluation->SetSelBackground( true, wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHT ) );
	scTessellationEvaluation->SetSelForeground( true, wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHTTEXT ) );
	bSizer62->Add( scTessellationEvaluation, 1, wxEXPAND|wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	wxBoxSizer* bSizer1411;
	bSizer1411 = new wxBoxSizer( wxHORIZONTAL );
	
	fpTessellationEvaluation = new wxFilePickerCtrl( m_panel11, wxID_ANY, wxEmptyString, wxT("Select a file"), wxT("*.tesse"), wxDefaultPosition, wxSize( 200,-1 ), wxFLP_DEFAULT_STYLE );
	fpTessellationEvaluation->SetMaxSize( wxSize( -1,30 ) );
	
	bSizer1411->Add( fpTessellationEvaluation, 1, wxALL|wxEXPAND, 5 );
	
	bSaveTessellationEvaluation = new wxBitmapButton( m_panel11, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer1411->Add( bSaveTessellationEvaluation, 0, wxALL, 5 );
	
	bLoadTessellationEvaluation = new wxBitmapButton( m_panel11, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer1411->Add( bLoadTessellationEvaluation, 0, wxALL, 5 );
	
	
	bSizer62->Add( bSizer1411, 0, wxEXPAND, 5 );
	
	
	m_panel11->SetSizer( bSizer62 );
	m_panel11->Layout();
	bSizer62->Fit( m_panel11 );
	m_notebook1->AddPage( m_panel11, wxT("Tessellation Evaluation Shader"), false );
	m_panel22 = new wxPanel( m_notebook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer611;
	bSizer611 = new wxBoxSizer( wxVERTICAL );
	
	scGeometry = new wxScintilla( m_panel22, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, wxEmptyString );
	scGeometry->SetUseTabs( true );
	scGeometry->SetTabWidth( 4 );
	scGeometry->SetIndent( 4 );
	scGeometry->SetTabIndents( true );
	scGeometry->SetBackSpaceUnIndents( true );
	scGeometry->SetViewEOL( false );
	scGeometry->SetViewWhiteSpace( false );
	scGeometry->SetMarginWidth( 2, 0 );
	scGeometry->SetIndentationGuides( true );
	scGeometry->SetMarginType( 1, wxSCI_MARGIN_SYMBOL );
	scGeometry->SetMarginMask( 1, wxSCI_MASK_FOLDERS );
	scGeometry->SetMarginWidth( 1, 16);
	scGeometry->SetMarginSensitive( 1, true );
	scGeometry->SetProperty( wxT("fold"), wxT("1") );
	scGeometry->SetFoldFlags( wxSCI_FOLDFLAG_LINEBEFORE_CONTRACTED | wxSCI_FOLDFLAG_LINEAFTER_CONTRACTED );
	scGeometry->SetMarginType( 0, wxSCI_MARGIN_NUMBER );
	scGeometry->SetMarginWidth( 0, scGeometry->TextWidth( wxSCI_STYLE_LINENUMBER, wxT("_99999") ) );
	scGeometry->MarkerDefine( wxSCI_MARKNUM_FOLDER, wxSCI_MARK_BOXPLUS );
	scGeometry->MarkerSetBackground( wxSCI_MARKNUM_FOLDER, wxColour( wxT("BLACK") ) );
	scGeometry->MarkerSetForeground( wxSCI_MARKNUM_FOLDER, wxColour( wxT("WHITE") ) );
	scGeometry->MarkerDefine( wxSCI_MARKNUM_FOLDEROPEN, wxSCI_MARK_BOXMINUS );
	scGeometry->MarkerSetBackground( wxSCI_MARKNUM_FOLDEROPEN, wxColour( wxT("BLACK") ) );
	scGeometry->MarkerSetForeground( wxSCI_MARKNUM_FOLDEROPEN, wxColour( wxT("WHITE") ) );
	scGeometry->MarkerDefine( wxSCI_MARKNUM_FOLDERSUB, wxSCI_MARK_EMPTY );
	scGeometry->MarkerDefine( wxSCI_MARKNUM_FOLDEREND, wxSCI_MARK_BOXPLUS );
	scGeometry->MarkerSetBackground( wxSCI_MARKNUM_FOLDEREND, wxColour( wxT("BLACK") ) );
	scGeometry->MarkerSetForeground( wxSCI_MARKNUM_FOLDEREND, wxColour( wxT("WHITE") ) );
	scGeometry->MarkerDefine( wxSCI_MARKNUM_FOLDEROPENMID, wxSCI_MARK_BOXMINUS );
	scGeometry->MarkerSetBackground( wxSCI_MARKNUM_FOLDEROPENMID, wxColour( wxT("BLACK") ) );
	scGeometry->MarkerSetForeground( wxSCI_MARKNUM_FOLDEROPENMID, wxColour( wxT("WHITE") ) );
	scGeometry->MarkerDefine( wxSCI_MARKNUM_FOLDERMIDTAIL, wxSCI_MARK_EMPTY );
	scGeometry->MarkerDefine( wxSCI_MARKNUM_FOLDERTAIL, wxSCI_MARK_EMPTY );
	scGeometry->SetSelBackground( true, wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHT ) );
	scGeometry->SetSelForeground( true, wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHTTEXT ) );
	bSizer611->Add( scGeometry, 1, wxEXPAND | wxALL, 5 );
	
	wxBoxSizer* bSizer151;
	bSizer151 = new wxBoxSizer( wxHORIZONTAL );
	
	fpGeometry = new wxFilePickerCtrl( m_panel22, wxID_ANY, wxEmptyString, wxT("Select a file"), wxT("*.geom"), wxDefaultPosition, wxDefaultSize, wxFLP_DEFAULT_STYLE );
	bSizer151->Add( fpGeometry, 1, wxALL|wxEXPAND, 5 );
	
	bSaveGeometry = new wxBitmapButton( m_panel22, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer151->Add( bSaveGeometry, 0, wxALL, 5 );
	
	bLoadGeometry = new wxBitmapButton( m_panel22, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer151->Add( bLoadGeometry, 0, wxALL, 5 );
	
	
	bSizer611->Add( bSizer151, 0, wxEXPAND, 5 );
	
	
	m_panel22->SetSizer( bSizer611 );
	m_panel22->Layout();
	bSizer611->Fit( m_panel22 );
	m_notebook1->AddPage( m_panel22, wxT("Geometry Shader"), false );
	m_panel2 = new wxPanel( m_notebook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer61;
	bSizer61 = new wxBoxSizer( wxVERTICAL );
	
	scFragment = new wxScintilla( m_panel2, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, wxEmptyString );
	scFragment->SetUseTabs( true );
	scFragment->SetTabWidth( 4 );
	scFragment->SetIndent( 4 );
	scFragment->SetTabIndents( true );
	scFragment->SetBackSpaceUnIndents( true );
	scFragment->SetViewEOL( false );
	scFragment->SetViewWhiteSpace( false );
	scFragment->SetMarginWidth( 2, 0 );
	scFragment->SetIndentationGuides( true );
	scFragment->SetMarginType( 1, wxSCI_MARGIN_SYMBOL );
	scFragment->SetMarginMask( 1, wxSCI_MASK_FOLDERS );
	scFragment->SetMarginWidth( 1, 16);
	scFragment->SetMarginSensitive( 1, true );
	scFragment->SetProperty( wxT("fold"), wxT("1") );
	scFragment->SetFoldFlags( wxSCI_FOLDFLAG_LINEBEFORE_CONTRACTED | wxSCI_FOLDFLAG_LINEAFTER_CONTRACTED );
	scFragment->SetMarginType( 0, wxSCI_MARGIN_NUMBER );
	scFragment->SetMarginWidth( 0, scFragment->TextWidth( wxSCI_STYLE_LINENUMBER, wxT("_99999") ) );
	scFragment->MarkerDefine( wxSCI_MARKNUM_FOLDER, wxSCI_MARK_BOXPLUS );
	scFragment->MarkerSetBackground( wxSCI_MARKNUM_FOLDER, wxColour( wxT("BLACK") ) );
	scFragment->MarkerSetForeground( wxSCI_MARKNUM_FOLDER, wxColour( wxT("WHITE") ) );
	scFragment->MarkerDefine( wxSCI_MARKNUM_FOLDEROPEN, wxSCI_MARK_BOXMINUS );
	scFragment->MarkerSetBackground( wxSCI_MARKNUM_FOLDEROPEN, wxColour( wxT("BLACK") ) );
	scFragment->MarkerSetForeground( wxSCI_MARKNUM_FOLDEROPEN, wxColour( wxT("WHITE") ) );
	scFragment->MarkerDefine( wxSCI_MARKNUM_FOLDERSUB, wxSCI_MARK_EMPTY );
	scFragment->MarkerDefine( wxSCI_MARKNUM_FOLDEREND, wxSCI_MARK_BOXPLUS );
	scFragment->MarkerSetBackground( wxSCI_MARKNUM_FOLDEREND, wxColour( wxT("BLACK") ) );
	scFragment->MarkerSetForeground( wxSCI_MARKNUM_FOLDEREND, wxColour( wxT("WHITE") ) );
	scFragment->MarkerDefine( wxSCI_MARKNUM_FOLDEROPENMID, wxSCI_MARK_BOXMINUS );
	scFragment->MarkerSetBackground( wxSCI_MARKNUM_FOLDEROPENMID, wxColour( wxT("BLACK") ) );
	scFragment->MarkerSetForeground( wxSCI_MARKNUM_FOLDEROPENMID, wxColour( wxT("WHITE") ) );
	scFragment->MarkerDefine( wxSCI_MARKNUM_FOLDERMIDTAIL, wxSCI_MARK_EMPTY );
	scFragment->MarkerDefine( wxSCI_MARKNUM_FOLDERTAIL, wxSCI_MARK_EMPTY );
	scFragment->SetSelBackground( true, wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHT ) );
	scFragment->SetSelForeground( true, wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHTTEXT ) );
	bSizer61->Add( scFragment, 1, wxEXPAND | wxALL, 5 );
	
	wxBoxSizer* bSizer15;
	bSizer15 = new wxBoxSizer( wxHORIZONTAL );
	
	fpFragment = new wxFilePickerCtrl( m_panel2, wxID_ANY, wxEmptyString, wxT("Select a file"), wxT("*.frag"), wxDefaultPosition, wxDefaultSize, wxFLP_DEFAULT_STYLE );
	bSizer15->Add( fpFragment, 1, wxALL|wxEXPAND, 5 );
	
	bSaveFragment = new wxBitmapButton( m_panel2, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer15->Add( bSaveFragment, 0, wxALL, 5 );
	
	bLoadFragment = new wxBitmapButton( m_panel2, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer15->Add( bLoadFragment, 0, wxALL, 5 );
	
	
	bSizer61->Add( bSizer15, 0, wxEXPAND, 5 );
	
	
	m_panel2->SetSizer( bSizer61 );
	m_panel2->Layout();
	bSizer61->Fit( m_panel2 );
	m_notebook1->AddPage( m_panel2, wxT("Fragment Shader"), true );
	m_panel13 = new wxPanel( m_notebook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer14;
	bSizer14 = new wxBoxSizer( wxVERTICAL );
	
	m_richText5 = new wxRichTextCtrl( m_panel13, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0|wxVSCROLL|wxHSCROLL|wxNO_BORDER|wxWANTS_CHARS );
	m_richText5->SetFont( wxFont( 8, 76, 90, 90, false, wxT("Monospace") ) );
	
	bSizer14->Add( m_richText5, 1, wxEXPAND | wxALL, 5 );
	
	
	m_panel13->SetSizer( bSizer14 );
	m_panel13->Layout();
	bSizer14->Fit( m_panel13 );
	m_notebook1->AddPage( m_panel13, wxT("Quick Reference"), false );
	
	bSizer5->Add( m_notebook1, 1, wxALL|wxEXPAND, 5 );
	
	scLog = new wxScintilla( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, wxEmptyString );
	scLog->SetUseTabs( true );
	scLog->SetTabWidth( 4 );
	scLog->SetIndent( 4 );
	scLog->SetTabIndents( true );
	scLog->SetBackSpaceUnIndents( true );
	scLog->SetViewEOL( false );
	scLog->SetViewWhiteSpace( false );
	scLog->SetMarginWidth( 2, 0 );
	scLog->SetIndentationGuides( true );
	scLog->SetMarginType( 1, wxSCI_MARGIN_SYMBOL );
	scLog->SetMarginMask( 1, wxSCI_MASK_FOLDERS );
	scLog->SetMarginWidth( 1, 16);
	scLog->SetMarginSensitive( 1, true );
	scLog->SetProperty( wxT("fold"), wxT("1") );
	scLog->SetFoldFlags( wxSCI_FOLDFLAG_LINEBEFORE_CONTRACTED | wxSCI_FOLDFLAG_LINEAFTER_CONTRACTED );
	scLog->SetMarginType( 0, wxSCI_MARGIN_NUMBER );
	scLog->SetMarginWidth( 0, scLog->TextWidth( wxSCI_STYLE_LINENUMBER, wxT("_99999") ) );
	scLog->MarkerDefine( wxSCI_MARKNUM_FOLDER, wxSCI_MARK_BOXPLUS );
	scLog->MarkerSetBackground( wxSCI_MARKNUM_FOLDER, wxColour( wxT("BLACK") ) );
	scLog->MarkerSetForeground( wxSCI_MARKNUM_FOLDER, wxColour( wxT("WHITE") ) );
	scLog->MarkerDefine( wxSCI_MARKNUM_FOLDEROPEN, wxSCI_MARK_BOXMINUS );
	scLog->MarkerSetBackground( wxSCI_MARKNUM_FOLDEROPEN, wxColour( wxT("BLACK") ) );
	scLog->MarkerSetForeground( wxSCI_MARKNUM_FOLDEROPEN, wxColour( wxT("WHITE") ) );
	scLog->MarkerDefine( wxSCI_MARKNUM_FOLDERSUB, wxSCI_MARK_EMPTY );
	scLog->MarkerDefine( wxSCI_MARKNUM_FOLDEREND, wxSCI_MARK_BOXPLUS );
	scLog->MarkerSetBackground( wxSCI_MARKNUM_FOLDEREND, wxColour( wxT("BLACK") ) );
	scLog->MarkerSetForeground( wxSCI_MARKNUM_FOLDEREND, wxColour( wxT("WHITE") ) );
	scLog->MarkerDefine( wxSCI_MARKNUM_FOLDEROPENMID, wxSCI_MARK_BOXMINUS );
	scLog->MarkerSetBackground( wxSCI_MARKNUM_FOLDEROPENMID, wxColour( wxT("BLACK") ) );
	scLog->MarkerSetForeground( wxSCI_MARKNUM_FOLDEROPENMID, wxColour( wxT("WHITE") ) );
	scLog->MarkerDefine( wxSCI_MARKNUM_FOLDERMIDTAIL, wxSCI_MARK_EMPTY );
	scLog->MarkerDefine( wxSCI_MARKNUM_FOLDERTAIL, wxSCI_MARK_EMPTY );
	scLog->SetSelBackground( true, wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHT ) );
	scLog->SetSelForeground( true, wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHTTEXT ) );
	bSizer5->Add( scLog, 1, wxALL|wxEXPAND, 5 );
	
	m_button1 = new wxButton( this, wxID_ANY, wxT("&Compile"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer5->Add( m_button1, 0, wxALL, 5 );
	
	
	this->SetSizer( bSizer5 );
	this->Layout();
	m_menubar2 = new wxMenuBar( 0 );
	shader = new wxMenu();
	wxMenuItem* loadFragment;
	loadFragment = new wxMenuItem( shader, ID_LOAD_FRAGMENT, wxString( wxT("Load Fragment") ) , wxEmptyString, wxITEM_NORMAL );
	shader->Append( loadFragment );
	
	wxMenuItem* saveFragment;
	saveFragment = new wxMenuItem( shader, ID_SAVE_FRAGMENT, wxString( wxT("Save Fragment") ) , wxEmptyString, wxITEM_NORMAL );
	shader->Append( saveFragment );
	
	wxMenuItem* loadVertex;
	loadVertex = new wxMenuItem( shader, ID_LOAD_VERTEX, wxString( wxT("Load Vertex") ) , wxEmptyString, wxITEM_NORMAL );
	shader->Append( loadVertex );
	
	wxMenuItem* saveVertex;
	saveVertex = new wxMenuItem( shader, ID_SAVE_VERTEX, wxString( wxT("Save Vertex") ) , wxEmptyString, wxITEM_NORMAL );
	shader->Append( saveVertex );
	
	wxMenuItem* compile;
	compile = new wxMenuItem( shader, ID_COMPILE, wxString( wxT("Compile") ) , wxEmptyString, wxITEM_NORMAL );
	shader->Append( compile );
	
	m_menubar2->Append( shader, wxT("Shader") ); 
	
	this->SetMenuBar( m_menubar2 );
	
	
	// Connect Events
	choiceShaders->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( fShaderEditor::OnChoiceShader ), NULL, this );
	fpVertex->Connect( wxEVT_COMMAND_FILEPICKER_CHANGED, wxFileDirPickerEventHandler( fShaderEditor::OnVertexFileChanged ), NULL, this );
	bSaveVertex->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fShaderEditor::OnButtonVertexLoad ), NULL, this );
	bLoadVertex->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fShaderEditor::OnButtonVertexSave ), NULL, this );
	fpTessellationControl->Connect( wxEVT_COMMAND_FILEPICKER_CHANGED, wxFileDirPickerEventHandler( fShaderEditor::OnTessellationControlFileChanged ), NULL, this );
	bSaveTessellationControl->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fShaderEditor::OnButtonTessellationLoad ), NULL, this );
	bLoadTessellationControl->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fShaderEditor::OnButtonTessellationControlLoad ), NULL, this );
	fpTessellationEvaluation->Connect( wxEVT_COMMAND_FILEPICKER_CHANGED, wxFileDirPickerEventHandler( fShaderEditor::OnTessellationEvaluationFileChanged ), NULL, this );
	bSaveTessellationEvaluation->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fShaderEditor::OnButtonTessellationEvaluationLoad ), NULL, this );
	bLoadTessellationEvaluation->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fShaderEditor::OnButtonTessellationEvaluationSave ), NULL, this );
	fpGeometry->Connect( wxEVT_COMMAND_FILEPICKER_CHANGED, wxFileDirPickerEventHandler( fShaderEditor::OnGeometryFileChanged ), NULL, this );
	bSaveGeometry->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fShaderEditor::OnButtonGeometryLoad ), NULL, this );
	bLoadGeometry->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fShaderEditor::OnButtonGeometryLoad ), NULL, this );
	fpFragment->Connect( wxEVT_COMMAND_FILEPICKER_CHANGED, wxFileDirPickerEventHandler( fShaderEditor::OnFragmentFileChanged ), NULL, this );
	bSaveFragment->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fShaderEditor::OnButtonFragmentLoad ), NULL, this );
	bLoadFragment->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fShaderEditor::OnButtonFragmentLoad ), NULL, this );
	scLog->Connect( wxEVT_LEFT_DCLICK, wxMouseEventHandler( fShaderEditor::OnLogLeftDClick ), NULL, this );
	m_button1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fShaderEditor::OnCompileClick ), NULL, this );
	this->Connect( compile->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( fShaderEditor::OnCompileClick ) );
}

fShaderEditor::~fShaderEditor()
{
	// Disconnect Events
	choiceShaders->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( fShaderEditor::OnChoiceShader ), NULL, this );
	fpVertex->Disconnect( wxEVT_COMMAND_FILEPICKER_CHANGED, wxFileDirPickerEventHandler( fShaderEditor::OnVertexFileChanged ), NULL, this );
	bSaveVertex->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fShaderEditor::OnButtonVertexLoad ), NULL, this );
	bLoadVertex->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fShaderEditor::OnButtonVertexSave ), NULL, this );
	fpTessellationControl->Disconnect( wxEVT_COMMAND_FILEPICKER_CHANGED, wxFileDirPickerEventHandler( fShaderEditor::OnTessellationControlFileChanged ), NULL, this );
	bSaveTessellationControl->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fShaderEditor::OnButtonTessellationLoad ), NULL, this );
	bLoadTessellationControl->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fShaderEditor::OnButtonTessellationControlLoad ), NULL, this );
	fpTessellationEvaluation->Disconnect( wxEVT_COMMAND_FILEPICKER_CHANGED, wxFileDirPickerEventHandler( fShaderEditor::OnTessellationEvaluationFileChanged ), NULL, this );
	bSaveTessellationEvaluation->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fShaderEditor::OnButtonTessellationEvaluationLoad ), NULL, this );
	bLoadTessellationEvaluation->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fShaderEditor::OnButtonTessellationEvaluationSave ), NULL, this );
	fpGeometry->Disconnect( wxEVT_COMMAND_FILEPICKER_CHANGED, wxFileDirPickerEventHandler( fShaderEditor::OnGeometryFileChanged ), NULL, this );
	bSaveGeometry->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fShaderEditor::OnButtonGeometryLoad ), NULL, this );
	bLoadGeometry->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fShaderEditor::OnButtonGeometryLoad ), NULL, this );
	fpFragment->Disconnect( wxEVT_COMMAND_FILEPICKER_CHANGED, wxFileDirPickerEventHandler( fShaderEditor::OnFragmentFileChanged ), NULL, this );
	bSaveFragment->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fShaderEditor::OnButtonFragmentLoad ), NULL, this );
	bLoadFragment->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fShaderEditor::OnButtonFragmentLoad ), NULL, this );
	scLog->Disconnect( wxEVT_LEFT_DCLICK, wxMouseEventHandler( fShaderEditor::OnLogLeftDClick ), NULL, this );
	m_button1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fShaderEditor::OnCompileClick ), NULL, this );
	this->Disconnect( ID_COMPILE, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( fShaderEditor::OnCompileClick ) );
	
}

fPostProcessEditor::fPostProcessEditor( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxVERTICAL );
	
	m_notebook2 = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_panel3 = new wxPanel( m_notebook2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxGridSizer* gSizer2;
	gSizer2 = new wxGridSizer( 2, 2, 0, 0 );
	
	m_staticText5 = new wxStaticText( m_panel3, wxID_ANY, wxT("Brightness"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText5->Wrap( -1 );
	gSizer2->Add( m_staticText5, 0, wxALL, 5 );
	
	brightnessSlider = new wxSlider( m_panel3, wxID_ANY, 256, 0, 1024, wxDefaultPosition, wxSize( 200,-1 ), wxSL_HORIZONTAL );
	gSizer2->Add( brightnessSlider, 0, wxALL, 5 );
	
	m_staticText51 = new wxStaticText( m_panel3, wxID_ANY, wxT("Saturation"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText51->Wrap( -1 );
	gSizer2->Add( m_staticText51, 0, wxALL, 5 );
	
	saturationSlider = new wxSlider( m_panel3, wxID_ANY, 1, 0, 255, wxDefaultPosition, wxSize( 200,-1 ), wxSL_HORIZONTAL );
	gSizer2->Add( saturationSlider, 0, wxALL, 5 );
	
	
	m_panel3->SetSizer( gSizer2 );
	m_panel3->Layout();
	gSizer2->Fit( m_panel3 );
	m_notebook2->AddPage( m_panel3, wxT("Color Correction"), false );
	m_panel11 = new wxPanel( m_notebook2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer18;
	bSizer18 = new wxBoxSizer( wxVERTICAL );
	
	m_panel12 = new wxPanel( m_panel11, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer19;
	bSizer19 = new wxBoxSizer( wxHORIZONTAL );
	
	m_textCtrl2 = new wxTextCtrl( m_panel12, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer19->Add( m_textCtrl2, 0, wxALL, 5 );
	
	m_slider14 = new wxSlider( m_panel12, wxID_ANY, 50, 0, 512, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizer19->Add( m_slider14, 1, wxALL, 5 );
	
	
	m_panel12->SetSizer( bSizer19 );
	m_panel12->Layout();
	bSizer19->Fit( m_panel12 );
	bSizer18->Add( m_panel12, 1, wxEXPAND | wxALL, 5 );
	
	m_panel121 = new wxPanel( m_panel11, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer191;
	bSizer191 = new wxBoxSizer( wxHORIZONTAL );
	
	m_textCtrl21 = new wxTextCtrl( m_panel121, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer191->Add( m_textCtrl21, 0, wxALL, 5 );
	
	m_slider141 = new wxSlider( m_panel121, wxID_ANY, 50, 0, 512, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizer191->Add( m_slider141, 1, wxALL, 5 );
	
	
	m_panel121->SetSizer( bSizer191 );
	m_panel121->Layout();
	bSizer191->Fit( m_panel121 );
	bSizer18->Add( m_panel121, 1, wxEXPAND | wxALL, 5 );
	
	m_panel122 = new wxPanel( m_panel11, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer192;
	bSizer192 = new wxBoxSizer( wxHORIZONTAL );
	
	m_textCtrl22 = new wxTextCtrl( m_panel122, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer192->Add( m_textCtrl22, 0, wxALL, 5 );
	
	m_slider142 = new wxSlider( m_panel122, wxID_ANY, 50, 0, 512, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizer192->Add( m_slider142, 1, wxALL, 5 );
	
	
	m_panel122->SetSizer( bSizer192 );
	m_panel122->Layout();
	bSizer192->Fit( m_panel122 );
	bSizer18->Add( m_panel122, 1, wxEXPAND | wxALL, 5 );
	
	m_panel123 = new wxPanel( m_panel11, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer193;
	bSizer193 = new wxBoxSizer( wxHORIZONTAL );
	
	m_textCtrl23 = new wxTextCtrl( m_panel123, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer193->Add( m_textCtrl23, 0, wxALL, 5 );
	
	m_slider143 = new wxSlider( m_panel123, wxID_ANY, 50, 0, 512, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizer193->Add( m_slider143, 1, wxALL, 5 );
	
	
	m_panel123->SetSizer( bSizer193 );
	m_panel123->Layout();
	bSizer193->Fit( m_panel123 );
	bSizer18->Add( m_panel123, 1, wxEXPAND | wxALL, 5 );
	
	m_panel124 = new wxPanel( m_panel11, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer194;
	bSizer194 = new wxBoxSizer( wxHORIZONTAL );
	
	m_textCtrl24 = new wxTextCtrl( m_panel124, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer194->Add( m_textCtrl24, 0, wxALL, 5 );
	
	m_slider144 = new wxSlider( m_panel124, wxID_ANY, 50, 0, 512, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizer194->Add( m_slider144, 1, wxALL, 5 );
	
	
	m_panel124->SetSizer( bSizer194 );
	m_panel124->Layout();
	bSizer194->Fit( m_panel124 );
	bSizer18->Add( m_panel124, 1, wxEXPAND | wxALL, 5 );
	
	m_panel125 = new wxPanel( m_panel11, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer195;
	bSizer195 = new wxBoxSizer( wxHORIZONTAL );
	
	m_textCtrl25 = new wxTextCtrl( m_panel125, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer195->Add( m_textCtrl25, 0, wxALL, 5 );
	
	m_slider145 = new wxSlider( m_panel125, wxID_ANY, 50, 0, 512, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizer195->Add( m_slider145, 1, wxALL, 5 );
	
	
	m_panel125->SetSizer( bSizer195 );
	m_panel125->Layout();
	bSizer195->Fit( m_panel125 );
	bSizer18->Add( m_panel125, 1, wxEXPAND | wxALL, 5 );
	
	m_panel126 = new wxPanel( m_panel11, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer196;
	bSizer196 = new wxBoxSizer( wxHORIZONTAL );
	
	m_textCtrl26 = new wxTextCtrl( m_panel126, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer196->Add( m_textCtrl26, 0, wxALL, 5 );
	
	m_slider146 = new wxSlider( m_panel126, wxID_ANY, 50, 0, 512, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizer196->Add( m_slider146, 1, wxALL, 5 );
	
	
	m_panel126->SetSizer( bSizer196 );
	m_panel126->Layout();
	bSizer196->Fit( m_panel126 );
	bSizer18->Add( m_panel126, 1, wxEXPAND | wxALL, 5 );
	
	m_panel127 = new wxPanel( m_panel11, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer197;
	bSizer197 = new wxBoxSizer( wxHORIZONTAL );
	
	m_textCtrl27 = new wxTextCtrl( m_panel127, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer197->Add( m_textCtrl27, 0, wxALL, 5 );
	
	m_slider147 = new wxSlider( m_panel127, wxID_ANY, 50, 0, 512, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizer197->Add( m_slider147, 1, wxALL, 5 );
	
	
	m_panel127->SetSizer( bSizer197 );
	m_panel127->Layout();
	bSizer197->Fit( m_panel127 );
	bSizer18->Add( m_panel127, 1, wxEXPAND | wxALL, 5 );
	
	
	m_panel11->SetSizer( bSizer18 );
	m_panel11->Layout();
	bSizer18->Fit( m_panel11 );
	m_notebook2->AddPage( m_panel11, wxT("Manual Uniforms"), true );
	
	bSizer8->Add( m_notebook2, 1, wxEXPAND | wxALL, 5 );
	
	
	bSizer7->Add( bSizer8, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer7 );
	this->Layout();
	
	// Connect Events
	brightnessSlider->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( fPostProcessEditor::onBrightnessChange ), NULL, this );
	brightnessSlider->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( fPostProcessEditor::onBrightnessChange ), NULL, this );
	brightnessSlider->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( fPostProcessEditor::onBrightnessChange ), NULL, this );
	brightnessSlider->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( fPostProcessEditor::onBrightnessChange ), NULL, this );
	brightnessSlider->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( fPostProcessEditor::onBrightnessChange ), NULL, this );
	brightnessSlider->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( fPostProcessEditor::onBrightnessChange ), NULL, this );
	brightnessSlider->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( fPostProcessEditor::onBrightnessChange ), NULL, this );
	brightnessSlider->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( fPostProcessEditor::onBrightnessChange ), NULL, this );
	brightnessSlider->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( fPostProcessEditor::onBrightnessChange ), NULL, this );
	saturationSlider->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( fPostProcessEditor::onSaturationChange ), NULL, this );
	saturationSlider->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( fPostProcessEditor::onSaturationChange ), NULL, this );
	saturationSlider->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( fPostProcessEditor::onSaturationChange ), NULL, this );
	saturationSlider->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( fPostProcessEditor::onSaturationChange ), NULL, this );
	saturationSlider->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( fPostProcessEditor::onSaturationChange ), NULL, this );
	saturationSlider->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( fPostProcessEditor::onSaturationChange ), NULL, this );
	saturationSlider->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( fPostProcessEditor::onSaturationChange ), NULL, this );
	saturationSlider->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( fPostProcessEditor::onSaturationChange ), NULL, this );
	saturationSlider->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( fPostProcessEditor::onSaturationChange ), NULL, this );
}

fPostProcessEditor::~fPostProcessEditor()
{
	// Disconnect Events
	brightnessSlider->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( fPostProcessEditor::onBrightnessChange ), NULL, this );
	brightnessSlider->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( fPostProcessEditor::onBrightnessChange ), NULL, this );
	brightnessSlider->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( fPostProcessEditor::onBrightnessChange ), NULL, this );
	brightnessSlider->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( fPostProcessEditor::onBrightnessChange ), NULL, this );
	brightnessSlider->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( fPostProcessEditor::onBrightnessChange ), NULL, this );
	brightnessSlider->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( fPostProcessEditor::onBrightnessChange ), NULL, this );
	brightnessSlider->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( fPostProcessEditor::onBrightnessChange ), NULL, this );
	brightnessSlider->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( fPostProcessEditor::onBrightnessChange ), NULL, this );
	brightnessSlider->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( fPostProcessEditor::onBrightnessChange ), NULL, this );
	saturationSlider->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( fPostProcessEditor::onSaturationChange ), NULL, this );
	saturationSlider->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( fPostProcessEditor::onSaturationChange ), NULL, this );
	saturationSlider->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( fPostProcessEditor::onSaturationChange ), NULL, this );
	saturationSlider->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( fPostProcessEditor::onSaturationChange ), NULL, this );
	saturationSlider->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( fPostProcessEditor::onSaturationChange ), NULL, this );
	saturationSlider->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( fPostProcessEditor::onSaturationChange ), NULL, this );
	saturationSlider->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( fPostProcessEditor::onSaturationChange ), NULL, this );
	saturationSlider->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( fPostProcessEditor::onSaturationChange ), NULL, this );
	saturationSlider->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( fPostProcessEditor::onSaturationChange ), NULL, this );
	
}

fMainEditor::fMainEditor( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxVERTICAL );
	
	wxGridSizer* gSizer3;
	gSizer3 = new wxGridSizer( 2, 2, 0, 0 );
	
	previewPanel = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer40;
	bSizer40 = new wxBoxSizer( wxVERTICAL );
	
	wxGridSizer* gSizer5;
	gSizer5 = new wxGridSizer( 2, 2, 0, 0 );
	
	m_staticText15 = new wxStaticText( previewPanel, wxID_ANY, wxT("FPS:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText15->Wrap( -1 );
	gSizer5->Add( m_staticText15, 0, wxALL, 5 );
	
	eFpsValue = new wxStaticText( previewPanel, wxID_ANY, wxT("FPSVALUE"), wxDefaultPosition, wxDefaultSize, 0 );
	eFpsValue->Wrap( -1 );
	gSizer5->Add( eFpsValue, 0, wxALL, 5 );
	
	cbFPSLimiter = new wxCheckBox( previewPanel, wxID_ANY, wxT("FPS Limiter"), wxDefaultPosition, wxDefaultSize, 0 );
	cbFPSLimiter->SetValue(true); 
	gSizer5->Add( cbFPSLimiter, 0, wxALL, 5 );
	
	cbAnimatedHorse = new wxCheckBox( previewPanel, wxID_ANY, wxT("Draw Animated Horse"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer5->Add( cbAnimatedHorse, 0, wxALL, 5 );
	
	m_loadDemo = new wxButton( previewPanel, wxID_ANY, wxT("Load"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer5->Add( m_loadDemo, 0, wxALL, 5 );
	
	m_saveDemo = new wxButton( previewPanel, wxID_ANY, wxT("Save"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer5->Add( m_saveDemo, 0, wxALL, 5 );
	
	cbFullscreenImage1 = new wxCheckBox( previewPanel, wxID_ANY, wxT("Draw Fullscreen Image"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer5->Add( cbFullscreenImage1, 0, wxALL, 5 );
	
	
	bSizer40->Add( gSizer5, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer401;
	bSizer401 = new wxBoxSizer( wxVERTICAL );
	
	m_dirPickerSkybox = new wxDirPickerCtrl( previewPanel, wxID_ANY, wxEmptyString, wxT("Select a folder"), wxDefaultPosition, wxDefaultSize, wxDIRP_DEFAULT_STYLE );
	bSizer401->Add( m_dirPickerSkybox, 0, wxALL, 5 );
	
	
	bSizer40->Add( bSizer401, 1, wxEXPAND, 5 );
	
	
	previewPanel->SetSizer( bSizer40 );
	previewPanel->Layout();
	bSizer40->Fit( previewPanel );
	gSizer3->Add( previewPanel, 1, wxEXPAND | wxALL, 5 );
	
	wxBoxSizer* bSizer48;
	bSizer48 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer49;
	bSizer49 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText18 = new wxStaticText( this, wxID_ANY, wxT("Scene:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText18->Wrap( -1 );
	bSizer49->Add( m_staticText18, 0, wxALL, 5 );
	
	wxArrayString m_choiceSceneChoices;
	m_choiceScene = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceSceneChoices, 0 );
	m_choiceScene->SetSelection( 0 );
	bSizer49->Add( m_choiceScene, 1, wxALL, 5 );
	
	
	bSizer48->Add( bSizer49, 0, wxALIGN_TOP|wxEXPAND|wxTOP|wxRIGHT|wxLEFT, 2 );
	
	m_SceneTree = new wxTreeCtrl( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTR_DEFAULT_STYLE );
	m_menuSceneGraph = new wxMenu();
	wxMenuItem* m_menuItemDeleteNode;
	m_menuItemDeleteNode = new wxMenuItem( m_menuSceneGraph, wxID_ANY, wxString( wxT("Delete Node") ) , wxEmptyString, wxITEM_NORMAL );
	m_menuSceneGraph->Append( m_menuItemDeleteNode );
	
	wxMenuItem* m_menuItemAddNode;
	m_menuItemAddNode = new wxMenuItem( m_menuSceneGraph, wxID_ANY, wxString( wxT("AddNode") ) , wxEmptyString, wxITEM_NORMAL );
	m_menuSceneGraph->Append( m_menuItemAddNode );
	
	wxMenuItem* m_menuItem11;
	m_menuItem11 = new wxMenuItem( m_menuSceneGraph, wxID_ANY, wxString( wxT("MyMenuItem") ) , wxEmptyString, wxITEM_NORMAL );
	m_menuSceneGraph->Append( m_menuItem11 );
	
	m_SceneTree->Connect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( fMainEditor::m_SceneTreeOnContextMenu ), NULL, this ); 
	
	bSizer48->Add( m_SceneTree, 1, wxALL|wxEXPAND, 5 );
	
	
	gSizer3->Add( bSizer48, 1, wxEXPAND, 5 );
	
	
	bSizer9->Add( gSizer3, 1, wxEXPAND, 5 );
	
	notebook = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	pLayers = new wxPanel( notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxVERTICAL );
	
	m_listCtrl4 = new wxListCtrl( pLayers, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_ICON );
	bSizer10->Add( m_listCtrl4, 1, wxALL|wxEXPAND, 5 );
	
	
	pLayers->SetSizer( bSizer10 );
	pLayers->Layout();
	bSizer10->Fit( pLayers );
	notebook->AddPage( pLayers, wxT("Layer"), false );
	mCurves = new wxPanel( notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer29;
	bSizer29 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer30;
	bSizer30 = new wxBoxSizer( wxHORIZONTAL );
	
	m_listCtrl3 = new wxListCtrl( mCurves, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_ICON );
	bSizer30->Add( m_listCtrl3, 0, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer41;
	bSizer41 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer42;
	bSizer42 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText16 = new wxStaticText( mCurves, wxID_ANY, wxT("Zoom"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText16->Wrap( -1 );
	bSizer42->Add( m_staticText16, 0, wxALL, 5 );
	
	m_sliderZoomCurvesX = new wxSlider( mCurves, wxID_ANY, 100, 25, 700, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizer42->Add( m_sliderZoomCurvesX, 1, wxALL, 5 );
	
	
	bSizer41->Add( bSizer42, 0, wxEXPAND, 5 );
	
	m_Timeline = new wxTimeline(mCurves, wxID_ANY, wxT("Test"));
	bSizer41->Add( m_Timeline, 1, wxALL|wxEXPAND, 5 );
	
	
	bSizer30->Add( bSizer41, 1, wxEXPAND, 5 );
	
	m_sliderZoomCurvesY = new wxSlider( mCurves, wxID_ANY, 100, 25, 700, wxDefaultPosition, wxDefaultSize, wxSL_VERTICAL );
	bSizer30->Add( m_sliderZoomCurvesY, 0, wxALL|wxEXPAND, 5 );
	
	
	bSizer29->Add( bSizer30, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer31;
	bSizer31 = new wxBoxSizer( wxHORIZONTAL );
	
	bNewCurve = new wxButton( mCurves, wxID_ANY, wxT("New Curve"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer31->Add( bNewCurve, 0, wxALL, 5 );
	
	bLoadCurve = new wxButton( mCurves, wxID_ANY, wxT("Load Curve"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer31->Add( bLoadCurve, 0, wxALL, 5 );
	
	bSaveCurve = new wxButton( mCurves, wxID_ANY, wxT("Save Curve"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer31->Add( bSaveCurve, 0, wxALL, 5 );
	
	
	bSizer29->Add( bSizer31, 0, wxEXPAND, 5 );
	
	
	mCurves->SetSizer( bSizer29 );
	mCurves->Layout();
	bSizer29->Fit( mCurves );
	notebook->AddPage( mCurves, wxT("Curves"), false );
	pPostProcessing = new wxPanel( notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer12;
	bSizer12 = new wxBoxSizer( wxVERTICAL );
	
	wxGridSizer* gSizer4;
	gSizer4 = new wxGridSizer( 3, 3, 0, 0 );
	
	
	bSizer12->Add( gSizer4, 1, wxEXPAND, 5 );
	
	
	pPostProcessing->SetSizer( bSizer12 );
	pPostProcessing->Layout();
	bSizer12->Fit( pPostProcessing );
	notebook->AddPage( pPostProcessing, wxT("PostProcessing"), true );
	m_panel10 = new wxPanel( notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer16;
	bSizer16 = new wxBoxSizer( wxHORIZONTAL );
	
	listTextures = new wxListCtrl( m_panel10, wxID_ANY, wxDefaultPosition, wxSize( 700,-1 ), wxLC_ICON|wxLC_VRULES );
	bSizer16->Add( listTextures, 0, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer17;
	bSizer17 = new wxBoxSizer( wxVERTICAL );
	
	bLoadTexture = new wxButton( m_panel10, wxID_ANY, wxT("Load Texture"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer17->Add( bLoadTexture, 0, wxALL, 5 );
	
	m_staticline2 = new wxStaticLine( m_panel10, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer17->Add( m_staticline2, 0, wxEXPAND | wxALL, 5 );
	
	bTextureFirst = new wxButton( m_panel10, wxID_ANY, wxT("First"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer17->Add( bTextureFirst, 0, wxALL, 5 );
	
	bTextureUp
	= new wxButton( m_panel10, wxID_ANY, wxT("Up"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer17->Add( bTextureUp
	, 0, wxALL, 5 );
	
	bTextureDown = new wxButton( m_panel10, wxID_ANY, wxT("Down"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer17->Add( bTextureDown, 0, wxALL, 5 );
	
	bTextureLast = new wxButton( m_panel10, wxID_ANY, wxT("Last"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer17->Add( bTextureLast, 0, wxALL, 5 );
	
	m_staticline1 = new wxStaticLine( m_panel10, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer17->Add( m_staticline1, 0, wxEXPAND | wxALL, 5 );
	
	mTextureDelete = new wxButton( m_panel10, wxID_ANY, wxT("Delete Texture"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer17->Add( mTextureDelete, 0, wxALL, 5 );
	
	
	bSizer16->Add( bSizer17, 1, wxEXPAND, 5 );
	
	
	m_panel10->SetSizer( bSizer16 );
	m_panel10->Layout();
	bSizer16->Fit( m_panel10 );
	notebook->AddPage( m_panel10, wxT("Textures"), false );
	m_panel28 = new wxPanel( notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer32;
	bSizer32 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer33;
	bSizer33 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer34;
	bSizer34 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText8 = new wxStaticText( m_panel28, wxID_ANY, wxT("Pos"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText8->Wrap( -1 );
	bSizer34->Add( m_staticText8, 0, wxALL, 5 );
	
	m_staticText9 = new wxStaticText( m_panel28, wxID_ANY, wxT("x"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText9->Wrap( -1 );
	bSizer34->Add( m_staticText9, 0, wxALL, 5 );
	
	mLightPosX = new wxTextCtrl( m_panel28, wxID_ANY, wxT("5"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer34->Add( mLightPosX, 0, wxALL, 5 );
	
	m_staticText10 = new wxStaticText( m_panel28, wxID_ANY, wxT("y"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText10->Wrap( -1 );
	bSizer34->Add( m_staticText10, 0, wxALL, 5 );
	
	mLightPosY = new wxTextCtrl( m_panel28, wxID_ANY, wxT("5"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer34->Add( mLightPosY, 0, wxALL, 5 );
	
	m_staticText11 = new wxStaticText( m_panel28, wxID_ANY, wxT("z"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText11->Wrap( -1 );
	bSizer34->Add( m_staticText11, 0, wxALL, 5 );
	
	mLightPosZ = new wxTextCtrl( m_panel28, wxID_ANY, wxT("5"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer34->Add( mLightPosZ, 0, wxALL, 5 );
	
	
	bSizer33->Add( bSizer34, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer36;
	bSizer36 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText12 = new wxStaticText( m_panel28, wxID_ANY, wxT("Size"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText12->Wrap( -1 );
	bSizer36->Add( m_staticText12, 0, wxALL, 5 );
	
	eLightSize = new wxTextCtrl( m_panel28, wxID_ANY, wxT("1"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer36->Add( eLightSize, 0, wxALL, 5 );
	
	m_staticText121 = new wxStaticText( m_panel28, wxID_ANY, wxT("Color"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText121->Wrap( -1 );
	bSizer36->Add( m_staticText121, 0, wxALL, 5 );
	
	colourPickerLight = new wxColourPickerCtrl( m_panel28, wxID_ANY, wxColour( 255, 255, 255 ), wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE );
	bSizer36->Add( colourPickerLight, 0, wxALL, 5 );
	
	
	bSizer33->Add( bSizer36, 1, wxEXPAND, 5 );
	
	
	bSizer32->Add( bSizer33, 1, wxEXPAND, 5 );
	
	
	m_panel28->SetSizer( bSizer32 );
	m_panel28->Layout();
	bSizer32->Fit( m_panel28 );
	notebook->AddPage( m_panel28, wxT("Light"), false );
	m_panel21 = new wxPanel( notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer341;
	bSizer341 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer35;
	bSizer35 = new wxBoxSizer( wxVERTICAL );
	
	mLoadModel = new wxButton( m_panel21, wxID_ANY, wxT("Load Model"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer35->Add( mLoadModel, 0, wxALL, 5 );
	
	mDeleteModel = new wxButton( m_panel21, wxID_ANY, wxT("Delete"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer35->Add( mDeleteModel, 0, wxALL, 5 );
	
	listModels = new wxListCtrl( m_panel21, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_ICON );
	bSizer35->Add( listModels, 1, wxALL|wxEXPAND, 5 );
	
	
	bSizer341->Add( bSizer35, 1, wxEXPAND, 5 );
	
	
	m_panel21->SetSizer( bSizer341 );
	m_panel21->Layout();
	bSizer341->Fit( m_panel21 );
	notebook->AddPage( m_panel21, wxT("Models"), false );
	m_panel22 = new wxPanel( notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer37;
	bSizer37 = new wxBoxSizer( wxHORIZONTAL );
	
	m_richText5 = new wxRichTextCtrl( m_panel22, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0|wxVSCROLL|wxHSCROLL|wxNO_BORDER|wxWANTS_CHARS );
	bSizer37->Add( m_richText5, 1, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer38;
	bSizer38 = new wxBoxSizer( wxVERTICAL );
	
	buttonLuaCompile = new wxButton( m_panel22, wxID_ANY, wxT("Compile"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer38->Add( buttonLuaCompile, 0, wxALL, 5 );
	
	m_button16 = new wxButton( m_panel22, wxID_ANY, wxT("MyButton"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer38->Add( m_button16, 0, wxALL, 5 );
	
	
	bSizer37->Add( bSizer38, 0, 0, 5 );
	
	
	m_panel22->SetSizer( bSizer37 );
	m_panel22->Layout();
	bSizer37->Fit( m_panel22 );
	notebook->AddPage( m_panel22, wxT("LUA Scripts"), false );
	
	bSizer9->Add( notebook, 1, wxEXPAND | wxALL, 5 );
	
	
	this->SetSizer( bSizer9 );
	this->Layout();
	m_menubar1 = new wxMenuBar( 0 );
	ressources = new wxMenu();
	wxMenuItem* load;
	load = new wxMenuItem( ressources, ID_LOAD, wxString( wxT("Load") ) , wxEmptyString, wxITEM_NORMAL );
	ressources->Append( load );
	
	m_menubar1->Append( ressources, wxT("Ressources") ); 
	
	lighting = new wxMenu();
	wxMenuItem* phongEditor;
	phongEditor = new wxMenuItem( lighting, ID_PHONG_EDITOR, wxString( wxT("Phong Editor") ) , wxEmptyString, wxITEM_NORMAL );
	lighting->Append( phongEditor );
	
	m_menubar1->Append( lighting, wxT("Lighting") ); 
	
	shader = new wxMenu();
	wxMenuItem* showEditor;
	showEditor = new wxMenuItem( shader, ID_SHOW_EDITOR, wxString( wxT("Show Editor") ) , wxEmptyString, wxITEM_NORMAL );
	shader->Append( showEditor );
	
	m_menubar1->Append( shader, wxT("Shader") ); 
	
	this->SetMenuBar( m_menubar1 );
	
	m_statusBar1 = this->CreateStatusBar( 1, wxST_SIZEGRIP, wxID_ANY );
	
	// Connect Events
	m_loadDemo->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fMainEditor::OnLoadDemoClick ), NULL, this );
	m_saveDemo->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fMainEditor::OnSaveDemoClick ), NULL, this );
	m_dirPickerSkybox->Connect( wxEVT_COMMAND_DIRPICKER_CHANGED, wxFileDirPickerEventHandler( fMainEditor::OnSkyboxDirChanged ), NULL, this );
	m_choiceScene->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( fMainEditor::OnSceneSelectionChoice ), NULL, this );
	m_SceneTree->Connect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( fMainEditor::OnSceneGraphTreeRightDown ), NULL, this );
	mCurves->Connect( wxEVT_LEFT_DOWN, wxMouseEventHandler( fMainEditor::OnCurveEditorLeftDown ), NULL, this );
	m_sliderZoomCurvesX->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( fMainEditor::OnScrollZoomCurvesX ), NULL, this );
	m_sliderZoomCurvesX->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( fMainEditor::OnScrollZoomCurvesX ), NULL, this );
	m_sliderZoomCurvesX->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( fMainEditor::OnScrollZoomCurvesX ), NULL, this );
	m_sliderZoomCurvesX->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( fMainEditor::OnScrollZoomCurvesX ), NULL, this );
	m_sliderZoomCurvesX->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( fMainEditor::OnScrollZoomCurvesX ), NULL, this );
	m_sliderZoomCurvesX->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( fMainEditor::OnScrollZoomCurvesX ), NULL, this );
	m_sliderZoomCurvesX->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( fMainEditor::OnScrollZoomCurvesX ), NULL, this );
	m_sliderZoomCurvesX->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( fMainEditor::OnScrollZoomCurvesX ), NULL, this );
	m_sliderZoomCurvesX->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( fMainEditor::OnScrollZoomCurvesX ), NULL, this );
	m_sliderZoomCurvesY->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( fMainEditor::OnScrollZoomCurvesY ), NULL, this );
	m_sliderZoomCurvesY->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( fMainEditor::OnScrollZoomCurvesY ), NULL, this );
	m_sliderZoomCurvesY->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( fMainEditor::OnScrollZoomCurvesY ), NULL, this );
	m_sliderZoomCurvesY->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( fMainEditor::OnScrollZoomCurvesY ), NULL, this );
	m_sliderZoomCurvesY->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( fMainEditor::OnScrollZoomCurvesY ), NULL, this );
	m_sliderZoomCurvesY->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( fMainEditor::OnScrollZoomCurvesY ), NULL, this );
	m_sliderZoomCurvesY->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( fMainEditor::OnScrollZoomCurvesY ), NULL, this );
	m_sliderZoomCurvesY->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( fMainEditor::OnScrollZoomCurvesY ), NULL, this );
	m_sliderZoomCurvesY->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( fMainEditor::OnScrollZoomCurvesY ), NULL, this );
	bNewCurve->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fMainEditor::OnNewCurveClick ), NULL, this );
	bLoadCurve->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fMainEditor::OnLoadCurveClick ), NULL, this );
	bSaveCurve->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fMainEditor::OnSaveCurveClick ), NULL, this );
	bLoadTexture->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fMainEditor::OnLoadTextureClick ), NULL, this );
	bTextureFirst->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fMainEditor::OnFirstTextureClick ), NULL, this );
	bTextureUp
	->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fMainEditor::OnUpTextureClick ), NULL, this );
	bTextureDown->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fMainEditor::OnDownTextureClick ), NULL, this );
	bTextureLast->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fMainEditor::OnLastTextureClick ), NULL, this );
	mTextureDelete->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fMainEditor::OnDeleteTextureClick ), NULL, this );
	mLoadModel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fMainEditor::OnLoadModelClick ), NULL, this );
	mDeleteModel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fMainEditor::OnDeleteModelClick ), NULL, this );
	this->Connect( load->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( fMainEditor::OnMenuLoadRessources ) );
	this->Connect( phongEditor->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( fMainEditor::onMenuPhongEditor ) );
	this->Connect( showEditor->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( fMainEditor::OnMenuShaderEditor ) );
}

fMainEditor::~fMainEditor()
{
	// Disconnect Events
	m_loadDemo->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fMainEditor::OnLoadDemoClick ), NULL, this );
	m_saveDemo->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fMainEditor::OnSaveDemoClick ), NULL, this );
	m_dirPickerSkybox->Disconnect( wxEVT_COMMAND_DIRPICKER_CHANGED, wxFileDirPickerEventHandler( fMainEditor::OnSkyboxDirChanged ), NULL, this );
	m_choiceScene->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( fMainEditor::OnSceneSelectionChoice ), NULL, this );
	m_SceneTree->Disconnect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( fMainEditor::OnSceneGraphTreeRightDown ), NULL, this );
	mCurves->Disconnect( wxEVT_LEFT_DOWN, wxMouseEventHandler( fMainEditor::OnCurveEditorLeftDown ), NULL, this );
	m_sliderZoomCurvesX->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( fMainEditor::OnScrollZoomCurvesX ), NULL, this );
	m_sliderZoomCurvesX->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( fMainEditor::OnScrollZoomCurvesX ), NULL, this );
	m_sliderZoomCurvesX->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( fMainEditor::OnScrollZoomCurvesX ), NULL, this );
	m_sliderZoomCurvesX->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( fMainEditor::OnScrollZoomCurvesX ), NULL, this );
	m_sliderZoomCurvesX->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( fMainEditor::OnScrollZoomCurvesX ), NULL, this );
	m_sliderZoomCurvesX->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( fMainEditor::OnScrollZoomCurvesX ), NULL, this );
	m_sliderZoomCurvesX->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( fMainEditor::OnScrollZoomCurvesX ), NULL, this );
	m_sliderZoomCurvesX->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( fMainEditor::OnScrollZoomCurvesX ), NULL, this );
	m_sliderZoomCurvesX->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( fMainEditor::OnScrollZoomCurvesX ), NULL, this );
	m_sliderZoomCurvesY->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( fMainEditor::OnScrollZoomCurvesY ), NULL, this );
	m_sliderZoomCurvesY->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( fMainEditor::OnScrollZoomCurvesY ), NULL, this );
	m_sliderZoomCurvesY->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( fMainEditor::OnScrollZoomCurvesY ), NULL, this );
	m_sliderZoomCurvesY->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( fMainEditor::OnScrollZoomCurvesY ), NULL, this );
	m_sliderZoomCurvesY->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( fMainEditor::OnScrollZoomCurvesY ), NULL, this );
	m_sliderZoomCurvesY->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( fMainEditor::OnScrollZoomCurvesY ), NULL, this );
	m_sliderZoomCurvesY->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( fMainEditor::OnScrollZoomCurvesY ), NULL, this );
	m_sliderZoomCurvesY->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( fMainEditor::OnScrollZoomCurvesY ), NULL, this );
	m_sliderZoomCurvesY->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( fMainEditor::OnScrollZoomCurvesY ), NULL, this );
	bNewCurve->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fMainEditor::OnNewCurveClick ), NULL, this );
	bLoadCurve->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fMainEditor::OnLoadCurveClick ), NULL, this );
	bSaveCurve->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fMainEditor::OnSaveCurveClick ), NULL, this );
	bLoadTexture->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fMainEditor::OnLoadTextureClick ), NULL, this );
	bTextureFirst->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fMainEditor::OnFirstTextureClick ), NULL, this );
	bTextureUp
	->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fMainEditor::OnUpTextureClick ), NULL, this );
	bTextureDown->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fMainEditor::OnDownTextureClick ), NULL, this );
	bTextureLast->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fMainEditor::OnLastTextureClick ), NULL, this );
	mTextureDelete->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fMainEditor::OnDeleteTextureClick ), NULL, this );
	mLoadModel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fMainEditor::OnLoadModelClick ), NULL, this );
	mDeleteModel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fMainEditor::OnDeleteModelClick ), NULL, this );
	this->Disconnect( ID_LOAD, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( fMainEditor::OnMenuLoadRessources ) );
	this->Disconnect( ID_PHONG_EDITOR, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( fMainEditor::onMenuPhongEditor ) );
	this->Disconnect( ID_SHOW_EDITOR, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( fMainEditor::OnMenuShaderEditor ) );
	
	delete m_menuSceneGraph; 
}
