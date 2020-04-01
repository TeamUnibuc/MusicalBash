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
    void addMusic(std::shared_ptr<PMusic> music);

    friend class PIndex;
};

#endif // INC_P_PLAYLIST_