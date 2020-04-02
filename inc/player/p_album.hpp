#ifndef INC_P_ALBUM_
#define INC_P_ALBUM_

#include "p_track.hpp"

#include <vector>
#include <string>

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
    PAlbum(std::string album_path);

    friend class PIndex;
};

#endif // INC_P_ALBUM_