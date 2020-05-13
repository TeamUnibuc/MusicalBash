#include "a_knowledge.hpp"

namespace Knowledge
{
UniquePtr<Player> Daddy_Player;

std::string application_path;

Constants::State::W curr_state = Constants::State::W::Home;

/// Global variables but available only 
/// in this translation unit so we are safe

/// Private data
static const sf::Event kMockEvent = {sf::Event::JoystickConnected, {}};

static sf::Event event_;
static std::pair<int, int> mouse_poz_;


/// Functions so we can use those global variables!
void ResetEvent()
{
    // mouse_poz_ = {-1, -1};
    event_ = kMockEvent;
}

void SetMousePoz(const std::pair<int, int>& where)
{
    mouse_poz_ = where;
}

std::pair<int,int> GetMousePoz()
{
    return mouse_poz_;
}

sf::Event GetEvent()
{
    return event_;
}

void SetEvent(sf::Event ev)
{
    event_ = ev;
}

void CreateApplicationPath()
{
    Logger::Get() << "Creating applicaition folders\n";

    system("mkdir $HOME/.musicalbash -p");
    system("mkdir $HOME/.musicalbash/downloads -p");
    system("mkdir $HOME/.musicalbash/database -p");

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