#include "u_album_entry.hpp"

const int   AlbumEntry::kEntryWidth    = 700;
const int   AlbumEntry::kButtonWidth   = 100;
const int   AlbumEntry::kHeight        = 66;
const int   AlbumEntry::kActualHeight  = 80;
const int   AlbumEntry::kGap           = 30;
const int   AlbumEntry::kSpriteOffset  = 8;
const float AlbumEntry::kHeightRatio   = 0.7;

const std::pair<int, int> AlbumEntry::kColBtnPos = {0, kHeight * (1. - kHeightRatio) / 2};
const std::pair<int, int> AlbumEntry::kDelBtnPos = {kEntryWidth + kGap, kHeight * (1. - kHeightRatio) / 2};

const std::pair<int, int> AlbumEntry::kColBtnSize = {kEntryWidth, kHeight * kHeightRatio};
const std::pair<int, int> AlbumEntry::kDelBtnSize = {kHeight * kHeightRatio, kHeight * kHeightRatio};

AlbumEntry::AlbumEntry(SharedPtr<PAlbum> alb_ptr, int number) :
    album_ptr_(alb_ptr),
    del_btn_sprite_("data/img/red_cross.png"),  /// kHeight * kHeightRatio, kHeight * kHeightRatio, 
    col_btn_(kColBtnSize.first, kColBtnSize.second, 
             std::make_unique<CShowSpecificAlbum>(alb_ptr), 
             Constants::kSideBtnIdle, Constants::kSideBtnHover),
    del_btn_(kDelBtnSize.first, kDelBtnSize.second,
             std::make_unique<CDeleteAlbum>(alb_ptr), 
             Constants::kSideBtnIdle, Constants::kSideBtnHover),
    number_(number)
{
    del_btn_sprite_.SetPosition(kDelBtnPos.first + kSpriteOffset, kDelBtnPos.second + kSpriteOffset);
    del_btn_sprite_.SetSize(kDelBtnSize.first - kSpriteOffset * 2, kDelBtnSize.second - kSpriteOffset * 2);

    col_btn_.SetPosition(kColBtnPos);

    del_btn_.SetPosition(kDelBtnPos);
}

    
void AlbumEntry::Update(int off_x, int off_y)
{
    del_btn_sprite_.Update(off_x + pos_x, off_y + pos_y);
    col_btn_.Update(off_x + pos_x, off_y + pos_y);
}

void AlbumEntry::Render(sf::RenderWindow& rw, int off_x, int off_y)
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

    TextBox album_name(30, off_height, txtLen, txt_height, 
                      0, album_ptr_->GetName());

    // Logger::Get() << "Song name textbox details: " << song_name.GetWidth() << " " << song_name.GetHeight() << '\n';
    
    txt_nr.Render(rw, off_x + pos_x, off_y + pos_y);
    album_name.Render(rw, off_x + pos_x, off_y + pos_y);

    del_btn_.Render(rw, off_x + pos_x, off_y + pos_y);
    del_btn_sprite_.Render(rw, off_x + pos_x, off_y + pos_y);

/// Render the underlying button with changing color on hover
//     auto under_del_btn = sf::RectangleShape({del_btn_sprite_.GetWidth(), del_btn_sprite_.GetHeight()});
//     under_del_btn.setPosition({del_btn_sprite_.GetPosition().first, del_btn_sprite_.GetPosition().second});

//     if (del_btn_.ThisButtonHovered(off_x, off_y))
//         under_del_btn.setFillColor(Constants::kSideBtnHover);
//     else
//         under_del_btn.setFillColor(Constants::kSideBtnIdle);
    
//     under_del_btn.move(off_x, off_y);

//     rw.draw(under_del_btn);

// /// Render the sprite for the button
//     del_btn_sprite_.Render(rw, off_x + pos_x, off_y + pos_y);
}

int AlbumEntry::GetWidth() const
{
    return kEntryWidth + kButtonWidth + kGap;
}

int AlbumEntry::GetHeight() const
{
    return kHeight;
}