#include "Displacement.h"

Displacement::Displacement(QObject *parent) : QObject(parent)
{

}

void Displacement::set(double v)
{
    value = v;
    emit changed(v);
}

double Displacement::get()
{
    return value;
}
