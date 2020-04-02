#include "tests/file_select_t.hpp"

namespace unit_tests
{
    bool TestFileSelect()
    {
        using std::cout;
        { // unnamed scope, so that PMusicPlayer variables gets destroyed, 
          // to test unique_ptr
            // cout << "Start PMusicPlayer test to play music:\n";
            cout << ".";

            std::string res;

            auto commPtr = new CFileSelect();
            commPtr->execute(&res);

            std::cout << "res";
        }

        // std::cout << "Now it should be silence\n";
        cout << ".";

        return 1;
    }
}