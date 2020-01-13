#pragma once
#ifndef ADMINVIEWMODEL_H
#define ADMINVIEWMODEL_H

#include <QObject>
#include <QSqlQuery>
#include "Models/AdminModel.h"
#include <QDebug>

// Connects the Admin backend model (C++ files) to the frontend admin components (QML files).
// Contains functionality for the Admin class, e.g. adding and removing users.
// Will potentially include functionality to check logs and go to advanced settings

class AdminViewModel: public QAbstractListModel
{
    Q_OBJECT

public:
    int rowCount(const QModelIndex &parent) const;
    AdminViewModel(std::shared_ptr<AdminModel> adminModel, QObject *parent = nullptr);
    ~AdminViewModel();
    QHash<int, QByteArray> roleNames() const;
    QVariant data(const QModelIndex &index, int role) const;

    void updateQuery();

    enum class RoleNames
    {
            firstName = Qt::UserRole + 1,
            lastName = Qt::UserRole +2,
            role = Qt::UserRole + 3,
     };

public slots:
    void addUser()
    {
        std::cout << "add user called" << std::endl;
        m_pAdminModel->AddUser();
    }

    void removeUser()
    {
        m_pAdminModel->RemoveUser();
    }



private:
     std::shared_ptr<AdminModel> m_pAdminModel;
     QHash<int, QByteArray> m_roleNames;
     QSqlQuery *m_dBQuery;
     int m_count;
};

#endif // ADMINVIEWMODEL_H
