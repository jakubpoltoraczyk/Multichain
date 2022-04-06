import QtQuick 2.12

import "../configuration"

DropArea {
    id: dropFileArea
    anchors.fill: parent

    /** Signal emitted, when file has been just dropped */
    signal fileDropped(string filePath)

    /** Called when component has been just created */
    Component.onCompleted: {
        fileDropped.connect(dropFileAreaController.onFileDropped)
    }

    /** Called when drop event has occured in drop area */
    onDropped: {
        fileDropped(drop.urls)
    }
}
