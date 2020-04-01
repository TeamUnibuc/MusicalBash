#ifndef INC_P_PLAYLIST_
#define INC_P_PLAYLIST_

#include "p_track.hpp"

#include <vector>
#include <string>
#include <memory>

/**
 * Class storing a playlist, inherited from PTrack
 */
class PPlaylist : public PTrack
{

public:
    /// default contructor
    PPlaylist();

    /// constructor with playlist name
    PPlaylist(std::string name);

    /// adds a title to the track
    void addMusic(std::string music);

    /// converts the content of the class to a string
    std::string Zip() const;

    /// restores the content of the class from the zip string
    void Unzip(std::string zipped);

    friend class PIndex;
};

#endif // INC_P_PLAYLIST_