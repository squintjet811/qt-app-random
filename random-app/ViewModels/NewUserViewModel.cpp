#include "NewUserViewModel.h"

NewUserViewModel::NewUserViewModel(std::shared_ptr<NewUserModel> newUserModel):
m_pNewUserModel(newUserModel)
{
}

void NewUserViewModel::SetUsername(QString username)
{
    auto usernameInModel = m_pNewUserModel->GetUsername();
    if (usernameInModel.compare(username.toStdString()) )
    {
        m_pNewUserModel->SetUsername(username.toStdString());
        emit usernameChanged();
    }
}

void NewUserViewModel::SetFirstName(QString firstName)
{
    auto firstNameInModel = m_pNewUserModel->GetFirstName();
    if (firstNameInModel.compare(firstName.toStdString()) )
    {
        m_pNewUserModel->SetFirstName(firstName.toStdString());
        emit firstNameChanged();
    }
}

void NewUserViewModel::SetLastName(QString lastName)
{
    auto lastNameInModel = m_pNewUserModel->GetLastName();
    if (lastNameInModel.compare(lastName.toStdString()) )
    {
        m_pNewUserModel->SetLastName(lastName.toStdString());
        emit lastNameChanged();
    }
}

void NewUserViewModel::SetPassword(QString password)
{
    auto passwordInModel = m_pNewUserModel->GetPassword();
    if (passwordInModel.compare(password.toStdString()) )
    {
        m_pNewUserModel->SetPassword(password.toStdString());
        emit passwordChanged();
    }
}

void NewUserViewModel::SetPasswordConfirm(QString passwordConfirm)
{
    auto passwordConfirmInModel = m_pNewUserModel->GetPasswordConfirm();
    if (passwordConfirmInModel.compare(passwordConfirm.toStdString()) )
    {
        m_pNewUserModel->SetPasswordConfirm(passwordConfirm.toStdString());
        emit passwordConfirmChanged();
    }
}

void NewUserViewModel::SetUserRole(QString userRole)
{
    auto userRoleInModel = m_pNewUserModel->GetUserRole();
    if (userRoleInModel.compare(userRole.toStdString()) )
    {
        m_pNewUserModel->SetUserRole(userRole.toStdString());
        emit userRoleChanged();
    }
}

void NewUserViewModel::SetAdminRole(bool isChecked)
{
    auto curRoleInModel = m_pNewUserModel->GetAdminRole();
    //std::cout << "Admin is not reading" << isChecked << " , "<<curRoleInModel << std::endl;
    if (curRoleInModel != isChecked)
    {
        m_pNewUserModel->SetAdminRole(isChecked);
        emit AdminRoleChanged();
    }
}

void NewUserViewModel::SetNurseRole(bool isChecked)
{
    auto curRoleInModel = m_pNewUserModel->GetNurseRole();
    if (curRoleInModel != isChecked)
    {
        m_pNewUserModel->SetNurseRole(isChecked);
        emit NurseRoleChanged();
    }
}

void NewUserViewModel::SetTechRole(bool isChecked)
{
    auto curRoleInModel = m_pNewUserModel->GetTechRole();
    if (curRoleInModel != isChecked)
    {
        m_pNewUserModel->SetTechRole(isChecked);
        emit TechRoleChanged();
    }
}

void NewUserViewModel::SetSurgeonRole(bool isChecked)
{
    auto curRoleInModel = m_pNewUserModel->GetSurgeonRole();
    if (curRoleInModel != isChecked)
    {
        m_pNewUserModel->SetSurgeonRole(isChecked);
        emit SurgeonRoleChanged();
    }
}

bool NewUserViewModel::GetAdminRole() const
{
    return m_pNewUserModel->GetAdminRole();
}

bool NewUserViewModel::GetNurseRole() const
{
    return m_pNewUserModel->GetNurseRole();
}

bool NewUserViewModel::GetTechRole() const
{
    return m_pNewUserModel->GetTechRole();
}

bool NewUserViewModel::GetSurgeonRole() const
{
    return m_pNewUserModel->GetSurgeonRole();
}





QString NewUserViewModel::GetUsername() const
{
    return QString::fromStdString(m_pNewUserModel->GetUsername());
}

QString NewUserViewModel::GetFirstName() const
{
    return QString::fromStdString(m_pNewUserModel->GetFirstName());
}

QString NewUserViewModel::GetLastName() const
{
    return QString::fromStdString(m_pNewUserModel->GetLastName());
}

QString NewUserViewModel::GetPassword() const
{
    return QString::fromStdString(m_pNewUserModel->GetPassword());
}

QString NewUserViewModel::GetPasswordConfirm() const
{
    return QString::fromStdString(m_pNewUserModel->GetPasswordConfirm());
}

QString NewUserViewModel::GetUserRole() const
{
    return QString::fromStdString(m_pNewUserModel->GetUserRole());
}

void NewUserViewModel::ResetValues()
{
    m_pNewUserModel->ResetValues();

    emit usernameChanged();
    emit firstNameChanged();
    emit lastNameChanged();
    emit passwordChanged();
    emit passwordConfirmChanged();
    emit userRoleChanged();
}
