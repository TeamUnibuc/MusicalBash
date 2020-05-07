#ifndef INC_APPLICATION_EXCEPTIONS_
#define INC_APPLICATION_EXCEPTIONS_

#include <exception>
#include <cstring>
#include <memory>

/*
 * Our own Exception class to use when loading an object to for the interface (texture, font, etc) fails
 * It will log the path to the file that failed to load
 */
class loading_error : public std::exception
{
private:
    /// The message that will be logged
    char * message;
protected:
public:
    /// Error constructor that takes in the path of the file that failed to load
    loading_error(std::string path);

    /// Overriding the what() function
    const char * what() const throw();

    /// Destructor to free up the memory taken up by the message
    ~loading_error();
};

/*
 * Our own Exception class to use when attempting to acces / write to an area out of the programs reach
 */
class out_of_bounds_error : public std::exception
{
private:
    /// The message that will be logged
    char * message;
protected:
public:
    /// Error constructor that takes in the message to be logged
    out_of_bounds_error(std::string message_);

    /// Overriding the what() function
    const char * what() const throw();

    /// Error destructor
    ~out_of_bounds_error();
};

/*
 * Our own Exception class to use when zipping goes wrong
 */
class zip_error : public std::exception
{
private:
    /// The message that will be logged
    char * message;
protected:
public:
    /// Error constructor that takes in the message to be logged
    zip_error(std::string message_);

    /// Overriding the what() function
    const char * what() const throw();

    /// Error destructor
    ~zip_error();
};

/*
 * Our own Exception class to use when the player encounters an error
 */
class player_runtime_error : public std::exception
{
private:
    /// The message that will be logged
    char * message;
protected:
public:
    /// Error constructor that takes in the message to be logged
    player_runtime_error(std::string message_);

    /// Overriding the what() function
    const char * what() const throw();

    /// Error destructor
    ~player_runtime_error();
};

#endif // INC_APPLICATION_EXCEPTIONS_