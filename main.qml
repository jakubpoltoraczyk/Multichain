import QtQuick.Window 2.12
import QtQuick 2.12

import "srcgui/configuration"
import "srcgui/dropfilearea"
import "srcgui/managementpanel"

Window {
    id: mainWindow
    width: 600
    height: 400
    color: ColorConstants.lightGrey
    visible: true

    Row {
        id: mainRow

        DropFileArea {
            id: dropFileArea
            width: 450
            height: mainWindow.height
        }

        ManagementPanel {
            id: managementPanel
            width: 150
            height: mainWindow.height
        }
    }
}
