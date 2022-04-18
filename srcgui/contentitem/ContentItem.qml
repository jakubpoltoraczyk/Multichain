import QtQuick 2.12

import "../configuration"
import "../dropfilearea"
import "../listviewarea"

Item {
    id: contentItem

    /** Visibility of drop file area */
    property alias dropFileAreaVisibility: dropFileArea.visible

    /** Visibility of list view area */
    property alias listViewAreaVisibility: listViewArea.visible

    /** Visibility of unknown area 2 */
    property alias unknownArea2Visibility: unknownArea2.visible

    /** Visibility of unknown area 3 */
    property alias unknownArea3Visibility: unknownArea3.visible

    DropFileArea {
        id: dropFileArea
        anchors.fill: parent
        visible: true
    }

    ListViewArea {
        id: listViewArea
        anchors.fill: parent
        visible: false
    }

    Rectangle {
        id: unknownArea2
        anchors.fill: parent
        visible: false
        color: ColorConstants.black
    }

    Rectangle {
        id: unknownArea3
        anchors.fill: parent
        visible: false
        color: ColorConstants.black
    }
}
