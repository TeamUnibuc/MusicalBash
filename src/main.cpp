#include <iostream>

#include "tests/wrapper.hpp"
#include "player.hpp" 
#include "p_music.hpp"

using namespace std;
/// #include "tests/sound_player_t.hpp"

int main()
{ 
    std::cout << "hey\n";
    PMusic someMusic("data/music_samples/IWillSurvive.wav");

    /// unit_tests::RunAllTests();

    return 0;
}