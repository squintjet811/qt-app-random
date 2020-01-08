#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQuick>
#include "ViewModels/PageNavigator.h"
#include "ViewModels/LoginViewModel.h"
#include "ViewModels/AdminViewModel.h"

#include "Models/PageList.h"
#include "Service/DataBaseConnector.h"


int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQuickView *view = new QQuickView;


    //std::shared_ptr<DataBaseConnector> dataBaseConnector; //DataBase Connector
    DataBaseConnector dataBaseConnector;
    dataBaseConnector.Open();

    static std::shared_ptr<LoginModel> loginModel = std::make_shared<LoginModel>(dataBaseConnector);
    LoginViewModel loginViewModel(loginModel);

    static std::shared_ptr<AdminModel> adminModel = std::make_shared<AdminModel>(dataBaseConnector);
    AdminViewModel adminViewModel(adminModel);

    auto pagesMapping = PageNavigatorViewModel::GetInstance().GetPageIndexMap();


    QStringList dataList = pagesMapping.values();
    view->rootContext()->setContextProperty("pageNavigatorViewModel", &PageNavigatorViewModel::GetInstance());
    view->rootContext()->setContextProperty("listOfPages", QVariant::fromValue(dataList));
    view->rootContext()->setContextProperty("loginViewModel", &loginViewModel);
    view->rootContext()->setContextProperty("adminViewModel", &adminViewModel);
    view->setSource(QStringLiteral("qrc:/main.qml"));
    //view->show();

    return app.exec();
}
