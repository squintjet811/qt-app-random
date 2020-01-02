#pragma once

#ifndef PAGENAVIGATORVIEWMODEL_H
#define PAGENAVIGATORVIEWMODEL_H

#include <QObject>
#include <QMap>

#include "../Models/PageList.h"

// This singleton class is responsible for the page navigation of the
// application. It is accessible to all other classes in the backend
// as well as components at the frontend (ideally the frontend should never
// call this class - we want the backend logic to control page navigation).

class PageNavigatorViewModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int currentPage READ GetCurrentPage WRITE SetCurrentPage NOTIFY currentPageChanged)
    Q_PROPERTY(int previousPage READ GetPreviousPage)
    Q_PROPERTY(int homePage READ GetHomePage)

public:
    static PageNavigatorViewModel & GetInstance()
    {
        static PageNavigatorViewModel instanceVM;
        static bool isRunningTheFirstTime = true;
        if (isRunningTheFirstTime)
        {
            isRunningTheFirstTime = false;
            InitializeData();
        }
        return instanceVM;
    } // instance

    PageNavigatorViewModel(const PageNavigatorViewModel &) = delete;
    PageNavigatorViewModel & operator = (const PageNavigatorViewModel &) = delete;

    void SetCurrentPage(int value);
    int GetCurrentPage() const;

    int GetPreviousPage() const;

    int GetHomePage() const;

    void GoBack();

    static QMap<int, QString> GetPageIndexMap();

public slots:
    void goBack()
    {
        GoBack();
    }

signals:
    void currentPageChanged();

private:
    PageNavigatorViewModel() {}
    ~PageNavigatorViewModel() {}
    static QMap<int, QString> m_PageListMap;

    static void InitializeData();

    int m_CurrentPageIndex = 0;
    int m_PreviousPageIndex = 0;
    int m_HomePageIndex = 0;
};

#endif //
