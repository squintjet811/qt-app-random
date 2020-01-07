#ifndef LOGINVIEWMODEL_H
#define LOGINVIEWMODEL_H

#include <string>
#include <memory>

#include "Models/LoginModel.h"

// Connects the Login backend model (C++ files) to the frontend login components (QML files).
// Contains functionality for the Login class, e.g. storing login info and letting other classes
// (eg. the Header) retrieve it, validating login, etc.

class LoginViewModel: public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString username READ GetUsername WRITE SetUsername NOTIFY usernameChanged)
    Q_PROPERTY(QString password READ GetPassword WRITE SetPassword NOTIFY passwordChanged)

public:

    LoginViewModel(std::shared_ptr<LoginModel> loginModel);
    void SetUsername(QString username);
    void SetPassword(QString password);

    QString GetUsername() const;
    QString GetPassword() const;
    QString GetUserRole() const;

public slots:
    void setUsername(QString username)
    {
        SetUsername(username);
    }

    void setPassword(QString password)
    {
        SetPassword(password);
    }

    void authenticateLogin()
    {
        bool loginAttempt =  m_pLoginModel->AuthenticateLogin();
        if (loginAttempt)
        {
            emit loginSuccess();
        }
    }

signals:
    void usernameChanged();
    void passwordChanged();
    void loginSuccess();

private:
    std::shared_ptr<LoginModel> m_pLoginModel;
};

#endif // LOGINVIEWMODEL_H
