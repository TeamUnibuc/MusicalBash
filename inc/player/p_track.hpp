#ifndef INC_P_TRACK_
#define INC_P_TRACK_

#include <vector>
#include <string>
#include <memory>

/**
 * Class storing the information about a playlist
 * / list of musics or whatever you want
 * to call it.
 * The PTrack DOES NOT have pointers to the PMusic.
 * For getting the pointer we MUST pass through the 
 * PIndex class.
 */

class PTrack
{
    std::vector <std::string> content_;
    std::string name_;

public:
    /// constructor
    PTrack();

    /// creates a track based on the files in content
    void Create(std::vector <std::string> content);

    /// sets the name of the track
    void setName(std::string name);

    /// returns the name of the track
    std::string getName() const;

    /// adds a title to the track
    void Push(std::string music);

    /// converts the content of the class to a string
    std::string Zip() const;

    /// restores the content of the class from the zip string
    void Restore(std::string zipped);

    /// returns number of elements in the track
    int Size() const;

    /// returns first element of track
    std::string FirstMusic(bool remove = false);

    /// returns random element of track
    std::string RandomMusic(bool remove = false);

    std::shared_ptr<PTrack> toPTrack();
    
    friend class PAlbum;
};
#endif // INC_P_TRACK_