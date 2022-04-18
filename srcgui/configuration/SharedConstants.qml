pragma Singleton
import QtQuick 2.12

QtObject {
    /** Default width of application border */
    readonly property int defaultBorderWidth: 2

    /** General path to appropriate images used in application */
    readonly property string imagePath: "qrc:/srcgui/images/%1"
}
