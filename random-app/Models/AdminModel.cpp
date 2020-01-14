#include "AdminModel.h"

AdminModel::AdminModel(DataBaseConnector &dataBaseConnector):
m_PageNavigator(PageNavigatorViewModel::GetInstance())
{
     //m_pDataBaseConnector = std::make_shared<DataBaseConnector>(&dataBaseConnector);
    m_pDataBaseConnector = &dataBaseConnector;
}

AdminModel::~AdminModel()
{
    delete m_pDataBaseConnector;
}

void AdminModel::AddUser()
{
    m_PageNavigator.SetCurrentPage(static_cast<int>(PageList::AddUser));
}

void AdminModel::RemoveUser()
{

}

void AdminModel::querUser(QSqlQuery &dBQery)
{

    std::string queryStatement =
        "SELECT users.firstName, users.lastName, GROUP_CONCAT(usersToRoles.role SEPARATOR ',') AS role FROM users LEFT JOIN  usersToRoles ON users.id = usersToRoles.id GROUP BY users.firstName, users.lastName;";
    std::cout << queryStatement << std::endl;
    if((*m_pDataBaseConnector).GetQueryObject()->open())
    {

         dBQery = QSqlQuery(*m_pDataBaseConnector->GetQueryObject());
         dBQery.exec(QString::fromStdString(queryStatement));
         std::cout << "Number of records: " <<dBQery.size() <<std::endl;
    }
    else
    {

        std::cout << "Database is not connected" << std::endl;
    }
    return;
}


