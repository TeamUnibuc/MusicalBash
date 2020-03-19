#include "console_manipulation.hpp"
using namespace std;

void ConsoleManipulation::WriteCharAt(char c, int poz_x, int poz_y)
{
    cout << "\033[" << poz_x << ';' << poz_y << 'H';
    cout << c;
}

void ConsoleManipulation::WriteStringAt(string s, int poz_x, int poz_y)
{
    cout << "\033[" << poz_x << ';' << poz_y << 'H';
    cout << s;
}

void ConsoleManipulation::PlaceCursorAt(int poz_x, int poz_y)
{
    cout << "\033[" << poz_x << ';' << poz_y << 'H';
}

pair <int, int> ConsoleManipulation::GetConsoleDimensions()
{
    // TODO
    return { 0, 0 };
}

// see http://tldp.org/HOWTO/Bash-Prompt-HOWTO/x361.html