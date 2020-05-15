#include "u_progress_bar.hpp"
#include "a_knowledge.hpp"
#include "a_utils.hpp"

ProgressBar::ProgressBar(int length, int hLeftBar, int hRightBar, int szCircle,
                sf::Color c_left, sf::Color c_right, sf::Color c_circle,
                std::function<float()> func, UniquePtr<SliderCommand> command) :
    length_(length),
    r_left_({0.f , 1.f * hLeftBar}), r_right_({0.f , 1.f * hRightBar}),
    circle_(szCircle),
    whatProgress(func),
    command_(std::move(command))
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

void ProgressBar::Update(int off_x, int off_y)
{
    const int HEIGHT_PROGRESS_BAR = 20;

    if (Knowledge::GetEvent().type == sf::Event::EventType::MouseButtonPressed) {
        if (Knowledge::GetEvent().mouseButton.button == sf::Mouse::Button::Left) {
            if (Utils::PointInsideRect(Knowledge::GetMousePoz(), 
                                       off_x + pos_x, off_y + pos_y - HEIGHT_PROGRESS_BAR, length_, 2 * HEIGHT_PROGRESS_BAR)) {
                double raport = Knowledge::GetMousePoz().first - off_x - pos_x;
                raport /= length_;
                raport *= 100;
                Logger::Get() << " ProgressBar detected press at " << raport << " percentage of length\n";
                command_->Execute(raport);
            }
        }
    }
}

int ProgressBar::GetHeight() const
{
    return std::max(r_left_.getSize().y, r_right_.getSize().y);
}

int ProgressBar::GetWidth() const
{
    return std::max(r_left_.getSize().x, r_right_.getSize().x);
}