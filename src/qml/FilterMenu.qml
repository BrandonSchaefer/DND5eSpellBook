import QtQuick 2.0
import QtQuick.Controls 1.3

Rectangle {
  width:  parent.width * 0.15
  height: parent.height
  color: "#777777"
  clip: true

  Flickable {
    anchors.fill:  parent
    contentWidth:  parent.width
    contentHeight: parent.height
    flickableDirection: Flickable.VerticalFlick
    clip: true

    Column {
      anchors.fill: parent
      anchors.margins: units.gu(0.5)

      Rectangle {
        width: parent.width
        height: sort_by_view.contentHeight + sort_by_text.height
        color: "transparent"

        Text {
          id: sort_by_text
          font.bold: true
          text: "Sort By"
        }

        ExclusiveGroup { id: sortByPosition }
        ListView {
          id: sort_by_view
          anchors {
            top: sort_by_text.bottom
            left: parent.left
            right:  parent.right
            bottom: parent.bottom
          }
          interactive: false
          model: SortByFilter {}
          delegate: RadioButton {
            text: name
            exclusiveGroup: sortByPosition
            checked: start
            onClicked: backend.SortBy(text)
            Component.onCompleted: if (start) backend.SortBy(text);
          }
        }
      }

      Rectangle {
        width: parent.width
        height: level_list_view.contentHeight + level_text.height
        color: "transparent"

        Text {
          id: level_text
          font.bold: true
          text: "Levels"
        }

        ListView {
          id: level_list_view
          anchors {
            top:    level_text.bottom
            left:   parent.left
            right:  parent.right
            bottom: parent.bottom
          }
          interactive: false
          model: SpellLevelFilter {}
          delegate: CheckBox {
            text: name
            onClicked: backend.LevelFilter(text, checked)
          }
        }
      }

      Rectangle {
        width: parent.width
        height: class_list_view.contentHeight + class_text.height
        color: "transparent"

        Text {
          id: class_text
          font.bold: true
          text: "Classes"
        }

        ListView {
          id: class_list_view
          anchors {
            top:    class_text.bottom
            left:   parent.left
            right:  parent.right
            bottom: parent.bottom
          }
          interactive: false
          model: ClassFilter {}
          delegate: CheckBox {
            text: name
            onClicked: backend.ClassFilter(text, checked)
          }
        }
      }
    }
  }
}

