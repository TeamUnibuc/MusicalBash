#include "a_button_factory.hpp"

UniquePtr<UiElement> ButtonFactory::Create(ButtonFactory::SideType type)
{
    const int btnWidth  = 230;
    const int btnHeight = 60;
    const int txtPosY   = 15;
    const int txtSzY    = 30;  /// 2 * txtPosY + txtSzY = btnHeight

    switch (type) {
        case SideType::Home : {
            return std::make_unique<TextButton> (
                btnWidth, btnHeight, std::make_unique<CShowHome>(), 
                Constants::kSideBtnIdle, Constants::kSideBtnHover,
                std::make_unique<TextBox>(0, txtPosY, btnWidth, txtSzY, 1, "Home"));
        }
        case SideType::Albums : {
            return std::make_unique<TextButton> (
                btnWidth, btnHeight, std::make_unique<CShowAlbums>(), 
                Constants::kSideBtnIdle, Constants::kSideBtnHover,
                std::make_unique<TextBox>(0, txtPosY, btnWidth, txtSzY, 1, "Albums"));
        }
        case SideType::Playlists : {
            return std::make_unique<TextButton> (
                btnWidth, btnHeight, std::make_unique<CShowPlaylists>(), 
                Constants::kSideBtnIdle, Constants::kSideBtnHover,
                std::make_unique<TextBox>(0, txtPosY, btnWidth, txtSzY, 1, "Playlists"));
        }
        case SideType::MusicQueue : {
            return std::make_unique<TextButton> (
                btnWidth, btnHeight, std::make_unique<CShowMusicQueue>(), 
                Constants::kSideBtnIdle, Constants::kSideBtnHover,
                std::make_unique<TextBox>(0, txtPosY, btnWidth, txtSzY, 1, "Music queue"));
        }
        case SideType::ImportAlbum : {
            return std::make_unique<TextButton> (
                btnWidth, btnHeight, std::make_unique<CImportAlbum>(), 
                Constants::kSideBtnIdle, Constants::kSideBtnHover,
                std::make_unique<TextBox>(0, txtPosY, btnWidth, txtSzY, 1, "Import Album"));
        }
        case SideType::CreatePlaylist : {
            return std::make_unique<TextButton> (
                btnWidth, btnHeight, std::make_unique<CCreatePlaylists>(), 
                Constants::kSideBtnIdle, Constants::kSideBtnHover,
                std::make_unique<TextBox>(0, txtPosY, btnWidth, txtSzY, 1, "Create Playlist"));
        }
        case SideType::Download : {
            return std::make_unique<TextButton> (
                btnWidth, btnHeight, std::make_unique<CDownloadFromWeb>(), 
                Constants::kSideBtnIdle, Constants::kSideBtnHover,
                std::make_unique<TextBox>(0, txtPosY, btnWidth, txtSzY, 1, "Download"));
        }
        case SideType::About : {
            return std::make_unique<TextButton> (
                btnWidth, btnHeight, std::make_unique<CShowAbout>(), 
                Constants::kSideBtnIdle, Constants::kSideBtnHover,
                std::make_unique<TextBox>(0, txtPosY, btnWidth, txtSzY, 1, "About Musical Bash"));
        }
    }
    throw bad_behaviour("Trying to create an SideType button that doesn't exist");
}

UniquePtr<UiElement> ButtonFactory::Create(ButtonFactory::PlayerType type)
{
    const int szX = 32;
    const int szY = 32;
    const sf::Color idle_color  = sf::Color::White;
    const sf::Color hover_color = sf::Color(203, 154, 225);

    switch (type) {
        case PlayerType::Next : {
            Logger::Get() << " - Created Next object\n";
            auto ptr = std::make_unique<PngColorButton> (
                szX, szY, std::make_unique<CPlayerNext>(), idle_color, hover_color,
                std::make_shared<PngSprite>("data/img/skip_next_white.png")
            );
            return ptr;
        }
        case PlayerType::Back : {
            Logger::Get() << " - Created Back object\n";
            auto ptr = std::make_unique<PngColorButton> (
                szX, szY, std::make_unique<CPlayerBack>(), idle_color, hover_color,
                std::make_shared<PngSprite>("data/img/skip_prev_white.png")
            );
            return ptr;
        }
        case PlayerType::Stop : {
            auto ptr = std::make_unique<PngColorButton> (
                szX, szY, std::make_unique<CPlayerStop>(), idle_color, hover_color,
                std::make_shared<PngSprite>("data/img/stop_button.png")
            );
            return ptr;
        }
        case PlayerType::Shuffle : {
            auto ptr = std::make_unique<PngColorButton> (
                szX, szY, std::make_unique<CPlayerShuffle>(), idle_color, hover_color,
                std::make_shared<PngSprite>("data/img/shuffle_btn.png"),
                [idle_color](sf::Color& col) {
                    if (Knowledge::Daddy_Player->getSufflingStatus())
                        col = Constants::kGreen;
                    else
                        col = idle_color;
                }
            );
            return ptr;
        }
        case PlayerType::PlayPause : {
            auto ptr = std::make_unique<DoublePngColorButton> (
                szX, szY, std::make_unique<CPlayerPlayPause>(), idle_color, hover_color,
                std::make_shared<PngSprite>("data/img/pause_btn_white.png"), 
                std::make_shared<PngSprite>("data/img/play_btn_white.png")
            );
            return ptr;
        }
        case PlayerType::VolUp : {
            auto ptr = std::make_unique<PngColorButton> (
                szX, szY, std::make_unique<CPlayerVolUp>(), idle_color, hover_color,
                std::make_shared<PngSprite>("data/img/music_up.png")
            );
            return ptr;
        }
        case PlayerType::VolDown : {
            auto ptr = std::make_unique<PngColorButton> (
                szX, szY, std::make_unique<CPlayerVolDown>(), idle_color, hover_color,
                std::make_shared<PngSprite>("data/img/music_down.png")
            );
            return ptr;
        }
        
    }

    throw bad_behaviour("Trying to create a PlayerType button that doesn't exist");
}