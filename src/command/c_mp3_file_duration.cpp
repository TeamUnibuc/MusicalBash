#include "c_mp3_file_duration.hpp"

CMp3FileDuration::CMp3FileDuration(const std::string& filePath)
    : filePath(filePath)
{ }

void CMp3FileDuration::Execute()
{
    using std::string;

    const int BUFF_SIZE = 256;
    char buffer[BUFF_SIZE + 1];
    string output;
    string command = "mp3info -p \"%S\" " + std::any_cast<string>(filePath);

    auto pstream = popen(command.c_str(), "r");

    if (pstream) {
        while (!feof(pstream)) {
            if (fgets(buffer, BUFF_SIZE, pstream) != NULL) 
                output.append(buffer);
            else
                break;
        }
    }
    pclose(pstream);

    duration_seconds_ = atoi(output.c_str());
}

int CMp3FileDuration::GetResult()
{
    return duration_seconds_;
}