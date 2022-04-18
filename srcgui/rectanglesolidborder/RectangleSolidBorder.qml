import QtQuick 2.12

import "../configuration"

Item {
    id: rectangleSolidBorder
    anchors.fill: parent

    /** Width of the border */
    property real borderWidth: SharedConstants.defaultBorderWidth

    /** Color of the border on the top side */
    property string topBorderColor: ColorConstants.black

    /** Color of the border on the right side */
    property string rightBorderColor: ColorConstants.black

    /** Color of the border on the bottom side */
    property string bottomBorderColor: ColorConstants.black

    /** Color of the border on the left side */
    property string leftBorderColor: ColorConstants.black

    /** Visibility of the border on the top side */
    property bool topBorderVisibility: true

    /** Visibility of the border on the right side */
    property bool rightBorderVisibility: true

    /** Visibility of the border on the bottom side */
    property bool bottomBorderVisibility: true

    /** Visibility of the border on the left side */
    property bool leftBorderVisibility: true

    Rectangle{
        id: topBorder
        width: parent.width + borderWidth
        height: borderWidth
        color: topBorderColor
        visible: topBorderVisibility
        anchors.bottom: parent.top
    }

    Rectangle{
        id: rightBorder
        width: borderWidth
        height: parent.height + borderWidth
        color: rightBorderColor
        visible: rightBorderVisibility
        anchors.left: parent.right
    }

    Rectangle{
        id: bottomBorder
        x: parent.x - borderWidth
        width: parent.width + borderWidth
        height: borderWidth
        color: bottomBorderColor
        visible: bottomBorderVisibility
        anchors.top: parent.bottom
    }

    Rectangle{
        id: leftBorder
        y: parent.y - borderWidth
        width: borderWidth
        height: parent.height + borderWidth
        color: leftBorderColor
        visible: leftBorderVisibility
        anchors.right: parent.left
    }
}
