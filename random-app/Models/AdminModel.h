#pragma once

#ifndef ADMINMODEL_H
#define ADMINMODEL_H

#include "ViewModels/PageNavigator.h"
#include "../Service/DataBaseConnector.h"
#include <iostream>
#include <memory>
#include <vector>
#include "PageList.h"

class AdminModel
{
public:
    AdminModel(DataBaseConnector &dataBaseConnector);
    ~AdminModel();
    void AddUser();
    void RemoveUser();
    void querUser(QSqlQuery &dBQery);

private:
    PageNavigatorViewModel & m_PageNavigator;
    DataBaseConnector *m_pDataBaseConnector;


    //std::shared_ptr<DataBaseConnector> m_pDataBaseConnector;

};

#endif //ADMINMODEL_H
