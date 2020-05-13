#include "c_open_downloads_folder.hpp"

COpenDownloadsFolder::COpenDownloadsFolder() { }

void COpenDownloadsFolder::Execute()
{
    std::string command = "xdg-open " + Constants::application_path + "/downloads";
    system(command.c_str());
}

std::string COpenDownloadsFolder::GetResult()
{
    throw bad_behaviour("This command does not return any result!");
    return "";
}
