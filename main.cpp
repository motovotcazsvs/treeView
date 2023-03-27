#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "treeviewmodel.h"
//#include <QtQml>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);


    TreeViewModel treemodel;

    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("treemodel", &treemodel);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    //treemodel.test();
    return app.exec();
}
