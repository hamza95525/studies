#include "TextWrapper.h"
#include <iostream>
#include <string>

int TextWrapper::characters() {
    int nCount = 0;
    std::string literki("abc defgh i");
    for(int i=0; i<literki.length(); i++)
    {
        nCount++;
    }

    return nCount;
}

int TextWrapper::separate() {
    
}