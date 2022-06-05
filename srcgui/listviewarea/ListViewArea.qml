import QtQuick 2.12
import QtQuick.Controls 2.12

import "../configuration"
import "../rectanglesolidborder"

Rectangle {
    id: listViewArea
    gradient: Gradient {
        orientation: Gradient.Horizontal
        GradientStop { position: 0.0; color: "#3ecae6" }
        GradientStop { position: 0.33; color: "#86e5f7" }
        GradientStop { position: 1.0; color: "#a6e8f5" }
    }

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
        background: Rectangle {
            color: ColorConstants.white
        }
    }

    Button {
        id: confirmButton
        width: ListViewAreaConstants.confirmButtoneWidth
        height: ListViewAreaConstants.confirmButtoneHeight
        visible: true
        text: "Confirm"
        state: ListViewAreaConstants.releasedState
        anchors.top: listViewComboBox.bottom
        anchors.horizontalCenter: listViewComboBox.horizontalCenter
        anchors.topMargin: 20
        background: Rectangle {
            color: ColorConstants.white
        }

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
