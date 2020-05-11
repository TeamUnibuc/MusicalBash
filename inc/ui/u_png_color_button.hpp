#pragma once

#include "u_color_button.hpp"
#include "u_png_sprite.hpp"
#include "a_updaters.hpp"

/**
 * Class that Changes background when hovered, 
 * executes a command when clicked and has an updater_function so it can get
 * information about the state of the app if needed
 */
class PngColorButton : public ColorButton, public ColorUpdater
{
protected:
    SharedPtr<PngSprite> sprite_;

public:
    PngColorButton(int szX, int szY, UniquePtr<Command> cPtr, sf::Color normal, sf::Color hover,
                   SharedPtr<PngSprite> pngPtr, std::function<void(sf::Color&)> func = ColorUpdater::kDefault);

    void Update(int off_x, int off_y) override;

    void Render(sf::RenderWindow& rw, int off_x, int off_y) override;
};
