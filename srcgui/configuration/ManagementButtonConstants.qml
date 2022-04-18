pragma Singleton
import QtQuick 2.12

QtObject {
    /** Default width of management button */
    readonly property int width: 60

    /** Default height of management button */
    readonly property int height: 60

    /** Released state name of management button */
    readonly property string releasedState: "releasedState"

    /** Pressed state name of management button */
    readonly property string pressedState: "pressedState"
}
