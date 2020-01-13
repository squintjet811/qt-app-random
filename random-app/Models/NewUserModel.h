#pragma once

#ifndef NEWUSERMODEL_H
#define NEWUSERMODEL_H

#include <memory>
#include <iostream>

#include "ViewModels/PageNavigator.h"
#include "Service/DataBaseConnector.h"

class NewUserModel
{
public:
    NewUserModel(DataBaseConnector &dataBaseConnector);
    ~NewUserModel();
    void SetUsername(std::string username);
    void SetFirstName(std::string firstName);
    void SetLastName(std::string lastName);
    void SetPassword(std::string password);
    void SetPasswordConfirm(std::string passwordConfirm);
    void SetUserRole(std::string userRole);

    std::string GetUsername() const;
    std::string GetFirstName() const;
    std::string GetLastName() const;
    std::string GetPassword() const;
    std::string GetPasswordConfirm() const;
    std::string GetUserRole() const;

    void CreateUser();

    void ResetValues();

private:
    PageNavigatorViewModel & m_PageNavigator;
    DataBaseConnector *m_pDataBaseConnector;


    std::string m_Username;
    std::string m_FirstName;
    std::string m_LastName;
    std::string m_Password;
    std::string m_PasswordConfirm;

    std::string m_UserRoleString;
    int m_UserRoleInt;
};

#endif //NEWUSERMODEL_H
