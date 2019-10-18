#pragma once

#include <string>

class TextWrapper{
public:

    int nCol;
    std::string Words;
    int nLength = Words.length();
    TextWrapper(){
        nCol = 0;
        Words = "";
    }

    TextWrapper(int nCol, std::string Words){
        this->nCol = nCol;
        this->Words = Words;
    }

    int columns(){
        return 10;
    }
};