#pragma once // C_CREATE_PLAYLISTS

#include "command.hpp"
#include "c_get_user_input.hpp"
#include "a_knowledge.hpp"

#include <thread>

/**
 * Command creating new playlists.
 * The command is started with Execute()
 * And one it finished executing it is joined
 * by regularly calling PostExecutionVerification()
*/
class CCreatePlaylists : public Command
{
    /**
     * Pointer to the only allowed CGetUserInput command.
     * The pointer is used to launch a new thread, whose joinability
     * is verified with the "thread_is_locked_" mutex.
     */
    static std::unique_ptr<CGetUserInput> user_input_command_;
    static std::thread user_input_thread_;

public:
    CCreatePlaylists();

    void Execute() override;

    static void PostExecutionVerification();
};
