#include "c_mp3_file_duration.hpp"

#include <iostream>

CMp3FileDuration::CMp3FileDuration(const std::string& filePath)
    : filePath(filePath)
{ }

void CMp3FileDuration::Execute()
{
    using std::string;

    const int BUFF_SIZE = 256;
    char buffer[BUFF_SIZE + 1];
    string output;
    string command = "mp3info -p \"%S\" \"" + filePath + "\"";

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

    // std::cout << "MP3 Command: " << output << '\n';

    if (output.size() < 1)
        throw std::runtime_error("No output from mp3info command!");
    if (!isdigit(output[0])) 
        throw std::runtime_error("First character not digit in mp3info command!");

    duration_seconds_ = atoi(output.c_str());
}

int CMp3FileDuration::GetResult()
{
    return duration_seconds_;
}