#ifndef ACCELERATION_H
#define ACCELERATION_H

#include <QObject>

class Acceleration : public QObject
{
    Q_OBJECT

public:
    explicit Acceleration(QObject *parent = nullptr);

     Q_INVOKABLE double get();

signals:
    void changed(double v);

public slots:
    void onChange(double v);

private:
    double first{};
    double second{};
    float value;
};

#endif // ACCELERATION_H

