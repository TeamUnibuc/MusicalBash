#include "u_playlist_entry.hpp"

PlaylistEntry::PlaylistEntry(SharedPtr<PPlaylist> pl_ptr, int number) :
    pl_ptr_(pl_ptr),
    sprite_del_btn_("data/img/red_cross.png"),
    col_btn_(kColBtnSize.first, kColBtnSize.second, 
             std::make_unique<CShowSpecificPlaylist>(pl_ptr), 
             sf::Color::Transparent, Constants::kSideBtnHover),
    del_btn_(kDelBtnSize.first, kDelBtnSize.second,
             std::make_unique<CDeletePlaylist>(pl_ptr), 
             sf::Color::Transparent, Constants::kSideBtnHover),
    number_(number)
{
    sprite_del_btn_.SetPosition(kDelBtnPos.first + kSpriteOffset, kDelBtnPos.second + kSpriteOffset);
    sprite_del_btn_.SetSize(kDelBtnSize.first - kSpriteOffset * 2, kDelBtnSize.second - kSpriteOffset * 2);

    col_btn_.SetPosition(kColBtnPos);

    del_btn_.SetPosition(kDelBtnPos);
}

void PlaylistEntry::Update(int off_x, int off_y)
{
    sprite_del_btn_.Update(off_x + pos_x, off_y + pos_y);
    col_btn_.Update(off_x + pos_x, off_y + pos_y);
    del_btn_.Update(off_x + pos_x, off_y + pos_y);
}

void PlaylistEntry::Render(sf::RenderWindow& rw, int off_x, int off_y)
{
/// The button that changes hover color for when clicking the album
    col_btn_.Render(rw, off_x + pos_x, off_y + pos_y);

    const int off_height = col_btn_.GetPosition().second + 9;
    const int txt_height = col_btn_.GetHeight() * 0.7;
    const int txtLen     = kEntryWidth - 12;

/// Render the number and album name
    TextBox txt_nr(12, off_height, 30, txt_height,
                   0, std::to_string(number_));
    txt_nr.SetColor(Constants::kGreen);

    TextBox playlist_name(30, off_height, txtLen, txt_height, 
                      0, pl_ptr_->GetName());

    TextBox underline(30, off_height + 10, txtLen, txt_height, 
                      0, std::string(playlist_name.GetText().size(), '_'));

    if (not col_btn_.ThisButtonHovered(off_x, off_y))
        underline.Render(rw, off_x + pos_x, off_y + pos_y);
    
    txt_nr.Render(rw, off_x + pos_x, off_y + pos_y);
    playlist_name.Render(rw, off_x + pos_x, off_y + pos_y);

/// Render the delete button and it's sprite
    del_btn_.Render(rw, off_x + pos_x, off_y + pos_y);
    sprite_del_btn_.Render(rw, off_x + pos_x, off_y + pos_y);
}

int PlaylistEntry::GetHeight() const
{
    return kHeight;
}

int PlaylistEntry::GetWidth()  const
{
    return kEntryWidth + kButtonWidth + kGap;
}