#ifndef INC_COMMAND_
#define INC_COMMAND_

#include <any>
#include <stdexcept>
#include "a_exceptions.hpp"

#include "a_logger.hpp"

/**
 *  Abstract class for commands
 *  All commands are executable, they might be multi-threaded
*/
class Command
{
protected:
    Command();
    
public:
    virtual ~Command();

    virtual void Execute() = 0;
};

#endif // INC_COMMAND_