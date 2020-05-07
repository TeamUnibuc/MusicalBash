#include "application.hpp"

using Constants::State;
using Constants::kGap, Constants::kWidth, Constants::kHeight;
 
Application::Application() :
    /// Sizes for views in pixels, relative to the optimal size of the app
    /// App will anyway scale how it should on resize
    rend_window_(sf::VideoMode(kWidth, kHeight), 
            Constants::kApplicationName,
            sf::Style::Close | sf::Style::Titlebar),

    w_side_bar_(kWidth * 1/4 - kGap, kHeight - kGap, 
                kGap * 1/2, kGap * 1/2),

    w_main_(kWidth * 3/4 - kGap, kHeight * 2/3 - kGap,
            w_side_bar_.GetWidth() + kGap * 3/2, kGap * 1/2),
            
    w_status_(kWidth * 3/4 - kGap, kHeight * 1/3 - kGap,
              w_side_bar_.GetWidth() + kGap * 3/2, w_main_.GetHeight() + kGap * 3/2)
{}

void Application::InitializingScript()
{
    w_side_bar_.ClearAllElements();
    w_main_.ClearAllElements();
    w_status_.ClearAllElements();

    w_side_bar_.setViewPort(sf::FloatRect(0, 0, 0.25, 1));
    w_main_.setViewPort(sf::FloatRect(0.25, 0, 0.75, 0.666));
    w_status_.setViewPort(sf::FloatRect(0.25, 0.666, 0.75, 0.333));
    
    rend_window_.setFramerateLimit(Constants::kFrameLimit);
}

void Application::Render()
{
    w_side_bar_.Render(rend_window_, 0, 0);
    w_status_.Render(rend_window_, 0, 0);
    w_main_.Render(rend_window_, 0, 0);
}

void Application::Update()
{
    w_side_bar_.Update(0, 0);
    w_status_.Update(0, 0);
    w_main_.Update(0, 0);
}

void Application::SetKnowledge_MousePosition()
{
    auto position = sf::Mouse::getPosition();
    auto window_pos = rend_window_.getPosition();
    Knowledge::SetMousePoz({position.x - window_pos.x, position.y - window_pos.y});
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

        // w_main_.AddSampleUiElement(power_btn_ptr);
        w_side_bar_.AddSampleUiElement(play_btn_ptr);
        w_status_.AddSampleUiElement(power_btn_ptr);

        power_btn_ptr->SetColor(sf::Color::Green);

        /// Lets add some list of objects!!
        const std::string play_str = "data/img/play_button.png";
        const std::string power_str = "data/img/power_button.png";
        SharedPtr<ScrollableList> my_scroll_list(new ScrollableList(550, 470));
        for (int i = 0;  i < 40;  ++i) {
            SharedPtr<DummyUI> someDummy(new DummyUI(400 + rand() % 100, 10 + rand() % 20));
            my_scroll_list->AddUiElement(someDummy);
        }

        w_main_.AddSampleUiElement(my_scroll_list);
    }
    /// should delete the scope above

    while (rend_window_.isOpen()){

        sf::Event event;
        while (rend_window_.pollEvent(event)){
            Knowledge::Reset();
            Knowledge::SetEvent(event);
            SetKnowledge_MousePosition();

            switch (event.type)
            {
                case sf::Event::Closed:
                {
                    rend_window_.close();
                    Logger::Get() << "The window was closed\n";
                    break;
                }  

                case sf::Event::MouseButtonPressed:
                {
                    EventHandler::Click(event);  
                    break;           
                }
                case sf::Event::MouseWheelScrolled:
                {
                    EventHandler::MouseWheelScrolled(event);
                    break;
                }
                default:
                {
                    break;
                }
            }
            this->Update();            
        }

        rend_window_.clear(sf::Color::White);

        _Debug_BackGroundRectangles();

        this->Render();
        rend_window_.display();        
    }

    return 0;
}

void Application::_Debug_PrintMousePosition()
{
    auto position = sf::Mouse::getPosition();
    auto window_pos = rend_window_.getPosition();
    Logger::Get() << "Mouse hovering at: " << position.x - window_pos.x << ' ' << position.y - window_pos.y << '\n';
}

void Application::_Debug_BackGroundRectangles()
{
    auto rect = sf::RectangleShape();

    rect.setFillColor(Constants::kWindowBackground);
    rect.setPosition(sf::Vector2f(w_side_bar_.off_x, w_side_bar_.off_y));
    rect.setSize(sf::Vector2f(w_side_bar_.GetWidth(), w_side_bar_.GetHeight()));
    rend_window_.draw(rect);

    rect.setFillColor(Constants::kWindowBackground);
    rect.setPosition(sf::Vector2f(w_main_.off_x, w_main_.off_y));
    rect.setSize(sf::Vector2f(w_main_.GetWidth(), w_main_.GetHeight()));
    rend_window_.draw(rect);

    rect.setFillColor(Constants::kWindowBackground);
    rect.setPosition(sf::Vector2f(w_status_.off_x, w_status_.off_y));
    rect.setSize(sf::Vector2f(w_status_.GetWidth(), w_status_.GetHeight()));
    rend_window_.draw(rect);
}