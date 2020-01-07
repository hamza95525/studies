import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.3
import pl.gwizdz 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    TextField {
        id: textField
        x: 220
        y: 68
        text: qsTr("Label")
    }

    Demo {
        id: demo
        value: 10.2;
        onTest: function() {
            console.log("It works...");
            textField.clear();
        }
    }

    Button {
        id: button
        x: 270
        y: 144
        text: qsTr("Button")
        onClicked: function() {
            label.text = textField.text;
            demo.doSomething();
        }
    }

    Label {
        id: label
        x: 302
        y: 232
        text: qsTr("Label")
    }

    Label {
        id: label1
        x: 308
        y: 232
        text: textField.text + demo.value;
    }
}
