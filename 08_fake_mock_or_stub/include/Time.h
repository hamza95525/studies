//
// Created by student on 02.12.2019.
//
#pragma once
class Time{
public:
    virtual void create(bool endless) = 0;
    virtual long long now() const = 0;
    virtual void flow() = 0;
};
