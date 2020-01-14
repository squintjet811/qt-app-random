#pragma once

#ifndef NEWUSERVIEWMODEL_H
#define NEWUSERVIEWMODEL_H

#include <QObject>

#include "Models/NewUserModel.h"


class NewUserViewModel: public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString username READ GetUsername WRITE SetUsername NOTIFY usernameChanged)
    Q_PROPERTY(QString firstName READ GetFirstName WRITE SetFirstName NOTIFY firstNameChanged)
    Q_PROPERTY(QString lastName READ GetLastName WRITE SetLastName NOTIFY lastNameChanged)

    Q_PROPERTY(QString password READ GetPassword WRITE SetPassword NOTIFY passwordChanged)
    Q_PROPERTY(QString passwordConfirm READ GetPasswordConfirm WRITE SetPasswordConfirm NOTIFY passwordConfirmChanged)
    // property for role selection
    Q_PROPERTY(bool isAdminRole READ GetAdminRole WRITE SetAdminRole NOTIFY AdminRoleChanged)
    Q_PROPERTY(bool isNurseRole READ GetNurseRole WRITE SetNurseRole NOTIFY NurseRoleChanged)
    Q_PROPERTY(bool isTechRole READ GetTechRole WRITE SetTechRole NOTIFY TechRoleChanged)
    Q_PROPERTY(bool isSurgeonRole READ GetSurgeonRole WRITE SetSurgeonRole NOTIFY SurgeonRoleChanged)

    Q_PROPERTY(QString userRole READ GetUserRole WRITE SetUserRole NOTIFY userRoleChanged)

public:
    NewUserViewModel(std::shared_ptr<NewUserModel> newUserModel);

    void SetUsername(QString username);
    void SetFirstName(QString firstName);
    void SetLastName(QString lastName);
    void SetPassword(QString password);
    void SetPasswordConfirm(QString passwordConfirm);
    void SetUserRole(QString userRole);

    void SetAdminRole(bool isButtonChecked);
    void SetNurseRole(bool isButtonChecked);
    void SetTechRole(bool isButtonChecked);
    void SetSurgeonRole(bool isButtonChecked);

    bool GetAdminRole() const;
    bool GetTechRole() const;
    bool GetSurgeonRole() const;
    bool GetNurseRole() const;

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
    void AdminRoleChanged();
    void NurseRoleChanged();
    void TechRoleChanged();
    void SurgeonRoleChanged();



private:
    std::shared_ptr<NewUserModel> m_pNewUserModel;
};

#endif // NEWUSERVIEWMODEL_H
