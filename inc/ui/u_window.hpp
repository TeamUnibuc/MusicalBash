#ifndef INC_UI_WINDOW_
#define INC_UI_WINDOW_

#include <memory>
#include <SFML/Graphics.hpp>

#include "a_knowledge.hpp"
#include "v_views.hpp"
#include "u_music_entry.hpp"

namespace Musical
{

class Window : public UiElement, public UiContainer
{
public:
    const int      size_x, size_y;
    const int      g_off_x,  g_off_y;

    enum class Type
    {
        Main,
        Side,
        Status
    };

private:
    sf::View             w_view_;

    const Type           type_;
    Constants::State::W  prev_state;

    void MainController(int off_x, int off_y);
    void SideController(int off_x, int off_y);
    void StatusController(int off_x, int off_y);

public:
    /// Height of the window, Height of the window, the horizontal offset of the window
    Window(int sz_x, int sz_y, int off_x, int off_y, Type w_type);

    /// Utility stuff
    int GetWidth() const;

    /// Get width and Height of the Window (view)
    int GetHeight() const;

    /// Set on which part of the screen the view will be shown
    void setViewPort(const sf::FloatRect& viewRect);

    /// Render all the Window's UiElements
    void Render(sf::RenderWindow& renderWindow, int offX, int offY);

    /// Update Window
    void Update(int offX, int offY);

    /// Add some UiElement to the Window
    void AddSampleUiElement(std::shared_ptr<UiElement> ptr);

    /// Deletes all the UiElement from the Window
    void ClearAllElements();
};

}

#endif // INC_UI_WINDOW_