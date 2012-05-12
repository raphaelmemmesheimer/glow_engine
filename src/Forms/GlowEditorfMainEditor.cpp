#include "GlowEditorfMainEditor.h"
#include "GlowEditorfPostProcessEditor.h"
//#include "../System/Engine.h"

std::vector<Texture*> GlowEditorfMainEditor::getTextures() const
{
    return textures;
}

std::vector<Mesh*> GlowEditorfMainEditor::getModels() const
{
    return models;
}

GlowEditorfPhongEditor *GlowEditorfMainEditor::getPhongEditor() const
{
    return fPhongEditor;
}

GlowEditorfPostProcessEditor *GlowEditorfMainEditor::getPostProcessEditor() const
{
    return fPostProcessEditor;
}

GlowEditorfShaderEditor *GlowEditorfMainEditor::getShaderEditor() const
{
    return fShaderEditor;
}

void GlowEditorfMainEditor::setModels(std::vector<Mesh*> models)
{
    this->models = models;
}

void GlowEditorfMainEditor::setTextures(std::vector<Texture*> textures)
{
    this->textures = textures;
}

GlowEditorfMainEditor::GlowEditorfMainEditor( wxWindow* parent )
:
fMainEditor( parent )
{
	fPhongEditor = new GlowEditorfPhongEditor(0L);
	fShaderEditor = new GlowEditorfShaderEditor(0L);
	fPostProcessEditor = new GlowEditorfPostProcessEditor(0L);

}

void GlowEditorfMainEditor::OnMenuLoadRessources( wxCommandEvent& event )
{
	// TODO: Implement OnMenuLoadRessources
}

void GlowEditorfMainEditor::onMenuPhongEditor( wxCommandEvent& event )
{
	//fPhongEditor = new GlowEditorfPhongEditor(0L);
	if (fPhongEditor)
		fPhongEditor->Show(true);
	//else


}

void GlowEditorfMainEditor::OnMenuShaderEditor( wxCommandEvent& event )
{
	if (fShaderEditor)
		fShaderEditor->Show(true);
}

void GlowEditorfMainEditor::OnLoadTextureClick(wxCommandEvent& event )
{
	wxString wildcards = _T("All files (*.*)|*.*");
    wxFileDialog dialog(this, _T("Load Textures"),
                        wxEmptyString, wxEmptyString, wildcards,
                        wxFD_OPEN|wxFD_MULTIPLE);

    if (dialog.ShowModal() == wxID_OK)
    {
        wxArrayString paths, filenames;

        dialog.GetPaths(paths);
        dialog.GetFilenames(filenames);

        wxString msg, s;
        size_t count = paths.GetCount();
        for ( size_t n = 0; n < count; n++ )
        {
            s.Printf(_T("File %d: %s (%s)\n"),
                     (int)n, paths[n].c_str(), filenames[n].c_str());
            listTextures->InsertItem(n, wxString::Format(_T("%s"), paths[n].c_str()));
            msg += s;

            Texture* texture = new Texture(std::string(paths[n].mb_str(wxConvUTF8)));

            this->textures.push_back(texture);
        }
        s.Printf(_T("Filter index: %d"), dialog.GetFilterIndex());
        msg += s;


//        wxMessageDialog dialog2(this, msg, _T("Selected files"));
//        dialog2.ShowModal();
    }

}


void GlowEditorfMainEditor::OnLoadModelClick(wxCommandEvent& event )
{
	wxString wildcards = _T("All files (*.*)|*.*");
    wxFileDialog dialog(this, _T("Load Textures"),
                        wxEmptyString, wxEmptyString, wildcards,
                        wxFD_OPEN|wxFD_MULTIPLE);

    if (dialog.ShowModal() == wxID_OK)
        {
            wxArrayString paths, filenames;

            dialog.GetPaths(paths);
            dialog.GetFilenames(filenames);

            wxString msg, s;
            size_t count = paths.GetCount();
            for ( size_t n = 0; n < count; n++ )
            {
                s.Printf(_T("File %d: %s (%s)\n"),
                         (int)n, paths[n].c_str(), filenames[n].c_str());
                listModels->InsertItem(n, wxString::Format(_T("%s"), paths[n].c_str()));
				
                msg += s;

                Mesh* model = new CTMModel();
                //textFileRead(std::string(fpVertex->GetPath().mb_str(wxConvUTF8))) 
				model->loadFile(std::string(paths[n].mb_str(wxConvUTF8)));
                this->models.push_back(model);
            }
            s.Printf(_T("Filter index: %d"), dialog.GetFilterIndex());
            msg += s;
        }


}


void GlowEditorfMainEditor::OnDeleteModelClick(wxCommandEvent& event)
{
   //listModels->DeleteItem;
   //this->models.
}

void GlowEditorfMainEditor::OnScrollZoomCurvesX( wxScrollEvent& event )
{
	m_Timeline->setZoomX(m_sliderZoomCurvesX->GetValue());
}

void GlowEditorfMainEditor::OnScrollZoomCurvesY( wxScrollEvent& event )
{
	m_Timeline->setZoomY(m_sliderZoomCurvesY->GetValue());
}

void GlowEditorfMainEditor::OnSkyboxDirChanged ( wxFileDirPickerEvent& event ){
	//event.
	//printf("Skybox changed to : "+event.GetPath() +"\n");
    //skybox->loadTextures((std::string)event.GetPath().c_str()+"/negy.jpg",
            //(std::string)event.GetPath().c_str()+"/posy.jpg",
            //(std::string)event.GetPath().c_str()+"/negz.jpg",
            //(std::string)event.GetPath().c_str()+"/posz.jpg",
            //(std::string)event.GetPath().c_str()+"/negx.jpg",
            //(std::string)event.GetPath().c_str()+"/posx.jpg");

}


void GlowEditorfMainEditor::OnLoadDemoClick(wxCommandEvent& event) {
    
    wxFileDialog* OpenDialog = new wxFileDialog(
		this, _("Choose a file to open"), wxEmptyString, wxEmptyString, 
		_("Glow Demo files (*.glow)|*.glow"),
		wxFD_OPEN, wxDefaultPosition);
 
	// Creates a "open file" dialog with 4 file types
	if (OpenDialog->ShowModal() == wxID_OK) // if the user click "Open" instead of "Cancel"
	{
		//CurrentDocPath = OpenDialog->GetPath(); //change this line 
		// Sets our current document to the file the user selected
		//MainEditBox->LoadFile(CurrentDocPath); //Opens that file
		//dem	OpenDialog->GetFilename()); // Set the Title to reflect the file open
	}
 
	// Clean up after ourselves
	OpenDialog->Destroy();
}

void GlowEditorfMainEditor::OnSaveDemoClick(wxCommandEvent& event) {
    wxFileDialog* OpenDialog = new wxFileDialog(
		this, _("Choose a file to save"), wxEmptyString, wxEmptyString, 
		_("Glow Demo files (*.glow)|*.glow"),
		wxFD_SAVE, wxDefaultPosition);
 
	// Creates a "open file" dialog with 4 file types
	if (OpenDialog->ShowModal() == wxID_OK) // if the user click "Open" instead of "Cancel"
	{
		//CurrentDocPath = OpenDialog->GetPath(); //change this line 
		// Sets our current document to the file the user selected
		//MainEditBox->LoadFile(CurrentDocPath); //Opens that file
		//dem	OpenDialog->GetFilename()); // Set the Title to reflect the file open
	}
 
	// Clean up after ourselves
	OpenDialog->Destroy();
}

void GlowEditorfMainEditor::OnSceneGraphTreeRightDown(wxCommandEvent& event) {
	//m_menuSceneGraph->;
	//PopupMenu(m_menuSceneGraph);
}

void GlowEditorfMainEditor::OnSceneSelectionChoice(wxCommandEvent& event) {	

	//engine->getDemo().getSceneManager()->getActiveScene()->getSceneGraph()->toWxTree(m_SceneTree);
}
