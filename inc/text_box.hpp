#ifndef INC_TEXT_BOX_
#define INC_TEXT_BOX_

#include "sprite.hpp"
#include <bits/stdc++.h>

/** 
 * Class inherited from sprite, able to display a given text
 * inside a box, idealy centered.
*/

class TextBox : public Sprite
{
    /// text inside the textbox
    std::string text_;
public:
    /// default constructor
    TextBox();
    /// constructor with the string and dimensions
    TextBox(std::string text, int dim_x, int dim_y);
    /// overload of the Render function inherited from sprite
    void Render(int delta_x, int delta_y, bool force_render = false);
};

#endif // INC_TEXT_BOX_