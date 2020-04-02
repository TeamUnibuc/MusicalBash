#ifndef INC_COMMAND_MP3_FILE_DURATION_
#define INC_COMMAND_MP3_FILE_DURATION_

#include "c_command.hpp"

#include <string>

/**
 * Class able to return the length of an mp3 file from given path
 * For more info please check
 */
class CMp3FileDuration final : public Command
{
private:
    std::string filePath;
    int duration_seconds_;

public:
    CMp3FileDuration() = delete;

    /// Ctor, filePath is the path to the mp3 file
    CMp3FileDuration(const std::string& filePath);

    /// Calculates the duration of the mp3 file
    void Execute();

    /// Returns the duration of the file in seconds
    int GetResult();
};

#endif // INC_COMMAND_MP3_FILE_DURATION_