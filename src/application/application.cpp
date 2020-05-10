#include "application.hpp"

using Constants::kGap, Constants::kWidth, Constants::kHeight;
 
Application::Application() :
    /// Sizes for views in pixels, relative to the optimal size of the app
    /// App will anyway scale how it should on resize
    rend_window_(sf::VideoMode(kWidth, kHeight), 
            Constants::kApplicationName,
            sf::Style::Close | sf::Style::Titlebar),

    w_side_bar_(kWidth * 1/4 - kGap, kHeight - kGap, 
                kGap * 1/2, kGap * 1/2,
                Musical::Window::Type::Side),

    w_main_(kWidth * 3/4 - kGap, kHeight * 2/3 - kGap,
            w_side_bar_.GetWidth() + kGap * 3/2, kGap * 1/2,
            Musical::Window::Type::Main),
            
    w_status_(kWidth * 3/4 - kGap, kHeight * 1/3 - kGap,
              w_side_bar_.GetWidth() + kGap * 3/2, w_main_.GetHeight() + kGap * 3/2,
              Musical::Window::Type::Status)
{}

void Application::InitUI()
{
    w_side_bar_.ClearAllElements();
    w_main_.ClearAllElements();
    w_status_.ClearAllElements();

    w_side_bar_.setViewPort(sf::FloatRect(0, 0, 0.25, 1));
    w_main_.setViewPort(sf::FloatRect(0.25, 0, 0.75, 0.666));
    w_status_.setViewPort(sf::FloatRect(0.25, 0.666, 0.75, 0.333));
    
    rend_window_.setFramerateLimit(Constants::kFrameLimit);

    
    if (!Constants::kFont.loadFromFile(Constants::kFontPath))
        throw loading_error(Constants::kFontPath);
    else
        Logger::Get() << "Successfully loaded the global font" << '\n';
}

void Application::InitializingScript()
{
    InitUI();

    PopulateWindows();

    Logger::Get() << "Creating DaddyPlayer Instance\n";
    Knowledge::Daddy_Player = std::make_unique<Player>();
    Logger::Get() << Knowledge::GetActiveSongNameOrEmpty() << '\n';
    Logger::Get() << "DaddyPlayer created\n";
}

void Application::PopulateWindows()
{
  { /// Left side bar
    for (int  vertical = 20, gap = 20;
         auto btn_type : {ButtonFactory::SideType::Home,
                          ButtonFactory::SideType::Playlists,
                          ButtonFactory::SideType::Albums,
                          ButtonFactory::SideType::MusicQueue,
                          ButtonFactory::SideType::ImportAlbum,
                          ButtonFactory::SideType::CreatePlaylist}) {
        auto btn_ptr = ButtonFactory::Create(btn_type);
        btn_ptr->SetPosition({20, vertical});
        vertical += btn_ptr->GetHeight() + gap;

        w_side_bar_.AddSampleUiElement(std::move(btn_ptr));
    }

    auto about_ptr = ButtonFactory::Create(ButtonFactory::SideType::About);
    about_ptr->SetPosition({20, 630});
    w_side_bar_.AddSampleUiElement(std::move(about_ptr));
  }

  { /// Clickable square buttons in status bar
    auto curr_song_txt_box = std::make_unique<SongTextBox>(4, 30, 550, 37, 1, "---");
    w_status_.AddSampleUiElement(std::move(curr_song_txt_box));

    for (int horizontal = 160, vertical = 120, gap = 22;
         auto btn_type : {ButtonFactory::PlayerType::Stop,
                          ButtonFactory::PlayerType::Back,
                          ButtonFactory::PlayerType::PlayPause,
                          ButtonFactory::PlayerType::Next,
                          ButtonFactory::PlayerType::Shuffle}) {
        auto ptr = ButtonFactory::Create(btn_type);
        ptr->SetPosition({horizontal, vertical});
        horizontal += ptr->GetWidth() + gap;
        w_status_.AddSampleUiElement(std::move(ptr));
    }

    for (int horizontal = 700, vertical = 120, gap = 22;
         auto btn_type : {ButtonFactory::PlayerType::VolDown,
                          ButtonFactory::PlayerType::VolUp}) {
        auto ptr = ButtonFactory::Create(btn_type);
        ptr->SetPosition({horizontal, vertical});
        horizontal += ptr->GetWidth() + gap;
        w_status_.AddSampleUiElement(std::move(ptr));
    }
  }
    
  { /// Creating song progress bar
    auto song_bar = std::make_unique<ProgressBar>(
        540, 6, 4, 10, sf::Color::White, sf::Color::Black, sf::Color(185, 87, 255),
        [](){
            auto curr_second = Knowledge::Daddy_Player->getActiveSongPlayingOffset();
            auto length = Knowledge::Daddy_Player->getActiveSongDuration();

            if (length < 0.1)
                return 0.;

            return curr_second / length * 100; 
        }
    );
    song_bar->SetPosition({20, 194});
    w_status_.AddSampleUiElement(std::move(song_bar));
  }
  
  { /// Creating volume bar
    auto vol_bar = std::make_unique<ProgressBar>(
        190, 6, 6, 6, sf::Color::White, sf::Color::Black, sf::Color(150, 150, 150),
        [](){
            return Knowledge::Daddy_Player->getVolume();
        } 
    );
    vol_bar->SetPosition({650, 194});

    w_status_.AddSampleUiElement(std::move(vol_bar));
  }

  { /// Creating the Time Marks
    auto from_ptr = std::make_unique<DynamicTextBox>(
        -5, 130, 90, 30, 2, "---",
        [](){
            int time = Knowledge::Daddy_Player->getActiveSongPlayingOffset();
            // Logger::Get() << "Set seconds: " << time << '\n';
            return Utils::IntToMinSecondSecond(time);
        }
    );
    w_status_.AddSampleUiElement(std::move(from_ptr));

    auto until_ptr = std::make_unique<DynamicTextBox>(
        485, 130, 90, 30, 0, "---",
        [](){
            int total = Knowledge::Daddy_Player->getActiveSongDuration();
            int time = Knowledge::Daddy_Player->getActiveSongPlayingOffset();
            if (total < 0 || time < 0 || total - time < 0)
                Logger::Get() << "Bad remaining duration from Player:  total = " << total << "  offset = " << time << '\n';
            return Utils::IntToMinSecondSecond(total - time);
        }
    );
    w_status_.AddSampleUiElement(std::move(until_ptr));
  }
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
    Knowledge::SetMousePoz({position.x - window_pos.x, position.y - window_pos.y - Constants::kTopBarSize});
}

int Application::Run()
{
    using std::cout;

    sf::Clock my_clock;
    bool startedSong = 0;

    InitializingScript();

    /// scope for testing
    
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
                    Logger::Get() << "Size of all music: " << Knowledge::Daddy_Player->getAllMusic().size() << '\n';
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
                default:
                {
                    break;
                }
            }
            this->Update();            
        }

        /// Music Player loop
        Knowledge::Daddy_Player->Step();

        /// Game loop UI

        rend_window_.clear(Constants::kAppBackground);

        _Debug_BackGroundRectangles();

        this->Render();
        rend_window_.display();  

        if(my_clock.getElapsedTime().asSeconds() > 3) {  /// DEBUG
            if (not startedSong) {
                startedSong = 1;
                Logger::Get() << "Creating and playing test music.....\n";
                auto music_ptr = SharedPtr<PMusic>(new PMusic("data/music_samples/IWillSurvive.wav"));
                Knowledge::Daddy_Player->addMusicToQueue(music_ptr);
                music_ptr = SharedPtr<PMusic>(new PMusic("data/music_samples/beatSample.mp3"));
                Knowledge::Daddy_Player->addMusicToQueue(music_ptr);

                Knowledge::Daddy_Player->PlayMusic();
            }
        }
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
}