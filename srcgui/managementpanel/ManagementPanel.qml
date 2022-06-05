import QtQuick 2.12

import "../configuration"

Rectangle {
    id: managementPanel
    gradient: Gradient {
        orientation: Gradient.Horizontal
        GradientStop { position: 0.0; color: "#a6e8f5" }
        GradientStop { position: 0.33; color: "#bceef7" }
        GradientStop { position: 1.0; color: "#d1f8ff" }
    }

    /** Contains last released button */
    property int lastReleasedButton: ManagementPanelConstants.ButtonType.DropFileArea

    /** Called when component has been just created */
    Component.onCompleted: {
        listViewButton.released.connect(controller.onListViewButtonReleased)
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
            id: authorsButton
            pressedIconSource: ManagementPanelConstants.authorsFadedIconSource
            releasedIconSource: ManagementPanelConstants.authorsIconSource

            /** Called when button has been just released */
            onReleased: {
                lastReleasedButton = ManagementPanelConstants.ButtonType.Authors
            }
        }
    }
}
