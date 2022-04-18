pragma Singleton
import QtQuick 2.12

QtObject {
    /** Spacing between components in management panel */
    readonly property int spacing: 20

    /** Source of icon in list view button */
    readonly property string listViewIconSource: SharedConstants.imagePath.arg("listviewicon.png")

    /** Source of faded icon in list view button */
    readonly property string listViewFadedIconSource: SharedConstants.imagePath.arg("listviewicon_faded.png")

    /** Source of icon in unknown button */
    readonly property string uknownButtonIconSource: SharedConstants.imagePath.arg("questionicon.png")

    /** Source of faded icon in unknown button */
    readonly property string unknownButtonFadedIconSource: SharedConstants.imagePath.arg("questionicon_faded.png")
}
