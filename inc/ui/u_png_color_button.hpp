#pragma once

#include "u_color_button.hpp"
#include "u_png_sprite.hpp"

class PngColorButton : public ColorButton
{
private:
    SharedPtr<PngSprite> sprite_;

public:
    PngColorButton(int szX, int szY, UniquePtr<Command> cPtr, sf::Color normal, sf::Color hover,
                   SharedPtr<PngSprite> pngPtr);

    void Update(int off_x, int off_y) override;

    void Render(sf::RenderWindow& rw, int off_x, int off_y) override;
};