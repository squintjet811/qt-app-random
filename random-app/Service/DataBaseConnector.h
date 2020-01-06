#ifndef DATABASECONNECTOR_H
#define DATABASECONNECTOR_H
#include <QObject>
#include <QtSql>
#include <QSqlDatabase>
#include <QDebug>

class DataBaseConnector
{
public:
    DataBaseConnector();
    ~DataBaseConnector();
    void Open();
    void Close();
    bool QueryPrepare(std::string);
    bool QueryExecute();
    const std::unique_ptr<QSqlDatabase>& GetQueryObject();

private:
    std::unique_ptr<QSqlDatabase>m_DB;
    //std::unique_ptr<QSqlQuery> m_DBQuery;
};

#endif // DATABASECONNECTOR_H
