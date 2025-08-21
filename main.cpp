#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include <currencyconverterlogic.h>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("problem_4", "Main");

    CurrencyConverterLogic ccl;

    engine.rootContext()->setContextProperty("ccl", &ccl);

    return app.exec();
}
