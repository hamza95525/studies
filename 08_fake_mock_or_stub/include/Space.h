//
// Created by student on 02.12.2019.
//
#pragma once

class Space{
public:
    virtual void create(unsigned int dimensions) = 0;
    virtual unsigned int dimensions() const = 0;
};