#pragma once

#ifndef NEWUSERVIEWMODEL_H
#define NEWUSERVIEWMODEL_H

#include <QObject>

#include "Models/NewUserModel.h"

// Connects the NewUser backend model (C++ files) to the frontend NewUser pages such as
// AddUser.qml.
// Contains functionality for the NewUser class, e.g. registering a new user into the
// application (saving user role, login info, etc.)

class NewUserViewModel: public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString username READ GetUsername WRITE SetUsername NOTIFY usernameChanged)
    Q_PROPERTY(QString firstName READ GetFirstName WRITE SetFirstName NOTIFY firstNameChanged)
    Q_PROPERTY(QString lastName READ GetLastName WRITE SetLastName NOTIFY lastNameChanged)

    Q_PROPERTY(QString password READ GetPassword WRITE SetPassword NOTIFY passwordChanged)
    Q_PROPERTY(QString passwordConfirm READ GetPasswordConfirm WRITE SetPasswordConfirm NOTIFY passwordConfirmChanged)

    Q_PROPERTY(QString userRole READ GetUserRole WRITE SetUserRole NOTIFY userRoleChanged)

public:
    NewUserViewModel(std::shared_ptr<NewUserModel> newUserModel);

    void SetUsername(QString username);
    void SetFirstName(QString firstName);
    void SetLastName(QString lastName);
    void SetPassword(QString password);
    void SetPasswordConfirm(QString passwordConfirm);
    void SetUserRole(QString userRole);

    QString GetUsername() const;
    QString GetFirstName() const;
    QString GetLastName() const;
    QString GetPassword() const;
    QString GetPasswordConfirm() const;
    QString GetUserRole() const;

    void ResetValues();

public slots:
    void setUsername(QString username)
    {
        SetUsername(username);
    }

    void setFirstName(QString firstName)
    {
        SetFirstName(firstName);
    }

    void setLastName(QString lastName)
    {
        SetLastName(lastName);
    }

    void setPassword(QString password)
    {
        SetPassword(password);
    }

    void setPasswordConfirm(QString passwordConfirm)
    {
        SetPasswordConfirm(passwordConfirm);
    }

    void setUserRole(QString userRole)
    {
        SetUserRole(userRole);
    }

    void createUser()
    {
        m_pNewUserModel->CreateUser();
    }

    void resetValues()
    {
        ResetValues();
    }

signals:
    void usernameChanged();
    void firstNameChanged();
    void lastNameChanged();
    void passwordChanged();
    void passwordConfirmChanged();
    void userRoleChanged();

private:
    std::shared_ptr<NewUserModel> m_pNewUserModel;
};

#endif // NEWUSERVIEWMODEL_H
