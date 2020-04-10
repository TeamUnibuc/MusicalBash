#include <iostream>

#include "application.hpp"

using namespace std;
/// #include "tests/sound_player_t.hpp"

int main()
{
    /// unit_tests::RunAllTests();

    Application musical_bash_app;

    musical_bash_app.Run();

    cout << "\n========\nGata!!\n";

    return 0;
}