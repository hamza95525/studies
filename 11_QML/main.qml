import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.3
import pl.hello 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Acceleration {
        id: acceleration
    }

    Displacement {
        id: displacement
        onChanged: speed.onChange(displacement.value);
    }

    Speed {
        id: speed
        onChanged: acceleration.onChange(speed.value);
    }

    Button {
        id: button
        x: 416
        y: 97
        width: 163
        height: 49
        text: qsTr("Change")
        onClicked: function() {
            displacement.set(parseInt(textField.text));
            speed.get();
            label2.text = speed.value;
            acceleration.get();
            label3.text = acceleration.value;
        }
    }

    TextField {
        id: textField
        x: 97
        y: 102
        text: qsTr("")
    }

    Label {
        id: label
        x: 97
        y: 232
        width: 62
        height: 21
        text: qsTr("Speed")
    }

    Label {
        id: label1
        x: 97
        y: 322
        width: 103
        height: 36
        text: qsTr("Acceleration")
    }

    Label {
        id: label2
        x: 302
        y: 236
        text: speed.value;
    }

    Label {
        id: label3
        x: 302
        y: 332
        text: acceleration.value;
    }
}
