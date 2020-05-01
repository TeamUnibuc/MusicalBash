#ifndef INC_APPLICATION_
#define INC_APPLICATION_

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "u_element.hpp"
#include "a_constants.hpp"
#include "a_event_handler.hpp"
#include "u_window.hpp"
#include "u_png_sprite.hpp"

class Application : public UiElement
{
    
private:
    sf::RenderWindow window_;
    
    /// App will anyway scale how it should on resize
    Musical::Window w_side_bar_;
    Musical::Window w_main_;
    Musical::Window w_status_;

    void InitializingScript();

    void Render(sf::RenderWindow& rendWindow, int off_x, int off_y) override;

    void Update(int off_x, int off_y) override;

    int GetHeight() const override;

    int GetWidth() const override;

public:
    Application();

    /// main Application Loop
    int Run();
};

#endif // INC_APPLICATION_