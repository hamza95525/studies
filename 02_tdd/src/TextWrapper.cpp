#include "TextWrapper.h"
#include <string>
#include <iostream>
string TextWrapper::wrapping() {
    string str = Words;
    int Length = nLength;
    int colNum = nCol;
    int counter = 1;
    int firstColNum = colNum;
    if (str == "")  return str;
    if( colNum == 1) {
        for (int i = 1; i < (Length * 2) - 1; i++) {
            if (i % 2 != 0)
                str.insert(i, "\n");
        }
    }
    else{
        for (int i = 1; i <= str.length()-1 ; i++) {
            if (i % colNum == 0 && str.at(i) != ' ') {
                str.insert(i, "\n");
                colNum = colNum+firstColNum+counter;
            }
            else if (i % colNum == 0 && str.at(i) == ' ') {
                str.replace(i, 1, "\n");
                colNum = colNum+firstColNum+counter;
            }
        }
    }
//  JUZ BEZ COMMITOW ZAKOMENTOWALEM TA CZESC KODU PONIEWAZ PO PROSTU OKAZALA SIE ZBEDNA
    /*else {
        for (int i = 1; i < str.length(); i++) {
            if (i % colNum == 0 && str.at(i) != ' ') {
                str.insert(i, "\n");
                colNum = colNum+firstColNum+counter;
            }
            else if (i % colNum ==0 && str.at(i) == ' ') {
                str.replace(i, 1, "\n");
                colNum = colNum+firstColNum+counter;
            }
        }
    }
*/
    return str;
}
