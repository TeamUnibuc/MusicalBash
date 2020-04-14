/**
 * Simple sfml graphics app taken from [here](https://www.sfml-dev.org/tutorials/2.5/graphics-draw.php)
 */

#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
using namespace std;


int main()
{
    sf::Texture play;
    if (!play.loadFromFile("../data/img/play_button.svg")) {
        cerr << "Unable to open texture\n";
        return 0;
    }

    sf::Sprite sprite;
    sprite.setTexture(play);

    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        window.draw(sprite);
        // draw everything here...
        // window.draw(...);

        // end the current frame
        window.display();
    }

    return 0;
}