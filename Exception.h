#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <iostream>

class Exception
{

    public:

    class DeckFileNotFound : public std::exception
    {
        DeckFileNotFound()=default;
        virtual ~DeckFileNotFound()=default;

        const char* what() const noexcept override
        {
            return const_cast<char*>("Deck File Error: File not found");
        }
    };

    class DeckFileFormatError : public std::exception
    {
    public:
        DeckFileFormatError(int line) : m_lineError("line")
        {

        };

        virtual ~DeckFileFormatError()=default;

        const char* what() const noexcept override
        {
            std::string output= "Deck File Error: File format error in line "+ m_lineError;
            return const_cast<char*>(output.c_str());
        }

    private:
        std::string m_lineError;
    };

    class DeckFileInvalidSize : public std::exception
    {

        const char* what() const noexcept override
        {
             return const_cast<char*>("Deck File Error: Deck size is invalid");
        }

    public:
        DeckFileInvalidSize()=default;

        virtual ~DeckFileInvalidSize()=default;
    };
};

#endif 