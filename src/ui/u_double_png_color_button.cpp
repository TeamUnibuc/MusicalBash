#include "u_double_png_color_button.hpp"

DoublePngColorButton::DoublePngColorButton(int szX, int szY, UniquePtr<Command> cPtr, sf::Color normal, sf::Color hover,
                   SharedPtr<PngSprite> pngPtr, SharedPtr<PngSprite> pngPtrTwo) :
    ColorButton(szX, szY, std::move(cPtr), normal, hover),
    sprite_one_(pngPtr), sprite_two_(pngPtrTwo)
{
    sprite_one_->SetSize(szX, szY);
    sprite_two_->SetSize(szX, szY);
}

void DoublePngColorButton::Render(sf::RenderWindow& rw, int off_x, int off_y)
{
    auto& color = (ThisButtonHovered(off_x, off_y) ? hovered_ : normal_);
    auto& cur_sprite = (Knowledge::Daddy_Player->getPlayingStatus() == 0 ? sprite_one_ : sprite_two_);

    cur_sprite->SetColor(color);
    
    // Logger::Get() << "Double Png ColorButton Render hehe!!\n";
    cur_sprite->Render(rw, off_x + pos_x, off_y + pos_y);
}