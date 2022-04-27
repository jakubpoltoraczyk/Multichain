import QtQuick 2.12
import QtQuick.Controls 2.12

import "../configuration"

Rectangle {
    id: listViewArea
    color: ColorConstants.extraLightGrey

    /** Emitted when file from list view has been just selected */
    signal listViewFileSelected(string fileName)

    /** Called when component has been just created */
    Component.onCompleted: {
        listViewFileSelected.connect(controller.onListViewFileSelected)
    }

    ComboBox {
        id: listViewComboBox
        anchors.centerIn: parent
        model: controller.listViewAreaFiles
    }

    Button {
        id: confirmButton
        width: 50
        height: 50
        x: 100 
        y: 100
        visible: true

        onReleased: {
            listViewFileSelected(listViewComboBox.currentText)
        }
    }
}
