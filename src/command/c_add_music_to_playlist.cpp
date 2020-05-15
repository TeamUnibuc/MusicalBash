#include "c_add_music_to_playlist.hpp"

std::unique_ptr<CFileSelect> CAddMusicToPlaylist::file_select_command_;
std::thread CAddMusicToPlaylist::file_select_thread_;
std::shared_ptr<PPlaylist> CAddMusicToPlaylist::playlist_;

CAddMusicToPlaylist::CAddMusicToPlaylist() { }

void CAddMusicToPlaylist::Execute()
{
    throw bad_behaviour("Not allowed to call this function!");
}

void CAddMusicToPlaylist::Execute(std::shared_ptr<PPlaylist> playlist)
{
    Logger::Get() << "Add Music To Playlist command received\n";

    if (file_select_command_) {
        Logger::Get() << "   Found Add to Music album command so skipping...\n";
        return;
    }

    playlist_ = playlist;
    file_select_command_ = std::make_unique<CFileSelect>();
    file_select_thread_ = std::thread(&CFileSelect::Execute, file_select_command_.get());
}

void CAddMusicToPlaylist::PostExecutionVerification()
{
    if (file_select_command_ && file_select_command_->thread_is_locked_.try_lock()) {
        /// there is a pending operation that I just managed to lock to
        file_select_thread_.join();

        std::string music_name = file_select_command_->GetResult();

        if (music_name != "") {
            std::shared_ptr<PMusic> music = Knowledge::Daddy_Player->CreateMusic(music_name);
            playlist_->AddMusic(music);
            Logger::Get() << "Music " << music_name << " added successfully to " << playlist_->GetName() << "!!! \n";
        }
        file_select_command_.reset();
        file_select_thread_ = std::thread();
    }
}