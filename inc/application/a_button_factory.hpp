#pragma once

#include "a_constants.hpp"
#include "a_exceptions.hpp"
#include "u_element.hpp"
#include "u_png_color_button.hpp"

#include "u_text_button.hpp"
#include "c_common_commands.hpp"
#include "c_player.hpp"

class ButtonFactory
{
private:

public:
    enum class SideType
    {
        Home,
        Albums,
        Playlists,
        MusicQueue,
        ImportAlbum,
        CreatePlaylist,
        About
    };
    
    enum class PlayerType
    {
        Shuffle,
        Play,
        Pause,
        Next,
        Stop,
        VolUp,
        VolDown
    };

    enum class ActionType
    {
        DeleteAlbum,
        DeletePlaylist,
        DeleteSongQueue,
        AddToPlaylist,
        DeleteFromPlaylist
    };

    static UniquePtr<UiElement> Create(SideType type);

    static UniquePtr<UiElement> Create(ActionType type);

    static UniquePtr<UiElement> Create(PlayerType type);
};