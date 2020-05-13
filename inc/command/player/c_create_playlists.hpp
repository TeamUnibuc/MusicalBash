#pragma once // C_CREATE_PLAYLISTS

#include "command.hpp"

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
