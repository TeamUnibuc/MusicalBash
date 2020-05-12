#include "u_album_entry.hpp"

const int AlbumEntry::kEntryWidth    = 700;
const int AlbumEntry::kButtonWidth   = 100;
const int AlbumEntry::kHeight        = 66;
const int AlbumEntry::kActualHeight  = 80;
const int AlbumEntry::kGap           = 30;
const float AlbumEntry::kHeightRatio = 0.7;

AlbumEntry::AlbumEntry(int posX, int posY, sf::Color normal, sf::Color hovered,
               SharedPtr<PAlbum> alb_ptr, int number, 
               UniquePtr<Command> c_ptr, SharedPtr<PngSprite> png_ptr) :
    album_ptr_(alb_ptr),
    del_btn_(kHeight * kHeightRatio, kHeight * kHeightRatio, 
             std::move(std::make_unique<CDeleteAlbum>(alb_ptr)), normal, hovered, png_ptr),
    col_btn_(kEntryWidth,            kHeight * kHeightRatio, 
             std::move(c_ptr), normal, hovered),
    number_(number)
{
    col_btn_.SetPosition({0, kHeight * (1. - kHeightRatio) / 2});
    del_btn_.SetPosition({kEntryWidth + kGap, kHeight * (1. - kHeightRatio) / 2});
}

    
void AlbumEntry::Update(int off_x, int off_y)
{
    del_btn_.Update(off_x + pos_x, off_y + pos_y);
    col_btn_.Update(off_x + pos_x, off_y + pos_y);
}

void AlbumEntry::Render(sf::RenderWindow& rw, int off_x, int off_y)
{
    col_btn_.Render(rw, off_x + pos_x, off_y + pos_y);

    const int off_height = col_btn_.GetPosition().second + 9;
    const int txt_height = col_btn_.GetHeight() * 0.7;
    const int txtLen     = kEntryWidth - 12;

    TextBox txt_nr(12, off_height, 30, txt_height,
                   0, std::to_string(number_));
    txt_nr.SetColor(Constants::kGreen);

    TextBox album_name(30, off_height, txtLen, txt_height, 
                      0, album_ptr_->GetName());

    // Logger::Get() << "Song name textbox details: " << song_name.GetWidth() << " " << song_name.GetHeight() << '\n';
    
    txt_nr.Render(rw, off_x + pos_x, off_y + pos_y);
    album_name.Render(rw, off_x + pos_x, off_y + pos_y);
    del_btn_.Render(rw, off_x + pos_x, off_y + pos_y);
}

int AlbumEntry::GetWidth() const
{
    return kEntryWidth + kButtonWidth + kGap;
}

int AlbumEntry::GetHeight() const
{
    return kHeight;
}