#include "u_text_box.hpp"

TextBox::TextBox(){}


TextBox::TextBox(int posX, int posY, int sizeX, int sizeY, int alignment, std::string textInput):
    UiElement(posX, posY), sizeX_(sizeX), sizeY_(sizeY)
{

}