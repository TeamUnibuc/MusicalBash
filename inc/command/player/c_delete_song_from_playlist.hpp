#pragma once /// COMMAND DELETE SONG FROM PLAYLIST HPP

#include "command.hpp"

#include "p_playlist.hpp"
#include "p_music.hpp"

class CDeleteSongFromPlaylist : public Command
{
private:
    SharedPtr<PMusic>    music_;
    SharedPtr<PPlaylist> playlist_;
    

public:
    CDeleteSongFromPlaylist(SharedPtr<PMusic> music, SharedPtr<PPlaylist> playlist);

    void SetPlaylist(SharedPtr<PPlaylist> ptr);

    void SetMusic(SharedPtr<PMusic> ptr);

    void Execute() override;
};