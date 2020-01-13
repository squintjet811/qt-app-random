import QtQuick 2.0
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.3
import QtQuick.Controls 1.4 as OldControls
import "../UIStyle"
ApplicationWindow{
    height: 800
    width: 600
    property int buttonComponentWidth : grid.width / 2.5
    property int buttonComponentHeight: grid.height / 3
    visible: true
    Page
    {
        visible: true
        id: root

        height: parent.height
        width: parent.width

        Rectangle
        {
            color: "Transparent"
            border.color: "Black"
            anchors.fill: userList
        }


        OldControls.TableView
    {
            id: userList
            anchors.top: parent.top
            anchors.horizontalCenter: parent.horizontalCenter
            height: parent.height / 4
            width: parent.width - 50
            anchors.margins: 5
            model: adminViewModel
            OldControls.TableViewColumn{
                role: "firstName"
                title: "First Name"
                visible: true
            }
            OldControls.TableViewColumn{
                role: "lastName"
                title: "Last Name"
                 visible: true
            }
            OldControls.TableViewColumn{
                role: "role"
                title: "Role"
                visible: true
            }

        }

        GridLayout{
            id: grid
            anchors.top: userList.bottom
            anchors.bottom: parent.bottom
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.leftMargin: parent.width / 10
            anchors.rightMargin: parent.width / 10
            rows: 2
            columns: 2

            Button
            {
                background: Rectangle
                {
                    radius: 10
                    border.color: "black"
                    border.width: 1
                }

                Layout.column: 0
                Layout.row:0
                Layout.alignment: Qt.AlignLeft
                Layout.preferredHeight: buttonComponentHeight
                Layout.preferredWidth: buttonComponentWidth
                Layout.minimumHeight: UIStyle.buttonMinHeight
                Layout.minimumWidth: UIStyle.buttonMinWidth
                text:"Add User"
                onClicked:adminViewModel.addUser()
            }

            Button
            {
                background: Rectangle
                {
                    radius: 10
                    border.color: "black"
                    border.width: 1
                }
                Layout.column: 1
                Layout.row: 0
                Layout.alignment: Qt.AlignRight
                Layout.preferredHeight: buttonComponentHeight
                Layout.preferredWidth: buttonComponentWidth
                Layout.minimumHeight: UIStyle.buttonMinHeight
                Layout.minimumWidth: UIStyle.buttonMinWidth
                text:"Remove User"
                onClicked:adminViewModel.removeUser()
            }

            Button
            {
                background: Rectangle
                {
                    radius: 10
                    border.color: "black"
                    border.width: 1
                }
                Layout.column: 0
                Layout.row: 1
                Layout.alignment: Qt.AlignLeft
                Layout.preferredHeight: buttonComponentHeight
                Layout.preferredWidth: buttonComponentWidth
                Layout.minimumHeight: UIStyle.buttonMinHeight
                Layout.minimumWidth: UIStyle.buttonMinWidth
                text:"Log"
                onClicked: {//should call adminViewModel.checkLogs()
                }
            }

            Button
            {
                background: Rectangle
                {
                    radius: 10
                    border.color: "black"
                    border.width: 1
                }
                Layout.column: 1
                Layout.row: 1
                Layout.alignment: Qt.AlignRight
                Layout.preferredHeight: buttonComponentHeight
                Layout.preferredWidth: buttonComponentWidth
                Layout.minimumHeight: UIStyle.buttonMinHeight
                Layout.minimumWidth: UIStyle.buttonMinWidth
                text:"Maintenance"
                onClicked: {//should call adminViewModel.doMaintenance()
                }
            }

        }
    }
}
