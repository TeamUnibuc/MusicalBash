#ifndef INC_UI_SPRITE_
#define INC_UI_SPRITE_

#include "u_element.hpp"

class Sprite : public UiElement
{
private:

protected:
    sf::Sprite sprite_;
public:
    Sprite();

    Sprite(int pos_x, int pos_y);

    virtual ~Sprite();

    void SetPosition(int px, int py);

    void Move(int x, int y);

    /// Not recommended!! Use SetSize instead
    void SetScale(float x, float y);

    void SetSize(int x, int y);

    virtual void Render(sf::RenderWindow & rendWindow, int offset_x) = 0;
};

#endif  // INC_UI_SPRITE_