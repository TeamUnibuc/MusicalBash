#ifndef INC_UI_SPRITE_
#define INC_UI_SPRITE_

#include "u_element.hpp"

class Sprite : public UiElement
{
private:

protected:
    int pos_x, pos_y;

    sf::Sprite sprite_;
public:
    Sprite();

    Sprite(int pos_x, int pos_y);

    virtual ~Sprite();

    void SetPosition(float px, float py);

    void Move(float x, float y);

    void SetScale(float x, float y);

    void SetSize(float x, float y);

    virtual void Render(sf::RenderWindow & rendWindow, int offset_x);
};

#endif  // INC_UI_SPRITE_