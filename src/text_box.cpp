<<<<<<< HEAD
#include "text_box.hpp"
#include "console_manipulation.hpp"
using namespace std;

TextBox::TextBox() : text_("") { }

TextBox::TextBox(string text, int dim_x, int dim_y) : text_(text), Sprite(dim_x, dim_y) { }

void TextBox::Render(int poz_x, int poz_y, bool forced)
{
    if (!forced && !had_render_updates_)
        return;
    ConsoleManipulation::WriteStringAt(text_, poz_x, poz_y);
    /// This is a really basic way to do it. It should be broken down into words and placed centerd in the rectangle
}
=======
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
>>>>>>> 9947741ebd0c1bd6a57f2afe35f25a922e58c301
