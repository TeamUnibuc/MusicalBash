#ifndef INC_C_FILE_SELECT_
#define INC_C_FILE_SELECT_

#include "c_command.hpp"

#include <string>

/**
 * Class able to launch a GUI menu asking for a file
 * For more info please check
 * [This](https://stackoverflow.com/questions/18948783/c-simple-open-file-dialog-in-linux).
 * I am not sure if the function does not add random junk at the end of the strings (should be checked)
 */
class CFileSelect : public Command
{
public:
    /// requests the user for a file in a blocking way 
    void execute(std::any outObject);
};


#endif // INC_C_FILE_SELECT_