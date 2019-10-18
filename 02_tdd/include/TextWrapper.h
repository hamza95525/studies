#pragma once

#include <string>

class TextWrapper{
public:

    int nCol;
    TextWrapper(){
        nCol = 0;
    }

    TextWrapper(int nCol){
        this->nCol = nCol;
    }

    int columns(){
        return 10;
    }
};