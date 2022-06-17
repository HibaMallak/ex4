#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <iostream>

    class DeckFileNotFound : public std::exception
    {

    public:

        const char* what() const noexcept override
        {
            return const_cast<char*>("Deck File Error: File not found");
        }

        DeckFileNotFound()=default;

        virtual ~DeckFileNotFound()=default;
    };

    class DeckFileFormatError : public std::exception
    {
    public:
        DeckFileFormatError(int line) : m_lineError(line)
        {

        };

        virtual ~DeckFileFormatError()=default;

        const char* what() const noexcept override
        {
            std::string output= "Deck File Error: File format error in line "+ std::to_string(m_lineError);
            return const_cast<char*>(output.c_str());
        }

    private:
        int m_lineError;
    };

    class DeckFileInvalidSize : public std::exception
    {
    public:

        const char* what() const noexcept override
        {
             return const_cast<char*>("Deck File Error: Deck size is invalid");
        }

        DeckFileInvalidSize()=default;

        virtual ~DeckFileInvalidSize()=default;
    };


#endif 