#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <iostream>

class Exception
{

    class DeckFileNotFound
    {
        void what()
        {
            std::cout <<"Deck File Error: File not found"<<std::endl;
        }
    };

    class DeckFileFormatError
    {
        void what(int lineNumberInDeckfile)
        {
            std::cout <<"Deck File Error: File format error in line "<<lineNumberInDeckfile<<std::endl;
        }
    };

    class DeckFileInvalidSize
    {
        void what()
        {
            std::cout <<"Deck File Error: Deck size is invalid"<<std::endl;
        }
    };

    class InvalidTeamSize{};
    
};

#endif 