#ifndef INC_UI_WINDOW_
#define INC_UI_WINDOW_

#include <memory>
#include <SFML/Graphics.hpp>

#include "u_container.hpp"
#include "a_constants.hpp"

namespace Musical
{

class Window : public UiContainer
{
private:
    const int      size_x_, size_y_;
    const int      offset_x_;
    sf::View       w_view_;

public:
    /// Height of the window, Height of the window, the horizontal offset of the window
    Window(int sz_x, int sz_y, int offset_x);

    /// Utility stuff
    int GetWidth() const;

    /// Get width and Height of the Window (view)
    int GetHeight() const;

    /// Set on which part of the screen the view will be shown
    void setViewPort(const sf::FloatRect& viewRect);

    /// Redraw all the Window's UiElements
    void Redraw(sf::RenderWindow& renderWindow);

    /// Add some UiElement to the Window
    void AddSampleUiElement(std::shared_ptr<UiElement> ptr);

    /// Deletes all the UiElement from the Window
    void ClearAllElements();
};

}

#endif // INC_UI_WINDOW_