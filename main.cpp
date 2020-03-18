#include "text_box.hpp"
#include "sprite.hpp"
#include <bits/stdc++.h>
using namespace std;

int main()
{
    Sprite* console = new Sprite(NULL);
    Sprite* text_box = new TextBox(console, "hello");
    console->AddElement(text_box, 0, 0);

    console->Render(1, 1, true);

    return 0;
}