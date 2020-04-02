#include "tests/wrapper.hpp"

namespace unit_tests
{
    using std::cout;

    static void RunSingleTest(std::function<bool ()> test_func, std::string test_name)
    {
        cout << "\033[1;37mTest  \033[0;33m" << test_name << "\033[0;33m: ";

        bool ok = test_func();
        cout << " " << (ok ? "\033[1;32mOK" : "\033[1;31mFAIL") << "\033[0m\n";
    }

    void RunAllTests()
    {   
        cout << std::unitbuf;

        cout << "\033[1;34mRunning all tests\n";

        RunSingleTest(TestFileSelect, "File select");
        RunSingleTest(TestDirectorySelect, "Directory select");
        RunSingleTest(TestBasicFunctionalityPMusicPlayer, "Basic Sound_Player");

        cout << std::nounitbuf;
    }

    void RunSpecificTests()
    {
        cout << std::unitbuf;

        cout << "\033[1;34mRunning SPECIFIC tests\n";

        // RunSingleTest(TestBasicFunctionalityPMusicPlayer, "Basic Sound_Player");
        RunSingleTest(TestFileSelect, "File select");
        RunSingleTest(TestDirectorySelect, "Directory select");

        cout << std::nounitbuf;
    }
}