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

    virtual void Render(sf::RenderWindow& rendWindow, int off_x, int off_y) = 0;

    virtual void Update(int off_x, int off_y) = 0;

    /// Watch out to properly override this!!
    virtual int GetHeight() const = 0;

    /// Watch out to properly override this!!
    virtual int GetWidth() const = 0;
};

#endif // INC_UI_ELEMENT_