#ifndef INC_C_DIRECTORY_SELECT_
#define INC_C_DIRECTORY_SELECT_

#include "command.hpp"

#include <string>
#include <mutex>

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
    /**
     * thread_is_locked_ is used for the caller to be able
     * to see when this command has finished executing
     */
    std::mutex thread_is_locked_;

public:
    CDirectorySelect();

    /// requests the user for a file in a blocking way 
    void Execute();

    /// Returns the selected directory
    std::string GetResult();
    
    friend class CImportAlbum;
};

#endif // INC_C_DIRECTORY_SELECT_