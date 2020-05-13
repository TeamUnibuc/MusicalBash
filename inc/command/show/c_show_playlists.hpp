#pragma once // C_SHOW_PLAYLISTS_HPP_

#include "command.hpp"
#include "a_knowledge.hpp"

/**
 * TO DO
*/
class CShowPlaylists : public Command
{
private:

public:
    CShowPlaylists();

    void Execute() override;
};
