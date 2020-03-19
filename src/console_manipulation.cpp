<<<<<<< HEAD
#include "console_manipulation.hpp"
using namespace std;

void ConsoleManipulation::WriteCharAt(char c, int poz_x, int poz_y)
{
    cout << "\033[" << poz_x << ';' << poz_y;
    cout << c;
}

void ConsoleManipulation::WriteStringAt(string s, int poz_x, int poz_y)
{
    cout << "\033[" << poz_x << ';' << poz_y;
    cout << s;
}

pair <int, int> ConsoleManipulation::GetConsoleDimensions()
{
    // TODO
    return { 0, 0 };
}

=======
#include "console_manipulation.hpp"
using namespace std;


void WriteCharAt(char c, int poz_x, int poz_y)
{
    cout << "\033[" << poz_x << ';' << poz_y;
    cout << c;
}

void WriteStringAt(string s, int poz_x, int poz_y)
{
    cout << "\033[" << poz_x << ';' << poz_y;
    cout << s;
}

std::pair <int, int> GetConsoleDimensions()
{
    // TODO
    return { 0, 0 };
}

>>>>>>> 9947741ebd0c1bd6a57f2afe35f25a922e58c301
// see http://tldp.org/HOWTO/Bash-Prompt-HOWTO/x361.html