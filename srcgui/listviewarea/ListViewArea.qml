import QtQuick 2.12
import QtQuick.Controls 2.12

import "../configuration"

Rectangle {
    id: listViewArea
    color: ColorConstants.extraLightGrey

    signal confirmButtonReleased(string customText)

    Component.onCompleted: {
        confirmButtonReleased.connect(controller.onConfirmButtonReleased)
    }

    Connections {
        target: controller

        onSendToComboBox: {
            console.log(exampleVector[0])
        }
    }

    ComboBox {
        id: listViewComboBox
        anchors.centerIn: parent
        model: ["First", "Second", "Third"]
    }

    Button {
        id: confirmButtom
        width: 50
        height: 50
        x: 100 
        y: 100
        visible: true

        onReleased: {
            confirmButtonReleased(listViewComboBox.currentText)
        }
    }
}
