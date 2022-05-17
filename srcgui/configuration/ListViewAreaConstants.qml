pragma Singleton
import QtQuick 2.12

QtObject {
    /** Maximum width of combo box items */
    readonly property int comboBoxMaxWidth: 250

    /** Width of confirm button */
    readonly property int confirmButtoneWidth: 100

    /** Height of confirm button */
    readonly property int confirmButtoneHeight: 50

    /** Coordinate X of confirm button */
    readonly property int confirmButtonCoordinateX: 300

    /** Coordinate Y of confirm button */
    readonly property int confirmButtonCoordinateY: 300

    /** Released state name of confirm button */
    readonly property string releasedState: "releasedState"

    /** Pressed state name of confirm button */
    readonly property string pressedState: "pressedState"
}
