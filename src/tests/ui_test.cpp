#include "tests/ui_test.hpp"

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

        sf::RenderWindow window(sf::VideoMode(512, 512), "Test Window");
        // sf::CircleShape shape(100.f);
        // shape.setFillColor(sf::Color::Green);

        while (window.isOpen()){
            sf::Event event;
            while (window.pollEvent(event)){
                if (event.type == sf::Event::Closed)
                    window.close();
                else if (event.type == sf::Event::Resized){
                    cout << "New window size: ";
                    // a special class in SFML, basically a pair
                    // .x is the width, .y is the height
                    auto sz = window.getSize();
                    cout << sz.x << ' ' << sz.y << '\n';
                }
            }

            window.clear();
            // window.draw(shape);
            window.display();
        }

        return 1;
    }

}