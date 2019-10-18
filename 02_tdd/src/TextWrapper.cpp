#include "TextWrapper.h"
#include <string>
#include <iostream>


string TextWrapper::wrapping() {
    int Length = nLength;
    string str = Words;
    int colNum = nCol;
    int newLineCounter = 0;


    if ( colNum % 2 != 0 ) {
        if (str == "")  return str;

        if( colNum == 1) {
            for (int i = 0; i < (Length * 2) - 1; i++) {
                if (i % 2 != 0)
                    str.insert(i, "\n");
            }
        }

        else{
            for (int i = 1; i < Length; i++) {
                if (i % colNum == 0) {
                    str.insert(i, "\n");
                    newLineCounter++;
                }
            }
        }

    }

    else {
        for (int i = 1; i < Length; i++) {
            if (i % 2 == 0 && str.at(i) != ' ') {
                str.insert(i, "\n");
            } else if (str.at(i) == ' ') {
                str.replace(i, 1, "\n");
                break;
            }
        }
    }


    return str;

}