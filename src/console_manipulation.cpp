#include "console_manipulation.hpp"

using std::cout;

void ConsoleManipulation::WriteCharAt(char c, int poz_x, int poz_y)
{
    cout << "\033[" << poz_x << ';' << poz_y << 'H';
    cout << c;
}

void ConsoleManipulation::WriteStringAt(std::string s, int poz_x, int poz_y)
{
    cout << "\033[" << poz_x << ';' << poz_y << 'H';
    cout << s;
}

void ConsoleManipulation::PlaceCursorAt(int poz_x, int poz_y)
{
    cout << "\033[" << poz_x << ';' << poz_y << 'H';
}

std::pair <int, int> ConsoleManipulation::GetConsoleDimensions()
{
    // TODO
    return { 0, 0 };
}

// see http://tldp.org/HOWTO/Bash-Prompt-HOWTO/x361.html