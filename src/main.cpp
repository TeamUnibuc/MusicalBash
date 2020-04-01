#include "tests/wrapper.hpp"
#include "c_file_select.hpp"
#include "p_index.hpp"
#include "p_track.hpp"

#include <string>
#include <iostream>

int main()
{
    //unit_tests::RunAllTests();

    PTrack track;
    std::string music = " I will survive.mp3";
    track.Push(music);
    track.Push("123");

    std::string enc = track.Zip();

    std::cerr << "Encoding for treack is \"" << enc << "\"\n";

    PTrack track2;
    track2.Restore(enc);

    std::cerr << "Encoding for track2 = \"" << track2.Zip() << "\"";

    return 0;
}