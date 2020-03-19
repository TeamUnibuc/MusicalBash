#include "sound_player.hpp"
#include "console_manipulation.hpp"
using namespace std;

int main()
{
    // SoundPlayer soundp("data/IWillSurvive.wav");
    // soundp.Play();
    system("clear");
    ConsoleManipulation::PlaceCursorAt(5, 5);
    cout << "Yep";
    ConsoleManipulation::WriteStringAt("It is working, Type an integer", 3, 3);
    int x;
    cin >> x;

    ConsoleManipulation::WriteStringAt(to_string(x), 10, 10);

    cout.flush();

    this_thread::sleep_for(chrono::seconds(10));

    // while (soundp.IsPlaying())
    // { }

    return 0;
}
