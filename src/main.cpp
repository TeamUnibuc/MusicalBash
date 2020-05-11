#include <iostream>

#include "application.hpp"
#include "wrapper.hpp"
#include "console_app.hpp"
#include "a_logger.hpp"

using namespace std;
/// #include "tests/sound_player_t.hpp"

int main()
{
    Logger::Get() << "Starting application...\n";

    // StartConsoleApp();
    
    // unit_tests::RunAllTests();

    Application musical_bash_app;

    musical_bash_app.Run();

    Logger::Get() << "Closing application..." << '\n';
    return 0;
}