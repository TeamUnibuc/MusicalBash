#include "c_get_user_input.hpp"

CGetUserInput::CGetUserInput(std::string input_message):
    input_message_(input_message)
{}

void CGetUserInput::Execute()
{
    thread_is_locked_.lock();

    try {
        char filename[1024];
        filename[0] = 0;
        
        input_message_ = "zenity --entry --text \"" + input_message_ + "\"";
        FILE *f = popen(input_message_.c_str(), "r");
        fgets(filename, 1024, f);

        if (filename[0] == 0)
            throw std::runtime_error("User returned empty input!");
        
        user_input_ = std::string(filename);
        
        if (user_input_.size() > 0)
            user_input_.pop_back();
    }
    catch (...) {
        Logger::Get() << "There was a problem processing the user input command!\n";
        user_input_ = "";
    }

    thread_is_locked_.unlock();
}

std::string CGetUserInput::GetResult()
{
    return user_input_;
}