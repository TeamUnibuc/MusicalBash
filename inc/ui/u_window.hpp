#ifndef INC_UI_WINDOW_
#define INC_UI_WINDOW_

#include <memory>
#include <SFML/Graphics.hpp>

#include "u_element.hpp"
#include "u_container.hpp"
#include "a_constants.hpp"

namespace Musical
{

class Window : public UiElement, public UiContainer
{
public:
    const int      size_x_, size_y_;
    const int      off_x_,  off_y_;

private:
    sf::View       w_view_;

public:
    /// Height of the window, Height of the window, the horizontal offset of the window
    Window(int sz_x, int sz_y, int off_x, int off_y);

    /// Utility stuff
    int GetWidth() const;

    /// Get width and Height of the Window (view)
    int GetHeight() const;

    /// Set on which part of the screen the view will be shown
    void setViewPort(const sf::FloatRect& viewRect);

    /// Render all the Window's UiElements
    void Render(sf::RenderWindow& renderWindow, int off_x, int off_y);

    /// Update Window
    void Update(int off_x, int off_y);

    /// Add some UiElement to the Window
    void AddSampleUiElement(std::shared_ptr<UiElement> ptr);

    /// Deletes all the UiElement from the Window
    void ClearAllElements();
};

}

#endif // INC_UI_WINDOW_