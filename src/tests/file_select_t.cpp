#include "tests/file_select_t.hpp"

namespace unit_tests
{
    bool TestFileSelect()
    {
        using std::cout;
        { // unnamed scope, so that PMusicPlayer variables gets destroyed, 

            CFileSelect command;
            command.Execute();

            std::cout << "File: " << command.GetResult();
        }

        return 1;
    }
}