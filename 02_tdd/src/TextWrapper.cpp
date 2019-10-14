#include "TextWrapper.h"
#include <string>

int TextWrapper::characters(std::string lancuch) {
    int nCount = 0;

    for(int i=0; i<lancuch.length(); i++)
    {
        nCount++;
    }

    return nCount;
}

int TextWrapper::separate(std::string lancuch) {
    int Col = Columns;
    std::string tekst = lancuch;
}