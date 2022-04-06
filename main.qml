import QtQuick.Window 2.12
import QtQuick 2.12

import "srcgui/configuration"
import "srcgui/dropfilearea"

Window {
    id: mainWindow
    width: MainWindowConstants.width
    height: MainWindowConstants.height
    color: ColorConstants.lightGrey
    visible: true

    DropFileArea {}
}
