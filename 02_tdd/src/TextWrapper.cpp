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

   /* else if(colNum ==2){
        for(int i=0;i<=Length; i++){
            if(i%2 == 0) {
                str.insert(i, "\n");
            }
        }
    }*/

    return str;

}