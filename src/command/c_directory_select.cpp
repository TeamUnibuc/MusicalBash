#include "c_directory_select.hpp"

CDirectorySelect::CDirectorySelect() { }

void CDirectorySelect::Execute()
{
    char filename[1024];
    filename[0] = 0;
    
    FILE *f = popen("zenity --file-selection --directory", "r");
    fgets(filename, 1024, f);

    if (filename[0] == 0)
        throw std::runtime_error("User returned no file!");
    
    std::string selected_directory_(filename);
    if (selected_directory_.size() > 0)
        selected_directory_.pop_back();
}

std::string CDirectorySelect::GetResult()
{
    return selected_directory_;
}
