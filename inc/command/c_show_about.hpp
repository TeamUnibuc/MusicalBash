#pragma once  /// C_SHOW_ABOUT_HPP_

#include "command.hpp"

/**
 * Class displaying a simple zenity --info message
 */
class CShowAbout : public Command 
{
private:

public:
    CShowAbout();

    void Execute();
};