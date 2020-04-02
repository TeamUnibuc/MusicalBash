#include "tests/directory_select_t.hpp"

namespace unit_tests
{
    bool TestDirectorySelect()
    {
        using std::cout;
        { // unnamed scope, so that PMusicPlayer variables gets destroyed, 

            std::string res;

            auto commPtr = CDirectorySelect();
            commPtr.execute(&res);

            std::cout << "Directory: " << res;
        }

        return 1;
    }
}