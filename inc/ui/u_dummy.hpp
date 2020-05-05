#ifndef U_UI_DUMMY_HPP_
#define U_UI_DUMMY_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "u_element.hpp"


class DummyUI : public UiElement
{
private:
    sf::Color color_;
    sf::RectangleShape rect_;
    
public:
    DummyUI(int szX, int szY) : color_((1u * rand() << 16)+ 1u * rand()), rect_(sf::Vector2f(szX, szY))
    {}

    int GetHeight() const override
    {
        return rect_.getSize().y;
    }

    int GetWidth() const override
    {
        return rect_.getSize().x;
    }

    virtual void Render(sf::RenderWindow& rendWindow, int off_x, int off_y)
    {
        rect_.setPosition(off_x, off_y);
        rendWindow.draw(rect_);
    }

    virtual void Update(int off_x, int off_y) {
        color_.b = (color_.b + rand() % 2) % 255;
        color_.r = (color_.r + rand() % 3) % 255;
        color_.g = (color_.g + rand() % 5) % 255;
        color_.a = 255;
        rect_.setFillColor(color_);
    }

};

#endif //U_UI_DUMMY_HPP_