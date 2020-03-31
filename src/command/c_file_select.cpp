#include "c_file_select.hpp"

#include <stdexcept>

CFileSelect::CFileSelect() { }

std::string CFileSelect::RequestFile()
{
    char filename[1024];
    filename[0] = 0;

    FILE *f = popen("zenity --file-selection", "r");
    fgets(filename, 1024, f);

    if (filename[0] == 0)
        throw std::runtime_error("User returned no file!");
    
    return std::string(filename);
}

std::string CFileSelect::RequestDirectory()
{
    char filename[1024];
    filename[0] = 0;
    
    FILE *f = popen("zenity --file-selection --directory", "r");
    fgets(filename, 1024, f);

    if (filename[0] == 0)
        throw std::runtime_error("User returned no file!");
    
    return std::string(filename);
}
