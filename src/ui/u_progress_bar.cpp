#include "u_progress_bar.hpp"

ProgressBar::ProgressBar(int length, int hLeftBar, int hRightBar, int szCircle,
                sf::Color c_left, sf::Color c_right, sf::Color c_circle,
                std::function<float()> func) :
    length_(length),
    r_left_({0.f , 1.f * hLeftBar}), r_right_({0.f , 1.f * hRightBar}),
    circle_(szCircle),
    whatProgress(func)
{
    r_left_.setFillColor(c_left);
    r_right_.setFillColor(c_right);
    circle_.setFillColor(c_circle);
}
    
void ProgressBar::Render(sf::RenderWindow& rw, int off_x, int off_y)
{
    const float splitPoint = whatProgress() / 100.0 * length_;
    r_left_.setSize({splitPoint, r_left_.getSize().y});
    r_right_.setSize({length_ - splitPoint, r_right_.getSize().y});

    r_left_.setPosition({(float)pos_x, pos_y - r_left_.getSize().y / 2.f});
    r_right_.setPosition({pos_x + splitPoint, pos_y - r_right_.getSize().y / 2.f});

    circle_.setPosition({pos_x + splitPoint - circle_.getRadius(), pos_y - circle_.getRadius()});
    // Logger::Get() << circle_.getPosition().x << " " << circle_.getPosition().y << '\n';
 
    r_left_.move(off_x, off_y);
    r_right_.move(off_x, off_y);
    circle_.move(off_x, off_y);
    // circle_.setRadius(10000000.f);

    rw.draw(r_left_);
    rw.draw(r_right_);
    rw.draw(circle_);
}

void ProgressBar::Update(int /* off_x */, int /* off_y */)
{
    /// Nothing lol ?
}

int ProgressBar::GetHeight() const
{
    return std::max(r_left_.getSize().y, r_right_.getSize().y);
}

int ProgressBar::GetWidth() const
{
    return std::max(r_left_.getSize().x, r_right_.getSize().x);
}