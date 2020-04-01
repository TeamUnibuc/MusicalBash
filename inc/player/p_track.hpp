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
    std::vector <std::shared_ptr<PMusic>> content_;
    std::string name_;

public:
    /// default contructor
    PTrack();

    /// constructor with name and data
    PTrack(std::string name, std::vector <std::shared_ptr<PMusic>> content);

    /// sets the name of the track
    void setName(std::string name);

    /// returns the name of the track
    std::string getName() const;

    /// adds a title to the track
    void addMusic(std::shared_ptr<PMusic> music);

    /// converts the content of the class to a string
    std::string Zip() const;

    /// restores the content of the class from the zip string
    void Unzip(std::string zipped);

    /// returns number of elements in the track
    int Size() const;

    friend class PMusicQueue;
};

#endif // INC_P_TRACK_