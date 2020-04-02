#include "c_directory_select.hpp"

void CDirectorySelect::execute(std::any obj)
{
    char filename[1024];
    filename[0] = 0;
    
    FILE *f = popen("zenity --file-selection --directory", "r");
    fgets(filename, 1024, f);

    if (filename[0] == 0)
        throw std::runtime_error("MB| User returned no file!");
    
    *std::any_cast<std::string*>(obj) = std::string(filename);
}
