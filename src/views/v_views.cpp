#include "v_views.hpp"

const int ViewsMain::kListWidthSimple  = 760 + 18;
const int ViewsMain::kListWidthButtons = 760 + 18 + 180;
const int ViewsMain::kListHeight       = 440; 
const int ViewsMain::kEntryHeight      = 66;

const int ViewsMain::kTitleHeight      = 38;


const std::pair<int,int> ViewsMain::kListPoz = {40, 50};

/// ====== Utils =====================

void ViewsMain::SetTitle(const std::string& str, UiContainer *const c_ptr, UiElement *const fatherUi)
{
    SharedPtr<TextBox> tb_ptr(new TextBox(0, 5, fatherUi->GetWidth(), kTitleHeight, 1, str));
    c_ptr->AddUiElementToList(tb_ptr);
}

/// ====================================== Main ======= Create ======= Home ==================

void ViewsMain::CreateHome(UiContainer *const father, UiElement *const fatherUi)
{
    Logger::Get() << "INFO: Creating Home View\n";

    SetTitle("Home", father, fatherUi);

    const int colWidth = 220, colHeight = 40, colGap = 70;
    const int lineGap  = 10,  lineOffsetX = 36, lineOffsetY = kTitleHeight + 55;
    const int nrItems  = 4;

/// Add the Buttons for Albums, Playlists and Songs  ====================

    auto album_list = Knowledge::Daddy_Player->getAlbums();
    auto playlist_list = Knowledge::Daddy_Player->getPlaylists();
    auto music_list = Knowledge::Daddy_Player->getAllMusic();

    std::random_shuffle(album_list.begin(), album_list.end());
    std::random_shuffle(playlist_list.begin(), playlist_list.end());
    std::random_shuffle(music_list.begin(), music_list.end());

    Logger::Get() << "DEBUG: Sizes =  " << album_list.size() << ' ' << playlist_list.size() << ' ' << music_list.size() << '\n';


    for (size_t i = 0; i < nrItems; ++i) {
        /// Create the first row of elemens
        SharedPtr<TextButton> btn_ptr;
      if (i < album_list.size()) {
        /// create album clickable
        auto c_spec_alb = std::make_unique<CShowSpecificAlbum>(album_list[i]);
        btn_ptr = std::make_shared<TextButton>(
            colWidth, colHeight, std::move(c_spec_alb),
            sf::Color::Transparent, Constants::kSideBtnHover,
            std::make_unique<TextBox>(
                11, 8, colWidth, 25, 0, album_list[i]->GetName()
            )
        );
        btn_ptr->SetPosition({lineOffsetX, lineOffsetY + (lineGap + colHeight) * i});
        father->AddUiElementToList(btn_ptr);
      }

      if (i < playlist_list.size()) {
        /// Create Playlist clickable
        auto c_spec_playlist = std::make_unique<CShowSpecificPlaylist>();
        c_spec_playlist->SetPlaylist(playlist_list[i]);
        btn_ptr = std::make_shared<TextButton>(
            colWidth, colHeight, std::move(c_spec_playlist),
            sf::Color::Transparent, Constants::kSideBtnHover,
            std::make_unique<TextBox>(
                11, 8, colWidth, 25, 0, playlist_list[i]->GetName()
            )
        );
        btn_ptr->SetPosition({lineOffsetX + colGap + colWidth, lineOffsetY + (lineGap + colHeight) * i});
        father->AddUiElementToList(btn_ptr);
      }

      if (i < music_list.size()) {
        /// Create Music clickable
        btn_ptr = std::make_shared<TextButton>(
            colWidth, colHeight, std::make_unique<CAddMusicQueue>(music_list[i]),
            sf::Color::Transparent, Constants::kSideBtnHover,
            std::make_unique<TextBox>(
                11, 8, colWidth, 25, 0, music_list[i]->getSongNameWithoutPath()
            )
        );
        btn_ptr->SetPosition({lineOffsetX + 2 * (colWidth + colGap), lineOffsetY + (lineGap + colHeight) * i});
        father->AddUiElementToList(btn_ptr);
      }

    }

/// Add green texts on top of the 3 lists
    auto txt_ptr = std::make_shared<TextBox>(
        lineOffsetX, kTitleHeight + 20, colWidth, 27, 1, "Albums");
    txt_ptr->SetColor(Constants::kGreen);
    father->AddUiElementToList(txt_ptr);
    
    txt_ptr = std::make_shared<TextBox>(
        lineOffsetX + colGap + colWidth, kTitleHeight + 20, colWidth, 27, 1, "Playlists");
    txt_ptr->SetColor(Constants::kGreen);
    father->AddUiElementToList(txt_ptr);

    txt_ptr = std::make_shared<TextBox>(
        lineOffsetX + 2 * (colGap + colWidth), kTitleHeight + 20, colWidth, 27, 1, "Songs");
    txt_ptr->SetColor(Constants::kGreen);
    father->AddUiElementToList(txt_ptr);
}

/// ====================================== Main ======= Update  ======= Home ==================

void ViewsMain::UpdateHome(UiContainer *const father, UiElement *const fatherUi)
{
    /// Reupdate Home ? Maybe after some time just redo create

    // if (last_time_home_created_.getElapsedTime().asSeconds() > Constants::kTimeToUpdate) {
    //     father->ClearAllUiElements();
    //     CreateHome(father, fatherUi);
    // }
}

/// ======================================= Main ===== Create ===== Queue ==========

void ViewsMain::CreateQueue(UiContainer * const c_ptr, UiElement *const fatherUi)
{
    SetTitle("Current Queue", c_ptr, fatherUi);

    auto lst_ptr = std::make_unique<ScrollableList>(
        kListWidthSimple, kListHeight
    );
    lst_ptr->SetPosition(kListPoz);

    c_ptr->AddUiElementToList(std::move(lst_ptr));
}

/// ================================ Main ===== Update ====== Queue ===============

void ViewsMain::UpdateQueue(SharedPtr<ScrollableList> l_ptr, const std::vector<SharedPtr<PMusic>>& music_list)
{
    int contor = 0;
    for (auto m_ptr : music_list) {
        auto entry_ptr = std::make_unique<MusicEntry>(
            kListWidthSimple, kEntryHeight, 
            Constants::kSideBtnIdle, Constants::kSideBtnHover,
            m_ptr, ++contor
        );
        l_ptr->AddUiElement(std::move(entry_ptr));
    }
}

/// ============================= Main ===== Create ===== Albums ====================

void ViewsMain::CreateAlbums(UiContainer *const father, UiElement *const fatherUi)
{
    SetTitle("Albums", father, fatherUi);

    auto lst_ptr = std::make_unique<ScrollableList>(
        kListWidthButtons, kListHeight
    );
    lst_ptr->SetPosition(kListPoz);

    father->AddUiElementToList(std::move(lst_ptr));
}

/// ============================= Main ===== Update ===== Albums ====================

void ViewsMain::UpdateAlbums(SharedPtr<ScrollableList> l_ptr,
                             const std::vector<SharedPtr<PAlbum>>& album_list)
{
    int contor = 0;
    for (auto a_ptr : album_list) {
        auto entry_ptr = std::make_unique<AlbumEntry>(
            a_ptr, ++contor
        );
        l_ptr->AddUiElement(std::move(entry_ptr));
    }
}

/// ============================= Main ===== Create ===== Playlists =================

void ViewsMain::CreatePlaylists(UiContainer *const father, UiElement *const fatherUi)
{
    SetTitle("Playlists", father, fatherUi);

    auto lst_ptr = std::make_unique<ScrollableList>(
        kListWidthButtons, kListHeight
    );
    lst_ptr->SetPosition(kListPoz);

    father->AddUiElementToList(std::move(lst_ptr));
}

/// ============================= Main ===== Update ===== Playlists =================

void ViewsMain::UpdatePlaylists(SharedPtr<ScrollableList> l_ptr, 
                                const std::vector<SharedPtr<PPlaylist>>& playlist_list)
{
    int contor = 0;
    for (auto pl_ptr : playlist_list) {
        auto entry_ptr = std::make_unique<PlaylistEntry>(
            pl_ptr, ++contor
        );
        l_ptr->AddUiElement(std::move(entry_ptr));
    }
}

/// ============================ Main ===== Create ===== Specific Album =============

void ViewsMain::CreateSpecificAlbum(UiContainer *const father, UiElement *const fatherUi)
{
    const auto& album = Knowledge::State::data.curr_album;
    SetTitle("Album: " + album->GetName(), father, fatherUi);

    auto lst_ptr = std::make_unique<ScrollableList>(
        kListWidthButtons, kListHeight
    );
    lst_ptr->SetPosition(kListPoz);

    father->AddUiElementToList(std::move(lst_ptr));
}

/// ============================ Main ===== Update ===== Specific Album =============

void ViewsMain::UpdateSpecificAlbum(SharedPtr<ScrollableList> l_ptr)
{
    const auto& album = Knowledge::State::data.curr_album;

    // if (album->GetName() != Constants::application_path + "/downloads")
    //     Logger::Get() << " Album to update: " << album->GetName() << '\n';

    int contor = 0;
    for (auto song_ptr : album->GetMusic()) {
        auto entry = std::make_unique<MusicEntry>(
            kListWidthSimple, kEntryHeight, 
            Constants::kSideBtnIdle, Constants::kSideBtnHover,
            song_ptr, ++contor
        );
        l_ptr->AddUiElement(std::move(entry));
    }
}

/// ============================ Main ===== Create ===== Specific Playlist =============

void ViewsMain::CreateSpecificPlaylist(UiContainer *const father, UiElement *const fatherUi)
{
    const auto& playlist = Knowledge::State::data.curr_playlist;
    SetTitle("Playlist: " + playlist->GetName(), father, fatherUi);

    auto lst_ptr = std::make_unique<ScrollableList>(
        kListWidthButtons, kListHeight
    );
    lst_ptr->SetPosition(kListPoz);

    father->AddUiElementToList(std::move(lst_ptr));
}

/// ============================ Main ===== Update ===== Specific Playlist =============

void ViewsMain::UpdateSpecificPlaylist(SharedPtr<ScrollableList> l_ptr)
{
    const auto& playlist = Knowledge::State::data.curr_playlist;

    Logger::Get() << " Playlist to update: " << Knowledge::State::data.curr_playlist->GetName() << '\n';

    int contor = 0;
    for (auto song_ptr : playlist->GetMusic()) {
        auto entry = std::make_unique<SongPlaylistEntry>(
            playlist, song_ptr, ++contor
        );
        l_ptr->AddUiElement(std::move(entry));
    }
}

///  Side Window
/// =========================== Side Menu ======== Create =========================

void ViewsSide::Create(UiContainer *const father_elem)
{
    for (int  vertical = 20, gap = 20;
         auto btn_type : {ButtonFactory::SideType::Home,
                          ButtonFactory::SideType::Playlists,
                          ButtonFactory::SideType::Albums,
                          ButtonFactory::SideType::MusicQueue,
                          ButtonFactory::SideType::ImportAlbum,
                          ButtonFactory::SideType::CreatePlaylist,
                          ButtonFactory::SideType::Download}) {
        auto btn_ptr = ButtonFactory::Create(btn_type);
        btn_ptr->SetPosition({20, vertical});
        vertical += btn_ptr->GetHeight() + gap;

        father_elem->AddUiElementToList(std::move(btn_ptr));
    }

    auto about_ptr = ButtonFactory::Create(ButtonFactory::SideType::About);
    about_ptr->SetPosition({20, 630});
    father_elem->AddUiElementToList(std::move(about_ptr));
}

/// ==================================================== Status ======= Create ====================

void ViewsStatus::Create(UiContainer *const father_elem)
{
  { /// Clickable square buttons in status bar
    auto curr_song_txt_box = std::make_unique<SongTextBox>(4, 30, 550, 37, 1, "---");
    father_elem->AddUiElementToList(std::move(curr_song_txt_box));

    for (int horizontal = 160, vertical = 120, gap = 22;
         auto btn_type : {ButtonFactory::PlayerType::Stop,
                          ButtonFactory::PlayerType::Back,
                          ButtonFactory::PlayerType::PlayPause,
                          ButtonFactory::PlayerType::Next,
                          ButtonFactory::PlayerType::Shuffle}) {
        auto ptr = ButtonFactory::Create(btn_type);
        ptr->SetPosition({horizontal, vertical});
        horizontal += ptr->GetWidth() + gap;
        father_elem->AddUiElementToList(std::move(ptr));
    }

    for (int horizontal = 700, vertical = 120, gap = 22;
         auto btn_type : {ButtonFactory::PlayerType::VolDown,
                          ButtonFactory::PlayerType::VolUp}) {
        auto ptr = ButtonFactory::Create(btn_type);
        ptr->SetPosition({horizontal, vertical});
        horizontal += ptr->GetWidth() + gap;
        father_elem->AddUiElementToList(std::move(ptr));
    }
  }
    
  { /// Creating song progress bar
    auto song_bar = std::make_unique<ProgressBar>(
        540, 6, 4, 10, sf::Color::White, sf::Color::Black, Constants::kPurple,
        [](){
            auto curr_second = Knowledge::Daddy_Player->getActiveSongPlayingOffset();
            auto length = Knowledge::Daddy_Player->getActiveSongDuration();

            if (length < 0.1)
                return 0.;

            return curr_second / length * 100; 
        },
        std::make_unique<CPlayerSetPlayingOffset>()
    );
    song_bar->SetPosition({20, 194});
    father_elem->AddUiElementToList(std::move(song_bar));
  }
  
  { /// Creating volume bar
    auto vol_bar = std::make_unique<ProgressBar>(
        190, 6, 6, 6, sf::Color::White, sf::Color::Black, Constants::kPurple,
        [](){
            return Knowledge::Daddy_Player->getVolume();
        },
        std::make_unique<CPlayerSetVol>()
    );
    vol_bar->SetPosition({650, 194});

    father_elem->AddUiElementToList(std::move(vol_bar));
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
    father_elem->AddUiElementToList(std::move(from_ptr));

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
    father_elem->AddUiElementToList(std::move(until_ptr));
  }
}