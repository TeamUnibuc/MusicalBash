#include "a_constants.hpp"
#include "a_logger.hpp"
#include "a_exceptions.hpp"

namespace Constants
{

constexpr int kWidth      = 1200;
constexpr int kHeight     = 750;
constexpr int kTopBarSize = 40;

constexpr int kGap = 30;

constexpr int    kFrameLimit   = 75;

const std::string kFontPath = "data/fonts/UbuntuMono-R.ttf";

const sf::Color kWindowBackground = sf::Color(70,  70, 70,  210);
const sf::Color kAppBackground    = sf::Color(20,  20, 20, 255);
const sf::Color kSideBtnHover     = sf::Color(20,  20,  20,  240);
const sf::Color kSideBtnIdle      = sf::Color(100, 100, 100, 240);
const sf::Color kSideActBtnIdle   = sf::Color(59, 50, 44, 240);
const sf::Color kSideActBtnHover  = sf::Color(128, 99, 80, 240);
const sf::Color kPurple           = sf::Color(185, 87,  255);
const sf::Color kGreen            = sf::Color(12,  201, 22);

const sf::Event kMockEvent = {sf::Event::JoystickConnected, {}};

const std::string kApplicationName = "Musical Bash";

const std::vector<std::string> kMusicExtensions {
    ".mp3",
    ".wav"
};

sf::Font kFont;

constexpr int kVolumeStep = 10;
constexpr int kStartingVolume = 50;

std::string kApplicationPath;

void CreateApplicationPath()
{
    Logger::Get() << "INFO:  Creating applicaition folders\n";

    system("mkdir $HOME/.musicalbash -p");
    system("mkdir $HOME/.musicalbash/downloads -p");
    system("mkdir $HOME/.musicalbash/database -p"); 
    system("mkdir $HOME/.musicalbash/tmp -p");

    char path[1024];
    path[0] = 0;
    
    FILE *f = popen("(cd $HOME/.musicalbash; pwd)", "r");
    fgets(path, 1024, f);

    if (path[0] == 0)
        throw bad_behaviour("Unable to find application path!");
    
    kApplicationPath = std::string(path);
    kApplicationPath.pop_back();

    Logger::Get() << "INFO:  Found app path at \"" + kApplicationPath + "\"\n";

    Logger::Get() << "INFO:  Running rm cache command for youtube-dl\n";
    system("youtube-dl --rm-cache-dir");
}

}