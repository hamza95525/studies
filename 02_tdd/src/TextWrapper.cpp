#include "TextWrapper.h"
#include <string>
#include <iostream>


string TextWrapper::wrapping() {
    int Length = nLength;
    string str = Words;
    int colNum = nCol;

    if(colNum == 1){
        if( str == "" )
            return str;
        else {
            for (int i = 0; i < (Length*2) - 1; i++) {
                if (i % 2 != 0)
                    str.insert(i, "\n");
            }
        }
    }
    else{
        int SpaceLeft = Length;
        for(int i=0; i<=Length; i++){
            if(colNum + 1 > SpaceLeft){
                str.insert(i, "\n");
                SpaceLeft = Length - 1;
            }
            else
                SpaceLeft -= colNum + 1;
        }
    }

    return str;

}