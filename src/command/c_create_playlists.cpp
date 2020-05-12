#include "c_create_playlists.hpp"

std::unique_ptr<CGetUserInput> CCreatePlaylists::user_input_command_;
std::thread CCreatePlaylists::user_input_thread_;

CCreatePlaylists::CCreatePlaylists() { }


void CCreatePlaylists::Execute()
{
    Logger::Get() << "CreatePlaylist command received\n";

    if (user_input_command_) {
        Logger::Get() << "   Found pending create playlist command so skipping...\n";
        return;
    }

    user_input_command_ = std::make_unique<CGetUserInput>("Please enter the playlist name:");

    user_input_thread_ = std::thread(&CGetUserInput::Execute, user_input_command_.get());
}

void CCreatePlaylists::PostExecutionVerification()
{
    if (user_input_command_ && user_input_command_->thread_is_locked_.try_lock()) {
        /// there is a pending operation that I just managed to lock to
        user_input_thread_.join();

        std::string playlist_name = user_input_command_->GetResult();

        if (playlist_name != "") {
            Knowledge::Daddy_Player->CreatePlaylist(playlist_name);
            Logger::Get() << "Playlist " << playlist_name << " has been created" << '\n';
        }
        user_input_command_.release();
        user_input_thread_ = std::thread();
    }
}
