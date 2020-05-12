#ifndef INC_C_NAME_SELECT_
#define INC_C_NAME_SELECT_

#include "command.hpp"

#include <string>
#include <mutex>

/**
 * Class able to launch a GUI menu asking for an input
 * as a text
 */
class CNameSelect final : public Command
{
private:
    std::string choosen_name_;
    /**
     * thread_is_locked_ is used for the caller to be able
     * to see when this command has finished executing
     */
    std::mutex thread_is_locked_;
    
public:
    CNameSelect();

    /// requests the user for a file in a blocking way 
    void Execute();

    /// Returns the selected directory
    std::string GetResult();
};

#endif // INC_C_NAME_SELECT_