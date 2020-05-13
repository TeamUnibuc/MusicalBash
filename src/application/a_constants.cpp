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
constexpr double kTimeToUpdate = 0.1;

const std::string kFontPath = "data/fonts/UbuntuMono-R.ttf";

const sf::Color kWindowBackground = sf::Color(65,  65,  65,  210);
const sf::Color kAppBackground    = sf::Color(51,  133, 255, 255);
const sf::Color kSideBtnHover     = sf::Color(20,  20,  20,  240);
const sf::Color kSideBtnIdle      = sf::Color(100, 100, 100, 240);
const sf::Color kPurple           = sf::Color(185, 87,  255);

const std::string kApplicationName = "Musical Bash";

const std::vector<std::string> kMusicExtensions {
    ".mp3",
    ".wav"
};

sf::Font kFont;

constexpr int kVolumeStep = 10;
constexpr int kStartingVolume = 50;

std::string application_path;

void CreateApplicationPath()
{
    Logger::Get() << "Creating applicaition folders\n";

    system("mkdir $HOME/.musicalbash -p");
    system("mkdir $HOME/.musicalbash/downloads -p");

    char path[1024];
    path[0] = 0;
    
    FILE *f = popen("(cd $HOME/.musicalbash; pwd)", "r");
    fgets(path, 1024, f);

    if (path[0] == 0)
        throw bad_behaviour("Unable to find application path!");
    
    application_path = std::string(path);
    application_path.pop_back();

    Logger::Get() << "Found app path at \"" + application_path + "\"\n";
}

}