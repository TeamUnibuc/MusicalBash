#ifndef INC_P_TRACK_
#define INC_P_TRACK_

#include "p_music.hpp"
#include "a_logger.hpp"

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
    std::vector <std::shared_ptr<PMusic>> content_;
    std::string name_;

public:
    /// default contructor
    PTrack();

    /// move constructor
    PTrack(PTrack && oth);

    /// assignation move constructor
    PTrack & operator=(PTrack && oth);

    /// returns the name of the track
    std::string GetName() const;

    /// returns number of elements in the track
    int Size() const;

    /// returns smart_ptrs to the music content of the track
    std::vector <std::shared_ptr<PMusic>> GetMusic();

    /// adds a title to the track
    void AddMusic(std::shared_ptr<PMusic> music);
};

#endif // INC_P_TRACK_