#include "v_views.hpp"

const int ViewsMain::kListWidthSimple  = 760 + 18;
const int ViewsMain::kListWidthButtons = 550;
const int ViewsMain::kListHeight       = 440; 
const int ViewsMain::kEntryHeight      = 66;

const std::pair<int,int> ViewsMain::kListPoz = {40, 50};


void ViewsMain::Home()
{

}

/// ======================================= Main ===== Create ===== Queue ==========

void ViewsMain::CreateQueue(UiContainer * const c_ptr)
{
    auto txt_ptr = std::make_unique<TextBox>(
        5, 8, 700, 30, 1, "Current Queue"
    );

    c_ptr->AddUiElementToList(std::move(txt_ptr));

    auto lst_ptr = std::make_unique<ScrollableList>(
        kListWidthSimple, kListHeight
    );
    lst_ptr->SetPosition(kListPoz);

    c_ptr->AddUiElementToList(std::move(lst_ptr));
}

/// ================================ Main ===== Update ====== Queue ===============

void ViewsMain::UpdateQueue(SharedPtr<ScrollableList> l_ptr, const std::vector<SharedPtr<PMusic>>& music_list)
{
    for (auto m_ptr : music_list) {
        auto entry_ptr = std::make_unique<MusicEntry>(
            kListWidthSimple, kEntryHeight, 
            Constants::kSideBtnIdle, Constants::kSideBtnHover,
            m_ptr
        );
        l_ptr->AddUiElement(std::move(entry_ptr));
    }
}

/// ==================================================== Side Menu ======== Create =========================
void ViewsSide::Create(UiContainer *const father_elem)
{
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
        }
    );
    song_bar->SetPosition({20, 194});
    father_elem->AddUiElementToList(std::move(song_bar));
  }
  
  { /// Creating volume bar
    auto vol_bar = std::make_unique<ProgressBar>(
        190, 6, 6, 6, sf::Color::White, sf::Color::Black, Constants::kPurple,
        [](){
            return Knowledge::Daddy_Player->getVolume();
        } 
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