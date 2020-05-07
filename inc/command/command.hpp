#ifndef INC_COMMAND_
#define INC_COMMAND_

#include <any>
#include <stdexcept>
#include "a_exceptions.hpp"

class Command
{
protected:
    Command();
    
public:
    virtual void Execute() = 0;
};

#endif // INC_COMMAND_