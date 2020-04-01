#ifndef INC_P_ALBUM_
#define INC_P_ALBUM_

#include "p_track.hpp"
#include "p_index.hpp"

#include <vector>
#include <memory>

/**
 *  Class storing the information about all the albums.
 *  Inherited from PTrack.
 *  Additionally, it also stores the absolute path of the coresponding folder
 */

class PAlbum
{
    std::string album_path_, album_name_;
    std::vector <std::string> content_;

public:
    /// constructor
    PAlbum();

    /// creates an album with a given path
    void Create(std::string album_path);

    /// converts the content of the class to a string
    std::string Zip() const;

    /// restores the content of the class from the zip string
    void Restore(std::string zipped);

    /// returns number of elements in the album
    int Size() const;

    /// converts tje album to a track (that can be played)
    std::shared_ptr<PTrack> toPTrack();

    friend class PIndex;
};

#endif // INC_P_ALBUM_