#pragma once // C_IMPORT_ALBUM_HPP_

#include "command.hpp"
#include "c_directory_select.hpp"
#include "a_knowledge.hpp"

#include <mutex>
#include <thread>

/**
 * Class creating a new album using a new thread.
 * To join it we must call PostExecutionVerification()
*/
class CImportAlbum : public Command
{
    /**
     * Pointer to the only allowed c_directory_select command.
     * The pointer is used to launch a new thread, whose joinability
     * is verified with the "thread_is_locked_" mutex.
     */
    static std::unique_ptr<CDirectorySelect> dir_select_command_;
    static std::thread dir_select_thread_;

public:
    CImportAlbum();

    void Execute() override;

    /**
     * Function called from the main loop once every few frames.
     * It detects if the linked object (dir_select_command_) is
     * joinable and if yes it finishes the command execution
     */
    static void PostExecutionVerification();
};
