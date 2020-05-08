#ifndef INC_C_FILE_SELECT_
#define INC_C_FILE_SELECT_

#include "command.hpp"

#include <string>

/**
 * Class able to launch a GUI menu asking for a file
 * For more info please check
 * [This](https://stackoverflow.com/questions/18948783/c-simple-open-file-dialog-in-linux).
 * I am not sure if the function does not add random junk at the end of the strings (should be checked)
 */
class CFileSelect final : public Command
{
private:
    std::string selected_file_;

public:
    CFileSelect();

    /// requests the user for a file in a blocking way 
    void Execute();

    /// Returns the path of the selected file
    std::string GetResult();
};


#endif // INC_C_FILE_SELECT_