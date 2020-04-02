#include "tests/file_select_t.hpp"

namespace unit_tests
{
    bool TestFileSelect()
    {
        using std::cout;
        { // unnamed scope, so that PMusicPlayer variables gets destroyed, 

            std::string res;

            auto commPtr = CFileSelect();
            commPtr.execute(&res);

            res.pop_back();

            std::cout << "File: " << res;
        }

        return 1;
    }
}