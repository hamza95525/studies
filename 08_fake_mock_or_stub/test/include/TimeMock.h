//
// Created by student on 02.12.2019.
//
#pragma once
#include "TimeImpl.h"
#include "Time.h"
#include "TestIncludes.h"
class TimeMock : public Time{
public:
    MOCK_METHOD1(create, void(bool endless) );
    MOCK_CONST_METHOD0(now, long long());
    MOCK_METHOD0(flow, void());
};
