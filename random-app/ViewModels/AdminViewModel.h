#pragma once
#ifndef ADMINVIEWMODEL_H
#define ADMINVIEWMODEL_H

#include <QObject>

#include "Models/AdminModel.h"

// Connects the Admin backend model (C++ files) to the frontend admin components (QML files).
// Contains functionality for the Admin class, e.g. adding and removing users.
// Will potentially include functionality to check logs and go to advanced settings

class AdminViewModel: public QObject
{
    Q_OBJECT

public:
    AdminViewModel(std::shared_ptr<AdminModel> adminModel);

public slots:
    void addUser()
    {
        m_pAdminModel->AddUser();
    }

    void removeUser()
    {
        m_pAdminModel->RemoveUser();
    }

private:
    std::shared_ptr<AdminModel> m_pAdminModel;
};

#endif // ADMINVIEWMODEL_H
