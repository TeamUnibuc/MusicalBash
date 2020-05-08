#include <iostream>

#include "application.hpp"
#include "wrapper.hpp"
#include "console_app.hpp"
#include "a_logger.hpp"
#include "sqlite3.h"

using namespace std;
/// #include "tests/sound_player_t.hpp"

int main()
{
    Logger::Get() << "Starting application...\n";

    // StartConsoleApp();
    
    // unit_tests::RunAllTests();

    // Application musical_bash_app;

    // musical_bash_app.Run();

    sqlite3* db;
    int db_res = sqlite3_open("databaseName.db", &db);
    if (db_res)
        throw std::runtime_error(sqlite3_errmsg(db));
    else
        Logger::Get() << "Opened database successfully" << '\n';
    
    sqlite3_close(db);
    

    Logger::Get() << "Closing application..." << '\n';
    return 0;
}