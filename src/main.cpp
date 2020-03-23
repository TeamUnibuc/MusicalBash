#include "tests/wrapper.hpp"

using namespace std;

int main()
{
    // SoundPlayer soundp("data/IWillSurvive.wav");
    // soundp.Play();
    // sf::SoundFileFactory::registerReader<audio::SoundFileReaderMp3>();
    
    unit_tests::RunAllTests();

    return 0;
}