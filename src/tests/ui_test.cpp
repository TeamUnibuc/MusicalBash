#include "tests/ui_test.hpp"

namespace unit_tests
{
    bool TestBasicFunctionalityUI()
    {
        using std::cout;
        {
            cout << "Starting up window\n";

            // sf::Window* wind;
            // delete wind;
            // return 1;

            // sf::RenderWindow* wnd = new sf::RenderWindow();
            // delete wnd;
            sf::RenderWindow window(sf::VideoMode(512, 512), "Test Window");
            return 1;

            // sf::RenderWindow window(sf::VideoMode(512, 512), "Test Window");
            // sf::CircleShape shape(100.f);
            // shape.setFillColor(sf::Color::Green);

            // sf::sleep(sf::seconds(5));
            // cout << "5 seconds passed\n";
            // window.close();
            // return 1;

            // while (window.isOpen())
            // {
            //     sf::Event event;
            //     while (window.pollEvent(event))
            //     {
            //         if (event.type == sf::Event::Closed)
            //             window.close();
            //         else if (event.type == sf::Event::Resized){
            //             cout << "New window size: ";
            //             // a special class in SFML, basically a pair
            //             // .x is the width, .y is the height
            //             auto sz = window.getSize();
            //             cout << sz.x << ' ' << sz.y << '\n';
            //         }
            //     }

            //     window.clear();
            //     // window.draw(shape);
            //     window.display();
            // }

            // /*
            // *  sf::Style::None	    No decoration at all (useful for splash screens, for example); this style cannot be combined with others
            // *  sf::Style::Titlebar	The window has a titlebar
            // *  sf::Style::Resize	    The window can be resized and has a maximize button
            // *  sf::Style::Close	    The window has a close button
            // *  sf::Style::Fullscreen	The window is shown in fullscreen mode; this style cannot be combined with others, and requires a valid video mode
            // *  sf::Style::Default	The default style, which is a shortcut for Titlebar | Resize | Close
            // */

            // unsigned current_style = sf::Style::Close | sf::Style::Resize;
            // // unsigned current_style = sf::Style::Resize;

            // sf::RenderWindow window(sf::VideoMode(512, 512), "Basic Window", current_style);

            // while (window.isOpen()){
            //     sf::Event _event;
            //     while (window.pollEvent(_event)){
            //         if (_event.type == sf::Event::Closed){
            //             window.close();
            //         }
            //         else if (_event.type == sf::Event::Resized){
            //             cout << "New window size: " << _event.size << ' ' << _event.size.width << ' ' << _event.size.height << '\n';
            //         }
            //     }
            // }

            // sf::sleep(sf::seconds(5));

            // cout << "5 seconds passed\n";
            // window.close();
        }

        return 1;
    }

}