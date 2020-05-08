#include "u_png_color_button.hpp"

PngColorButton::PngColorButton(int szX, int szY, UniquePtr<Command> cPtr, sf::Color normal, sf::Color hover,
                               SharedPtr<PngSprite> pngPtr) :
    ColorButton(szX, szY, std::move(cPtr), normal, hover),
    sprite_(pngPtr)
{
    sprite_->SetSize(szX, szY);
}

void PngColorButton::Update(int off_x, int off_y)
{
    ColorButton::Update(off_x, off_y);
}

void PngColorButton::Render(sf::RenderWindow& rw, int off_x, int off_y)
{
    if (ThisButtonHovered(off_x, off_y))
        sprite_->SetColor(hovered_);
    else
        sprite_->SetColor(normal_);
    
    // Logger::Get() << "PngColorButton Render hehe!!\n";
    sprite_->Render(rw, off_x + pos_x, off_y + pos_y);
}