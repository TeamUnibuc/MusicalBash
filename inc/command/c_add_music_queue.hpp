#pragma once

#include "command.hpp"
#include "p_music.hpp"
#include "a_knowledge.hpp"

class CAddMusicQueue : public Command
{
private:
    SharedPtr<PMusic> music_;

public:
    CAddMusicQueue(SharedPtr<PMusic>);

    void Execute() override;

    void SetMusic(SharedPtr<PMusic> ptr);
};

