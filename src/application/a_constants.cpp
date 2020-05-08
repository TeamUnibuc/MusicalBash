#include "a_constants.hpp"

namespace Constants
{

constexpr int kWidth      = 1200;
constexpr int kHeight     = 750;
constexpr int kTopBarSize = 40;

constexpr int kGap = 30;

constexpr int kFrameLimit = 75;

const std::string kFontPath = "data/fonts/UbuntuMono-R.ttf";

const sf::Color kWindowBackground = sf::Color(65,  65,  65,  210);
const sf::Color kAppBackground    = sf::Color(51,  133, 255, 255);
const sf::Color kSideBtnHover     = sf::Color(20,  20,  20,  240);
const sf::Color kSideBtnIdle      = sf::Color(100, 100, 100, 240);

const std::string kApplicationName = "Musical Bash";

const std::vector<std::string> kMusicExtensions {
    ".mp3",
    ".wav"
};

sf::Font kFont;

}