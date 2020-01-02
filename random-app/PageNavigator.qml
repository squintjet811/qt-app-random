import QtQuick 2.0
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.12

StackLayout{
    id: pageList
    anchors.fill: parent
    currentIndex: pageNavigatorViewModel.currentPage

    Repeater{
        model: listOfPages
        Loader{
            source: modelData  //See https://doc.qt.io/qt-5/qtquick-modelviewsdata-cppmodels.html#
        }
    }
}
