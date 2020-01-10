#ifndef SPEED_H
#define SPEED_H

#include <QObject>

class Speed : public QObject
{
    Q_OBJECT

    Q_PROPERTY(float value
               READ get
               WRITE set
               NOTIFY changed);

public:
    explicit Speed(QObject *parent = nullptr);

    Q_INVOKABLE double get();
    Q_INVOKABLE void set(double v);

signals:
    void changed(double v);

public slots:
    void onChange(double v);

private:
    double first{};
    double second{};
    float value;
};

#endif // SPEED_H

