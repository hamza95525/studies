#pragma once

#include <string>

using namespace std;

class TextWrapper{
public:

    int nCol;
    string Words;
    int nLength;

    TextWrapper(){
        nCol = 0;
        Words = "";
        nLength = Words.length();
    }

    TextWrapper(int nCol, string Words){
        this->nCol = nCol;
        this->Words = Words;
        nLength = Words.length();
    }

    int wrapping();


};