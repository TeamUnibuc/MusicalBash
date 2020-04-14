#include "application.hpp"

using Constants::State;

Application::Application() :
    /// Sizes for views in pixels, relative to the optimal size of the app
    /// App will anyway scale how it should on resize
    window_(sf::VideoMode(Constants::kWidth, Constants::kHeight), 
            Constants::kApplicationName,
            sf::Style::Close | sf::Style::Titlebar),

    w_side_bar_(Constants::kWidth * 1 / 4, Constants::kHeight, 
                0),

    w_main_(Constants::kWidth * 3 / 4, Constants::kHeight * 2 / 3,
            w_side_bar_.GetWidth() + 20),
            
    w_status_(Constants::kWidth * 3 / 4, Constants::kHeight * 1 / 3,
              w_side_bar_.GetWidth() + 20 + w_main_.GetWidth() + 20)
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

int Application::Run()
{
    using std::cout;

    sf::Clock my_clock;

    InitializingScript();

    /// scope for testing
    {
        auto power_btn_ptr = std::make_shared<PngSprite>("data/img/play_button.png");
        power_btn_ptr->SetSize(100, 100);
        power_btn_ptr->SetPosition(0, 0);

        w_main_.AddSampleUiElement(power_btn_ptr);
        w_side_bar_.AddSampleUiElement(power_btn_ptr);

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
                    cout << "Mouse button pressed at: " 
                         << event.mouseButton.x << ' ' << event.mouseButton.y << '\n';
                    EventHandler::ClickAtPosition(event.mouseButton.x, event.mouseButton.y);             
                }
                default:
                {
                    break;
                }
            }            
        }

        window_.clear(sf::Color::White);

        w_side_bar_.Redraw(window_);
        w_status_.Redraw(window_);
        w_main_.Redraw(window_);

        window_.display();

        auto position = sf::Mouse::getPosition();
        cout << "Mouse hovering at: " << position.x << ' ' << position.y << '\n';
    }

    return 0;
}

