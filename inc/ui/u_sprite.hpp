#ifndef INC_UI_SPRITE_
#define INC_UI_SPRITE_

#include "u_element.hpp"

class Sprite : public UiElement
{
private:

protected:
    sf::Texture texture_;
    sf::Sprite sprite_;

public:
    Sprite();

    Sprite(int pos_x, int pos_y);

    Sprite(int pos_x, int pos_y, int sz_x, int sz_y = 0);

    virtual ~Sprite();

    /// Set position of sprite with respect to the holding Window
    void SetPosition(int px, int py);

    /// Move the sprite
    void Move(int x, int y);

    /// Not recommended!! Use SetSize instead
    void SetScale(float x, float y);

    /// Sets the size of the Sprite in Pixels
    void SetSize(int x, int y);

    virtual int GetHeight() const;

    virtual int GetWidth() const;

    /// Sets color of Sprite
    void SetColor(sf::Color color);

    virtual void Render(sf::RenderWindow &rendWindow, int offset_x) = 0;
};

#endif  // INC_UI_SPRITE_