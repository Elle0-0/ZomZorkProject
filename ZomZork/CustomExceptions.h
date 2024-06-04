#ifndef CUSTOMEXCEPTIONS_H
#define CUSTOMEXCEPTIONS_H

#include <string>
#include <exception>


class CustomException : public std::exception
{
private:
    std::string msg;

public:
    explicit CustomException(const std::string& error) : msg(error) {}
    virtual const char* what () const noexcept override { //overiding thw what() function
        return msg.c_str();
    }
};


class InvalidRoomException : public CustomException
{
public:
    InvalidRoomException(const std::string& errorMessage) : CustomException(errorMessage) {}

};

#endif // CUSTOMEXCEPTIONS_H
