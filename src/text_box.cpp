#include "text_box.hpp"
#include "console_manipulation.hpp"
using namespace std;

TextBox::TextBox(Sprite* origin, string text) : Sprite(origin), text_(text) { }

void TextBox::Render(int poz_x, int poz_y, bool forced)
{
    if (!forced && !had_render_updates_)
        return;
    WriteStringAt(text_, poz_x, poz_y);
}
