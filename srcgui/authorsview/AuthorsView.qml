import QtQuick 2.12
import QtQuick.Controls 2.12

import "../configuration"

Rectangle {
    id: authorsView
    color: ColorConstants.extraLightGrey

    Text {
        id: header
        text: "Multichain project authors:"
        font.pixelSize: 26
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
        topPadding: 80
    }

    Column {
        id: authorsColumn
        spacing: 18
        anchors.centerIn: parent

        Repeater {
            id: authorsRepeater
            model: ["Michał Słowiński", "Piotr Kuboń", "Jakub Półtoraczyk"]
            Text {
                text: modelData
                font.pixelSize: 20
            }
        }
    }
}
