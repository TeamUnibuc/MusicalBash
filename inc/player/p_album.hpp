#ifndef INC_P_ALBUM_
#define INC_P_ALBUM_

#include "p_track.hpp"

#include <vector>
#include <string>
#include <map>
#include <p_music.hpp>

/**
 *  Class storing the information about an album.
 *  Inherited from PTrack.
 *  Additionally, it also stores the absolute path of the coresponding folder
 */
class PAlbum : public PTrack
{
    
public:
    /// constructor
    PAlbum();

    /// creates an album with a given path
    PAlbum(std::string album_path, std::map <std::string, std::shared_ptr<PMusic>> & pmusic);

    void AddMusic(std::shared_ptr<PMusic> music) = delete;

    friend class PIndex;
};

#endif // INC_P_ALBUM_