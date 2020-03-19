<<<<<<< HEAD
#ifndef INC_CONSOLE_MANIPULATION_
#define INC_CONSOLE_MANIPULATION_

#include <bits/stdc++.h>

/**
 * Self explaning
*/

class ConsoleManipulation
{
public:
    static void WriteCharAt(char c, int poz_x, int poz_y);
    static void WriteStringAt(std::string s, int poz_x, int poz_y);
    static std::pair <int, int> GetConsoleDimensions();
};

=======
#ifndef INC_CONSOLE_MANIPULATION_
#define INC_CONSOLE_MANIPULATION_

#include <bits/stdc++.h>

void WriteCharAt(char, int, int);
void WriteStringAt(std::string, int, int);
std::pair <int, int> GetConsoleDimensions();

>>>>>>> 9947741ebd0c1bd6a57f2afe35f25a922e58c301
#endif // INC_CONSOLE_MANIPULATION_