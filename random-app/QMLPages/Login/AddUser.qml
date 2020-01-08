import QtQuick 2.0
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.0
import "../UIStyle"
import "../Util"

Page
{
    id: pageAddUserId
    property int textInputComponentWidth: pageAddUserId.width/2
    property int textInputComponentHeight: pageAddUserId.height/10
    anchors.fill: parent
    ColumnLayout
    {

        anchors.fill: parent
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottomMargin: 20

        TextInputBox
        {
            id: userName
            labelText: qsTr("Username")
            placeHolderText: qsTr("Please type your username")
            inputText: newUserViewModel.username
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            Layout.preferredHeight: textInputComponentHeight
            Layout.preferredWidth: textInputComponentWidth
            Layout.minimumHeight: UIStyle.buttonMinHeight
            Layout.minimumWidth: UIStyle.buttonMinWidth

            Binding
            {
                target: newUserViewModel
                property: "username"
                value: userName.inputText
            }
        }

        TextInputBox
        {
            id: firstName
            labelText: qsTr("First Name")
            placeHolderText: qsTr("Please type your first name")
            inputText: newUserViewModel.firstName
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            Layout.preferredHeight: textInputComponentHeight
            Layout.preferredWidth: textInputComponentWidth
            Layout.minimumHeight: UIStyle.buttonMinHeight
            Layout.minimumWidth: UIStyle.buttonMinWidth

            Binding
            {
                target: newUserViewModel
                property: "firstName"
                value: firstName.inputText
            }
        }

        TextInputBox {
            id: lastName
            labelText: qsTr("Last Name")
            placeHolderText: qsTr("Please type your last name")
            inputText: newUserViewModel.lastName
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            Layout.preferredHeight: textInputComponentHeight
            Layout.preferredWidth: textInputComponentWidth
            Layout.minimumHeight: UIStyle.buttonMinHeight
            Layout.minimumWidth: UIStyle.buttonMinWidth

            Binding
            {
                target: newUserViewModel
                property: "lastName"
                value: lastName.inputText
            }
        }

        TextInputBox
        {
            id: password
            labelText: qsTr("Password")
            placeHolderText: qsTr("Please type your password")
            inputText: newUserViewModel.password
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            Layout.preferredHeight: textInputComponentHeight
            Layout.preferredWidth: textInputComponentWidth
            Layout.minimumHeight: UIStyle.buttonMinHeight
            Layout.minimumWidth: UIStyle.buttonMinWidth

            Binding
            {
                target: newUserViewModel
                property: "password"
                value: password.inputText
            }
        }

        TextInputBox {
            id: passwordConfirm
            labelText: qsTr("Password confirmation")
            placeHolderText: qsTr("Please confirm your password")
            inputText: newUserViewModel.passwordConfirm
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            Layout.preferredHeight: textInputComponentHeight
            Layout.preferredWidth: textInputComponentWidth
            Layout.minimumHeight: UIStyle.buttonMinHeight
            Layout.minimumWidth: UIStyle.buttonMinWidth

            Binding
            {
                target: newUserViewModel
                property: "passwordConfirm"
                value: passwordConfirm.inputText
            }
        }

        ButtonGroup
        {
            buttons: userRole.children
            exclusive: false
        }

        RowLayout
        {
            id: userRole

            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            Layout.preferredHeight: textInputComponentHeight
            Layout.preferredWidth: textInputComponentWidth
            Layout.minimumHeight: UIStyle.buttonMinHeight
            Layout.minimumWidth: UIStyle.buttonMinWidth

            RadioButton
            {
                id: nurseRole
                text: qsTr("Nurse")
                checked: newUserViewModel.isNurseRole
                Binding
                {
                    target: newUserViewModel
                    property: "isNurseRole"
                    value: nurseRole.checked
                }

            }

            RadioButton
            {
                id: surgeonRole
                text: qsTr("Surgeon")
                checked: newUserViewModel.isSurgeonRole

                Binding
                {
                    target: newUserViewModel
                    property: "isSurgeonRole"
                    value: surgeonRole.checked
                }

            }

            RadioButton
            {
                id: techRole
                text: qsTr("Tech")
                checked: newUserViewModel.isTechRole
                Binding
                {
                    target: newUserViewModel
                    property: "isTechRole"
                    value: techRole.checked
                }
            }


            RadioButton
            {
                id: adminRole
                text: qsTr("Admin")
                checked: newUserViewModel.isAdminRole
                Binding
                {
                    target: newUserViewModel
                    property: "isAdminRole"
                    value: adminRole.checked
                }

            }

            RadioButton
            {
                id: testingRole
                text: qsTr("Testing")
                checked: newUserViewModel.isTestingRole
                Binding
                {
                    target: newUserViewModel
                    property: "isTestingRole"
                    value: testingRole.checked
                }

            }

            RadioButton
            {
                id: engineerRole
                text: qsTr("Engineer")
                checked: newUserViewModel.isEngineerRole
                Binding
                {
                    target: newUserViewModel
                    property: "isEngineerRole"
                    value: engineerRole.checked
                }
            }
        }

        Item
        {
            Layout.alignment: Qt.AlignBottom | Qt.AlignHCenter
            Layout.fillHeight: false
            Layout.fillWidth: false
            Layout.preferredHeight: parent.height / 10
            Layout.preferredWidth: parent.width / 1.5
            Layout.minimumHeight: UIStyle.buttonMinHeight
            Layout.minimumWidth: UIStyle.buttonMinWidth
            RowLayout
            {
                id: rowlayout

                anchors.fill: parent
                // note this will fill the rest area of the column layout
                spacing: 10
                Button
                {
                    id: goBackButton
                    Layout.fillHeight: false
                    Layout.fillWidth: false
                    Layout.preferredHeight: parent.height * 0.75
                    Layout.preferredWidth: parent.width / 4
                    Layout.minimumHeight: UIStyle.buttonMinHeight
                    Layout.minimumWidth: UIStyle.buttonMinWidth
                    text: qsTr("Go Back")
                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

                    onClicked:
                    {
                        newUserViewModel.resetValues()
                        masterControllerViewModel.goBack()
                    }
                }

                Button
                {
                    id: createUserButton
                    Layout.fillHeight: false
                    Layout.fillWidth: false
                    Layout.preferredHeight: parent.height * 0.75
                    Layout.preferredWidth: parent.width / 4
                    Layout.minimumHeight: UIStyle.buttonMinHeight
                    Layout.minimumWidth: UIStyle.buttonMinWidth
                    text: qsTr("Create User")
                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

                    onClicked:
                    {
                        newUserViewModel.createUser()
                        newUserViewModel.resetValues()
                    }
                    Keys.onReturnPressed:
                    {
                        newUserViewModel.createUser() // Enter key
                        newUserViewModel.resetValues()
                    }
                    Keys.onEnterPressed:
                    {
                        newUserViewModel.createUser() // Numpad enter key
                        newUserViewModel.resetValues()
                    }
                }
            }
        }
    }
    Connections
    {
        target: headerViewModel
        onLogOut:
        {
            newUserViewModel.resetValues()
        }
    }
}





/*##^## Designer {
    D{i:0;autoSize:true;height:768;width:1024}
}
 ##^##*/







