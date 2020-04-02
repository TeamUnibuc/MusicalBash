#include "c_file_select.hpp"

#include <stdexcept>

std::any CFileSelect::execute(std::any /* obj */)
{
    char filename[1024];
    filename[0] = 0;

    FILE *f = popen("zenity --file-selection", "r");
    fgets(filename, 1024, f);

    if (filename[0] == 0)
        throw std::runtime_error("User returned no file!");
    
    std::string res(filename);
    // if (res.size() > 0)
    //     res.pop_back();

    return res;
}
