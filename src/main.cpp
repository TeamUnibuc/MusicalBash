#include <iostream>

#include "application.hpp"
#include "wrapper.hpp"
#include "console_app.hpp"
#include "a_logger.hpp"
#include "sqlite3.h"
#include "a_database.hpp"

#include "c_download_from_web.hpp"

using namespace std;
/// #include "tests/sound_player_t.hpp"

int main()
{
    Logger::Get() << "APP:  Starting application...\n";

    Application musical_bash_app;

    musical_bash_app.Run();

    Logger::Get() << "APP:  Closing application..." << '\n';
    return 0;
}