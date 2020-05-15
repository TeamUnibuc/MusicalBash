#ifndef C_OPEN_FOLDER_
#define C_OPEN_FOLDER_

#include "a_constants.hpp"
#include "command.hpp"

#include <string>

/**
 * Class able to launch a GUI file explorer
 * with the downloaded music folder
 */
class COpenFolder final : public Command
{
private:
    std::string folder_path_;

public:
    COpenFolder(std::string folderPath);
 
    void Execute();
};

#endif // C_OPEN_DOWNLOADS_FOLDER_
