#ifndef INC_C_GET_USER_INPUT_
#define INC_C_GET_USER_INPUT_

#include "command.hpp"

#include <string>
#include <mutex>

/**
 * Class requesting for user input in a textbox.
 */
class CGetUserInput : public Command
{
private:
    std::string input_message_;
    std::string user_input_;
    /**
     * thread_is_locked_ is used for the caller to be able
     * to see when this command has finished executing
     */
    std::mutex thread_is_locked_;

protected:
public:
    CGetUserInput(std::string input_message = "Please enter new name:");

    void Execute() override;

    std::string GetResult();

    friend class CCreatePlaylists;
};

#endif /// INC_C_GET_USER_INPUT_