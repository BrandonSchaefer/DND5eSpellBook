//-*- Mode: QML; indent-tabs-mode: nil; tab-width: 2 -*-
/* * Copyright (C) 2015 Brandon Schaefer
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License version 3 as
* published by the Free Software Foundation.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*
* Authored by: Brandon Schaefer <brandontschaefer@gmail.com>
*/

import QtQuick 2.0
import QtQuick.Controls 1.3

Rectangle {
  width:  parent.width * 0.2
  height: parent.height
  color: "#777777"
  clip: true

  Flickable {
    anchors.fill:  parent
    anchors.margins: units.gu(1)
    contentWidth:  parent.width
    contentHeight: sort.height + sort_by.height + level.height + classes.height + school.height
    flickableDirection: Flickable.VerticalFlick
    clip: true

    Column {
      anchors.fill: parent
      anchors.margins: units.gu(0.5)

      Rectangle {
        id: sort
        width: parent.width
        height: direction_view.contentHeight + sort_text.height
        color: "transparent"

        Text {
          id: sort_text
          font.bold: true
          text: "Sort"
        }

        ExclusiveGroup { id: directionPosition }
        ListView {
          id: direction_view
          anchors {
            top: sort_text.bottom
            left: parent.left
            right:  parent.right
            bottom: parent.bottom
          }
          interactive: false
          model: AscendingFilter {}
          delegate: RadioButton {
            text: name
            exclusiveGroup: directionPosition
            checked: start
            onClicked: backend.Ascending(sortByPosition.current.text, text)
            Component.onCompleted: if (start) backend.Ascending(sortByPosition.current.text, text);
          }
        }
      }

      Rectangle {
        id: sort_by
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
        id: level
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
        id: classes
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

      Rectangle {
        id: school
        width: parent.width
        height: school_list_view.contentHeight + school_text.height
        color: "transparent"

        Text {
          id: school_text
          font.bold: true
          text: "Schools"
        }

        ListView {
          id: school_list_view
          anchors {
            top:    school_text.bottom
            left:   parent.left
            right:  parent.right
            bottom: parent.bottom
          }
          interactive: false
          model: SchoolFilter {}
          delegate: CheckBox {
            text: name
            onClicked: backend.SchoolFilter(text, checked)
          }
        }
      }
    }
  }
}

