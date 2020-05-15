#include "application.hpp"

using Constants::kGap, Constants::kWidth, Constants::kHeight;
 
Application::Application() :
    /// Sizes for views in pixels, relative to the optimal size of the app
    /// App will anyway scale how it should on resize
    rend_window_(sf::VideoMode(kWidth, kHeight), 
            Constants::kApplicationName,
            sf::Style::Default),

    w_side_bar_(kWidth * 1/4 - kGap, kHeight - kGap, 
                kGap * 2/3, kGap * 1/2,
                Musical::Window::Type::Side),

    w_main_(kWidth * 3/4 - kGap, kHeight * 2/3 - kGap * 1/2,
            w_side_bar_.GetWidth() + kGap * 4/3, kGap * 1/2,
            Musical::Window::Type::Main),
            
    w_status_(kWidth * 3/4 - kGap, kHeight * 1/3 - kGap,
              w_side_bar_.GetWidth() + kGap * 4/3, w_main_.GetHeight() + kGap,
              Musical::Window::Type::Status)
{}

void Application::InitializingScript()
{
    Logger::Get() << "Called the initializing script\n";
    /// computes the absolute path of `$HOME/.musicalbash`
    Constants::CreateApplicationPath();

    Logger::Get() << "Creating DaddyPlayer Instance\n";
    
    Knowledge::Daddy_Player = std::make_unique<Player>();

    Logger::Get() << Knowledge::Daddy_Player->getActiveSong()->getName() << '\n';
    Logger::Get() << "DaddyPlayer created\n";

    InitUI();

    PopulateWindows();
}

void Application::InitUI()
{
    w_side_bar_.ClearAllUiElements();
    w_main_.ClearAllUiElements();
    w_status_.ClearAllUiElements();

    rend_window_.setFramerateLimit(Constants::kFrameLimit);

    
    if (!Constants::kFont.loadFromFile(Constants::kFontPath))
        throw loading_error(Constants::kFontPath);
    else
        Logger::Get() << "Successfully loaded the global font" << '\n';
}

void Application::PopulateWindows()
{
    ViewsSide::Create(&w_side_bar_);

    ViewsStatus::Create(&w_status_);
}

void Application::Render()
{
    /// Displays the darker rectangles behind every Big UI Window
    rend_window_.clear(Constants::kAppBackground);

    auto rect = sf::RectangleShape();

    rect.setFillColor(Constants::kWindowBackground);
    rect.setPosition(sf::Vector2f(w_side_bar_.g_off_x, w_side_bar_.g_off_y));
    rect.setSize(sf::Vector2f(w_side_bar_.GetWidth(), w_side_bar_.GetHeight()));
    rend_window_.draw(rect);

    rect.setFillColor(Constants::kWindowBackground);
    rect.setPosition(sf::Vector2f(w_main_.g_off_x, w_main_.g_off_y));
    rect.setSize(sf::Vector2f(w_main_.GetWidth(), w_main_.GetHeight()));
    rend_window_.draw(rect);

    rect.setFillColor(Constants::kWindowBackground);
    rect.setPosition(sf::Vector2f(w_status_.g_off_x, w_status_.g_off_y));
    rect.setSize(sf::Vector2f(w_status_.GetWidth(), w_status_.GetHeight()));
    rend_window_.draw(rect);

    /// Renders its children
    w_side_bar_.Render(rend_window_, 0, 0);
    w_status_.Render(rend_window_, 0, 0);
    w_main_.Render(rend_window_, 0, 0);

    rend_window_.display(); 
}

void Application::Update()
{
    /// Updating multithread stuff
    CImportAlbum::PostExecutionVerification();
    CCreatePlaylists::PostExecutionVerification();
    CDownloadFromWeb::PostExecutionVerification();
    
    // sf::Clock cll;

    w_side_bar_.Update(0, 0);
    w_status_.Update(0, 0);
    w_main_.Update(0, 0);

    // Logger::Get() << "Update Time: " << cll.getElapsedTime().asMilliseconds() << '\n';
    // cll.restart();
}

void Application::SetKnowledge_MousePosition()
{
    auto position = sf::Mouse::getPosition();
    auto window_pos = rend_window_.getPosition();
    
    std::pair <int, int> poz = { position.x - window_pos.x, position.y - window_pos.y - Constants::kTopBarSize };
    double mult_x = 1. * Constants::kWidth / rend_window_.getSize().x; 
    double mult_y = 1. * Constants::kHeight / rend_window_.getSize().y;
    poz.first = std::round(poz.first * mult_x);
    poz.second = std::round(poz.second * mult_y);

    Knowledge::SetMousePoz(poz);
}

int Application::Run()
{
    InitializingScript();

    /// reset clock for updating
    clock_update_.restart();

    while (rend_window_.isOpen()){

        sf::Event event;
        while (rend_window_.pollEvent(event)){
            Knowledge::SetEvent(event);
            SetKnowledge_MousePosition();

            switch (event.type)
            {
                case sf::Event::MouseButtonPressed:
                {
                    EventHandler::Click();
                    break;           
                }

                case sf::Event::MouseWheelScrolled:
                {
                    EventHandler::MouseWheelScrolled(event);
                    break;
                }
                /// This is mostly for debug
                case sf::Event::KeyPressed:
                {
                    if (event.key.code == sf::Keyboard::LAlt)
                        EventHandler::DebugKeyDown();
                    break;
                }

                case sf::Event::Closed:
                {
                    EventHandler::Close(rend_window_);
                    break;
                }
                case sf::Event::MouseMoved:
                {
                    continue;
                    break;
                }
                default:
                    break;
            }

            this->Update();
            this->Render();

            Knowledge::ResetEvent();
        }

        if (clock_update_.getElapsedTime().asSeconds() > 1. / Constants::kFrameLimit) {
            Knowledge::Daddy_Player->CreateAlbum(Constants::kApplicationPath + "/downloads");
            this->Update();
            this->Render();
            Knowledge::Daddy_Player->Step();

            clock_update_.restart();
        }
    }

    return 0;
}
