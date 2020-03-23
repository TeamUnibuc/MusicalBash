#ifndef INC_SOUND_PLAYER_
#define INC_SOUND_PLAYER_

#include <SFML/Audio.hpp>
#include "mp3_sound_stream.hpp"

class SoundPlayer
{
protected:
    const std::unique_ptr<sfe::Mp3> p_mp3;
    const std::unique_ptr<sf::Music> p_music;
    
public:
    SoundPlayer();
    SoundPlayer(const std::string & source);

    void Play();
    void Pause();
    bool IsPlaying() const;
    void SetVolume(float volume);
private:
    std::string getExtensionLC(const std::string& str);
};

#endif // INC_SOUND_
