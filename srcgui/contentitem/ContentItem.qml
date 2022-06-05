import QtQuick 2.12

import "../configuration"
import "../dropfilearea"
import "../listviewarea"
import "../authorsview"

Item {
    id: contentItem

    /** Visibility of drop file area */
    property alias dropFileAreaVisibility: dropFileArea.visible

    /** Visibility of list view area */
    property alias listViewAreaVisibility: listViewArea.visible

    /** Visibility of unknown area 3 */
    property alias authorsViewVisibility: authorsView.visible

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

    AuthorsView {
        id: authorsView
        anchors.fill: parent
        visible: false
    }
}
