import QtQuick 2.12
import QtQuick.Controls 2.12

import "../configuration"
import "../rectanglesolidborder"

Rectangle {
    id: listViewArea
    color: ColorConstants.extraLightGrey

    /** Emitted when file from list view has been just selected */
    signal listViewFileSelected(string fileName)

    /** Called when component has been just created */
    Component.onCompleted: {
        listViewFileSelected.connect(controller.onListViewFileSelected)
    }

    ComboBox {
        id: listViewComboBox
        width: ListViewAreaConstants.comboBoxMaxWidth
        font.pixelSize: SharedConstants.defaultFontPixelSize
        anchors.centerIn: parent
        model: controller.listViewAreaFiles
        delegate: ItemDelegate {
            id: itemDelegateComponent
            width: parent.width
            text: modelData
            contentItem: Label {
                id: contentItemComponent
                text: itemDelegateComponent.text
                elide: Label.ElideLeft
                font.pixelSize: SharedConstants.defaultFontPixelSize
            }
        }
    }

    Button {
        id: confirmButton
        width: ListViewAreaConstants.confirmButtoneWidth
        height: ListViewAreaConstants.confirmButtoneHeight
        x: ListViewAreaConstants.confirmButtonCoordinateX
        y: ListViewAreaConstants.confirmButtonCoordinateY
        visible: true
        palette.button: ColorConstants.lightGrey
        text: "Confirm"
        state: ListViewAreaConstants.releasedState

        states: [
            State {
                name: ListViewAreaConstants.pressedState
                PropertyChanges {
                    target: solidBorder
                    topBorderColor: ColorConstants.darkGrey
                    leftBorderColor: ColorConstants.darkGrey
                    bottomBorderColor: ColorConstants.white
                    rightBorderColor: ColorConstants.white
                }
            },
            State {
                name: ListViewAreaConstants.releasedState
                PropertyChanges {
                    target: solidBorder
                    topBorderColor: ColorConstants.white
                    leftBorderColor: ColorConstants.white
                    bottomBorderColor: ColorConstants.darkGrey
                    rightBorderColor: ColorConstants.darkGrey
                }
            }
        ]

        /** Called, when button has been pressed */
        onPressed: {
            state = ManagementButtonConstants.pressedState
        }

        /** Called, when button has been released */
        onReleased: {
            state = ManagementButtonConstants.releasedState
            listViewFileSelected(listViewComboBox.currentText)
        }

        /** Called, when button has been canceled */
        onCanceled: {
            state = ManagementButtonConstants.releasedState
        }

        RectangleSolidBorder {
            id: solidBorder
        }
    }
}
