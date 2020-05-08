#pragma once /// U_UI_COLOR_BUTTON_HPP_

#include "u_button.hpp"

class ColorButton : public Button
{
private:
protected:
    sf::Color normal_;
    sf::Color hovered_;

public:
    ColorButton(int szX, int szY, UniquePtr<Command> cPtr, sf::Color normal, sf::Color hovered);

    void Update(int off_x, int off_y);

    void Render(sf::RenderWindow& rw, int off_x, int off_y);
};