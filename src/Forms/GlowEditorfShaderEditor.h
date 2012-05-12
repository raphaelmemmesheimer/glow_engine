#ifndef __GlowEditorfShaderEditor__
#define __GlowEditorfShaderEditor__

/**
@file
Subclass of fShaderEditor, which is generated by wxFormBuilder.
*/

#include "Editors.h"
#include "../System/Shader.h"
#include <vector>
#include "../System/ShaderManager.h"

/** Implementing fShaderEditor */
class GlowEditorfShaderEditor : public fShaderEditor
{

friend class ShaderManager;
private:
    Shader *shader;
    ShaderManager shaderManager;

    std::string glslKeyWords;

    //std::vector<Shader*> shaderList;
protected:
    // Handlers for fShaderEditor events.
    void OnCompileClick(wxCommandEvent & event);
    void OnFragmentFileChanged(wxCommandEvent & event);
    void OnVertexFileChanged(wxCommandEvent & event);
    void OnButtonFragmentLoad(wxCommandEvent & event);
    void OnButtonVertexLoad(wxCommandEvent & event);
    void OnButtonFragmentSave(wxCommandEvent & event);
    void OnButtonGeometryLoad(wxCommandEvent & event);
    void OnButtonGeometrySave(wxCommandEvent & event);
    void OnButtonTessellationControlLoad(wxCommandEvent & event);
    void OnButtonTessellationControlSave(wxCommandEvent & event);
    void OnButtonTessellationEvaluationLoad(wxCommandEvent & event);
	void OnButtonTessellationEvaluationSave(wxCommandEvent & event);
    void OnButtonVertexSave(wxCommandEvent & event);
    void OnChoiceShader(wxCommandEvent & event);
    void OnLogLeftDClick(wxMouseEvent & event);

    void ShaderManagerOnAddShader(Shader* shader);

    void OnEditorKeyDown(wxKeyEvent& event);
    //void OnLogLeftDown(wxCommandEvent & event);

public:
    /** Constructor */
    GlowEditorfShaderEditor(wxWindow *parent);
    Shader *getShader() const;
    void setShader(Shader *shader);
    std::vector<Shader*> getShaderList() const;
    void setShaderList(std::vector<Shader*> shaderList);
    ShaderManager getShaderManager() const;
    void setShaderManager(ShaderManager shaderManager);
    void refreshShaderList();
};

#endif // __GlowEditorfShaderEditor__