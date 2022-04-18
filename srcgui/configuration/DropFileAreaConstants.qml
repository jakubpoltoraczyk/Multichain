pragma Singleton
import QtQuick 2.12

QtObject {
    /** Name of drag entered state */
    readonly property string dragEnteredState: "dragEnteredState"

    /** Name of drag exited state */
    readonly property string dragExitedState: "dragExitedState"

    /** Source of drop file icon image */
    readonly property string dropFileIconImageSource: SharedConstants.imagePath.arg("dropfileicon.png")

    /** Source of drop file icon faded image */
    readonly property string dropFileIconFadedImageSource: SharedConstants.imagePath.arg("dropfileicon_faded.png")
}
