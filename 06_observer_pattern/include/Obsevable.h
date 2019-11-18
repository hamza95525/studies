//
// Created by student on 18.11.2019.
//
#pragma once
#include "Observer.h"

class Observable : public Observer
{
private:
    std::set<Observer*> observers;

protected:
    void notifyObservers(float);

public:
    void registerObserver(Observer*);
    void unregisterObserver(Observer*);

};
