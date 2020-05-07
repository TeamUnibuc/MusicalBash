#include "a_constants.hpp"

namespace Constants
{

const int kWidth = 1200;
const int kHeight = 750;
const int kTopBarSize = 40;

const int kGap = 30;

const int kFrameLimit = 75;

const sf::Color kWindowBackground = sf::Color(64,64,64, 199);

const std::string kApplicationName = "Musical Bash";

const std::vector<std::string> kMusicExtensions = {
    ".mp3",
    ".wav"
};

sf::Font kFont;

}