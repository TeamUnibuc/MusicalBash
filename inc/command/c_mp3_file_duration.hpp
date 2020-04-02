#ifndef INC_COMMAND_MP3_FILE_DURATION_
#define INC_COMMAND_MP3_FILE_DURATION_

#include "c_command.hpp"

#include <string>

/**
 * Class able to return the length of an mp3 file from given path
 * For more info please check
 */
class CMp3FileDuration : public Command
{
public:
    /// returns the lengths of an mp3 file
    std::any execute(std::any obj = nill_obj);
};

#endif // INC_COMMAND_MP3_FILE_DURATION_