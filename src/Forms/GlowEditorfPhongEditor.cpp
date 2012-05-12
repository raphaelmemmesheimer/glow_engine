#include "GlowEditorfPhongEditor.h"

GlowEditorfPhongEditor::GlowEditorfPhongEditor( wxWindow* parent )
:
fPhongEditor( parent )
{

}

void GlowEditorfPhongEditor::OnIdle( wxIdleEvent& event )
{
	// TODO: Implement OnIdle
}

void GlowEditorfPhongEditor::OnScrollAmbient( wxScrollEvent& event )
{
	colourPickerAmbient->SetColour(wxColour(sliderColorAmbientRed->GetValue(),sliderColorAmbientGreen->GetValue(),sliderColorAmbientBlue->GetValue()));
}

void GlowEditorfPhongEditor::OnScrollDiffuse( wxScrollEvent& event )
{
	colourPickerDiffuse->SetColour(wxColour(sliderColorRed->GetValue(),sliderColorGreen->GetValue(),sliderColorBlue->GetValue()));
}

void GlowEditorfPhongEditor::OnScrollSpecular( wxScrollEvent& event )
{
	colourPickerSpecular->SetColour(wxColour(sliderColorSpecularRed->GetValue(),sliderColorSpecularGreen->GetValue(),sliderColorSpecularBlue->GetValue()));
}

void GlowEditorfPhongEditor::OnAmbientColorChanged( wxColourPickerEvent& event )
{
	sliderColorAmbientRed->SetValue(colourPickerAmbient->GetColour().Red());
	sliderColorAmbientGreen->SetValue(colourPickerAmbient->GetColour().Green());
	sliderColorAmbientBlue->SetValue(colourPickerAmbient->GetColour().Blue());
}

void GlowEditorfPhongEditor::OnDiffuseColorChanged( wxColourPickerEvent& event )
{
	sliderColorRed->SetValue(colourPickerDiffuse->GetColour().Red());
	sliderColorGreen->SetValue(colourPickerDiffuse->GetColour().Green());
	sliderColorBlue->SetValue(colourPickerDiffuse->GetColour().Blue());
}

void GlowEditorfPhongEditor::OnSpecularColorChanged( wxColourPickerEvent& event )
{
	sliderColorSpecularRed->SetValue(colourPickerSpecular->GetColour().Red());
	sliderColorSpecularGreen->SetValue(colourPickerSpecular->GetColour().Green());
	sliderColorSpecularBlue->SetValue(colourPickerSpecular->GetColour().Blue());
}
