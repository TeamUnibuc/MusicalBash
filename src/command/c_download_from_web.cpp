#include "c_download_from_web.hpp"

std::unique_ptr<CGetUserInput> CDownloadFromWeb::user_input_command_;
std::thread CDownloadFromWeb::user_input_thread_;

const std::string CDownloadFromWeb::kTempPath = "$HOME/.musicalbash/tmp/";
const std::string CDownloadFromWeb::kDownloadPath = "$HOME/.musicalbash/downloads/";

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
            // Logger::Get() << "DownloadFromWeb command received link " << '\n';

            // std::string mini_script = "(cd $HOME/.musicalbash/downloads; ";
            // mini_script += "youtube-dl " + link_to_music;
            // mini_script += " -x --audio-format mp3 -o '%(title)s.%(ext)s' &)";
            
            // std::cerr << "Trying to execute \n" + mini_script + "\n\n";
            // system(mini_script.c_str());

            std::thread sideJob(DownloadAndMove, link_to_music);
            sideJob.detach();
        }
        user_input_command_.reset();
        user_input_thread_ = std::thread();
    }
}

std::string CDownloadFromWeb::FindSongName(std::string url)
{
    std::string songName = "";
    try {
        const std::string script = "youtube-dl '" + url + "' -x --audio-format mp3 -o '%(title)s.%(ext)s' --get-filename";
        

        char filename[1024];
        filename[0] = 0;

        FILE *f = popen(script.c_str(), "r");
        fgets(filename, 1024, f);

        if (filename[0] == 0)
            throw std::runtime_error("FindSongName subroutine did not return a valid song name!");
        
        songName = std::string(filename);
        if (songName.size() > 0)
            songName.pop_back();
    }
    catch (...) {
        Logger::Get() << "There was a problem with FindSongName for url: " + url + "\n";
    }

    songName = Utils::ReplaceExtensionWith(songName, "mp3");

    std::cerr << "Got filename: " << songName << '\n';
    return songName;
}

void CDownloadFromWeb::DownloadAndMove(std::string url)
{
    Logger::Get() << "DownloadFromWeb thread command received link: " + url << '\n';

    const std::string fileName = FindSongName(url);

    std::string download_script = "(cd " + kTempPath + "; ";
    download_script += "youtube-dl '" + url + "'";
    download_script += " -x --audio-format mp3 -o '%(title)s.%(ext)s')";
    
    std::cerr << "Executing:  \n  " + download_script + "\n\n";
    system(download_script.c_str());

    const std::string apostrofName = "\"" + fileName + "\"";

    std::string move_script = "mv " + kTempPath + apostrofName + "  " + kDownloadPath + apostrofName;
    std::cerr << "Executing:  \n " + move_script + "\n\n";
    system(move_script.c_str());

    std::cerr << "INFO: Download and Move Command finished for url: " + url + "\n";
}
