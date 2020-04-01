#ifndef INC_P_TRACK_
#define INC_P_TRACK_

#include "p_music.hpp"

#include <vector>
#include <string>
#include <memory>

/**
 * Base class for playlists, albums and waiting-queue.
 * I basically just stores pointers to music.
 */
class PTrack
{
protected:
    std::vector <std::string> content_;
    std::string name_;

public:
    /// default contructor
    PTrack();

    /// constructor with name and vector of songs
    PTrack(std::string name, std::vector <std::string> content);

    /// returns the name of the track
    std::string getName() const;

    /// returns number of elements in the track
    int Size() const;

    friend class PMusicQueue;
};

#endif // INC_P_TRACK_