#include "PageNavigator.h"
#include <iostream>

QMap<int, QString> PageNavigatorViewModel::m_PageListMap  = QMap<int, QString>();

void PageNavigatorViewModel::SetCurrentPage(int value)
{
    if (value!=m_CurrentPageIndex)
    {
        m_PreviousPageIndex = m_CurrentPageIndex;
        m_CurrentPageIndex = value;
        emit currentPageChanged();
    }
}

int PageNavigatorViewModel::GetCurrentPage() const
{
    return  m_CurrentPageIndex;
}

int PageNavigatorViewModel::GetPreviousPage() const
{
    return  m_PreviousPageIndex;
}

int PageNavigatorViewModel::GetHomePage() const
{
    return m_HomePageIndex;
}

void PageNavigatorViewModel::GoBack()
{
    SetCurrentPage(GetPreviousPage());
}

QMap<int, QString> PageNavigatorViewModel::GetPageIndexMap()
{
    return m_PageListMap;
}

void PageNavigatorViewModel::InitializeData()
{
    QMap<int, QString> dataList;

    dataList.insert(static_cast<int>(PageList::LoginPage), QStringLiteral("qrc:/QMLPages/Login/Login.qml"));

    m_PageListMap = dataList;
}
