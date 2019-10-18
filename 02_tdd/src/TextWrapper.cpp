#include "TextWrapper.h"
#include <string>
#include <iostream>


string TextWrapper::wrapping() {

    string str = Words;
    int Length = nLength;
    int colNum = nCol;
    int counter = 1;
    int firstColNum = colNum;


    if ( colNum % 2 != 0 ) {
        if (str == "")  return str;

        if( colNum == 1) {
            for (int i = 1; i < (Length * 2) - 1; i++) {
                if (i % 2 != 0)
                    str.insert(i, "\n");
            }
        }

        else{
            for (int i = 1; i <= Length; i++) {
                if (i % colNum == 0) {
                    str.insert(i, "\n");
                    colNum = colNum+firstColNum+counter;
                }
            }
        }

    }

    else {
        for (int i = 1; i < Length; i++) {
            if (i % 2 == 0 && str.at(i) != ' ') {
                str.insert(i, "\n");
            }
            else if (str.at(i) == ' ') {
                str.replace(i, 1, "\n");
                break;
            }
        }
    }


    return str;

}