import QtQuick 2.12
import QtQuick.Controls 2.12

import "../configuration"

Rectangle {
    id: listViewArea
    color: ColorConstants.extraLightGrey

    ComboBox {
        id: listViewComboBox
        anchors.centerIn: parent
        model: ["First", "Second", "Third"]
    }
}
