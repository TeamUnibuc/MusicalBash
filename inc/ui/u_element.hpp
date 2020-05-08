#ifndef INC_UI_ELEMENT_
#define INC_UI_ELEMENT_

#include <SFML/Graphics.hpp>
#include "a_exceptions.hpp"

/**
 * UIElement class, representing a drawable element.
 * The element contains a delta_x, delta_y position with respect to
 * the parent element.
 * This class SHOULD NEVER BE INSTANCIATED as it doesn't contain any
 * drawable element, and the Render and Update functions are pure vitual.
 */
class UiElement
{   
private:
protected:
    int pos_x, pos_y;

public:
    virtual ~UiElement();

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