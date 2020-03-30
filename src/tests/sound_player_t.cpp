#include "tests/sound_player_t.hpp"

namespace unit_tests
{
    bool TestBasicFunctionalitySoundPlayer()
    {
        using std::cout;
        { // unnamed scope, so that SoundPlayer variables gets destroyed, 
          // to test unique_ptr
            // cout << "Start SoundPlayer test to play music:\n";
            cout << ".";

            SoundPlayer test_mp3("data/music_samples/Beethoven_12_Variation.mp3");
            test_mp3.Play();

            // std::cout << "Beethoven 12th Variation  playing...\n";
            cout << ".";
            sf::sleep(sf::seconds(4));

            // std::cout << "Setting volume to 30% on Beethoven song\n";
            test_mp3.SetVolume(30);
            sf::sleep(sf::seconds(1.5));

            SoundPlayer test_wav("data/music_samples/IWillSurvive.wav");
            test_wav.Play();

            // std::cout << "I WIll Survive  playing...\n";
            cout << ".";
            sf::sleep(sf::seconds(10));

            assert(test_wav.IsPlaying());
            assert(test_mp3.IsPlaying());
        }

        // std::cout << "Now it should be silence\n";
        cout << ".";

        sf::sleep(sf::seconds(2));

        return 1;
    }
}