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

    void Play();
    void Pause();
    bool IsPlaying() const;
    bool IsPaused() const;
    void SetVolume(float volume);
    double getDuration() const;
    double getPlayingOffset() const;

private:
    std::string getExtensionLC(const std::string& str);
};

#endif // INC_P_MUSIC_PLAYER_
