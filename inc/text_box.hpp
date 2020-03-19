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

#endif // INC_TEXT_BOX_