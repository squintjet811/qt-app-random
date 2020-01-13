#include "AdminViewModel.h"

AdminViewModel::AdminViewModel(std::shared_ptr<AdminModel> adminModel, QObject *parent):
     QAbstractListModel(parent), m_pAdminModel(adminModel)
{
    m_roleNames[static_cast<int>(RoleNames::firstName)] = "firstName";
    m_roleNames[static_cast<int>(RoleNames::lastName)] = "lastName";
    m_roleNames[static_cast<int>(RoleNames::role)] = "role";
    m_count = 0;
    m_dBQuery = new QSqlQuery();
}

AdminViewModel::~AdminViewModel()
{
    delete m_dBQuery;
}


QHash<int, QByteArray> AdminViewModel::roleNames() const
{
    return m_roleNames;
}



int AdminViewModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    m_pAdminModel->querUser(*m_dBQuery);
    std::cout << "Number of records: " <<m_dBQuery->record().count() <<std::endl;
    return m_dBQuery->size();


}

void AdminViewModel::updateQuery()
{
    m_pAdminModel->querUser(*m_dBQuery);
}
QVariant AdminViewModel::data(const QModelIndex &index, int role) const
{
    int row = index.row();
    std::cout << "triggered" << role << std::endl;
    if(row < 0 || row >= m_dBQuery->size())
    {
        return QVariant();
    }


    m_dBQuery->seek(row);

    QSqlRecord dBRecord = m_dBQuery->record();

    switch(role)
    {
        case static_cast<int>(RoleNames::firstName):

            return dBRecord.value(dBRecord.indexOf(m_roleNames[static_cast<int>(RoleNames::firstName)]));

        case static_cast<int>(RoleNames::lastName):
            return dBRecord.value(dBRecord.indexOf(m_roleNames[static_cast<int>(RoleNames::lastName)]));

        case static_cast<int>(RoleNames::role):
            return dBRecord.value(dBRecord.indexOf(m_roleNames[static_cast<int>(RoleNames::role)]));

        default:
            return QVariant();

    }

}
