# PIndex

### Class storing the information about all the albums, playlists and musics.

### Implementation:

1. [p_index.hpp](/inc/player/p_index.hpp)
1. [p_index.cpp](/src/player/p_index.cpp)


## List of methods:

```c++
    /// constructor
    PIndex();

    /// converts the content of the class, playlists, albums and musics to a string
    std::string Zip() const;

    /// restores the content of the class from the zip string
    void Restore(std::string zipped);

```