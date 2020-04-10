#ifndef INC_APPLICATION_CONSTANTS_
#define INC_APPLICATION_CONSTANTS_

#include <vector>
#include <string>

namespace Constants
{
    /// width and height of thw Window (that holds every part of the UI))
    extern const int kWidth, kHeight;

    /// Name of the application
    extern const std::string kApplicationName;

    /// holds a list of accepted extensions by the application
    extern const std::vector<std::string> kMusicExtensions;
};

#endif // INC_APPLICATION_CONSTANTS_