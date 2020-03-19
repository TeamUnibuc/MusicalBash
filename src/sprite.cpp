#include "sprite.hpp"
using namespace std;

Sprite::Sprite() : origin_(NULL), had_render_updates_(false), dim_x_(-1), dim_y_(-1) { }

Sprite::Sprite(int dim_x, int dim_y) : origin_(NULL), had_render_updates_(true),
    dim_x_(dim_x), dim_y_(dim_y) { }

void Sprite::Render(int x_min, int y_min, bool forced)
{
    if (!forced && !had_render_updates_)
        return;
    for (auto & i : under_me_) {
        int new_x_min = x_min + get<1>(i);
        int new_y_min = y_min + get<2>(i);
        get<0>(i)->Render(new_x_min, new_y_min, forced);
    }
}

void Sprite::AddElement(Sprite* s, int poz_x, int poz_y)
{
    under_me_.emplace_back(s, poz_x, poz_y);
    s->origin_ = this;
    s->RenderUpdate();
}

void Sprite::RenderUpdate()
{
    if (had_render_updates_)
        return;
    had_render_updates_ = true;
    if (origin_ != NULL)
        origin_->RenderUpdate();
}