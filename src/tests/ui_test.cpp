#include "tests/ui_test.hpp"

template < class T > T smin(T &a,T b) {if (a > b) a = b; return a;}
template < class T > T smax(T &a,T b) {if (a < b) a = b; return a;}

namespace unit_tests
{ 
    bool TestBasicFunctionalityUI()
    {   

        using std::cout;

        cout << "Starting up window\n";

        //   Why RenderWindow and not Window ?
        //   Extract from https://www.sfml-dev.org/tutorials/2.0/graphics-draw.php
        //   " Everything that you've learnt about sf::Window (creation, event handling, controlling the framerate, mixing with OpenGL, etc.)
        //   is applicable to sf::RenderWindow as well. 
        //   On top of that, sf::RenderWindow adds high-level functions to help you draw things easily."

        // 
        //    The 3rd argument for initializing a renderwindow is style, an unsigned 32-bit bitmask,
        //    describing how the window will  manifest, and how the user can interact with it

          /*
        // *  sf::Style::None	    No decoration at all (useful for splash screens, for example); this style cannot be combined with others
        // *  sf::Style::Titlebar	The window has a titlebar
        // *  sf::Style::Resize	    The window can be resized and has a maximize button
        // *  sf::Style::Close	    The window has a close button
        // *  sf::Style::Fullscreen	The window is shown in fullscreen mode; this style cannot be combined with others, and requires a valid video mode
        // *  sf::Style::Default	The default style, which is a shortcut for Titlebar | Resize | Close
        // */        

        // unsigned current_style = sf::Style::Close | sf::Style::Resize;
        // sf::RenderWindow window(sf::VideoMode(512, 512), "Test Window", current_style);

        sf::RenderWindow window(sf::VideoMode(800, 800), "Test Window");
        // sf::CircleShape shape(100.f);
        // shape.setFillColor(sf::Color::Green);

        sf::Texture playButtonT;
        playButtonT.loadFromFile("data/img/play_button.png");

        sf::Sprite playButtonS(playButtonT);

        // sf::Image img;
        // if (!img.loadFromFile("data/img/play_button.png"))
            // return 0;

        while (window.isOpen()){
            sf::Event event;
            while (window.pollEvent(event)){
                if (event.type == sf::Event::Closed){
                    window.close();
                }


                /*
                else if (event.type == sf::Event::Resized){
                    cout << "New window size: ";
                    // a special class in SFML, basically a pair
                    // .x is the width, .y is the height
                    auto sz = window.getSize();
                    cout << sz.x << ' ' << sz.y << '\n';
                }
                */
            }

            window.clear();
            // window.draw(shape);
            // playButtonS.setPosition(100, 100);
            auto sz = window.getSize();
            auto minDimension = smin(sz.x, sz.y);
            if (minDimension <= 200){
                playButtonS.setScale(0.1, 0.1);
            } else if (minDimension <= 400){
                playButtonS.setScale(0.15, 0.15);
            } else if (minDimension <= 600){
                playButtonS.setScale(0.17, 0.17);
            } else if (minDimension <= 800){
                playButtonS.setScale(0.2, 0.2);
            }
            window.draw(playButtonS);

            window.display();
        }

        return 1;
    }

}