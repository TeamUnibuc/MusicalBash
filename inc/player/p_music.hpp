#ifndef INC_P_MUSIC_
#define INC_P_MUSIC_

#include <string>

#include <SFML/Audio.hpp>
#include "c_mp3_file_duration.hpp"

/**
 * Class storing the information about a single track.
 */

class PMusic
{
    /// number of times a song was played
    int played_count_;
    /// absolute path of the song (in the filesistem of the PC)
    std::string path_;
    /// The Duration of the music
    double duration_seconds_;

public:
    /* Creates a new music from the path path */
    PMusic(std::string path);

    /// converts the content of the class to a string
    std::string Zip() const;

    /// restores the content of the class from the zip string
    void Unzip(std::string zipped);

    /// returns full path of the song
    std::string getFullPath() const;

    /// returns name of the song
    std::string getName() const;

    /// returns nr of times it was played
    int getPlayedCount() const;

    /// adds 1 to the played count
    void addPlayedCount();

    /// Returns the duration of the music in seconds
    double getDuration() const;
};

#endif // INC_P_MUSIC_