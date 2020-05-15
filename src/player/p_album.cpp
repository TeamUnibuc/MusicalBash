#include "p_album.hpp"
#include "c_file_system.hpp"

PAlbum::PAlbum() { }

PAlbum::PAlbum(std::string album_path, std::map <std::string, std::shared_ptr<PMusic>> & pmusic) 
{
    name_ = album_path;
    CFileSystem filesys(name_);
    filesys.Execute();

    std::vector <std::string> files = filesys.GetResult();
    for (auto i : files) {
        if (pmusic.find(i) == pmusic.end()) {
            try {
                auto m_ptr = std::make_shared<PMusic>(i);
                pmusic[i] = m_ptr;
                content_.push_back(pmusic[i]);
            }
            catch (...) {
                Logger::Get() << "INFO:  problem creating music with name: " << i << '\n';
            }
        }
        else if (pmusic[i]->isValidMusic()) {
            content_.push_back(pmusic[i]);
        }
        
    }
}
