#include "LoginViewModel.h"

LoginViewModel::LoginViewModel(std::shared_ptr<LoginModel> loginModel)
{
    m_pLoginModel = loginModel;
}

QString LoginViewModel::GetUsername() const
{
    return QString::fromStdString(m_pLoginModel->GetUsername());
}

QString LoginViewModel::GetPassword() const
{
    return QString::fromStdString(m_pLoginModel->GetPassword());
}

QString LoginViewModel::GetUserRole() const
{
    return QString::fromStdString(m_pLoginModel->GetUserRole());
}

void LoginViewModel::SetUsername(QString username)
{
    auto usernameInModel = m_pLoginModel->GetUsername();
    if (usernameInModel.compare(username.toStdString()) )
    {
        m_pLoginModel->SetUsername(username.toStdString());
        emit usernameChanged();
    }
}

void LoginViewModel::SetPassword(QString password)
{
    auto passwordInModel = m_pLoginModel->GetPassword();
    if (passwordInModel.compare(password.toStdString()) )
    {
        m_pLoginModel->SetPassword(password.toStdString());
        emit passwordChanged();
    }
}
