#include "u_music_entry.hpp"

const float MusicEntry::kPercentage          = 0.09; /// % of length allocated for timestamp
const float MusicEntry::kHeightRatio         = 0.7;  /// % of height the button takes from the whole space
const int   MusicEntry::kMinSpaceForDuration = 85;
const float MusicEntry::kTextScale           = 0.7;  /// Ratio for controlling text font (height)

MusicEntry::MusicEntry(int szX, int szY, 
                       sf::Color normal, sf::Color hovered,
                       SharedPtr<PMusic> mPtr, int number = 0) :
    size_x_(szX), size_y_(szY),
    col_btn_(szX, szY * kHeightRatio, std::make_unique<CAddMusicQueue>(mPtr), normal, hovered),
    music_(mPtr), number_(number)
{
    if (not mPtr)
        throw null_pointer("MusicEntry created with null pointer to PMusic");

    col_btn_.SetPosition({0, szY * (1 - kHeightRatio) / 2.});
}

void MusicEntry::SetNumber(int nr)
{
    number_ = nr;
}

void MusicEntry::Render(sf::RenderWindow& rw, int off_x, int off_y) 
{
    if (size_x_ < 100)
        Logger::Get() << "WARNING: Trying to render MusicEntry with a very small width: " << size_x_ << '\n';

    col_btn_.Render(rw, off_x + pos_x, off_y + pos_y);

    const int off_height = col_btn_.GetPosition().second + 9;
    const int txt_height = col_btn_.GetHeight() * kTextScale;
    const int txtLen     = size_x_ - std::max(kMinSpaceForDuration, int(size_x_ * kPercentage));

    TextBox txt_nr(5, off_height, 30, txt_height,
                   0, std::to_string(number_));
    txt_nr.SetColor(Constants::kGreen);

    TextBox song_name(30, off_height, txtLen, txt_height, 
                      0, music_->getSongNameWithoutPath());

    TextBox song_duration(txtLen - 14, off_height, size_x_ - txtLen, txt_height,
                          2, Utils::IntToMinSecondSecond(music_->getDuration()));

    // Logger::Get() << "Song name textbox details: " << song_name.GetWidth() << " " << song_name.GetHeight() << '\n';
    
    txt_nr.Render(rw, off_x + pos_x, off_y + pos_y);
    song_name.Render(rw, off_x + pos_x, off_y + pos_y);
    song_duration.Render(rw, off_x + pos_x, off_y + pos_y);
}

void MusicEntry::Update(int off_x, int off_y)
{
    // Logger::Get() << "  Music entry update:\n";
    col_btn_.Update(off_x + pos_x, off_y + pos_y);
}

int MusicEntry::GetHeight() const
{
    return size_y_;
}

int MusicEntry::GetWidth() const
{
    return size_x_;
}