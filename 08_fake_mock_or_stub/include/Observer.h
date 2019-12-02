//
// Created by student on 02.12.2019.
//
#pragma once

#include <iostream>

class Observer{
public:
    virtual void remember(std::string question, std::string answer) = 0;
    virtual std::string answer(std::string question) const = 0;
};