#include "tests/directory_select_t.hpp"

namespace unit_tests
{
    bool TestDirectorySelect()
    {
        using std::cout;
        { // unnamed scope, so that PMusicPlayer variables gets destroyed, 

            auto command = CDirectorySelect();
            std::string res = std::any_cast<std::string>(command.execute());

            std::cout << "Directory: " << res;
        }

        return 1;
    }
}