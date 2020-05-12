#include "c_import_album.hpp"

std::unique_ptr<CDirectorySelect> CImportAlbum::dir_select_command_;
std::thread CImportAlbum::dir_select_thread_;

CImportAlbum::CImportAlbum() { }

void CImportAlbum::Execute()
{
    Logger::Get() << "Import Album command received\n";

    if (dir_select_command_) {
        Logger::Get() << "   Found pending import album command so skipping...\n";
        return;
    }

    dir_select_command_ = std::make_unique<CDirectorySelect>();

    dir_select_thread_ = std::thread(&CDirectorySelect::Execute, dir_select_command_.get());
}

void CImportAlbum::PostExecutionVerification()
{
    if (dir_select_command_ && dir_select_command_->thread_is_locked_.try_lock()) {
        /// there is a pending operation that I just managed to lock to
        dir_select_thread_.join();

        std::string album_name = dir_select_command_->GetResult();

        if (album_name != "") {
            Knowledge::Daddy_Player->CreateAlbum(album_name);
            Logger::Get() << "Album " << album_name << " added successfully!!! \n";
        }
        dir_select_command_.reset();
        dir_select_thread_ = std::thread();
    }
}