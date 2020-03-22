#include "sound_player.hpp"
#include "SoundFileReaderMp3.hpp"

using namespace std;

int main()
{
    // SoundPlayer soundp("data/IWillSurvive.wav");
    // soundp.Play();
    sf::SoundFileFactory::registerReader<audio::SoundFileReaderMp3>();
    

    SoundPlayer snd("data/beatSample.mp3");
    snd.Play();

    while (true) {
        while (snd.IsPlaying()) {}
        
        snd.Play();
    }

    
    sf::sleep(sf::seconds(4.f));


    // }

    std::cout << "hehe\n";

    
    // ConsoleManipulation::PlaceCursorAt(5, 5);
    // cout << "Yep";
    // ConsoleManipulation::WriteStringAt("It is working, Type an integer", 3, 3);
    // int x;
    // cin >> x;

    // ConsoleManipulation::WriteStringAt(to_string(x), 10, 10);

    // cout.flush();

    // this_thread::sleep_for(chrono::seconds(10));

    

    // while (soundp.IsPlaying())
    // { }

    return 0;
}