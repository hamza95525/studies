#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    displacement = new Displacement(this);
    speed = new Speed(this);
    acceleration = new Acceleration(this);

    connect(displacement, SIGNAL(changed(double)), speed, SLOT(onChange(double)));
    connect(speed, SIGNAL(changed(double)), acceleration, SLOT(onChange(double)));

    ui->setupUi(this);

    connect(speed, SIGNAL(changed(double)), ui->lcdNumberSpeed, SLOT(display(double)));
    connect(acceleration, SIGNAL(changed(double)), ui->lcdNumberAcceleration, SLOT(display(double)));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    auto value = ui->lineEditDisplacement->text().toDouble();
    displacement -> set(value);
}
