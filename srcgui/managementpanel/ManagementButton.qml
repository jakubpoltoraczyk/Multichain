import QtQuick 2.12
import QtQuick.Controls 2.12

import "../configuration"
import "../rectanglesolidborder"

Button {
    id: managementButton
    width: ManagementButtonConstants.width
    height: ManagementButtonConstants.height
    state: ManagementButtonConstants.releasedState

    /** Source of image icon in pressed state */
    property string pressedIconSource: ""

    /** Source of image icon in released state */
    property string releasedIconSource: ""

    states: [
        State {
            name: ManagementButtonConstants.pressedState
            PropertyChanges {
                target: solidBorder
                topBorderColor: ColorConstants.darkGrey
                leftBorderColor: ColorConstants.darkGrey
                bottomBorderColor: ColorConstants.white
                rightBorderColor: ColorConstants.white
            }
            PropertyChanges {
                target: iconImage
                source: pressedIconSource
            }
        },
        State {
            name: ManagementButtonConstants.releasedState
            PropertyChanges {
                target: solidBorder
                topBorderColor: ColorConstants.white
                leftBorderColor: ColorConstants.white
                bottomBorderColor: ColorConstants.darkGrey
                rightBorderColor: ColorConstants.darkGrey
            }
            PropertyChanges {
                target: iconImage
                source: releasedIconSource
            }
        }
    ]

    /** Called when component has been just created */
    Component.onCompleted: {
        background.color = ColorConstants.white
    }

    /** Called, when button has been pressed */
    onPressed: {
        state = ManagementButtonConstants.pressedState
    }

    /** Called, when button has been released */
    onReleased: {
        state = ManagementButtonConstants.releasedState
    }

    /** Called, when button has been canceled */
    onCanceled: {
        state = ManagementButtonConstants.releasedState
    }

    RectangleSolidBorder {
        id: solidBorder
    }

    Image {
        id: iconImage
        anchors.centerIn: parent
    }
}
