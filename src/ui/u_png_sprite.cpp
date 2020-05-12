#include "u_png_sprite.hpp"

PngSprite::~PngSprite()
{}

PngSprite::PngSprite(const std::string& path) : Sprite()
{
    if (!texture_.loadFromFile(path)) {
        throw loading_error(path);
    }
    texture_.setSmooth(true);
    sprite_.setTexture(texture_);
}  

void PngSprite::Render(sf::RenderWindow & rendWindow, int off_x, int off_y)
{
    sprite_.setPosition(off_x + pos_x, off_y + pos_y);
    rendWindow.draw(sprite_);
}

void PngSprite::Update(int /* off_x */, int /* off_y */)
{

}