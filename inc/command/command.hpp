#ifndef INC_COMMAND_
#define INC_COMMAND_

#include <any>
#include <stdexcept>

class Command
{
protected:
    Command();
    
public:
    virtual void Execute() = 0;
};

#endif // INC_COMMAND_