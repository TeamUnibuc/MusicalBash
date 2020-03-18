#ifndef TEXT_BOX_
#define TEXT_BOX_

#include "sprite.hpp"
#include <bits/stdc++.h>

class TextBox : Sprite {
    std::string text_;
public:
    TextBox(Sprite*, std::string="");
    void Render(int, int, bool = false);
};

#endif // TEXT_BOX_