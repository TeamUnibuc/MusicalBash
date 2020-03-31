#include "tests/wrapper.hpp"
#include "c_file_select.hpp"
#include <string>

int main()
{
    //unit_tests::RunAllTests();

    CFileSelect cfs;

    std::string ans = cfs.RequestFile();

    std::cerr << "Selected file " << ans << '\n';

    return 0;
}