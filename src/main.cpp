#include "tests/wrapper.hpp"
#include "c_file_select.hpp"
#include "p_music.hpp"

#include <string>
#include <iostream>

int main()
{
    //unit_tests::RunAllTests();

    PMusic music;
    music.Create("idk path.txt");

    music.addPlayedCount();

    std::cout << "Music is " << music.getTitle() << std::endl;

    std::cout << "Encoding is " << music.Zip() << ".\n";

    std::string enc = music.Zip();

    PMusic music2;
    music2.Restore(enc);

    return 0;
}