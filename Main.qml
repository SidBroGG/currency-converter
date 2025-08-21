import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Window {
    width: 640
    height: 480
    visible: true
    title: "Converter"

    ColumnLayout {
        anchors.centerIn: parent
        spacing: 25

        Text {
            id: appNameLabel
            text: "Currency converter"
            font.pixelSize: 35
        }

        RowLayout {
            Layout.alignment: Qt.AlignHCenter
            spacing: 35

            ColumnLayout {
                ComboBox {
                    id: fromComboBox
                    currentIndex: 0
                    model: [ "USD", "EURO", "BYN" ]
                    Layout.fillWidth: true
                }

                TextField {
                    id: fromTextField
                    placeholderText: "Enter value"
                    validator: DoubleValidator { bottom: 0}
                    Layout.fillWidth: true

                    onTextEdited: {
                        updateaToField()
                    }
                }
            }

            Text {
                text: "<=====>"
            }

            ColumnLayout {
                ComboBox {
                    id: toComboBox
                    currentIndex: 0
                    model: [ "USD", "EURO", "BYN" ]
                    Layout.fillWidth: true
                }

                TextField {
                    id: toTextField
                    placeholderText: "Enter value"
                    validator: DoubleValidator { bottom: 0}
                    Layout.fillWidth: true

                    onTextEdited: {
                        updateaFromField()
                    }
                }
            }
        }
    }

    function updateaToField() {
        if (fromTextField.activeFocus) {
            toTextField.text = ccl.convert(fromTextField.text,
                                           fromComboBox.currentIndex,
                                           toComboBox.currentIndex)
        }
    }

    function updateaFromField() {
        if (toTextField.activeFocus) {
            fromTextField.text = ccl.convert(toTextField.text,
                                           toComboBox.currentIndex,
                                           fromComboBox.currentIndex)
        }
    }
}
