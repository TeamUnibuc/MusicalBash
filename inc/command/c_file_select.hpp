#ifndef INC_C_FILE_SELECT_
#define INC_C_FILE_SELECT_

#include "command.hpp"

#include <string>
#include <mutex>

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
    /**
     * thread_is_locked_ is used for the caller to be able
     * to see when this command has finished executing
     */
    std::mutex thread_is_locked_;

public:
    CFileSelect();

    /// requests the user for a file in a blocking way 
    void Execute();

    /// Returns the path of the selected file
    std::string GetResult();

    friend class CAddMusicToPlaylist;
};


#endif // INC_C_FILE_SELECT_