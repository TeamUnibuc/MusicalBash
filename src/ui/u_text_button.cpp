#include "u_text_button.hpp"

TextButton::TextButton(int szX, int szY, UniquePtr<Command> cPtr, 
                       sf::Color normal, sf::Color hovered, UniquePtr<TextBox> txtPtr) :
    ColorButton(szX, szY, std::move(cPtr), normal, hovered), 
    text_box_(std::move(txtPtr))
{}

void TextButton::Render(sf::RenderWindow& rw, int off_x, int off_y)
{
    ColorButton::Render(rw, off_x, off_y);
    text_box_->Render(rw, off_x + pos_x, off_y + pos_y);
}

const UniquePtr<TextBox>& TextButton::TextBoxPtr()
{
    return text_box_;
}

TextBox& TextButton::TheTextBox()
{
    return *text_box_;
}