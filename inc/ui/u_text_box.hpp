#ifndef INC_UI_TEXT_BOX_
#define INC_UI_TEXT_BOX_

#include "u_element.hpp"

/*
 *  Class able to draw a text box
 *  It can store text either to the left, middle, or right of its box
 *  It only knows to render the text correctly and cut it and add "..." if it is too long
 */
class TextBox: public UiElement
{
private:
    const int sizeX_;
    const int sizeY_;
    std::string text_;

    // For cosmetic testing only, to be removed later !!!
    

protected:

public:

    // Default constructor
    TextBox();

    /*
     *  Create a text box by specifying posX and posY (relative to its container)
     *      width, height and alignment
     *  Mode can be one of the following 3:
     *    0. left-aligned
     *    1. centered
     *    2. right-aligned
     */
    TextBox(int posX, int posY, int sizeX, int sizeY, int alignment, std::string textInput);

};

#endif // INC_UI_TEXT_BOX