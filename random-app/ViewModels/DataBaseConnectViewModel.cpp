#include "DataBaseConnectViewModel.h"

DataBaseConnectViewModel::DataBaseConnectViewModel()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL", "qt5");
    db.setHostName("127.0.0.1");
    db.setUserName("root");
    db.setPassword("");
    db.setDatabaseName("qt5");
    bool isConnected = db.open();
    if(isConnected){
        qInfo() << "Connection success" ;
    }
    else{
        qInfo() << "Connection failed";
    }
}


