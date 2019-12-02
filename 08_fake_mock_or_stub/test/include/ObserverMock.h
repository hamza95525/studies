//
// Created by student on 02.12.2019.
//
#pragma once

#include "Observer.h"
#include "TestIncludes.h"

class ObserverMock : public Observer{
public:
    MOCK_METHOD2(remember, void(std::string question, std::string answear));
    MOCK_CONST_METHOD1(answer, std::string(std::string question));
};