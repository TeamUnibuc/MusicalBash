#pragma once // C_CREATE_PLAYLISTS

#include "command.hpp"
#include "c_get_user_input.hpp"
#include "a_knowledge.hpp"

/**
 * TO DO
*/
class CCreatePlaylists : public Command
{
private:

public:
    CCreatePlaylists();

    void Execute() override;
};
