import QtQuick 2.12

import "../configuration"

Rectangle {
    id: managementPanel
    color: ColorConstants.lightGrey

    /** Contains last released button */
    property int lastReleasedButton: ManagementPanelConstants.ButtonType.DropFileArea

    Component.onCompleted: {
        listViewButton.released.connect(controller.myCustomSlot)
    }

    Column {
        id: managementPanelRow
        spacing: ManagementPanelConstants.spacing
        anchors.centerIn: parent

        ManagementButton {
            id: dropFileButton
            pressedIconSource: ManagementPanelConstants.uploadFileFadedIconSource
            releasedIconSource: ManagementPanelConstants.uploadFileIconSource

            /** Called when button has been just released */
            onReleased: {
                lastReleasedButton = ManagementPanelConstants.ButtonType.DropFileArea
            }
        }

        ManagementButton {
            id: listViewButton
            pressedIconSource: ManagementPanelConstants.listViewFadedIconSource
            releasedIconSource: ManagementPanelConstants.listViewIconSource

            /** Called when button has been just released */
            onReleased: {
                lastReleasedButton = ManagementPanelConstants.ButtonType.ListViewArea
            }
        }

        ManagementButton {
            id: unknownButton2
            pressedIconSource: ManagementPanelConstants.unknownButtonFadedIconSource
            releasedIconSource: ManagementPanelConstants.uknownButtonIconSource

            /** Called when button has been just released */
            onReleased: {
                lastReleasedButton = ManagementPanelConstants.ButtonType.Unknown2
            }
        }

        ManagementButton {
            id: unknownButton3
            pressedIconSource: ManagementPanelConstants.unknownButtonFadedIconSource
            releasedIconSource: ManagementPanelConstants.uknownButtonIconSource

            /** Called when button has been just released */
            onReleased: {
                lastReleasedButton = ManagementPanelConstants.ButtonType.Unknown3
            }
        }
    }
}
