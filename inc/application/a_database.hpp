#ifndef INC_APPLICATION_DATABASE_
#define INC_APPLICATION_DATABASE_

#include <iostream>
#include <fstream>

#include "sqlite3.h"
#include "a_logger.hpp"
#include "a_constants.hpp"

/*
 * Class that handles the queries into and from the application database
 * The database used is sqlite3
 */
class DBHandler
{
private:
    /// The pointer which gives access to the actual database
    static sqlite3* db;

    /// The char * at which the sqlite3 will store the error message in case sth goes wrong
    static char* zErrMsg;

    /// Mandatory callback function for sqlite3
    static int callback(void *NotUsed, int argc, char **argv, char **azColName);

    /// The body of the sqlite3 insert operation, we will insert the data at index 51
    static const std::string sql_insert_;

    /// The sqlite3 delete operation
    static const std::string sql_delete_;

    /// The sqlite3 operation for selecting the table column we want
    static const std::string sql_select_;

    /// The sqlite3 operation for creating the table
    static const std::string sql_create_;

    /// Tempate for executing various sqlite3 operations
    static void executeOperation(const std::string& operation);

    /// Global (sort of) variable to store the result of a sqlite3 query
    static std::string response;

    /// Create the table if it doesn't exist
    static void CreateTableIfNotExists();

protected:
public:
    /// Write into the database
    static void StoreData(std::string data);

    /// Extract from the database
    static std::string ExtractData();
    
};

#endif /// INC_APPLICATION_DATABASE_