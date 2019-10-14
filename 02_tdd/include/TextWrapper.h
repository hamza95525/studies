#include <iostream>
#include <string>
#pragma once

class TextWrapper{
public:
    int Columns;
    TextWrapper(int C){
        this->Columns = C;
    };

    int characters(std::string lancuch);
    int separate(std::string lancuch);
};