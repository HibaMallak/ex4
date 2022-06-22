#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <iostream>

static const std::string FILE_NOT_FOUND = "Deck File Error: File not found";
static const std::string FORMAT_ERROR = "Deck File Error: File format error in line ";
static const std::string INVALID_SIZE ="Deck File Error: Deck size is invalid";

class DeckFileNotFound : public std::exception
{
/*
* Deck File Error: File not found 
* This exception will be thrown when the cards deck file was not found:
*/    
public:

    DeckFileNotFound() = default;
    virtual ~DeckFileNotFound() override = default;

    virtual const char* what() const noexcept override
    {
        return (FILE_NOT_FOUND).c_str();
    }

};


class DeckFileFormatError : public std::exception
{
/*
* Deck File Error: File format error in line
* This exception will be thrown when the format of the cards deck file is not right,
* returning the number of line where it occured:
*/ 
public:

    DeckFileFormatError(int line) : m_errorMessage(FORMAT_ERROR + std::to_string(line))
    {

    };

    virtual ~DeckFileFormatError() override = default;

    virtual const char* what() const noexcept override
    {
        return (m_errorMessage).c_str();
    }

private:
    std::string m_errorMessage;

};


class DeckFileInvalidSize : public std::exception
{
/*
* Deck File Error: Deck size is invalid
* This exception will be thrown when the number of cards in the cards deck file is invalid 
* (when number of cards is less than 5):
*/ 
public:

    DeckFileInvalidSize() = default;
    virtual ~DeckFileInvalidSize() override = default;

    virtual const char* what() const noexcept override
    {
        return (INVALID_SIZE).c_str();
    }
};

#endif 