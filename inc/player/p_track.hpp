#ifndef INC_P_TRACK_
#define INC_P_TRACK_

#include "p_music.hpp"

#include <vector>
#include <string>
#include <memory>

class PTrack
{
    std::vector <std::shared_ptr<PMusic>> content_;

public:
    /// constructor
    PTrack();

    /// creates a track based on the files in content
    void Create(std::vector <std::shared_ptr<PMusic>> content);

    /// adds a title to the track
    void Push(std::shared_ptr<PMusic> music);

    /// converts the content of the class to a string
    std::string Zip() const;

    /// restores the content of the class from the zip string
    void Restore(std::string zipped);

    /// returns number of elements in the track
    int Size() const;

    /// returns first element of track
    std::shared_ptr<PMusic> FirstMusic(bool remove = false);

    /// returns random element of track
    std::shared_ptr<PMusic> RandomMusic(bool remove = false);

};
#endif // INC_P_TRACK_