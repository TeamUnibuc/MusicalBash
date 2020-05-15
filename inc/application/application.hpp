#ifndef INC_APPLICATION_
#define INC_APPLICATION_

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "a_constants.hpp"
#include "a_logger.hpp"
#include "a_event_handler.hpp"
#include "a_exceptions.hpp"
#include "u_window.hpp"
#include "u_png_sprite.hpp"
#include "u_scrollable_list.hpp"
#include "u_song_text_box.hpp"
#include "u_progress_bar.hpp"
#include "u_dynamic_text_box.hpp"
#include "c_download_from_web.hpp"

#include "a_button_factory.hpp"

#include "u_dummy.hpp"

class Application
{
    
private:
    sf::RenderWindow rend_window_;
    
    /// App will anyway scale how it should on resize
    Musical::Window w_side_bar_;
    Musical::Window w_main_;
    Musical::Window w_status_;

    /// clock for calling update if nothing happened for some time
    sf::Clock clock_update_;
    sf::Clock clock_render_;

    void InitializingScript();

    void Render();

    void Update();

    void PopulateWindows();

    void SetKnowledge_MousePosition();

    void InitUI();
    
public:
    Application();

    /// main Application Loop
    int Run();
};

#endif // INC_APPLICATION_