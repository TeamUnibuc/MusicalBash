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
