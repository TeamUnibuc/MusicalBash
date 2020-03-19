#include "text_box.hpp"
#include "console_manipulation.hpp"
using namespace std;

TextBox::TextBox() : text_("") { }

TextBox::TextBox(string text, int dim_x, int dim_y) : Sprite(dim_x, dim_y), text_(text) { }

void TextBox::Render(int poz_x, int poz_y, bool forced)
{
    if (!forced && !had_render_updates_)
        return;
    ConsoleManipulation::WriteStringAt(text_, poz_x, poz_y);
    /// This is a really basic way to do it. It should be broken down into words and placed centerd in the rectangle
}
