#pragma once

class TextWrapper{
public:
    int Columns;
    TextWrapper(int C){
        this->Columns = C;
    };
    int characters();
    int separate();
};