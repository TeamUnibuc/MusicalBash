#pragma once // C_DOWNLOAD_fROM_WEB

#include "command.hpp"
#include "a_knowledge.hpp"
#include "c_get_user_input.hpp"
#include "a_utils.hpp"

#include <thread>

/**
 * Command downloading a music from the internet and placing it in
 * the "$HOME/.musicalbash/downloads" folder
*/
class CDownloadFromWeb : public Command
{
    /**
     * Pointer to the only allowed CGetUserInput command.
     * The pointer is used to launch a new thread, whose joinability
     * is verified with the "thread_is_locked_" mutex.
     */
    static std::unique_ptr<CGetUserInput> user_input_command_;
    static std::thread user_input_thread_;

    /** This function is running in a parralel thread so it should be static and copy the argument BY VALUE
     * So that it doesn't crash when the (this)object that called this function gets destroyed
     */
    static void        DownloadAndMove(std::string url);
    static std::string FindSongName(std::string url);

    static const std::string kTempPath;
    static const std::string kDownloadPath;

public:

    CDownloadFromWeb();

    void Execute() override;

    static void PostExecutionVerification();
};
