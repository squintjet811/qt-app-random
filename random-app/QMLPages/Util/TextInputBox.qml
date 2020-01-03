import QtQuick 2.0
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12
import "../UIStyle"

Item {
    id: textInputWithLabelId
    property alias labelText: labelId.text
    property alias placeHolderText: textFieldId.placeholderText
    property alias inputText: textFieldId.text
    property bool isPasswordField :false
    signal userInputChanged(string input)
    RowLayout
    {
        id: rowLayoutId
        spacing: 20
        anchors.fill: parent
        // left side for text part
        Rectangle
        {
            id: rectangleLabelHolder
            color: "transparent"
            Layout.fillHeight: true
            Layout.preferredWidth: Math.min(150, parent.width*0.25)
            Text
            {
                id: labelId
                anchors.centerIn: parent
                font.pixelSize: UIStyle.fontSizeLarge
            }
        }
        // right side for user text input
        TextField
        {
            id: textFieldId
            Layout.fillWidth: true
            font.pixelSize: UIStyle.fontSizeLarge
            echoMode: (isPasswordField === true )? TextInput.Password : TextInput.Normal
            onFocusChanged: textInputWithLabelId.userInputChanged(text)
        }
    }
}

















