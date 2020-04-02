#include "tests/file_select_t.hpp"

namespace unit_tests
{
    bool TestFileSelect()
    {
        using std::cout;
        { // unnamed scope, so that PMusicPlayer variables gets destroyed, 

            auto commPtr = CFileSelect();
            std::string res = std::any_cast<std::string>(commPtr.execute());

            std::cout << "File: " << res;
        }

        return 1;
    }
}