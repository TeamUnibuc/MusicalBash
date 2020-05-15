#include "u_open_folder_button.hpp"

OpenFolderButton::OpenFolderButton(SharedPtr<PAlbum> ptr) : 
    PngColorButton(43, 31, nullptr,
                   sf::Color::White, Constants::kGreen,
                   std::make_shared<PngSprite>("data/img/open_folder_icon.png")),
    album_(ptr)
{
    SetPosition({775, 12});
}

void OpenFolderButton::SetAlbum(SharedPtr<PAlbum> ptr)
{
    album_ = ptr;
}

void OpenFolderButton::Update(int ofx, int ofy)
{
    if (ThisButtonClicked(ofx, ofy)){
        if (not album_)
            throw null_pointer("Trying to run instantiate and run COpenFolder command with null pointer to album");
        
        COpenFolder addCommand(album_->GetName());
        addCommand.Execute();
    }
}