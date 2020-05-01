#include "application.hpp"

using Constants::State;

Application::Application() :
    /// Sizes for views in pixels, relative to the optimal size of the app
    /// App will anyway scale how it should on resize
    window_(sf::VideoMode(Constants::kWidth, Constants::kHeight), 
            Constants::kApplicationName,
            sf::Style::Close | sf::Style::Titlebar),

    w_side_bar_(Constants::kWidth * 1 / 4, Constants::kHeight, 
                0, 0),

    w_main_(Constants::kWidth * 3 / 4, Constants::kHeight * 2 / 3,
            w_side_bar_.GetWidth(), 0),
            
    w_status_(Constants::kWidth * 3 / 4, Constants::kHeight * 1 / 3,
              w_side_bar_.GetWidth(), w_main_.GetHeight())
{}

void Application::InitializingScript()
{
    w_side_bar_.ClearAllElements();
    w_main_.ClearAllElements();
    w_status_.ClearAllElements();

    w_side_bar_.setViewPort(sf::FloatRect(0, 0, 0.25, 1));
    w_main_.setViewPort(sf::FloatRect(0.25, 0, 0.75, 0.666));
    w_status_.setViewPort(sf::FloatRect(0.25, 0.666, 0.75, 0.333));
    
    window_.setFramerateLimit(Constants::kFrameLimit);
}

void Application::Render()
{
    w_side_bar_.Render(window_, 0, 0);
    w_status_.Render(window_, 0, 0);
    w_main_.Render(window_, 0, 0);
}

void Application::Update()
{
    w_side_bar_.Update(0, 0);
    w_status_.Update(0, 0);
    w_main_.Update(0, 0);
}

int Application::Run()
{
    using std::cout;

    sf::Clock my_clock;

    InitializingScript();

    /// scope for testing
    {
        auto power_btn_ptr = std::make_shared<PngSprite>("data/img/power_button.png");
        auto play_btn_ptr = std::make_shared<PngSprite>("data/img/play_button.png");
        power_btn_ptr->SetSize(100, 100);
        power_btn_ptr->SetPosition(20, 50);
        play_btn_ptr->SetSize(80, 80);

        w_main_.AddSampleUiElement(power_btn_ptr);
        w_side_bar_.AddSampleUiElement(play_btn_ptr);
        w_status_.AddSampleUiElement(power_btn_ptr);

        power_btn_ptr->SetColor(sf::Color::Green);
    }
    /// should delete the scope above

    while (window_.isOpen()){

        sf::Event event;
        while (window_.pollEvent(event)){
            switch (event.type)
            {
                case sf::Event::Closed:
                {
                    window_.close();
                    cout << "The window was closed\n";
                    break;
                }

                case sf::Event::MouseButtonPressed:
                {
                    // cout << "Mouse button pressed at: " 
                    //      << event.mouseButton.x << ' ' << event.mouseButton.y << '\n';
                    EventHandler::ClickAtPosition(event.mouseButton.x, event.mouseButton.y);             
                }
                default:
                {
                    break;
                }
            }
            this->Update();            
        }


        window_.clear(sf::Color::White);

        _DebugBackGroundRectangles();

        this->Render();
        window_.display();

        auto position = sf::Mouse::getPosition();
        auto window_pos = window_.getPosition();
        // std::cerr << "Mouse hovering at: " << position.x - window_pos.x << ' ' << position.y - window_pos.y << '\n';
    }

    return 0;
}

void Application::_DebugBackGroundRectangles()
{
    auto rect = sf::RectangleShape({(float)w_side_bar_.GetWidth(), (float)w_side_bar_.GetHeight()});
    rect.setFillColor(sf::Color(191, 191, 63, 0.41 * 255));
    window_.draw(rect);

    rect.setFillColor(sf::Color(28, 156, 236, 0.38 * 255));
    rect.setPosition({w_main_.off_x_, w_main_.off_y_});
    rect.setSize({w_main_.GetWidth(), w_main_.GetHeight()});
    window_.draw(rect);

    rect.setFillColor(sf::Color(236, 28, 32, 0.38 * 255));
    rect.setPosition({w_status_.off_x_, w_status_.off_y_});
    rect.setSize({w_status_.GetWidth(), w_status_.GetHeight()});
    window_.draw(rect);
}