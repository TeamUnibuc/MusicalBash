#include "c_get_user_input.hpp"

CGetUserInput::CGetUserInput(std::string input_message):
    input_message_(input_message)
{}

void CGetUserInput::Execute()
{
    char filename[1024];
    filename[0] = 0;
    
    input_message_ = "zenity --entry --text \"" + input_message_ + "\"";
    FILE *f = popen(input_message_.c_str(), "r");
    fgets(filename, 1024, f);

    if (filename[0] == 0)
        throw std::runtime_error("User returned empty input!");
    
    user_input = std::string(filename);

}

std::string CGetUserInput::GetResult()
{
    return user_input;
}