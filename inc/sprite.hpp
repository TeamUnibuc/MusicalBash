<<<<<<< HEAD
#ifndef INC_SPRITE_
#define INC_SPRITE_

#include <bits/stdc++.h>

/** Base class from which any displayable
 *  element is printed on the terminal.
 *  Classes inheriting from Sprite should 
 *  declare a new Render() function.
*/

class Sprite
{
protected:
    /// Sprite above me
    Sprite* origin_;
    /// If me (of someone below me) needs an update
    bool had_render_updates_;
    /// dimension of the sprite
    int dim_x_, dim_y_;
    /// sprites below me, along with the delta_x and delta_y relative positions
    std::vector <std::tuple <Sprite*, int, int>> under_me_;

public:
    /// Default constructor
    Sprite();
    /// Constructor with the dimensions of the sprite
    Sprite(int dim_x, int dim_y);
    /// Renders elements on the screen with a given offset
    virtual void Render(int delta_x, int delta_y, bool force_render = false);
    /// Adds an element under me, with a given offset
    void AddElement(Sprite* element, int delta_x, int delta_y);
    // Informs all my ancesters that I need a render update
    void RenderUpdate();
};

#endif // INC_SPRITE_
=======
#ifndef INC_SPRITE_
#define INC_SPRITE_

#include <bits/stdc++.h>

class Sprite {
protected:
    Sprite* origin_;
    bool had_render_updates_;
    std::vector <std::tuple <Sprite*, int, int>> under_me_;
public:
    Sprite(Sprite*);
    virtual void Render(int, int, bool = false);
    void AddElement(Sprite*, int, int);
    void RenderUpdate();
};

#endif // INC_SPRITE_
>>>>>>> 9947741ebd0c1bd6a57f2afe35f25a922e58c301
