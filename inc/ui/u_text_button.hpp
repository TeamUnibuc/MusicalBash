#pragma once

#include "u_color_button.hpp"
#include "u_text_box.hpp"

class TextButton : public ColorButton
{
protected:
    UniquePtr<TextBox> text_box_;

public:
    TextButton(int szX, int szY, UniquePtr<Command> cPtr, sf::Color normal, sf::Color hovered, 
               UniquePtr<TextBox> txtPtr);
    
    void Render(sf::RenderWindow& rw, int off_x, int off_y) override;

    const UniquePtr<TextBox>& TextBoxPtr();

    TextBox& TheTextBox();
};