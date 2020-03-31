# PMusic

### Class storing the information about a single track.

### Implementation:

1. [p_music.hpp](/inc/player/p_music.hpp)
1. [p_music.cpp](/src/player/p_music.cpp)


## List of methods:

```c++
    /// constructor
    PMusic();

    /// creates a new music file 
    void Create(std::string PATH);

    /// converts the content of the class to a string
    std::string Zip() const;

    /// restores the content of the class from the zip string
    void Restore(std::string zipped);

    /// returns the title of the song (the name)
    std::string getTitle() const;

    /// returns nr of times it was played
    int getPlayedCount() const;

    /// adds 1 to the played count
    void addPlayedCount();


```