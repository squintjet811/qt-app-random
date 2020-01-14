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

void NewUserModel::SetAdminRole(bool isChecked){
    //std::cout << "Set admin : " << isChecked << std::endl;
    m_IsRole[static_cast<int>(m_Roles::Admin)] = isChecked;
}

void NewUserModel::SetNurseRole(bool isChecked){
    m_IsRole[static_cast<int>(m_Roles::Nurse)] = isChecked;
}

void NewUserModel::SetSurgeonRole(bool isChecked){
    m_IsRole[static_cast<int>(m_Roles::Surgeon)] = isChecked;
}

void NewUserModel::SetTechRole(bool isChecked){
    m_IsRole[static_cast<int>(m_Roles::Tech)] = isChecked;
}

bool NewUserModel::GetAdminRole() const
{
    //std::cout << "Get admin : " << m_IsRole[Admin] <<  std::endl;
    return m_IsRole[static_cast<int>(m_Roles::Admin)];
}

bool NewUserModel::GetNurseRole() const
{
    return m_IsRole[static_cast<int>(m_Roles::Nurse)];
}

bool NewUserModel::GetTechRole() const
{
    return m_IsRole[static_cast<int>(m_Roles::Tech)];

}
bool NewUserModel::GetSurgeonRole() const
{
    return m_IsRole[static_cast<int>(m_Roles::Surgeon)];
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
