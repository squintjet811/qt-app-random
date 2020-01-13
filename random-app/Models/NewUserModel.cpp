#include "NewUserModel.h"

NewUserModel::NewUserModel(DataBaseConnector &dataBaseConnector):
    m_PageNavigator(PageNavigatorViewModel::GetInstance())
{
    m_pDataBaseConnector = &dataBaseConnector;
}

NewUserModel::~NewUserModel()
{
    delete m_pDataBaseConnector;
}

void NewUserModel::SetUsername(std::string username)
{
    m_Username = username;

}

void NewUserModel::SetFirstName(std::string firstName)
{
    m_FirstName = firstName;

}

void NewUserModel::SetLastName(std::string lastName)
{
    m_LastName = lastName;

}

void NewUserModel::SetPassword(std::string password)
{
    m_Password = password;
}

void NewUserModel::SetPasswordConfirm(std::string passwordConfirm)
{
    m_PasswordConfirm = passwordConfirm;
}

void NewUserModel::SetUserRole(std::string userRole)
{
    m_UserRoleString = userRole;
    //m_UserRoleInt = UserRoles::UserRoleStringtoIntMap[userRole];

}

std::string NewUserModel::GetUsername() const
{
    return m_Username;
}

std::string NewUserModel::GetFirstName() const
{
    return m_FirstName;
}

std::string NewUserModel::GetLastName() const
{
    return m_LastName;
}

std::string NewUserModel::GetPassword() const
{
    return m_Password;
}

std::string NewUserModel::GetPasswordConfirm() const
{
    return m_PasswordConfirm;
}

std::string NewUserModel::GetUserRole() const
{
    return m_UserRoleString;
}

void NewUserModel::CreateUser()
{
    return;
}

void NewUserModel::ResetValues()
{
    m_Username = "";
    m_FirstName = "";
    m_LastName = "";
    m_Password = "";
    m_PasswordConfirm = "";
    m_UserRoleInt = 0;
    m_UserRoleString = "";

}
