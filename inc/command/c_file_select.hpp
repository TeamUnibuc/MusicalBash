#ifndef INC_C_FILE_SELECT_
#define INC_C_FILE_SELECT_

#include "command.hpp"

#include <string>

/**
 * Class able to launch a GUI menu asking for a file / directory.
 * For more info please check
 * [This](https://stackoverflow.com/questions/18948783/c-simple-open-file-dialog-in-linux).
 * I am not sure if the function does not add random junk at the end of the strings (should be checked)
 */
class CFileSelect : public Command
{
public:
    /// Constructor. Does not do anything
    CFileSelect();

    /// requests the user for a file in a blocking way 
    std::string RequestFile();
    
    /// requests the user for a directory in a blocking way 
    std::string RequestDirectory();
};


#endif // INC_C_FILE_SELECT_