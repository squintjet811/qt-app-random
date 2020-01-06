#include "DataBaseConnector.h"

DataBaseConnector::DataBaseConnector()
{

    m_DB = std::unique_ptr<QSqlDatabase>(new QSqlDatabase(QSqlDatabase::addDatabase("QMYSQL", "qt5")));
    m_DB->setUserName("root");
    m_DB->setPassword("19921023");
    m_DB->setDatabaseName("qt5");
};

const std::unique_ptr<QSqlDatabase>& DataBaseConnector::GetQueryObject()
{
    return m_DB;
}

void DataBaseConnector::Open()
{
    bool isConnected = m_DB->open();
    if(isConnected){
        qInfo() << "Connection success" ;
        //m_DBQuery = std::unique_ptr<QSqlQuery>(new QSqlQuery(*m_DB));
        //qInfo() << "Set up Query object";
    }
    else{
        qInfo() << "Connection failed";
    }

};

void DataBaseConnector::Close()
{
    m_DB->close();
}

 DataBaseConnector::~DataBaseConnector()
 {
    qInfo() << "Destroy";
    qInfo() << "Connection lost due to closing of the program" ;
    m_DB->close();
 };


