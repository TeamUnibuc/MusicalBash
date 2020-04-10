#ifndef INC_APPLICATION_CONSTANTS_
#define INC_APPLICATION_CONSTANTS_

#include <vector>
#include <string>

namespace Constants
{
    /// States saying what should each window should look for in each frame
    /// Also used to see if we need to rebuild the structure of the Music::Window
    enum State
    {
        Side_Normal,
        Main_Home,
        Main_Playlists,
        Main_Albums,
        Main_AllSongs,
        Main_ManageSongs,
        Status_Playing,
        Status_NotPlaying,
        Status_Nothing
    };

    /// width and height of thw Window (that holds every part of the UI))
    extern const int kWidth, kHeight;

    /// Maximum framerate
    extern const int kFrameLimit;

    /// Name of the application
    extern const std::string kApplicationName;

    /// holds a list of accepted extensions by the application
    extern const std::vector<std::string> kMusicExtensions;
};

#endif // INC_APPLICATION_CONSTANTS_