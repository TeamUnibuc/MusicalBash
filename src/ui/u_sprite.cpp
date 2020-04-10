#include "u_sprite.hpp"

Sprite::~Sprite() 
{}

Sprite::Sprite() : pos_x(0), pos_y(0) 
{}

Sprite::Sprite(int x, int y) : pos_x(x), pos_y(y)
{}

void Sprite::SetPosition(float x, float y)
{
    pos_x = x;
    pos_y = y;
}

void Sprite::Move(float x, float y)
{
    sprite_.move(sf::Vector2f(x, y));
}

void Sprite::Render(sf::RenderWindow& rendWindow, int offset_x)
{
    sprite_.setPosition(pos_x + offset_x, pos_y);
    rendWindow.draw(sprite_);
}

void Sprite::SetScale(float x, float y)
{
    sprite_.setScale(x, y);
}