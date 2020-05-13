#include "c_directory_select.hpp"

CDirectorySelect::CDirectorySelect() { }

void CDirectorySelect::Execute()
{
    thread_is_locked_.lock();

    try {
        char filename[1024];
        filename[0] = 0;
        
        FILE *f = popen("zenity --file-selection --directory", "r");
        fgets(filename, 1024, f);

        if (filename[0] == 0)
            throw std::runtime_error("User returned no file!");
        
        selected_directory_ = std::string(filename);

        if (selected_directory_.size() > 0)
            selected_directory_.pop_back();
    }
    catch (...) {
        Logger::Get() << "There was a problem processing the dir_select command!\n";
        selected_directory_ = "";
    }
    
    thread_is_locked_.unlock();
}

std::string CDirectorySelect::GetResult()
{
    return selected_directory_;
}
