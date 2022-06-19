#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <iostream>

static const std::string FILE_NOT_FOUND= "Deck File Error: File not found";
static const std::string FORMAT_ERROR= "Deck File Error: File format error in line ";
static const std::string INVALID_SIZE="Deck File Error: Deck size is invalid";

    class DeckFileNotFound : public std::exception
    {

    public:

        DeckFileNotFound()=default;
        virtual ~DeckFileNotFound() override=default;

        virtual const char* what() const noexcept override
        {
            return (FILE_NOT_FOUND).c_str();
        }

    };



    class DeckFileFormatError : public std::exception
    {
    public:
        DeckFileFormatError(int line) : m_Error_message(FORMAT_ERROR+ std::to_string(line))
        {

        };

        virtual ~DeckFileFormatError() override=default;

        virtual const char* what() const noexcept override
        {
            return (m_Error_message).c_str();
        }

    private:
        std::string m_Error_message;
    };

    class DeckFileInvalidSize : public std::exception
    {
    public:

        DeckFileInvalidSize()=default;
        virtual ~DeckFileInvalidSize() override=default;

        virtual const char* what() const noexcept override
        {
            return (INVALID_SIZE).c_str();
        }
    };


#endif 