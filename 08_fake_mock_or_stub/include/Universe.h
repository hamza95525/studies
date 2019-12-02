#pragma once

#include "TimeImpl.h"
#include "SpaceImpl.h"
#include "ObserverImpl.h"

class Universe {
public:

    Universe(TimeImpl &time, SpaceImpl &space, ObserverImpl &observer);

    void create();
    void simulate(long years);

private:
    TimeImpl &time;
    SpaceImpl &space;
    ObserverImpl &observer;
};
