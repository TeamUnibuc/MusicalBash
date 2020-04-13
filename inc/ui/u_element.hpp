#ifndef INC_UI_ELEMENT_
#define INC_UI_ELEMENT_

#include <SFML/Graphics.hpp>

class UiElement
{
private:
protected:

    int pos_x, pos_y;

public:
    UiElement();

    UiElement(int pos_x, int pos_y);

    virtual void Render(sf::RenderWindow& rendWindow, int offset_x) = 0;
};

#endif // INC_UI_ELEMENT_