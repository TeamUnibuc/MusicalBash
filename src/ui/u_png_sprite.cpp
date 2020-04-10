#include "u_png_sprite.hpp"

PngSprite::~PngSprite() {}

PngSprite::PngSprite(const std::string& path)
{
    if (!texture_.loadFromFile(path)) {
        throw std::runtime_error("SFML Failed to load texture from file: " + path);
    }
    sprite_.setTexture(texture_);
}

// void PngSprite::Render(sf::RenderWindow & rendWindow, int offset_x)
// {
//     sprite_.setPosition(pos_x + offset_x, pos_y);
//     rendWindow.draw(sprite_);
// }