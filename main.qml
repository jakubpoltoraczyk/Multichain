import QtQuick.Window 2.12
import QtQuick 2.12

import "srcgui/configuration"
import "srcgui/contentitem"
import "srcgui/managementpanel"
import "srcgui/messagedialog"

Window {
    id: mainWindow
    width: 600
    height: 400
    minimumWidth: width
    maximumWidth: width
    minimumHeight: height
    maximumHeight: height
    color: ColorConstants.lightGrey
    visible: true

    Row {
        id: mainRow

        ContentItem {
            id: contentItem
            width: 450
            height: mainWindow.height
            dropFileAreaVisibility: managementPanel.lastReleasedButton === ManagementPanelConstants.DropFileArea
            listViewAreaVisibility: managementPanel.lastReleasedButton === ManagementPanelConstants.ListViewArea
            unknownArea2Visibility: managementPanel.lastReleasedButton === ManagementPanelConstants.Unknown2
            authorsViewVisibility: managementPanel.lastReleasedButton === ManagementPanelConstants.Authors
        }

        ManagementPanel {
            id: managementPanel
            width: 150
            height: mainWindow.height
        }
    }

    CustomMessageDialog {
        id: customMessageDialog
    }   
}
