#ifndef _INC_UI
#define _INC_UI

#include <SFML/Graphics.hpp>
#include <iostream>

#define smin(X, Y) ((X) < (Y) ? (X) : (Y))
#define smax(X, Y) ((X) > (Y) ? (X) : (Y))

inline float controlButtonSize = 20;
inline float controlButtonSizeWidth = 20;
inline float controlButtonSizeHeight = 20;
inline float controlButtonSizeScale = 20.0 / 512;
inline float controlButtonSizeScaleX  = 20.0 / 512;
inline float controlButtonSizeScaleY = 20.0 / 512;
inline const unsigned buttonImageSize = 512;
inline float buttonSpacing = 5;

// actual image size: 512px x 512px
// shown width = width_we_want / 512 (actual size)

inline const unsigned int MIN_WIDTH = 720;
inline const unsigned int MIN_HEIGHT = 480;
inline const unsigned int window_style = sf::Style::Titlebar | sf::Style::Resize | sf::Style::Close;

//    The 3rd argument for initializing a renderwindow is style, an unsigned 32-bit bitmask,
//    describing how the window will  manifest, and how the user can interact with it
/*
 *  sf::Style::None	        No decoration at all (useful for splash screens, for example); this style cannot be combined with others
 *  sf::Style::Titlebar	    The window has a titlebar
 *  sf::Style::Resize	    The window can be resized and has a maximize button
 *  sf::Style::Close	    The window has a close button
 *  sf::Style::Fullscreen	The window is shown in fullscreen mode; this style cannot be combined with others, and requires a valid video mode
 *  sf::Style::Default	    The default style, which is a shortcut for Titlebar | Resize | Close
// */ 

/*
 * Class containing the visual interface
 */
class GUI{
    sf::RenderWindow window;
    sf::Texture playButtonTexture, nextButtonTexture, previousButtonTexture, stopButtonTexture;
    sf::Sprite playButtonSprite, nextButtonSprite, previousButtonSprite, stopButtonSprite;

public:
    // default constructor
    GUI();

    // constructs a window with given width and height;
    GUI(unsigned int width, unsigned int height);

    // get the GUI's RenderWindow
    sf::RenderWindow& getWindow();

    // redraw the the player
    void redraw();

    // maybe obsolete, review later
    // check that the visual player is still running
    bool isOpen()const;
};

#endif //_INC_UI