#pragma once // U_PROGERSS_BAR_HPP_

#include "u_element.hpp"
#include "command.hpp"
#include "a_logger.hpp"
#include "c_player.hpp"

/**
 * Ui element which has a left progressbar, and a right progress bar
 * The function passed when creating the object should return values between 0 and 100
 */
class ProgressBar : public UiElement
{
private:
protected:
    int length_;

    sf::RectangleShape r_left_, r_right_;
    sf::CircleShape circle_;
    
    ///  When called, this function tells the ProgressBar where the circle should be
    std::function<float()> whatProgress;

    /// Command to call when progress bar is pressed
    UniquePtr<SliderCommand> command_;

public:
    ProgressBar(int length, int hLeftBar, int hRightBar, int szCircle,
                sf::Color c_left, sf::Color c_right, sf::Color c_circle,
                std::function<float()> func, UniquePtr<SliderCommand> command);
    
    void Render(sf::RenderWindow& rw, int off_x, int off_y) override;

    void Update(int off_x, int off_y) override;

    int GetHeight() const override;

    int GetWidth() const override;
};