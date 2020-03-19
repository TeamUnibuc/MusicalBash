<<<<<<< HEAD
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

=======
#ifndef INC_TEXT_BOX_
#define INC_TEXT_BOX_

#include "sprite.hpp"
#include <bits/stdc++.h>

class TextBox : public Sprite {
    std::string text_;
public:
    TextBox(Sprite*, std::string="");
    void Render(int, int, bool = false);
};

>>>>>>> 9947741ebd0c1bd6a57f2afe35f25a922e58c301
#endif // INC_TEXT_BOX_