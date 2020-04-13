#include "c_file_system.hpp"

#include <stdexcept>

CFileSystem::CFileSystem(std::string path) : path_(path) { }

std::vector <std::string> CFileSystem::RecursiveGetMusic()
{
    if (path_.empty())
        throw std::runtime_error("Tried to get files from invalid path");
    
    std::vector <std::string> ans;

    namespace fs = std::filesystem;

    for (auto& dir : fs::recursive_directory_iterator(path_)) {
        if (dir.is_regular_file()) {
            std::string path = dir.path();
            if (path.size() < 4)
                continue;
            if (path.substr(path.size() - 4, 4) == ".mp3" ||
                path.substr(path.size() - 4, 4) == ".wav")
                ans.push_back(path);
        }       
    }

    return ans;
}
