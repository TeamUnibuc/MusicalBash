#include "a_exceptions.hpp"

loading_error::loading_error(std::string path_)
{
    path_ = "Failed to load file at: " + path_;
    message = new char[path_.size() + 1];
    std::copy(path_.begin(), path_.end(), message);
    message[path_.size()] = '\0';
}

const char * loading_error::what() const throw()
{
    return message;
}

loading_error::~loading_error()
{
    delete[] message;
}

out_of_bounds_error::out_of_bounds_error(std::string message_)
{
    message = new char[message_.size() + 1];
    std::copy(message_.begin(), message_.end(), message);
    message[message_.size()] = '\0';
}

const char * out_of_bounds_error::what() const throw()
{
    return message;
}

out_of_bounds_error::~out_of_bounds_error()
{
    delete []message;
}

zip_error::zip_error(std::string message_)
{
    message = new char[message_.size() + 1];
    std::copy(message_.begin(), message_.end(), message);
    message[message_.size()] = '\0';
}

const char * zip_error::what() const throw()
{
    return message;
}

zip_error::~zip_error()
{
    delete []message;
}

player_runtime_error::player_runtime_error(std::string message_)
{
    message = new char[message_.size() + 1];
    std::copy(message_.begin(), message_.end(), message);
    message[message_.size()] = '\0';
}

const char * player_runtime_error::what() const throw()
{
    return message;
}

player_runtime_error::~player_runtime_error()
{
    delete []message;
}

bad_behaviour::bad_behaviour(std::string message_)
{
    message = new char[message_.size() + 1];
    std::copy(message_.begin(), message_.end(), message);
    message[message_.size()] = '\0';
}

const char * bad_behaviour::what() const throw()
{
    return message;
}

bad_behaviour::~bad_behaviour()
{
    delete []message;
}

null_pointer::null_pointer(std::string message_)
{
    message = new char[message_.size() + 1];
    std::copy(message_.begin(), message_.end(), message);
    message[message_.size()] = '\0';
}

const char * null_pointer::what() const throw()
{
    return message;
}

null_pointer::~null_pointer()
{
    delete []message;
}