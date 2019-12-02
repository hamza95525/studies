#pragma once

#include "TimeImpl.h"
#include "Space.h"
#include "Observer.h"

class Universe {
public:

    Universe(TimeImpl &time, Space &space, Observer &observer);

    void create();
    void simulate(long years);

private:
    TimeImpl &time;
    Space &space;
    Observer &observer;
};
