#ifndef INC_APPLICATION_
#define INC_APPLICATION_

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "a_constants.hpp"
#include "a_event_handler.hpp"
#include "u_window.hpp"
#include "u_png_sprite.hpp"
#include "u_scrollable_list.hpp"

class Application
{
    
private:
    sf::RenderWindow rend_window_;
    
    /// App will anyway scale how it should on resize
    Musical::Window w_side_bar_;
    Musical::Window w_main_;
    Musical::Window w_status_;

    void InitializingScript();

    void Render();

    void Update();

    void SetKnowledgeMousePosition();

    /// Debug functions
    void _Debug_BackGroundRectangles();

    void _Debug_PrintMousePosition();
    
public:
    Application();

    /// main Application Loop
    int Run();
};

#endif // INC_APPLICATION_