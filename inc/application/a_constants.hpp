#ifndef INC_APPLICATION_CONSTANTS_
#define INC_APPLICATION_CONSTANTS_

#include <vector>
#include <string>
#include <memory>

// Useful typedefs we will use throughout the code
template <typename T>
using SharedPtr = std::shared_ptr<T>;

namespace Constants
{
    /// States saying what should each window should look for in each frame
    /// Also used to see if we need to rebuild the structure of the Music::Window
    enum State
    {
        kHome,
        kPlaylists,
        kAlbums,
        kAllSongs,
        kManageSongs
    };

    /// width and height of thw Window (that holds every part of the UI))
    extern const int kWidth, kHeight, kTopBarSize;

    /// Maximum framerate
    extern const int kFrameLimit;

    /// Name of the application
    extern const std::string kApplicationName;

    /// holds a list of accepted extensions by the application
    extern const std::vector<std::string> kMusicExtensions;
};

#endif // INC_APPLICATION_CONSTANTS_