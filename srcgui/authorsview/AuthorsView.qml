import QtQuick 2.12
import QtQuick.Controls 2.12

import "../configuration"

Rectangle {
    id: authorsView
    gradient: Gradient {
        orientation: Gradient.Horizontal
        GradientStop { position: 0.0; color: "#3ecae6" }
        GradientStop { position: 0.33; color: "#86e5f7" }
        GradientStop { position: 1.0; color: "#a6e8f5" }
    }

    Text {
        id: header
        text: "Multichain project authors"
        font.pixelSize: 26
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
        topPadding: 120
    }

    Column {
        id: authorsColumn
        spacing: 18
        anchors.top: header.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        topPadding: 20

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
