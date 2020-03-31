# PMusicPlayer

### Class able to play sound using the `SFML/Sound` engine.

### Implementation:

1. [p_music_player.hpp](/inc/player/p_music_player.hpp)
1. [p_music_player.cpp](/src/player/p_music_player.cpp)

## List of methods:

```c++
/// creates a player object from file
MusicPlayer(string file);

/// starts playing
void Play();

/// stops the music and resets to second 0
void Stop();

/// pauses the music
void Pause();

/// returns if music is curently playing
bool IsPlaying();

/// returns length in seconds of the music
int GetDuration();

/// returns time played (from start)
int GetPlayingOffest();

/// sets offset (where to start the music from)
void SetPlayingOffest(int where);

/// sets volume (0-100)
void SetVolume(float volume);

/// gets curent volume
int GetVolume(); 
```