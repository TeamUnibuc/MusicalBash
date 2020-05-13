#include "u_song_playlist_entry.hpp"

SongPlaylistEntry::SongPlaylistEntry(SharedPtr<PPlaylist> pl_ptr, SharedPtr<PMusic> ms_ptr, int number) :
    pl_ptr_(pl_ptr), song_ptr_(ms_ptr),
    sprite_del_btn_("data/img/red_cross.png"),
    col_btn_(kColBtnSize.first, kColBtnSize.second, 
             std::make_unique<CAddMusicQueue>(ms_ptr), 
             sf::Color::Transparent, Constants::kSideBtnHover),
    del_btn_(kDelBtnSize.first, kDelBtnSize.second,
             std::make_unique<CDeleteSongFromPlaylist>(ms_ptr, pl_ptr), 
             sf::Color::Transparent, Constants::kSideBtnHover),
    number_(number)
{
    sprite_del_btn_.SetPosition(kDelBtnPos.first + kSpriteOffset, kDelBtnPos.second + kSpriteOffset);
    sprite_del_btn_.SetSize(kDelBtnSize.first - kSpriteOffset * 2, kDelBtnSize.second - kSpriteOffset * 2);

    col_btn_.SetPosition(kColBtnPos);

    del_btn_.SetPosition(kDelBtnPos);
}

void SongPlaylistEntry::Update(int off_x, int off_y)
{
    sprite_del_btn_.Update(off_x + pos_x, off_y + pos_y);
    col_btn_.Update(off_x + pos_x, off_y + pos_y);
    del_btn_.Update(off_x + pos_x, off_y + pos_y);
}

void SongPlaylistEntry::Render(sf::RenderWindow& rw, int off_x, int off_y) 
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

    TextBox song_name(30, off_height, txtLen, txt_height, 
                      0, song_ptr_->getSongNameWithoutPath());

    TextBox underline(30, off_height + 10, txtLen, txt_height, 
                      0, std::string(song_name.GetText().size(), '_'));

    if (not col_btn_.ThisButtonHovered(off_x, off_y))
        underline.Render(rw, off_x + pos_x, off_y + pos_y);
    
    txt_nr.Render(rw, off_x + pos_x, off_y + pos_y);
    song_name.Render(rw, off_x + pos_x, off_y + pos_y);

/// Render the delete button and it's sprite
    del_btn_.Render(rw, off_x + pos_x, off_y + pos_y);
    sprite_del_btn_.Render(rw, off_x + pos_x, off_y + pos_y);
}

int SongPlaylistEntry::GetWidth() const
{
    return kEntryWidth + kButtonWidth + kGap;
}

int SongPlaylistEntry::GetHeight() const
{
    return kHeight;
}