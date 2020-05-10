#ifndef INC_APPLICATION_LOGGER_
#define INC_APPLICATION_LOGGER_

#include <memory>
#include <iostream>

#include "a_constants.hpp"

/// Singleton class that provides logging functionality
class Logger
{
private:
    Logger();
    Logger(const Logger & oth) = delete;
    Logger & operator=(const Logger & oth) = delete;

public:
    static void PrintEnum (Constants::State::W type)
    {
        if (type == Constants::State::W::Albums)
        std::cerr << "W-Albums";
    if (type == Constants::State::W::Create)
        std::cerr << "W-Create";
    if (type == Constants::State::W::Home)
        std::cerr << "W-Home";
    if (type == Constants::State::W::Import)
        std::cerr << "W-Import";
    if (type == Constants::State::W::Playlists)
        std::cerr << "W-Playlists";
    if (type == Constants::State::W::Queue)
        std::cerr << "W-Queue";
    if (type == Constants::State::W::ViewAlbum)
        std::cerr << "W-ViewAlbum";
    if (type == Constants::State::W::ViewPlaylist)
        std::cerr << "W-ViewPlaylist";
    }
    
    static Logger & Get();

    /**
     * Logger `<<` operator implemented inline for not
     * having issues with un-applied template argument
     */
    template <typename T>
    Logger& operator << (const T & elem) {
        std::cerr << elem;
        return *this;
    }

    typedef std::ostream& (*SEL)(std::ostream&);
    
    Logger& operator << (SEL manipulator)
    {
        manipulator(std::cerr);

        return *this;
    }

    

};

#endif // INC_APPLICATION_LOGGER_