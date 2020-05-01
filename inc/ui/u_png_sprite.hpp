#ifndef INC_UI_PNG_SPRITE_
#define INC_UI_PNG_SPRITE_

#include <string>

#include "u_sprite.hpp"

class PngSprite : public Sprite
{
private:
    PngSprite() = delete;

protected:

public:
    PngSprite(const std::string& path);

    virtual ~PngSprite();

    virtual void Render(sf::RenderWindow& rendWindow, int off_x, int off_y);

    virtual void Update(int off_x, int off_y);
};

#endif  // INC_UI_PNG_SPRITE_