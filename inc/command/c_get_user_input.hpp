#ifndef INC_C_GET_USER_INPUT_
#define INC_C_GET_USER_INPUT_

#include "command.hpp"

#include <string>

class CGetUserInput : public Command
{
private:
    std::string input_message_;
    std::string user_input;
protected:
public:
    CGetUserInput(std::string input_message = "Please enter new text:");

    void Execute() override;

    std::string GetResult();
};

#endif /// INC_C_GET_USER_INPUT_