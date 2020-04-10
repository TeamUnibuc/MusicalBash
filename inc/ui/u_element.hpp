#ifndef INC_UI_ELEMENT_
#define INC_UI_ELEMENT_

#include <SFML/Graphics.hpp>

class UiElement
{
private:
protected:
public:
    UiElement();

    virtual void Render(sf::RenderWindow& rendWindow, int offset_x) = 0;
};

#endif // INC_UI_ELEMENT_