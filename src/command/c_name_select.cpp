#include "c_name_select.hpp"

CNameSelect::CNameSelect() { }

void CNameSelect::Execute()
{
    char filename[1024];
    filename[0] = 0;
    
    FILE *f = popen("zenity --entry --text=\"Ce nume doriti sa aiba noul playlist?\"", "r");
    fgets(filename, 1024, f);

    if (filename[0] == 0)
        throw player_runtime_error("User wrote no output!");
    
    choosen_name_ = std::string(filename);
    // if (choo_.size() > 0)
    //     selected_directory_.pop_back();
}

std::string CNameSelect::GetResult()
{
    return choosen_name_;
}
