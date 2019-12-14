#include "Speed.h"
#include <QDebug>

Speed::Speed(QObject *parent) : QObject(parent)
{

}

void Speed::onDisplacementChanged(double v)
{
    qDebug() << "Displacement changed to: " << v;
    emit changed(v);
}

void Speed::onChange(double v)
{
    if(hasFirstValue == 0) {
        firstValue = v;
        hasFirstValue = true;
    }
    else if(hasSecondValue == 0) {
        secondValue = v;
        hasSecondValue = true;
    }
    else {
        firstValue = secondValue;
        secondValue = v;
    }

    v = secondValue - firstValue;
    emit changed(v);
}


