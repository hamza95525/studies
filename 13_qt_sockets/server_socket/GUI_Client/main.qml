import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.3
import pl.socket 1.0
Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    Socket {
        id: socket
    }
    TextEdit {
        id: textEdit
        x: 29
        y: 330
        width: 433
        height: 40
        text: qsTr("")
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 10
    }
    Button {
        id: button
        x: 468
        y: 330
        text: qsTr("Send")
        onClicked: socket.text = textEdit.text
    }
    Label {
        id: label
        x: 29
        y: 126
        width: 539
        height: 75
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        fontSizeMode: Text.Fit
        font.weight: Font.ExtraLight
        text: socket.text
    }
}
