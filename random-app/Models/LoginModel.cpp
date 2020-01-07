#include "LoginModel.h"
#include <string>

LoginModel::LoginModel(DataBaseConnector &dataBaseConnector):
    m_PageNavigator(PageNavigatorViewModel::GetInstance())
{
   m_pDataBaseConnector = &dataBaseConnector;
   m_UserRole = "";
   m_Username = "";
   m_Password = "";
}

void LoginModel::SetUsername(std::string username)
{
    m_Username = username;

}

std::string LoginModel::GetUsername() const
{
    std::cout << "calling get function" << std::endl;
    return m_Username;
}

void LoginModel::SetPassword(std::string password)
{
    m_Password = password;
}

std::string LoginModel::GetPassword() const
{
    return m_Password;
}

void LoginModel::SetUserRole(std::string userRole)
{
    m_UserRole = userRole;

}

std::string LoginModel::GetUserRole() const
{
    return m_UserRole;
}

bool LoginModel::AuthenticateLogin()
{
    bool isLoginOk = false;
    std::string queryStatement = "SELECT Role From UserTable Where Username=" + m_Username + "And" + m_Password;
    if((*m_pDataBaseConnector).GetQueryObject()->open())
    {
         QSqlQuery dBQuery(*m_pDataBaseConnector->GetQueryObject());
         dBQuery.prepare(QString::fromStdString(queryStatement));
         dBQuery.exec();
         int count = 0;
         while(dBQuery.next())
         {
             count++;
         }
         if(count != 0)
         {
             isLoginOk = true;
         }

    }
    return isLoginOk;




}
