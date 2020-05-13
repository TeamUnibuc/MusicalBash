#include <iostream>

#include "application.hpp"
#include "wrapper.hpp"
#include "console_app.hpp"
#include "a_logger.hpp"
#include "sqlite3.h"
#include "a_database.hpp"
#include "c_open_downloads_folder.hpp"

#include "c_download_from_web.hpp"

using namespace std;
/// #include "tests/sound_player_t.hpp"

int main()
{
    // Constants::application_path = "/home/theodor/.musicalbash";
    // auto c = COpenDownloadsFolder();
    // c.Execute();

    // auto command = CDownloadFromWeb();
    // command.Execute();

    // this_thread::sleep_for(chrono::seconds(1));

    // while (true) {
    //     command.PostExecutionVerification();
    //     this_thread::sleep_for(chrono::seconds(1));
    //     cerr << "Main\n";
    // }

    Logger::Get() << "Starting application...\n";

    // StartConsoleApp();
    
    // unit_tests::RunAllTests();

    Application musical_bash_app;

    musical_bash_app.Run();

    Logger::Get() << "Closing application..." << '\n';
    return 0;
}