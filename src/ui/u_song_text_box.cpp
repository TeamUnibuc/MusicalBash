#include "u_song_text_box.hpp"

SongTextBox::SongTextBox(int posX, int posY, int sizeX, int sizeY, int alignment, std::string text) :
    TextBox(posX, posY, sizeX, sizeY, alignment, text)
{}

void SongTextBox::Render(sf::RenderWindow& rw, int off_x, int off_y) 
{  
    TextBox::SetText(Knowledge::GetActiveSongNameOrEmpty());
    TextBox::Render(rw, off_x, off_y);
}