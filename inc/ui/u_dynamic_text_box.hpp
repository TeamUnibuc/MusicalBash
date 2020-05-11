#pragma once /// DYNAMIC TEXT BOX HPP

#include "u_text_box.hpp"
#include "a_knowledge.hpp"
#include "a_utils.hpp"

class DynamicTextBox : public TextBox
{
private:
protected:
    std::function<std::string()> reloaded_text;

public:
    DynamicTextBox(int posX, int posY, int sizeX, int sizeY, int alignment, std::string textInput,
                   std::function<std::string()> func);

    void Render(sf::RenderWindow& rw, int off_x, int off_y);
};