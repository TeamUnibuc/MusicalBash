#ifndef INC_UI_PNG_SPRITE_
#define INC_UI_PNG_SPRITE_

#include <string>

#include "u_sprite.hpp"

class PngSprite : public Sprite
{
private:
    PngSprite() = delete;

protected:
    sf::Texture texture_;

public:
    PngSprite(const std::string& path);

    virtual ~PngSprite();

    virtual void Render(sf::RenderWindow& rendWindow, int offset_x);
};

#endif  // INC_UI_PNG_SPRITE_