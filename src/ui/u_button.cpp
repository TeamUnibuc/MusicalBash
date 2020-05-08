#include "u_button.hpp"

Button::Button(int szX, int szY, UniquePtr<Command> cPtr) : 
    sizeX_(szX), sizeY_(szY), command_(std::move(cPtr))
{}

bool Button::ThisButtonClicked(int off_x, int off_y) const
{
    // Logger::Get() << "Checking click at: " <<  off_x + pos_x << ' '
        //  << off_y + pos_y << ' ' <<  sizeX_ << ' ' << sizeY_ << '\n';
    if (Knowledge::GetEvent().type == sf::Event::EventType::MouseButtonPressed)
        if (Knowledge::GetEvent().mouseButton.button == sf::Mouse::Button::Left)
            if (Utils::PointInsideRect(Knowledge::GetMousePoz(), 
                                       off_x + pos_x, off_y + pos_y, sizeX_, sizeY_))
                return true;
    return false;
}

bool Button::ThisButtonHovered(int off_x, int off_y) const
{
    if (Utils::PointInsideRect(Knowledge::GetMousePoz(), 
                               off_x + pos_x, off_y + pos_y, sizeX_, sizeY_))
        return true;
    return false;
}

void Button::Update(int off_x, int off_y)
{
    if (ThisButtonClicked(off_x, off_y))
        command_->Execute();
}

int Button::GetHeight() const
{
    return sizeY_;
}

int Button::GetWidth() const
{
    return sizeX_;
}