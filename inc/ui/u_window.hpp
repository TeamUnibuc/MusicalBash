#ifndef INC_UI_WINDOW_
#define INC_UI_WINDOW_

#include <memory>
#include <SFML/Graphics.hpp>

#include "u_container.hpp"

namespace Musical
{

class Window : public UiContainer
{
private:
    int size_x, size_y;

    sf::View w_view_;
public:
    Window(int sz_x, int sz_y);

    /// Utility stuff
    int GetWidth() const;

    int GetHeight() const;

    void SetWatchOver(float vLeft, float vTop, float vWidth, float vHeight);

    void setViewPort(const sf::FloatRect& viewRect);

    void Redraw(sf::RenderWindow& renderWindow, int offset_x);

    void AddSampleUiElement(std::shared_ptr<UiElement> ptr);

    void ClearAllElements();
};

}

#endif // INC_UI_WINDOW_