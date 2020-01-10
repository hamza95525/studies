#ifndef DISPLACEMENT_H
#define DISPLACEMENT_H

#include <QObject>

class Displacement : public QObject
{
    Q_OBJECT

    Q_PROPERTY(float value
               READ get
               WRITE set
               NOTIFY changed);

public:
    explicit Displacement(QObject *parent = nullptr);

    Q_INVOKABLE void set(double v);
    Q_INVOKABLE double get();

signals:
    void changed(double v);

public slots:

private:
    double value;
};

#endif // DISPLACEMENT_H
