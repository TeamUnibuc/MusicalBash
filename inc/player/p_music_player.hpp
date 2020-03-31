#ifndef INC_P_MUSIC_PLAYER_
#define INC_P_MUSIC_PLAYER_

#include <SFML/Audio.hpp>
#include "p_mp3_sound_stream.hpp"

/// Documentation in docs/sound_player.md

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
    void SetVolume(float volume);
private:
    std::string getExtensionLC(const std::string& str);
};

#endif // INC_P_MUSIC_PLAYER_
