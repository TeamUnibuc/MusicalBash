#include "c_download_from_web.hpp"

std::unique_ptr<CGetUserInput> CDownloadFromWeb::user_input_command_;
std::thread CDownloadFromWeb::user_input_thread_;

CDownloadFromWeb::CDownloadFromWeb() { }


void CDownloadFromWeb::Execute()
{
    Logger::Get() << "DownloadFromWeb command received\n";

    if (user_input_command_) {
        Logger::Get() << "   Found pending command so skipping...\n";
        return;
    }

    user_input_command_ = std::make_unique<CGetUserInput>("Please enter the link of the desired music:");

    user_input_thread_ = std::thread(&CGetUserInput::Execute, user_input_command_.get());
}

void CDownloadFromWeb::PostExecutionVerification()
{
    if (user_input_command_ && user_input_command_->thread_is_locked_.try_lock()) {
        /// there is a pending operation that I just managed to lock to
        user_input_thread_.join();

        std::string link_to_music = user_input_command_->GetResult();

        std::cerr << "Finished execution\n";

        if (link_to_music != "") {
            Logger::Get() << "DownloadFromWeb command received link " << '\n';

            std::string mini_script = "(cd $HOME/.musicalbash/downloads; ";
            mini_script += "youtube-dl " + link_to_music;
            mini_script += " -x --audio-format mp3 &)";
            
            std::cerr << "Trying to execute \n" + mini_script + "\n\n";
            system(mini_script.c_str());
        }
        user_input_command_.reset();
        user_input_thread_ = std::thread();
    }
}
