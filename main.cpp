#include "sound_player.hpp"
#include "SoundFileReaderMp3.hpp"

using namespace std;

// https://www.sfml-dev.org/tutorials/2.5/audio-sounds.php
// install sfml with sudo apt-get install libsfml-dev
// https://www.sfml-dev.org/tutorials/2.5/start-linux.php

/*
    MUSIC DOES NOT WORK FROM VSCODE TERMINAL
    APP MUST BE LAUNCHED FROM A REAL TERMINAL
    FOR SOUND
*/

int main()
{
    // Register our custom sf::SoundFileReader for mp3 files.
	// This is the preferred way of adding support for a new audio format.
	// Other formats will be handled by their respective readers.
	sf::SoundFileFactory::registerReader<audio::SoundFileReaderMp3>();
    
    SoundPlayer soundp("data/beatSample.mp3");
    soundp.Play();

    while (soundp.IsPlaying())
    { }

    return 0;
}

// #include <SFML/Graphics.hpp>

// int main()
// {
//     sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
//     sf::CircleShape shape(100.f);
//     shape.setFillColor(sf::Color::Green);

//     while (window.isOpen())
//     {
//         sf::Event event;
//         while (window.pollEvent(event))
//         {
//             if (event.type == sf::Event::Closed)
//                 window.close();
//         }

//         window.clear();
//         window.draw(shape);
//         window.display();
//     }

//     return 0;
// }