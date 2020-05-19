#include "c_open_folder.hpp"

COpenFolder::COpenFolder(std::string folderPath) : folder_path_(folderPath)
{ }

void COpenFolder::Execute()
{
    Logger::Get() << "INFO:  Command is opening folder: " + folder_path_ << '\n';
    std::string command = "xdg-open \"" + folder_path_ + "\"";
    system(command.c_str());
}