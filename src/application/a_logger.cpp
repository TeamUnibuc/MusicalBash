#include "a_logger.hpp"

#include <iostream>

Logger * Logger::ptr_to_logger = nullptr;

Logger::Logger() { }

Logger & Logger::Get()
{
    if (ptr_to_logger == nullptr)
        ptr_to_logger = new Logger();
    return *ptr_to_logger;
}
