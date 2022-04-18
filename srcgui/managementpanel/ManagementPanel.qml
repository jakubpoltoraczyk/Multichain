import QtQuick 2.12

import "../configuration"

Rectangle {
    id: managementPanel
    color: ColorConstants.lightGrey

    Column {
        id: managementPanelRow
        spacing: ManagementPanelConstants.spacing
        anchors.centerIn: parent


        ManagementButton {
            id: listViewButton
            pressedIconSource: ManagementPanelConstants.listViewFadedIconSource
            releasedIconSource: ManagementPanelConstants.listViewIconSource
        }

        ManagementButton {
            id: unknownButton1
            pressedIconSource: ManagementPanelConstants.unknownButtonFadedIconSource
            releasedIconSource: ManagementPanelConstants.uknownButtonIconSource
        }

        ManagementButton {
            id: unknownButton2
            pressedIconSource: ManagementPanelConstants.unknownButtonFadedIconSource
            releasedIconSource: ManagementPanelConstants.uknownButtonIconSource
        }

        ManagementButton {
            id: unknownButton3
            pressedIconSource: ManagementPanelConstants.unknownButtonFadedIconSource
            releasedIconSource: ManagementPanelConstants.uknownButtonIconSource
        }
    }
}
