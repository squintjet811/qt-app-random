import QtQuick 2.0
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.3
import "../Util"
import "../UIStyle"

Page
{
    anchors.fill: parent
    background:Image
    {
        source: "../Images/background_android.jpg"
        fillMode: Image.PreserveAspectCrop
        clip: true
    }
    Rectangle
    {
        anchors.top: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        height: parent.height * 0.3
        width: parent.width * 0.5
        color: "white"
        ColumnLayout
        {
            anchors.fill: parent
            spacing: 10
            TextInputBox
            {
                Layout.alignment: Qt.AlignCenter
                Layout.preferredWidth: parent.width * 0.8
                Layout.preferredHeight: parent.height * 0.25
                labelText: qsTr("Username")
                placeHolderText: qsTr("Please type your username")
                inputText: loginViewModel.username
                onUserInputChanged: {

                    loginViewModel.setUsername(input)
                    console.log(input)
                }
            }

            TextInputBox
            {
                id: passwordId
                Layout.alignment: Qt.AlignCenter
                Layout.preferredWidth: parent.width * 0.8
                Layout.preferredHeight: parent.height * 0.25
                labelText: qsTr("Password")
                isPasswordField: true
                placeHolderText: qsTr("Please type your password")
                inputText: loginViewModel.password
                // the input of this binding is when the backend got updated,
                // the frontend is updated as well
                // however it is not necessary if you directly bind the property to a
                // viewmodel in the backend, it was updated using signals

                Binding {
                    target: loginViewModel
                    property: "password"
                    value: passwordId.inputText
                }

            }

            Button{
                id: loginButton
                text: qsTr("Login")
                Layout.alignment: Qt.AlignCenter
                Layout.preferredHeight: Math.min(50, parent.height*0.25)
                Layout.preferredWidth: parent.width * 0.3
                onClicked: loginViewModel.authenticateLogin()
                Keys.onReturnPressed: loginViewModel.authenticateLogin() // Enter key
                Keys.onEnterPressed: loginViewModel.authenticateLogin() // Numpad enter key
            }

        }
    }
}
