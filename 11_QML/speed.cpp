#include "speed.h"

Speed::Speed(QObject *parent) : QObject(parent)
{

}

double Speed::get()
{
    value = second - first;
    return value;
}

void Speed::onChange(double v)
{
    first = second;
    second = v;

    emit changed(get());
}


