import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

ApplicationWindow {
    width: 400
    height: 300
    visible: true
    title: "Motor Control"

    MotorController {
        id: controller
        target: targetSlider.value
    }

    ColumnLayout {
        anchors.centerIn: parent
        spacing: 16

        Label {
            text: "Speed: " + controller.speed.toFixed(0) + " rpm"
            font.pixelSize: 24
        }

        Label {
            text: "Target: " + targetSlider.value.toFixed(0) + " rpm"
        }

        Slider {
            id: targetSlider
            from: 0
            to: 3000
            stepSize: 100
            value: 1500
            Layout.preferredWidth: 300
        }

        Button {
            text: controller.running ? "Stop" : "Start"
            onClicked: controller.running ? controller.stop() : controller.start()
        }
    }
}
