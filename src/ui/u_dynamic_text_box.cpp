#include "u_dynamic_text_box.hpp"

DynamicTextBox::DynamicTextBox(int posX, int posY, int sizeX, int sizeY, int alignment, std::string textInput,
                   std::function<std::string()> func) :
    TextBox(posX, posY, sizeX, sizeY, alignment, textInput),
    reloaded_text(func)
{}

void DynamicTextBox::Render(sf::RenderWindow& rw, int off_x, int off_y)
{
    std::string time = reloaded_text();
    SetText(time);

    // Logger::Get() << "Set text: " << time << '\n';

    TextBox::Render(rw, off_x, off_y);
}