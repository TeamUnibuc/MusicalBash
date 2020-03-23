#ifndef INC_CONSOLE_MANIPULATION_
#define INC_CONSOLE_MANIPULATION_

#include <bits/stdc++.h>

/**
 * Self explaning
**/

class ConsoleManipulation
{
public:
    static void WriteCharAt(char c, int poz_x, int poz_y);
    static void WriteStringAt(std::string s, int poz_x, int poz_y);
    static void PlaceCursorAt(int poz_x, int poz_y);
    static std::pair <int, int> GetConsoleDimensions();
};

#endif // INC_CONSOLE_MANIPULATION_