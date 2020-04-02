#ifndef INC_C_COMMAND_
#define INC_C_COMMAND_

#include <any>
#include <stdexcept>

class CNILL
{

};

class Command
{
protected:
    static const CNILL nill_obj;

public:
    Command();
    virtual std::any execute(std::any obj = nill_obj) = 0;
};

#endif // INC_C_COMMAND_