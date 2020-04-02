#ifndef INC_C_COMMAND_
#define INC_C_COMMAND_

#include <any>
#include <stdexcept>

class Command
{
protected:
    Command();
    
public:
    virtual void Execute() = 0;
};

#endif // INC_C_COMMAND_