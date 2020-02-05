#ifndef ACCELERATION_H
#define ACCELERATION_H
#include <QObject>
class Acceleration : public QObject
{
    Q_OBJECT
public:
    explicit Acceleration(QObject *parent = nullptr);
signals:
    void changed(double v);
private:
    double firstValue;
public slots:
    void onChange(double v);
    void onSpeedChanged(double v);
};
#endif // ACCELERATION_H
