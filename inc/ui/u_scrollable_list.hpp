#ifndef INC_UI_SCROLLABLE_LIST_
#define INC_UI_SCROLLABLE_LIST_

#include <iostream>

#include "a_constants.hpp"
#include "a_event_handler.hpp"
#include "u_element.hpp"
#include "u_container.hpp"

class ScrollableList : public UiElement, public UiContainer
{
private:
    const int  sizeX_;
    const int  sizeY_;
    int        start_index_;

protected:

public:
    ScrollableList(int sizeX, int sizeY);

    void AddUiElement(SharedPtr<UiElement> ptr);

    void SetStartIndex(int index);

    void Render(sf::RenderWindow& rendWindow, int off_x, int off_y);

    void Update(int off_x, int off_y);

    /// Watch out to properly override this!!
    int GetHeight() const;

    /// Watch out to properly override this!!
    int GetWidth() const;

};

#endif // INC_UI_SCROLLABLE_LIST_