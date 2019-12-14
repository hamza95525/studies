#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Acceleration.h"
#include "Speed.h"
#include "Displacement.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Acceleration* acceleration = new Acceleration(this);;
    Displacement* displacement = new Displacement(this);
    Speed* speed = new Speed(this);
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
