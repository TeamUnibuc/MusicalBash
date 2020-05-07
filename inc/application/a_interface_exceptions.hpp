#ifndef INC_APPLICATION_INTERFACE_EXCEPTIONS_
#define INC_APPLICATION_INTERFACE_EXCEPTIONS_

#include <exception>

/*
 * Our own Exception class to use when loading an object to for the interface (texture, font, etc) fails
 */
class interface_load_exception : public std::exception
{
private:
    char* msg;
protected:
public:
    
};

#endif // INC_APPLICATION_INTERFACE_EXCEPTIONS_