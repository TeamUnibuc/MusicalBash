#include "c_mp3_file_duration.hpp"

std::any CMp3FileDuration::execute(std::any obj)
{
    using std::string;

    const int BUFF_SIZE = 256;
    char buffer[BUFF_SIZE + 1];
    string output;
    string command = "mp3info -p \"%S\" " + std::any_cast<string>(obj);

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

    return output;
}

