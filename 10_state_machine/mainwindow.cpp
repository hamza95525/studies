#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QStateMachine>
#include <QHistoryState>
#include <QFileDialog>
#include <QDebug>
#include <iostream>

#include <QStateMachine> //tu caly framework do maszyny stanow

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // TODO: Create state machine
    auto stateMachine = new QStateMachine(this);
    // TODO: Create states
    auto unLocked = new QState(stateMachine);
    auto Locked = new QState(stateMachine);

    auto Startup = new QState(unLocked);
    auto Open = new QState(unLocked);
    auto Error = new QState(unLocked);
    auto View = new QState(unLocked);
    auto Edit = new QState(unLocked);
    auto Save = new QState(unLocked);

    auto unLockedHistory = new QHistoryState(unLocked);


    // TODO: Set appropriate 'assignProperty'

    //------------UNLOCKED---------------------
    unLocked->assignProperty(ui->pbToggle, "text", "Lock");
    unLocked->assignProperty(ui->pbOpen, "enabled", true);
    unLocked->assignProperty(ui->pbSave, "enabled", true);
    unLocked->assignProperty(ui->teText, "enabled", true);

    //------------LOCKED-----------------------
    Locked->assignProperty(ui->pbToggle, "text", "Unlock");
    Locked->assignProperty(ui->pbOpen, "enabled", false);
    Locked->assignProperty(ui->pbSave, "enabled", false);
    Locked->assignProperty(ui->teText, "enabled", false);

    //------------STARTUP---------------------
    Startup->assignProperty(ui->pbOpen, "enabled", true);
    Startup->assignProperty(ui->pbSave, "enabled", false);
    Startup->assignProperty(ui->teText, "enabled", false);
    Startup->assignProperty(ui->teText, "placeholderText", "Open file to start editing...");

    //------------ERROR-----------------------
    Error->assignProperty(ui->pbOpen, "enabled", true);
    Error->assignProperty(ui->pbSave, "enabled", false);
    Error->assignProperty(ui->teText, "enabled", false);
    Error->assignProperty(ui->teText, "placeholderText", "Error ocured. Open file to start editing...");

    //------------VIEW---------------------
    View->assignProperty(ui->pbOpen, "enabled", true);
    View->assignProperty(ui->pbSave, "enabled", false);
    View->assignProperty(ui->teText, "enabled", true);

    //------------EDIT---------------------
    Edit->assignProperty(ui->pbOpen, "enabled", false);
    Edit->assignProperty(ui->pbSave, "enabled", true);
    Edit->assignProperty(ui->teText, "enabled", true);

    // TODO: Set state transitions including this class events and slots
    unLocked->addTransition(ui->pbToggle, SIGNAL(clicked()), Locked);
    Locked->addTransition(ui->pbToggle, SIGNAL(clicked()), unLockedHistory);

    Startup->addTransition(ui->pbOpen, SIGNAL(clicked(bool)), Open);

    Open->addTransition(this, SIGNAL(opened()), View);
    View->addTransition(ui->pbOpen, SIGNAL(clicked()), Open);

    Open->addTransition(this, SIGNAL(error()), Error);
    Error->addTransition(ui->pbOpen, SIGNAL(clicked()), Open);

    View->addTransition(ui->teText, SIGNAL(textChanged()), Edit);
    Edit->addTransition(ui->pbSave, SIGNAL(clicked()), Save);

    Save->addTransition(this, SIGNAL(saved()), View);
    Save->addTransition(this, SIGNAL(error()), Error);

    connect(Open, SIGNAL(entered()), this, SLOT(open()));
    connect(Save, SIGNAL(entered()), this, SLOT(save()));

    // TODO: Set initial state
    stateMachine -> setInitialState(unLocked);
    unLocked->setInitialState(Startup);

    // TODO: Start state machine
    stateMachine->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::open()
{
    // TODO: Show file dialog
    auto fileName = QFileDialog::getOpenFileName(this, tr("Open file to start editing..."), "/home/", tr("Text Files (*.txt)"));
    qDebug() << fileName;
    // TODO: Open selected file
    QFile file( fileName );

    // TODO: Emit 'error' if opening failed
    if(!file.open(QIODevice::ReadOnly)){
        emit error();
    }
    // TODO: Set text and emit 'opened' if suceeded

    else {
        QTextStream in(&file);
        ui->teText->setPlainText(in.readAll());
        emit opened();
    }
    // TODO: Save file name in 'fileName'
    this->fileName = fileName;
}

void MainWindow::save()
{
    // TODO: Open 'fileName' for writing
    QFile file( this -> fileName);

    // TODO: Emit 'error' if opening failed
    if(!file.open(QIODevice::WriteOnly)){
        emit error();
    }
    // TODO: Save file and emit 'saved' if succeeded
    else {
        QTextStream out(&file);
        out << ui->teText->toPlainText();
        emit saved();
    }
}

void MainWindow::log()
{
    qDebug() << "Inside log() function...";
    emit done();
}


/*
 *     // TODO: Create state machine
auto stateMachine = new QStateMachine(this); //utworzona klasa maszyna stanow i odrazu jest podpieta pod glowne okno, poprzez (this)

// TODO: Create states
auto greenState = new QState(stateMachine); //tym razem podpinamy pod maszyne stanow zamiast podpinac pod okno
auto yellowState = new QState(stateMachine); //definicja konkretnych stanow
auto redState = new QState(stateMachine);
auto logState = new QState(stateMachine);

// TODO: Set appropriate 'assignProperty'
greenState->assignProperty(ui->pbToggle, "text", "GREEN"); //mowimy jak ma wygladac w ui ten konkretny stan
yellowState->assignProperty(ui->pbToggle, "text", "YELLOW");
redState->assignProperty(ui->pbToggle, "text", "RED");

// TODO: Set state transitions including this class events and slots - ustawic odpowiednie przejscia pomiedzy stanami
greenState->addTransition(ui->pbToggle, SIGNAL(clicked()), redState); //mowimy co ma byc trigerem do tego przejscia
redState->addTransition(ui->pbToggle, SIGNAL(clicked()), yellowState); //z tego stany na sygnal click idziemy do yellow
yellowState->addTransition(ui->pbToggle, SIGNAL(clicked()), logState);
//TODO: Add last transition
logState->addTransition(this, SIGNAL(done()), greenState);

connect(logState, SIGNAL(entered()), this, SLOT(log())); //podpiece/wywolanie tej funkcji log()
// TODO: Set initial state
stateMachine->setInitialState(greenState);

// TODO: Start state machine
stateMachine->start();
*/
