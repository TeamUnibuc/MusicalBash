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
}

void Application::Update()
{
<<<<<<< HEAD
    Logger::Get() << "INFO:  New Update tick!\n";

=======
    /// Updating multithread stuff
    CImportAlbum::PostExecutionVerification();
    CCreatePlaylists::PostExecutionVerification();
    CDownloadFromWeb::PostExecutionVerification();
    
>>>>>>> master
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

    sf::Clock debug_clock;
    bool startedSong = 0;

    Logger::Get() << "Application run called\n";

    InitializingScript();

    /// reset clock for updating
    clock_update_.restart();

    while (rend_window_.isOpen()){
        
        /// Handle events that took place from last render

        sf::Event event;
        while (rend_window_.pollEvent(event)){
            Knowledge::SetEvent(event);
            SetKnowledge_MousePosition();

            Logger::Get() << "SFML:  I Got an event!\n";

            switch (event.type)
            {
                case sf::Event::MouseButtonPressed:
                {
                    EventHandler::Click();
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
                case sf::Event::Closed:
                {
                    Knowledge::Daddy_Player->Zip();
                    rend_window_.close();
                    Logger::Get() << "The window was closed\n";
                    break;
                }
                default:
                    break;
            }
            /// Update UiElements if they "sense" something need to be changed
            if (event.type != sf::Event::MouseMoved) {
                this->Update(); 

                /// Reset the knowledge so we dont update multiple times
                Knowledge::ResetEvent();
            }
        }

        /// once every ktimetoupdate we have to refresh
        if (clock_update_.getElapsedTime().asSeconds() > Constants::kTimeToUpdate) {
            this->Update();
            clock_update_.restart();

            /// refreshing the downloads folder
            Knowledge::Daddy_Player->CreateAlbum(Constants::application_path + "/downloads");
        }

        /// Music Player loop
        Knowledge::Daddy_Player->Step();

        rend_window_.clear(Constants::kAppBackground);

        this->Render();
        rend_window_.display();  




        if(debug_clock.getElapsedTime().asSeconds() > 2) {  /// DEBUG
            if (not startedSong) {
                startedSong = 1;
                // Logger::Get() << "Creating and playing test music.....\n";
                // auto music_ptr = SharedPtr<PMusic>(new PMusic("data/music_samples/beatSample.mp3"));
                // Knowledge::Daddy_Player->addMusicToQueue(music_ptr);
                // music_ptr = SharedPtr<PMusic>(new PMusic("data/music_samples/IWillSurvive.wav"));
                // Knowledge::Daddy_Player->addMusicToQueue(music_ptr);
                // music_ptr = SharedPtr<PMusic>(new PMusic("data/music_samples/beatSample.mp3"));
                // Knowledge::Daddy_Player->addMusicToQueue(music_ptr);

                

                Logger::Get() << "DEBUG: Adding Album to Player\n";
                Knowledge::Daddy_Player->CreateAlbum("data");

                Knowledge::Daddy_Player->addAlbumToQueue( Knowledge::Daddy_Player->getAlbums()[0] );

                Knowledge::Daddy_Player->PlayMusic();

                // Knowledge::Daddy_Player->PlayMusic();
                
                // Knowledge::Daddy_Player->CreateAlbum("data/music_samples");
                
                for (int i = 0; i < 2; ++i) {
                    auto album_ptr = Knowledge::Daddy_Player->getAlbums()[0];

                    Knowledge::Daddy_Player->addAlbumToQueue(album_ptr);

                    Knowledge::Daddy_Player->CreatePlaylist("Test Playlist" + std::to_string(i));
                    Knowledge::Daddy_Player->CreatePlaylist("Coding" + std::to_string(i));

                    Knowledge::Daddy_Player->getPlaylists()[0]->AddMusic(
                        Knowledge::Daddy_Player->getAllMusic()[2]
                    );
                    
                    Knowledge::Daddy_Player->getPlaylists()[0]->AddMusic(
                        Knowledge::Daddy_Player->getAllMusic()[1]
                    );
                }
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