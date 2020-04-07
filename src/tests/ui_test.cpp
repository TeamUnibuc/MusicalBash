#include "tests/ui_test.hpp"
#include "user-interface/GUI.hpp"

/*
    TO-DO:
        Deal with minimum width/height for when resizing the window
        The responsive design (view or window size ??)
*/

namespace unit_tests
{ 
    bool TestBasicFunctionalityUI()
    {   

        using std::cout;

        cout << "Starting up window\n";

        GUI playerWindow(1000, 800);
        sf::Vector2u size(1000, 800);

        sf::View view = playerWindow.getWindow().getDefaultView();

        while (playerWindow.getWindow().isOpen()){
            sf::Event event;
            bool flag = 0;
            while (playerWindow.getWindow().pollEvent(event)){
                switch (event.type)
                {
                    case sf::Event::Closed:
                    {
                        playerWindow.getWindow().close();
                        cout << "The window was closed\n";
                        break;
                    }
                    case sf::Event::Resized:
                    {
                        size = playerWindow.getWindow().getSize();
                        auto sz = playerWindow.getWindow().getSize();                       
                        if (sz.x < MIN_WIDTH){
                            sz.x = MIN_WIDTH;
                            flag = 1;
                        }
                        if (sz.y < MIN_HEIGHT){
                            sz.y = MIN_HEIGHT;
                            flag = 1;
                        }
                        cout << size.x << ' ' << size.y << '\n';
                        if (flag){
                            view.setSize(sz.x, sz.y);
                            playerWindow.getWindow().setView(view);
                            playerWindow.getWindow().setSize(sz);
                        }
                            
                        break;
                    }
                    default:{
                        break;}
                }
                // if (flag)
                //     playerWindow.getWindow().setSize(sf::Vector2u(MIN_WIDTH, MIN_HEIGHT));
                
            }
            // if (flag)
            //     playerWindow.getWindow().setSize(sf::Vector2u(MIN_WIDTH, MIN_HEIGHT));
            playerWindow.redraw();

        }

        return 1;
    }

}