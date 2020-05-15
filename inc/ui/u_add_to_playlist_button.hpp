#pragma once /// UI ADD TO PLAYLIST BUTTON

#include "u_png_color_button.hpp"
#include "c_add_music_to_playlist.hpp"

class AddToPlaylistButton : public PngColorButton
{
private:
    SharedPtr<PPlaylist> pl_ptr_;

public:
    AddToPlaylistButton(SharedPtr<PPlaylist> ptr, int letters);

    void SetPlaylist(SharedPtr<PPlaylist> ptr);

    void Update(int ofx, int ofy) override;
};