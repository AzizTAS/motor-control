import QtQuick
import QtQuick.Controls

ApplicationWindow {
    width: 400
    height: 300
    visible: true
    title: "Motor Control"

    Label {
        anchors.centerIn: parent
        text: "Speed: 0 rpm"
        font.pixelSize: 24
    }
}