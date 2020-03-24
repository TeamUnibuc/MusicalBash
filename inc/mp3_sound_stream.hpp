#ifndef MP3_SOUND_STREAM_
#define MP3_SOUND_STREAM_

#include <cstring>
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>
#include <SFML/Audio.hpp>
#include "mpg123.h"

namespace sfe
{
class Mp3 : public sf::SoundStream
{
public :
    Mp3();
    ~Mp3();

    bool openFromFile(const std::string& filename);
    bool openFromMemory(void* data, size_t sizeInBytes);

protected :
    virtual bool onGetData(Chunk& data);
    virtual void onSeek(sf::Time timeOffset);

private :
    mpg123_handle*      myHandle;
    size_t              myBufferSize;
    unsigned char*      myBuffer;
    sf::Mutex           myMutex;
    long                mySamplingRate;
};

} // namespace sfe

#endif // MP3_SOUND_STREAM_