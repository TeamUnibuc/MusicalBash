#include "p_index.hpp"

#include <stdexcept>
#include <sstream>

PIndex::PIndex() { }

std::string PIndex::Zip() const
{
    /* first line contains the number of musics
    next each line starts with size of zip of music
    followed by the music zip */
    std::string enc = std::to_string(pmusic_.size()) + "\n";
    
    for (auto i : pmusic_) {
        std::string zip_music = i.second->Zip();
        enc += std::to_string(zip_music.size()) + "\n" + zip_music;
    }

    return enc;
}

void PIndex::Restore(std::string zipped)
{
    std::stringstream buff(zipped);
    int count;
    buff >> count;

    for (int i = 0; i < count; i++) {
        int dim;
        buff >> dim;
        std::string enc;
        while (dim--)
            enc.push_back(buff.get());
        
        std::shared_ptr<PMusic> music(new PMusic);
        music->Restore(enc);
        pmusic_[music->getFullPath()] = music; /// TODO: IDK if this works because of how shared_ptr is saved
    }
}


std::shared_ptr<PMusic> PIndex::getMusicFromPath(std::string path) const
{
    if (pmusic_.find(path) == pmusic_.end())
        throw std::runtime_error("Music searched in the index does not exist!");
    
    return pmusic_.at(path);
}