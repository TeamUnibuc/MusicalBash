#include "a_button_factory.hpp"

UniquePtr<UiElement> ButtonFactory::Create(ButtonFactory::SideType type)
{
    const int btnWidth  = 230;
    const int btnHeight = 60;
    const int txtPosY   = 15;
    const int txtSzY    = 30;

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
        case SideType::About : {
            return std::make_unique<TextButton> (
                btnWidth, btnHeight, std::make_unique<CShowAbout>(), 
                Constants::kSideBtnIdle, Constants::kSideBtnHover,
                std::make_unique<TextBox>(0, txtPosY, btnWidth, txtSzY, 1, "About Musical Bash"));
        }
    }
    throw bad_behaviour("Trying to create an SideType button that doesn't exist");
}