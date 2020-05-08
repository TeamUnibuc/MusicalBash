#ifndef INC_C_NAME_SELECT_
#define INC_C_NAME_SELECT_

#include "command.hpp"

#include <string>
    
/**
 * Class able to launch a GUI menu asking for an input
 * as a text
 */
class CNameSelect final : public Command
{
private:
    std::string choosen_name_;

public:
    CNameSelect();

    /// requests the user for a file in a blocking way 
    void Execute();

    /// Returns the selected directory
    std::string GetResult();
};

#endif // INC_C_NAME_SELECT_