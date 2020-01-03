pragma Singleton
import QtQuick 2.4

QtObject {
    id: uiStyle
    readonly property int fontSizeSmall: 12
    readonly property int fontSizeLarge: 14
    readonly property int fontSizeXXL: 18

    readonly property int buttonMinWidth: 10
    readonly property int buttonMinHeight: 10

    readonly property int windowCommonWidth: 1024
    readonly property int windowCommonHeight: 768
}
