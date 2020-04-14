#include "tests/directory_select_t.hpp"

namespace unit_tests
{
    bool TestDirectorySelect()
    {
        using std::cout;
        { // unnamed scope, so that PMusicPlayer variables gets destroyed, 

            CDirectorySelect command;
            command.Execute();

            std::cout << "Directory: " << command.GetResult();
        }

        return 1;
    }
}