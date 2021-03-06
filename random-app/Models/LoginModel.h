#pragma once
#ifndef LOGINM_H
#define LOGINM_H

#include <string>
#include <memory>
#include <iostream>
#include "../ViewModels/PageNavigator.h"
#include "../Service/DataBaseConnector.h"
#include "PageList.h"

class LoginModel
{
public:
    LoginModel(DataBaseConnector &dataBaseConnector);
    ~LoginModel();
    void SetUsername(std::string username);
    std::string GetUsername() const;

    void SetPassword(std::string password);
    std::string GetPassword() const;

    void SetUserRole(std::string password);
    std::string GetUserRole() const;

    bool AuthenticateLogin();
    enum class AuthReturnValues
    {
        NoDataBaseConnectoin = -2,
        UserPasswordNotMatch = -1,
        LoginSuccess = 0
    };

private:
    std::string m_UserRole;
    std::string m_Username;
    std::string m_Password;
    PageNavigatorViewModel & m_PageNavigator;
    //std::shared_ptr<DataBaseConnector> m_pDataBaseConnector;
    DataBaseConnector *m_pDataBaseConnector;
};

#endif // LOGINM_H
