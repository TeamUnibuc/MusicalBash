#pragma once // C_CREATE_PLAYLISTS

#include "command.hpp"
#include "c_file_select.hpp"
#include "a_knowledge.hpp"

#include <thread>

/**
 * Command adding a new song to an existing playlist
*/
class CAddMusicToPlaylist : public Command
{
    /**
     * Pointer to the only allowed CFileSelect command.
     * The pointer is used to launch a new thread, whose joinability
     * is verified with the "thread_is_locked_" mutex.
     */
    static std::unique_ptr<CFileSelect> file_select_command_;
    static std::thread file_select_thread_;
    static std::shared_ptr<PPlaylist> playlist_;

public:

    CAddMusicToPlaylist();

    void Execute(std::shared_ptr<PPlaylist> playlist);

    void Execute() override;

    static void PostExecutionVerification();
};
