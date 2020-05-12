#include "u_color_button.hpp"

ColorButton::ColorButton(int szX, int szY, UniquePtr<Command> cPtr, sf::Color normal, sf::Color hovered) :
    Button(szX, szY, std::move(cPtr)), normal_(normal), hovered_(hovered)
{}

void ColorButton::Update(int off_x, int off_y)
{
    // Logger::Get() << "Update ColBut at: " << off_x << ' ' << off_y << '\n';
    Button::Update(off_x, off_y);
}

void ColorButton::Render(sf::RenderWindow& rw, int off_x, int off_y)
{
    sf::RectangleShape rect(sf::Vector2f(sizeX_, sizeY_));
    rect.setSize(sf::Vector2f(sizeX_, sizeY_));
    rect.setPosition(sf::Vector2f(off_x + pos_x, off_y + pos_y));
    // Logger::Get() << "Render button at: " << off_x + pos_x << ' ' << off_y + pos_y << '\n';
    if (ThisButtonHovered(off_x, off_y))
        rect.setFillColor(hovered_);
    else
        rect.setFillColor(normal_);
    
    rw.draw(rect);
}