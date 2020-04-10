#include "application.hpp"

using Constants::State;

Application::Application() :
    /// Sizes for views in pixels, relative to the optimal size of the app
    /// App will anyway scale how it should on resize
    window_(sf::VideoMode(Constants::kWidth, Constants::kHeight), 
            Constants::kApplicationName,
            sf::Style::Close | sf::Style::Titlebar),

    w_side_bar_(Constants::kWidth * 1 / 4, Constants::kHeight, 
               {State::Side_Normal}),

    w_main_(Constants::kWidth * 3 / 4, Constants::kHeight * 2 / 3,
           {State::Main_Albums, 
            State::Main_AllSongs, 
            State::Main_Home, 
            State::Main_ManageSongs, 
            State::Main_Playlists}),
            
    w_status_(Constants::kWidth * 3 / 4, Constants::kHeight * 1 / 3,
             {State::Status_Nothing, 
              State::Status_NotPlaying, 
              State::Status_Playing})
{
    using Constants::kWidth, Constants::kHeight; 

    offset_side_bar_ = 0;
    offset_main_ = w_side_bar_.GetWidth() + 20;
    offset_status_ = offset_main_ + w_main_.GetWidth() + 20;
}

int Application::Run()
{
    using std::cout;

    w_side_bar_.SetWatchOver(offset_side_bar_, 0, w_side_bar_.GetWidth(), w_side_bar_.GetHeight());
    w_main_.SetWatchOver(offset_main_, 0, w_main_.GetWidth(), w_main_.GetHeight());
    w_status_.SetWatchOver(offset_status_, 0, w_status_.GetWidth(), w_status_.GetHeight());

    w_side_bar_.setViewPort(sf::FloatRect(0, 0, 0.25, 1));
    w_main_.setViewPort(sf::FloatRect(0.25, 0, 0.75, 0.666));
    w_status_.setViewPort(sf::FloatRect(0.25, 0.666, 0.75, 0.333));

    {
        auto power_btn_ptr = std::make_shared<PngSprite>("data/img/power_button.png");
        power_btn_ptr->SetScale(0.1, 0.1);

        w_main_.AddSampleUiElement(power_btn_ptr);
    }

    
    window_.setFramerateLimit(Constants::kFrameLimit);

    sf::Clock my_clock;

    InitializingScript();

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
                    cout << "Mouyse button pressed at: " << event.mouseButton.x << ' ' << event.mouseButton.y << '\n';
                    int tx = window_.getSize().x;
                    int ty = window_.getSize().y;
                    tx = 1.0 * event.mouseButton.x / tx * Constants::kWidth;
                    ty = 1.0 * event.mouseButton.y / ty * Constants::kHeight; 
                    cout << "Transformed location: " << tx << ' ' << ty << '\n';
                }
                default:
                {
                    break;
                }
            }
            // if (flag)
            //     playerWindow.getWindow().setSize(sf::Vector2u(MIN_WIDTH, MIN_HEIGHT));
            
        }

        // double secondsNow = my_clock.getElapsedTime().asSeconds();

        // if (secondsNow > 10 && secondsNow < 10.2) {
        //     w_main_.ClearAllElements();
        // }
        // if (secondsNow > 10) {
        //     cout << "No more button!!\n";
        // }

        window_.clear(sf::Color::White);

        // if (flag)
        //     playerWindow.getWindow().setSize(sf::Vector2u(MIN_WIDTH, MIN_HEIGHT));
        w_side_bar_.Redraw(window_, offset_side_bar_);
        w_main_.Redraw(window_, offset_main_);
        w_status_.Redraw(window_, offset_status_);

        window_.display();
    }

    return 0;
}

void Application::InitializingScript()
{
    w_side_bar_.ClearAllElements();
    w_main_.ClearAllElements();
    w_status_.ClearAllElements();


}