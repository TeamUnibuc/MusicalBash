#ifndef INC_P_MUSIC_QUEUE_
#define INC_P_MUSIC_QUEUE_

#include "p_track.hpp"

#include <vector>
#include <string>
#include <memory>

/**
 * Class storing the curent waiting queue for playing music.
 * Inherited from PTrack.
 */
class PMusicQueue : public PTrack
{
public:
    /// default contructor
    PMusicQueue();

    /// adds a title to the end of the queue
    PMusicQueue& operator +=(std::shared_ptr<PMusic> music);

    /// adds the content of an PTrack to end of the queue
    PMusicQueue& operator +=(std::shared_ptr<PTrack> track);

    /// adds a music to the begging of the track (used for prev command)
    void AddToFront(std::shared_ptr<PMusic> music);

    /// returns first element of track
    std::shared_ptr<PMusic> FirstMusic(bool remove = false);

    /// returns random element of track
    std::shared_ptr<PMusic> RandomMusic(bool remove = false);
};

#endif // INC_P_MUSIC_QUEUE_