#include "GlowEditorfShaderEditor.h"

Shader *GlowEditorfShaderEditor::getShader() const
{
    return shader;
}

void GlowEditorfShaderEditor::OnFragmentFileChanged(wxCommandEvent & event)
{
}

void GlowEditorfShaderEditor::OnVertexFileChanged(wxCommandEvent & event)
{
}

void GlowEditorfShaderEditor::OnButtonFragmentLoad(wxCommandEvent & event)
{
	scFragment->SetText(wxString::FromAscii(textFileRead(std::string(fpFragment->GetPath().mb_str(wxConvUTF8)))));
	//printf("read fragment\n");
}

void GlowEditorfShaderEditor::OnButtonVertexLoad(wxCommandEvent & event)
{
  //textFileRead(std::string(fpVertex->GetPath().mb_str(wxConvUTF8)));
  scVertex->SetText(wxString::FromAscii( textFileRead(std::string(fpVertex->GetPath().mb_str(wxConvUTF8))) ));
}

void GlowEditorfShaderEditor::OnButtonGeometryLoad(wxCommandEvent & event)
{
	scGeometry->SetText(wxString::FromAscii(textFileRead(std::string(fpGeometry->GetPath().mb_str(wxConvUTF8)))));
}

void GlowEditorfShaderEditor::OnButtonTessellationControlLoad(wxCommandEvent & event)
{
    scTessellationControl->SetText(wxString::FromAscii(textFileRead(std::string(fpTessellationControl->GetPath().mb_str(wxConvUTF8)))));
}

void GlowEditorfShaderEditor::OnButtonTessellationEvaluationLoad(wxCommandEvent & event)
{
    scTessellationEvaluation->SetText(wxString::FromAscii(textFileRead(std::string(fpTessellationEvaluation->GetPath().mb_str(wxConvUTF8)))));
}

void GlowEditorfShaderEditor::OnButtonFragmentSave(wxCommandEvent & event)
{
    textFileWrite(std::string(fpFragment->GetPath().mb_str(wxConvUTF8)),std::string(scFragment->GetText().mb_str(wxConvUTF8)));
}

void GlowEditorfShaderEditor::OnButtonVertexSave(wxCommandEvent & event)
{
    textFileWrite(std::string(fpVertex->GetPath().mb_str(wxConvUTF8)),std::string(scVertex->GetText().mb_str(wxConvUTF8)));
}

void GlowEditorfShaderEditor::OnButtonGeometrySave(wxCommandEvent & event)
{
    textFileWrite(std::string(fpGeometry->GetPath().mb_str(wxConvUTF8)),std::string(scGeometry->GetText().mb_str(wxConvUTF8)));
}

void GlowEditorfShaderEditor::OnButtonTessellationControlSave(wxCommandEvent & event)
{
    textFileWrite(std::string(fpTessellationControl->GetPath().mb_str(wxConvUTF8)),std::string(scTessellationControl->GetText().mb_str(wxConvUTF8)));
}

void GlowEditorfShaderEditor::OnButtonTessellationEvaluationSave(wxCommandEvent & event)
{
    textFileWrite(std::string(fpTessellationEvaluation->GetPath().mb_str(wxConvUTF8)),std::string(scTessellationEvaluation->GetText().mb_str(wxConvUTF8)));
}


ShaderManager GlowEditorfShaderEditor::getShaderManager() const
{
    return shaderManager;
}

void GlowEditorfShaderEditor::setShaderManager(ShaderManager shaderManager)
{
    this->shaderManager = shaderManager;
    for (unsigned int i = 0; i < shaderManager.getShaders().size(); ++i) {
        choiceShaders->Append(wxString::FromAscii(shaderManager[i]->getName().c_str()));
    }

}

void GlowEditorfShaderEditor::setShader(Shader *shader)
{
    this->shader = shader;
    scFragment->SetText(wxString::FromAscii(shader->getFsText().c_str()));
    scVertex->SetText(wxString::FromAscii(shader->getVsText().c_str()));
    scGeometry->SetText(wxString::FromAscii(shader->getGsText().c_str()));
    scTessellationControl->SetText(wxString::FromAscii(shader->getTcsText().c_str()));
    scTessellationEvaluation->SetText(wxString::FromAscii(shader->getTesText().c_str()));
}

GlowEditorfShaderEditor::GlowEditorfShaderEditor( wxWindow* parent )
:
fShaderEditor( parent )
{
	glslKeyWords = 	"centroid patch flat smooth noperspective sample break continue do for while if switch case default else subroutine in out inout"
				 	" float double int void bool true false invariant discard return mat2 mat3 mat4 dmat2 dmat3 dmat4 mat2x2 mat2x3 mat2x4 dmat2x2 dmat2x3 dmat2x4"
					" mat3x2 mat3x3 mat3x4 dmat3x2 dmat3x3 dmat3x4 mat4x2 mat4x3 mat4x4 dmat4x2 dmat4x3 dmat4x4 vec2 vec3 vec4 uint lowp uvec2 ivec2 ivec3 ivec4"
					" uvec3 bvec2 bvec3 bvec4 dvec2 dvec3 dvec4 uvec4 mediump highp precision sampler1D sampler2D sampler3D samplerCube"
					" sampler1DShadow sampler2DShadow samplerCubeShadow sampler1DArray sampler2DArray sampler1DArrayShadow sampler2DArrayShadow"
					" isampler1D isampler2D isampler3D isamplerCube isampler1DArray isampler2DArray	usampler1D usampler2D usampler3D usamplerCube"
					" usampler1DArray usampler2DArray sampler2DRect sampler2DRectShadow isampler2DRect samplerBuffer isamplerBuffer usamplerBuffer"
					" sampler2DMS isampler2DMS usampler2DRect usampler2DMS sampler2DMSArray isampler2DMSArray usampler2DMSArray samplerCubeArray "
					" samplerCubeArrayShadow isamplerCubeArray usamplerCubeArray struct layout location uniform sin tan cos abs"; //source : opengl4 reference

	scFragment->SetLexer(wxSCI_LEX_CPP);
	scVertex->SetLexer(wxSCI_LEX_CPP);
	scGeometry->SetLexer(wxSCI_LEX_CPP);
	scTessellationControl->SetLexer(wxSCI_LEX_CPP);
	scTessellationEvaluation->SetLexer(wxSCI_LEX_CPP);
    scFragment->SetKeyWords(0, wxString::FromAscii(glslKeyWords.c_str()));
    scVertex->SetKeyWords(0, wxString::FromAscii(glslKeyWords.c_str()));
//
    wxFont font( 10, wxMODERN, wxNORMAL, wxNORMAL );
    font.SetFaceName(_("Monospace"));

	//scVertex->StyleSetFont( wxSCI_STYLE_DEFAULT, font );
    //scFragment->StyleSetFont( wxSCI_STYLE_DEFAULT, &font );
    scVertex->StyleSetFontAttr(wxSCI_STYLE_DEFAULT, 10, wxString::FromAscii("Monospace"), false, false, false);
    scFragment->StyleSetFontAttr(wxSCI_STYLE_DEFAULT, 10, wxString::FromAscii("Monospace"), false, false, false);
    scGeometry->StyleSetFontAttr(wxSCI_STYLE_DEFAULT, 10, wxString::FromAscii("Monospace"), false, false, false);
    scTessellationControl->StyleSetFontAttr(wxSCI_STYLE_DEFAULT, 10, wxString::FromAscii("Monospace"), false, false, false);
    scTessellationEvaluation->StyleSetFontAttr(wxSCI_STYLE_DEFAULT, 10, wxString::FromAscii("Monospace"), false, false, false);

	scVertex->StyleClearAll();
	scVertex->StyleSetBold( wxSCI_C_WORD, true );
	scVertex->StyleSetForeground( wxSCI_C_WORD, *wxBLUE );
	scVertex->StyleSetForeground( wxSCI_C_STRING, *wxRED );
	scVertex->StyleSetForeground( wxSCI_C_STRINGEOL, *wxRED );
	scVertex->StyleSetForeground( wxSCI_C_PREPROCESSOR, wxColour( 49, 106, 197 ) );
	scVertex->StyleSetForeground( wxSCI_C_COMMENT, wxColour( 0, 128, 0 ) );
	scVertex->StyleSetForeground( wxSCI_C_COMMENTLINE, wxColour( 0, 128, 0 ) );
	scVertex->StyleSetForeground( wxSCI_C_COMMENTDOC, wxColour( 0, 128, 0 ) );
	scVertex->StyleSetForeground( wxSCI_C_COMMENTLINEDOC, wxColour( 0, 128, 0 ) );
	scVertex->StyleSetForeground( wxSCI_C_NUMBER, *wxBLUE );
	scVertex->SetUseTabs( true );
	scVertex->SetTabWidth( 4 );
	scVertex->SetTabIndents( true );
	scVertex->SetBackSpaceUnIndents( true );
	scVertex->SetIndent( 4 );
	scVertex->SetSelBackground( true, wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHT ) );
	scVertex->SetSelForeground( true, wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHTTEXT ) );
	scVertex->SetCaretWidth( 2 );

	scFragment->StyleClearAll();
	scFragment->StyleSetBold( wxSCI_C_WORD, true );
	scFragment->StyleSetForeground( wxSCI_C_WORD, *wxBLUE );
	scFragment->StyleSetForeground( wxSCI_C_STRING, *wxRED );
	scFragment->StyleSetForeground( wxSCI_C_STRINGEOL, *wxRED );
	scFragment->StyleSetForeground( wxSCI_C_PREPROCESSOR, wxColour( 49, 106, 197 ) );
	scFragment->StyleSetForeground( wxSCI_C_COMMENT, wxColour( 0, 128, 0 ) );
	scFragment->StyleSetForeground( wxSCI_C_COMMENTLINE, wxColour( 0, 128, 0 ) );
	scFragment->StyleSetForeground( wxSCI_C_COMMENTDOC, wxColour( 0, 128, 0 ) );
	scFragment->StyleSetForeground( wxSCI_C_COMMENTLINEDOC, wxColour( 0, 128, 0 ) );
	scFragment->StyleSetForeground( wxSCI_C_NUMBER, *wxBLUE );
	scFragment->SetUseTabs( true );
	scFragment->SetTabWidth( 4 );
	scFragment->SetTabIndents( true );
	scFragment->SetBackSpaceUnIndents( true );
	scFragment->SetIndent( 4 );
	scFragment->SetSelBackground( true, wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHT ) );
	scFragment->SetSelForeground( true, wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHTTEXT ) );
	scFragment->SetCaretWidth( 2 );

	scGeometry->StyleClearAll();
	scGeometry->StyleSetBold( wxSCI_C_WORD, true );
	scGeometry->StyleSetForeground( wxSCI_C_WORD, *wxBLUE );
	scGeometry->StyleSetForeground( wxSCI_C_STRING, *wxRED );
	scGeometry->StyleSetForeground( wxSCI_C_STRINGEOL, *wxRED );
	scGeometry->StyleSetForeground( wxSCI_C_PREPROCESSOR, wxColour( 49, 106, 197 ) );
	scGeometry->StyleSetForeground( wxSCI_C_COMMENT, wxColour( 0, 128, 0 ) );
	scGeometry->StyleSetForeground( wxSCI_C_COMMENTLINE, wxColour( 0, 128, 0 ) );
	scGeometry->StyleSetForeground( wxSCI_C_COMMENTDOC, wxColour( 0, 128, 0 ) );
	scGeometry->StyleSetForeground( wxSCI_C_COMMENTLINEDOC, wxColour( 0, 128, 0 ) );
	scGeometry->StyleSetForeground( wxSCI_C_NUMBER, *wxBLUE );
	scGeometry->SetUseTabs( true );
	scGeometry->SetTabWidth( 4 );
	scGeometry->SetTabIndents( true );
	scGeometry->SetBackSpaceUnIndents( true );
	scGeometry->SetIndent( 4 );
	scGeometry->SetSelBackground( true, wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHT ) );
	scGeometry->SetSelForeground( true, wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHTTEXT ) );
	scGeometry->SetCaretWidth( 2 );


	scFragment->Colourise(0, -1);
	scVertex->Colourise(0, -1);
	scGeometry->Colourise(0, -1);

	scFragment->AutoCompSetIgnoreCase(true);
}

void GlowEditorfShaderEditor::OnCompileClick( wxCommandEvent& event )
{
    scLog->SetText(wxString::FromAscii("")); // Clear Log
    shaderManager[choiceShaders->GetCurrentSelection()]->setShaderSource(std::string(scFragment->GetText().mb_str(wxConvUTF8)),
                                                                         std::string(scVertex->GetText().mb_str(wxConvUTF8)), 
                                                                         std::string(scGeometry->GetText().mb_str(wxConvUTF8)), 
                                                                         std::string(scTessellationControl->GetText().mb_str(wxConvUTF8)), 
                                                                         std::string(scTessellationEvaluation->GetText().mb_str(wxConvUTF8)));//  set new shader source
    shaderManager[choiceShaders->GetCurrentSelection()]->compileAttachLink();
    scLog->SetText(wxString::FromAscii(shaderManager[choiceShaders->GetCurrentSelection()]->getCompileMessage().c_str()));
}

void GlowEditorfShaderEditor::OnChoiceShader(wxCommandEvent & event)
{
    if ((choiceShaders->GetCurrentSelection()) != -1)
            this->setShader(shaderManager[choiceShaders->GetCurrentSelection()]);
    //  this->setShader(shaderList[choiceShaders->GetCurrentSelection()]);
}

void GlowEditorfShaderEditor::OnLogLeftDClick(wxMouseEvent & event)
{
	//printf("%d\n",mLog->GetCaretPosition());
	//mLog->GetLineText(mLog->GetCaretPosition()).c_str()
	scFragment->SetText(scLog->GetCurLine());


	//scFragment->set
}

void GlowEditorfShaderEditor::OnEditorKeyDown(wxKeyEvent& event)
{

	//
}
