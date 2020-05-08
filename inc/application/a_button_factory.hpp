#pragma once

#include "a_constants.hpp"
#include "u_element.hpp"

#include "u_color_button.hpp"
#include "c_common_commands.hpp"

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

    static UniquePtr<UiElement> CreateButton(SideType type);

    static UniquePtr<UiElement> CreateButton(ActionType type);

    static UniquePtr<UiElement> CreateButton(PlayerType type);
};