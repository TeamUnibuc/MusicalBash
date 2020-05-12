#include "c_file_select.hpp"

#include <stdexcept>

CFileSelect::CFileSelect() { }

void CFileSelect::Execute()
{
    thread_is_locked_.lock();

    try {
        char filename[1024];
        filename[0] = 0;

        FILE *f = popen("zenity --file-selection", "r");
        fgets(filename, 1024, f);

        if (filename[0] == 0)
            throw std::runtime_error("User returned no file!");
        
        selected_file_ = std::string(filename);
        if (selected_file_.size() > 0)
            selected_file_.pop_back();
    }
    catch (...) {
        Logger::Get() << "There was a problem processing the file_select command!\n";
        selected_file_ = "";
    }
    thread_is_locked_.unlock();
}

std::string CFileSelect::GetResult()
{
    return selected_file_;
}