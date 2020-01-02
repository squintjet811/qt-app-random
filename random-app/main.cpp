#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQuick>
#include "ViewModels/PageNavigator.h"
#include "Models/PageList.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQuickView *view = new QQuickView;
    auto pagesMapping = PageNavigatorViewModel::GetInstance().GetPageIndexMap();


    QStringList dataList = pagesMapping.values();
    view->rootContext()->setContextProperty("pageNavigatorViewModel", &PageNavigatorViewModel::GetInstance());
    view->rootContext()->setContextProperty("listOfPages", QVariant::fromValue(dataList));
    view->setSource(QStringLiteral("qrc:/main.qml"));
    //view->show();

    return app.exec();
}
