#include "a_database.hpp"

sqlite3 *DBHandler::db = NULL;

char *DBHandler::zErrMsg = 0;

const std::string DBHandler::sql_insert_ = "INSERT INTO MusicalBash (id, content) VALUES (0, \"\"); ";

const std::string DBHandler::sql_delete_ = "DELETE from MusicalBash where ID=0; ";

const std::string DBHandler::sql_select_ = "SELECT content from MusicalBash; ";

const std::string DBHandler::sql_create_ = "CREATE TABLE MusicalBash(id int primary_key, content longtext); ";

std::string DBHandler::response = "";

int DBHandler::callback(void * /* NotUsed */, int /* argc */, char **argv, char ** /* azColName */)
{
    response = argv[0];

    // int i;
    // for (i = 0; i < argc; i++)
    // {
    //     Logger::Get() << azColName[i] << " = " << (argv[i] ? argv[i] : "NULL") << '\n';

    //     /// Template from the documentation, not sure what magic it does
    //     // printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    // }

    // Logger::Get() << '\n';
    // // printf("\n");
    return 0;
}

void DBHandler::executeOperation(const std::string& operation)
{
    std::string database_path = Constants::application_path + "/database/database.db";
    Logger::Get() << "Database path is " << database_path << '\n';
    int db_res = sqlite3_open(database_path.c_str(), &db);

    if (db_res)
        throw std::runtime_error(sqlite3_errmsg(db));
    else
        Logger::Get() << "Opened database successfully" << '\n';

    db_res = sqlite3_exec(db, operation.c_str(), callback, 0, &zErrMsg);

    if (db_res != SQLITE_OK)
    {
        throw std::runtime_error(zErrMsg);
        // Logger::Get() << "SQL Error: " << zErrMsg << '\n';
        // sqlite3_free(zErrMsg);

        /// Template from the documentation
        // fprintf(stderr, "SQL error: %s\n", zErrMsg);
        // sqlite3_free(zErrMsg);
    }
    else
    {
        Logger::Get() << operation.substr(0, 6) << " operation executed successfully" << '\n';

        /// Template from the documentation
        // fprintf(stdout, "Records created successfully\n");
    }

    sqlite3_close(db);
    delete[] zErrMsg;
}

void DBHandler::StoreData(std::string data)
{
    CreateTableIfNotExists();

    /// First remove the old data
    executeOperation(sql_delete_);

    std::string sql_insert = sql_insert_;
    sql_insert.insert(50, data);

    /// Insert new data
    executeOperation(sql_insert);

    // std::cerr << sql_insert << '\n';
}

std::string DBHandler::ExtractData()
{
    CreateTableIfNotExists();
    executeOperation(sql_select_);
    return response;
}

void DBHandler::CreateTableIfNotExists()
{
    std::ifstream test_in(Constants::application_path + "/database/database.db");
    if (!test_in.is_open()){
        Logger::Get() << "Database folder not found, so will create one" << '\n';

        executeOperation(sql_create_);

        executeOperation(sql_insert_);

        Logger::Get() << "Database initialized" << '\n';
    }
}