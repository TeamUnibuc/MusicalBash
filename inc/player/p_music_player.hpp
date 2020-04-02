#ifndef INC_P_MUSIC_PLAYER_
#define INC_P_MUSIC_PLAYER_

#include <SFML/Audio.hpp>
#include "p_mp3_sound_stream.hpp"

/**
 * Class able to play sound using the `SFML/Sound` engine.
 */

class PMusicPlayer
{
protected:
    const std::unique_ptr<sfe::Mp3> p_mp3;
    const std::unique_ptr<sf::Music> p_music;
    
public:
    PMusicPlayer();
    PMusicPlayer(const std::string & source);

    /// makes the music play
    void Play();

    /// makes the music pause
    void Pause();

    /// makes the music stop
    void Stop();

    /// returns true if the music is playing
    bool IsPlaying() const;

    /// returns true if the music is paused
    bool IsPaused() const;

    /// returns true if the music is stopped
    bool IsStopped() const;

    /// sets the volume (a number between 0 - 100)
    void SetVolume(double volume);

    /// returns curent volume (between 0 - 100)
    double GetVolume() const;

    /// returns track duration in seconds
    double GetDuration() const;

    /// returns where the cursor got (time played so far) in seconds
    double GetPlayingOffset() const;

    /// sets the cursor at a given position in seconds
    void SetPlayingOffset(double offset);

private:
    std::string getExtensionLC(const std::string& str);
};

#endif // INC_P_MUSIC_PLAYER_
