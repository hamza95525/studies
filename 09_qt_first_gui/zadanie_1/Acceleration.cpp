#include "Acceleration.h"
#include "QDebug"

Acceleration::Acceleration(QObject *parent) : QObject(parent)
{

}

void Acceleration::onChange(double v)
{
    emit changed(v - this->firstValue);
    this->firstValue = v;
}

void Acceleration::onSpeedChanged(double v)
{
    qDebug() << "[Acceleration] Value: " << v;
}
