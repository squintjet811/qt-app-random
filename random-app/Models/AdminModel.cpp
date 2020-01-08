#include "AdminModel.h"

AdminModel::AdminModel(DataBaseConnector &dataBaseConnector):
m_PageNavigator(PageNavigatorViewModel::GetInstance())
{
     //m_pDataBaseConnector = std::make_shared<DataBaseConnector>(&dataBaseConnector);
    m_pDataBaseConnector = &dataBaseConnector;
}

void AdminModel::AddUser()
{
    m_PageNavigator.SetCurrentPage(static_cast<int>(PageList::AddUser));
}

void AdminModel::RemoveUser()
{

}

AdminModel::~AdminModel()
{
    delete m_pDataBaseConnector;
}
