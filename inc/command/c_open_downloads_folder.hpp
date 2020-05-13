#ifndef C_OPEN_DOWNLOADS_FOLDER_
#define C_OPEN_DOWNLOADS_FOLDER_

#include "a_constants.hpp"
#include "command.hpp"

#include <string>

/**
 * Class able to launch a GUI file explorer
 * with the downloaded music folder
 */
class COpenDownloadsFolder final : public Command
{
public:
    COpenDownloadsFolder();
 
    void Execute();

    std::string GetResult();
};

#endif // C_OPEN_DOWNLOADS_FOLDER_
