#include "u_add_to_playlist_button.hpp"

AddToPlaylistButton::AddToPlaylistButton(SharedPtr<PPlaylist> ptr, int letters) :
    PngColorButton(35, 35, nullptr,
                   sf::Color::White, Constants::kGreen,
                   std::make_shared<PngSprite>("data/img/add_icon.png")),
    pl_ptr_(ptr)
{ 
    PngColorButton::SetPosition({784, 10});
}

void AddToPlaylistButton::SetPlaylist(SharedPtr<PPlaylist> ptr)
{
    pl_ptr_ = ptr;
}

void AddToPlaylistButton::Update(int off_x, int off_y)
{
    if (ThisButtonClicked(off_x, off_y)){
        CAddMusicToPlaylist addCommand;
        addCommand.Execute(pl_ptr_);
    }
}