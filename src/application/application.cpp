#include "application.hpp"

Application::Application() :
    /// Sizes for views in pixels, relative to the optimal size of the app
    /// App will anyway scale how it should on resize
    w_side_bar_(Constants::kWidth * 1 / 4, Constants::kHeight),
    w_main_(Constants::kWidth * 3 / 4, Constants::kHeight * 2 / 3),
    w_status_(Constants::kWidth * 3 / 4, Constants::kHeight * 1 / 3)
{
    using Constants::kWidth, Constants::kHeight; 

    sf::Window window_ = 
        sf::Window(sf::VideoMode(kWidth, kHeight), Constants::kApplicationName);

    offset_side_bar_ = 0;
    offset_main_ = w_side_bar_.GetWidth() + 20;
    offset_status_ = offset_main_ + w_main_.GetWidth() + 20;
}

int Application::Run()
{
    using std::cout;

    const int MIN_WIDTH = 500;
    const int MIN_HEIGHT = 350;

    w_side_bar_.SetWatchOver(offset_side_bar_, 0, w_side_bar_.GetWidth(), w_side_bar_.GetHeight());
    w_main_.SetWatchOver(offset_main_, 0, w_main_.GetWidth(), w_main_.GetHeight());
    w_status_.SetWatchOver(offset_status_, 0, w_status_.GetWidth(), w_status_.GetHeight());

    w_side_bar_.setViewPort(sf::FloatRect(0, 0, 0.25, 1));
    w_main_.setViewPort(sf::FloatRect(0.25, 0, 0.75, 0.666));
    w_status_.setViewPort(sf::FloatRect(0.25, 0.666, 0.75, 0.333));

    {
        auto power_btn_ptr = std::make_shared<PngSprite>("data/img/power_button.png");

        w_main_.AddSampleUiElement(power_btn_ptr);
    }

    sf::Vector2u size;

    sf::Clock my_clock;

    while (window_.isOpen()){
        sf::Event event;
        bool flag = 0;
        while (window_.pollEvent(event)){
            switch (event.type)
            {
                case sf::Event::Closed:
                {
                    window_.close();
                    cout << "The window was closed\n";
                    break;
                }
                case sf::Event::Resized:
                {
                    size = window_.getSize();
                    auto sz = window_.getSize();                       
                    if (sz.x < MIN_WIDTH){
                        sz.x = MIN_WIDTH;
                        flag = 1;
                    }
                    if (sz.y < MIN_HEIGHT){
                        sz.y = MIN_HEIGHT;
                        flag = 1;
                    }
                    cout << size.x << ' ' << size.y << '\n';
                    if (flag){
                        window_.setSize(sf::Vector2u(sz.x, sz.y));
                    }
                        
                    break;
                }
                default:
                {
                    break;
                }
            }
            // if (flag)
            //     playerWindow.getWindow().setSize(sf::Vector2u(MIN_WIDTH, MIN_HEIGHT));
            
        }

        if (my_clock.getElapsedTime().asSeconds() > 5) {
            w_main_.ClearAllElements();
        }

        window_.clear();
        // if (flag)
        //     playerWindow.getWindow().setSize(sf::Vector2u(MIN_WIDTH, MIN_HEIGHT));
        w_side_bar_.Redraw(window_, offset_side_bar_);
        w_main_.Redraw(window_, offset_main_);
        w_status_.Redraw(window_, offset_status_);
    }

    return 0;
}