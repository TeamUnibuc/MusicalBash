#pragma once // C_SHOW_MUSIC_QUEUE_HPP_

#include "command.hpp"

#include "a_knowledge.hpp" 

/**
 * TO DO
*/
class CShowMusicQueue : public Command
{
private:

public:
    CShowMusicQueue();

    void Execute() override;
};
