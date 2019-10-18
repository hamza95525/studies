#pragma once

#include <string>

class TextWrapper{
public:

    int nCol;
    std::string Words;
    TextWrapper(){
        nCol = 0;
        Words = "Hi! Hello!";
    }

    TextWrapper(int nCol, std::string Words){
        this->nCol = nCol;
        this->Words = Words;
    }

    int columns(){
        return 10;
    }
};