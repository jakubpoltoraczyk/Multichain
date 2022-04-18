import QtQuick 2.12

import "../configuration"

Rectangle {
    id: dropFileRectangle
    state: DropFileAreaConstants.dragExitedState

    states: [
        State {
            name: DropFileAreaConstants.dragEnteredState
            PropertyChanges {
                target: dropFileRectangle
                color: ColorConstants.white
            }
            PropertyChanges {
                target: dropFileIconImage
                source: DropFileAreaConstants.dropFileIconFadedImageSource
            }
        },
        State {
            name: DropFileAreaConstants.dragExitedState
            PropertyChanges {
                target: dropFileRectangle
                color: ColorConstants.extraLightGrey
            }
            PropertyChanges {
                target: dropFileIconImage
                source: DropFileAreaConstants.dropFileIconImageSource
            }
        }
    ]

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
            dropFileRectangle.state = DropFileAreaConstants.dragExitedState
        }

        /** Called when drag entered drop area */
        onEntered: {
            dropFileRectangle.state = DropFileAreaConstants.dragEnteredState
        }

        /** Called when drag exited drop area */
        onExited: {
            dropFileRectangle.state = DropFileAreaConstants.dragExitedState
        }
    }

    Image {
        id: dropFileIconImage
        anchors.centerIn: parent
    }
}
