#ifndef INC_APPLICATION_CONSTANTS_
#define INC_APPLICATION_CONSTANTS_

#include <vector>
#include <string>
#include <memory>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

namespace Constants
{
    /// width and height of thw Window (that holds every part of the UI))
    extern const int kWidth, kHeight, kTopBarSize;

    /// Space between Main windows
    extern const int kGap;

    extern const sf::Color kWindowBackground;
    extern const sf::Color kAppBackground;
    extern const sf::Color kSideBtnIdle, kSideBtnHover;
    extern const sf::Color kPurple;

    /// Maximum framerate
    extern const int    kFrameLimit;

    /// How much time to pass until Update function it's propagated again, even if no event takes place
    extern const double kTimeToUpdate;


    /// Name of the application
    extern const std::string              kApplicationName;

    /// holds a list of accepted extensions by the application
    extern const std::vector<std::string> kMusicExtensions;

    /// holds the font used by the application
    extern sf::Font           kFont;
    extern const std::string  kFontPath;

    extern const int  kVolumeStep;
    extern const int  kStartingVolume;

};

#endif // INC_APPLICATION_CONSTANTS_