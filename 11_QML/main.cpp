#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "acceleration.h"
#include "speed.h"
#include "Displacement.h"
int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    qmlRegisterType<Acceleration>("pl.hello", 1, 0, "Acceleration");
    qmlRegisterType<Displacement>("pl.hello", 1, 0, "Displacement");
    qmlRegisterType<Speed>("pl.hello", 1, 0, "Speed");
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;
    return app.exec();
}
