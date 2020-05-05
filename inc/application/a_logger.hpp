#ifndef INC_APPLICATION_LOGGER_
#define INC_APPLICATION_LOGGER_

#include <memory>
#include <iostream>

/// Singleton class that provides logging functionality
class Logger
{
private:
    Logger();
    static Logger * ptr_to_logger;

public:
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