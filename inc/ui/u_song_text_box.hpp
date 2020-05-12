#pragma once  /// U_SONG_TEXT_BOX_HPP_

#include "u_text_box.hpp"

#include "a_knowledge.hpp"

class SongTextBox : public TextBox
{
protected:
public:
    SongTextBox(int posX, int posY, int sizeX, int sizeY, int alignment, std::string text);

    void Render(sf::RenderWindow& rw, int off_x, int off_y) override;
};