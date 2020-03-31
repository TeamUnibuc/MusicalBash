#ifndef INC_P_MUSIC_
#define INC_P_MUSIC_

#include <string>

/**
 * Class storing the information about a single track.
 */

class PMusic
{
    /// number of times a song was played
    int played_count_;
    /// absolute path of the song (in the filesistem of the PC)
    std::string path_;

public:
    /* PMusic constructor. I don't think we shoud overload it as it will
    created confusions between the Create function and the Resore one */
    PMusic();

    /// creates a new music file (curent object becomes the music located at path)
    void Create(std::string path);

    /// converts the content of the class to a string
    std::string Zip() const;

    /// restores the content of the class from the zip string
    void Restore(std::string zipped);

    /// returns the title of the song (the name)
    std::string getTitle() const;

    /// returns full path of the song
    std::string getFullPath() const;

    /// returns nr of times it was played
    int getPlayedCount() const;

    /// adds 1 to the played count
    void addPlayedCount();
};

#endif // INC_P_MUSIC_