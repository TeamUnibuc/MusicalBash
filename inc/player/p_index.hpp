#ifndef INC_P_INDEX_
#define INC_P_INDEX_

#include "p_music.hpp"

#include <map>
#include <memory>

/**
 *  Class storing the information about all the albums, playlists and musics.
 */


class PIndex
{
    std::map <std::string, std::shared_ptr<PMusic>> pmusic_;

public:
    /// constructor
    PIndex();

    /// converts the content of the class, playlists, albums and musics to a string
    std::string Zip() const;

    /// restores the content of the class from the zip string
    void Restore(std::string zipped);

    std::shared_ptr<PMusic> getMusicFromPath(std::string path) const;
};

#endif // INC_P_INDEX_