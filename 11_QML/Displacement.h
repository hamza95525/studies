#ifndef DISPLACEMENT_H
#define DISPLACEMENT_H

#include <QObject>

class Displacement : public QObject
{
    Q_OBJECT
public:
    explicit Displacement(QObject *parent = nullptr);

    Q_INVOKABLE void set(double v);

signals:
    void changed(double v);

public slots:
};

#endif // DISPLACEMENT_H
