#ifndef SPEED_H
#define SPEED_H

#include <QObject>

class Speed : public QObject
{
    Q_OBJECT

public:
    explicit Speed(QObject *parent = nullptr);

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

#endif // SPEED_H

