#include "u_sprite.hpp"

Sprite::~Sprite() 
{}

Sprite::Sprite() : UiElement(0, 0) 
{}

Sprite::Sprite(int x, int y) : UiElement(x, y)
{}

void Sprite::SetPosition(int x, int y)
{
    pos_x = x;
    pos_y = y;
}

void Sprite::Move(int x, int y)
{
    sprite_.move(sf::Vector2f(x, y));
}

void Sprite::Render(sf::RenderWindow& rendWindow, int offset_x)
{
    sprite_.setPosition(pos_x + offset_x, pos_y);
    rendWindow.draw(sprite_);
}

void Sprite::SetSize(int x, int y)
{
    auto size = sprite_.getTexture()->getSize();
    int sx = size.x, sy = size.y;

    sprite_.setScale(1.0 * x / sx, 1.0 * y / sy);

}

void Sprite::SetScale(float x, float y)
{
    sprite_.setScale(x, y);
}