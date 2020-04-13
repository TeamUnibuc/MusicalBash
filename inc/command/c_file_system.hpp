#ifndef INC_C_FILE_SYSTEM_
#define INC_C_FILE_SYSTEM_

#include "command.hpp"

#include <filesystem>
#include <string>
#include <vector>

/**
 * Class able to navigate through the filesistem.
 * Curently it knows to get a folder and return all the music in that single folder (excluding subfolders)
 */
class CFileSystem : public Command
{
private:
    std::string path_;

public:
    /// constructor with path
    CFileSystem(std::string path);

    /// returns a list with all the music (including subfolders)
    std::vector <std::string> RecursiveGetMusic();

};

#endif // INC_C_FILE_SYSYEM_