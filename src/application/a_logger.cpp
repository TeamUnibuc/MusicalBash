#include "a_logger.hpp"

#include <iostream>

Logger::Logger() { }

Logger & Logger::Get()
{
    static Logger logger;
    return logger;
}
