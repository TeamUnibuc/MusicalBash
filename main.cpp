#include <SFML/Audio.hpp>
#include <bits/stdc++.h>
using namespace std;

// https://www.sfml-dev.org/tutorials/2.5/audio-sounds.php
// install sfml with sudo apt-get install libsfml-dev
// https://www.sfml-dev.org/tutorials/2.5/start-linux.php


int main()
{
    sf::Music music;
    if (!music.openFromFile("data/IWillSurvive.wav"))
        return -1; // error
    music.play();

    this_thread::sleep_for(chrono::seconds(10));

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