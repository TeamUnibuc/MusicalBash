#include "tests/mp3_file_duration_t.hpp"

namespace unit_tests
{
    bool TestGetFileDuration()
    {
        using std::cout;
        { // unnamed scope, so that PMusicPlayer variables gets destroyed, 
            std::string filePath = "data/music_samples/Beethoven_12_Variation.mp3.mp3";

            CMp3FileDuration command(filePath);
            command.Execute();

            std::cout << "\nfile: " << filePath;

            std::cout << "\nduration: " << command.GetResult();
        }

        return 1;
    }
}