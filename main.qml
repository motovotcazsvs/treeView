import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import QtQuick.Controls 2.0
import QtQuick.Controls.Styles 1.4

Window {
    visible: true
    width: 620
    height: 680


    TreeView {
        model: treemodel
        anchors.fill: parent
        headerVisible: false

        style: TreeViewStyle {
            backgroundColor: "transparent"
            alternateBackgroundColor : "transparent"
        }

        TableViewColumn {
            role: "display"
        }

    }

}
