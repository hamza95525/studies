#ifndef SPEED_H
#define SPEED_H

#include <QObject>

class Speed : public QObject
{
    Q_OBJECT
public:
    explicit Speed(QObject *parent = nullptr);

signals:
    void changed(double v);

private:
    bool hasFirstValue;
    bool hasSecondValue;
    int firstValue;
    int secondValue;

public slots:
    void onDisplacementChanged(double v);
    void onChange(double v);
};

#endif // SPEED_H
