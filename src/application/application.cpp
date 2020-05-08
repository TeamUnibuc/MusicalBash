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
    /// Left side bar
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

    /// TO DO, place Music player elements
    auto curr_song_txt_box = std::make_unique<SongTextBox>(0, 10, 550, 37, 1, "---");
    w_status_.AddSampleUiElement(std::move(curr_song_txt_box));
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
    {
        /// Lets add some list of objects!!
        const std::string play_str = "data/img/play_button.png";
        const std::string power_str = "data/img/power_button.png";
        SharedPtr<ScrollableList> my_scroll_list(new ScrollableList(550, 470));
        for (int i = 0;  i < 20;  ++i) {
            // SharedPtr<DummyUI> someDummy(new DummyUI(400 + rand() % 100, 10 + rand() % 20));
            SharedPtr<TextBox> someDummy(new TextBox(0, 0, 550, 40, 0, "Musical Bash"));
            if (i % 3 == 0){
                someDummy->SetColor(sf::Color::Blue);
                someDummy->SetAlignment(i % 3);
            }
            else if (i % 3 == 1) {
                someDummy->SetColor(sf::Color::Yellow);
                someDummy->SetAlignment(i % 3);
            }
            else {
                someDummy->SetColor(sf::Color::Red);
                someDummy->SetAlignment(i % 3);
            }
            
            my_scroll_list->AddUiElement(someDummy);
        }
        for (int i = 20; i < 40; ++i){
            SharedPtr<TextBox> someDummy(new TextBox(0, 0, 550, 40, 0, "The FitnessGram Pacer Test is a multistage aerobic capacity test that progressively gets more difficult as it continues. The 20 meter pacer test will begin in 30 seconds. Line up at the start. The running speed starts slowly but gets faster each minute after you hear this signal bodeboop."));
            if (i % 3 == 0){
                someDummy->SetColor(sf::Color::Blue);
                
            }
            else if (i % 3 == 1){
                someDummy->SetColor(sf::Color::Yellow);
                someDummy->SetAlignment(i % 3);
            }
            else{
                someDummy->SetColor(sf::Color::Red);
                someDummy->SetAlignment(i % 3);
            }
            
            my_scroll_list->AddUiElement(someDummy);
        }


        w_main_.AddSampleUiElement(my_scroll_list);

        SharedPtr<TextBox> my_text_box(new TextBox(0, 0, 550, 50, 0, "The FitnessGram Pacer Test is a multistage aerobic capacity test that progressively gets more difficult as it continues. The 20 meter pacer test will begin in 30 seconds. Line up at the start. The running speed starts slowly but gets faster each minute after you hear this signal bodeboop. "));
        SharedPtr<TextBox> my_text_box2(new TextBox(0, 50, 550, 50, 0, "Musical Bash"));
        SharedPtr<TextBox> my_text_box3(new TextBox(0, 100, 550, 50, 1, "Musical Bash"));
        SharedPtr<TextBox> my_text_box4(new TextBox(0, 150, 550, 50, 2, "Musical Bash"));

        // w_main_.AddSampleUiElement(my_text_box);
        // w_main_.AddSampleUiElement(my_text_box2);
        // w_main_.AddSampleUiElement(my_text_box3);
        // w_main_.AddSampleUiElement(my_text_box4);
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
                    Logger::Get() << "Size of all music: " << Knowledge::Daddy_Player->getAllMusic().size() << '\n';
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

        rend_window_.clear(Constants::kAppBackground);

        _Debug_BackGroundRectangles();

        this->Render();
        rend_window_.display();  

        if(my_clock.getElapsedTime().asSeconds() > 6) {
            if (not startedSong) {
                startedSong = 1;
                Logger::Get() << "Creating and playing test music.....\n";
                auto music_ptr = SharedPtr<PMusic>(new PMusic("data/music_samples/beatSample.mp3"));
                Knowledge::Daddy_Player->addMusicToQueue(music_ptr);
                music_ptr = SharedPtr<PMusic>(new PMusic("data/music_samples/beatSample copy.mp3"));
                Knowledge::Daddy_Player->addMusicToQueue(music_ptr);

                Knowledge::Daddy_Player->PlayMusic();
            }
            else {
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