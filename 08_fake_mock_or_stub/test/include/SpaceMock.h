//
// Created by student on 02.12.2019.
//
#pragma once
#include "TestIncludes.h"
#include "Space.h"
class SpaceMock : public Space{
public:
    MOCK_METHOD1(create, void(unsigned int dimensions));
    MOCK_CONST_METHOD0(dimensions, unsigned int());
};
