#pragma once /// COMMAND DELETE PLAYLIST

#include "command.hpp"
#include "p_playlist.hpp"
#include "a_knowledge.hpp"

class CDeletePlaylist : public Command
{
private:
    SharedPtr<PPlaylist> pl_ptr;

public:
    CDeletePlaylist(SharedPtr<PPlaylist> ptr = nullptr);

    void SetPlaylist(SharedPtr<PPlaylist> ptr);

    void Execute() override;
};