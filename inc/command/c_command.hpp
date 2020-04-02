#ifndef INC_C_COMMAND_
#define INC_C_COMMAND_

#include <any>
#include <stdexcept>

class Command
{
public:
    Command();
    virtual void execute(std::any outObject) = 0;
};

#endif // INC_C_COMMAND_