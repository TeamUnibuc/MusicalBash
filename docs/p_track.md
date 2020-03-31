# PTRack

### Class storing the information about a playlist / album / list of musics or whatever you want to call it.

### Implementation:

1. [p_track.hpp](/inc/player/p_track.hpp)
1. [p_track.cpp](/src/player/p_track.cpp)


## List of methods:

```c++
    /// constructor
    PTrack();

    /// creates a track based on the files in content
    void Create(vector <shared_ptr<PMusic>> content);

    /// adds a title to the track
    void Push(shared_ptr<PMusic> music);

    /// converts the content of the class to a string
    std::string Zip() const;

    /// restores the content of the class from the zip string
    void Restore(std::string zipped);

    /// returns number of elements in the track
    int Size() const;

    /// returns first element of track
    shared_ptr<PMusic> FirstMusic(bool remove = false);

    /// returns random element of track
    shared_ptr<PMusic> RandomMusic(bool remove = false);
```