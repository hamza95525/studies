#include "acceleration.h"

Acceleration::Acceleration(QObject *parent) : QObject(parent)
{

}

double Acceleration::get()
{
    value = second - first;
    return value;

}

void Acceleration::onChange(double v)
{
    first = second;
    second = v;

    emit changed(get());
}

