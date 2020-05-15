#pragma once /// UI OPEN FOLDER BUTTON

#include "u_png_color_button.hpp"
#include "c_open_folder.hpp"

class OpenFolderButton : public PngColorButton
{
private:
    SharedPtr<PAlbum> album_;

public:
    OpenFolderButton(SharedPtr<PAlbum> ptr = nullptr);

    void SetAlbum(SharedPtr<PAlbum> ptr);

    void Update(int ofx, int ofy) override;
};