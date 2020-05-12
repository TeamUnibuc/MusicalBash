#pragma once  /// Double png color button HPP_

#include "u_png_color_button.hpp"

class DoublePngColorButton : public ColorButton
{
private:
protected:
    SharedPtr<PngSprite> sprite_one_;
    SharedPtr<PngSprite> sprite_two_;

public:
    DoublePngColorButton(int szX, int szY, UniquePtr<Command> cPtr, sf::Color normal, sf::Color hover,
                   SharedPtr<PngSprite> pngPtr, SharedPtr<PngSprite> pngPtrTwo);
    
    void Render(sf::RenderWindow& rw, int off_X, int off_y) override;
};