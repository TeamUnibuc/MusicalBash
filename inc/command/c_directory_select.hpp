#ifndef INC_C_DIRECTORY_SELECT_
#define INC_C_DIRECTORY_SELECT_

#include "command.hpp"

#include <string>
    
/**
 * Class able to launch a GUI menu asking for a directory.
 * For more info please check
 * [This](https://stackoverflow.com/questions/18948783/c-simple-open-file-dialog-in-linux).
 * I am not sure if the function does not add random junk at the end of the strings (should be checked)
 */
class CDirectorySelect final : public Command
{
private:
    std::string selected_directory_;

public:
    CDirectorySelect();

    /// requests the user for a file in a blocking way 
    void Execute();

    /// Returns the selected directory
    std::string GetResult();
};

#endif // INC_C_DIRECTORY_SELECT_