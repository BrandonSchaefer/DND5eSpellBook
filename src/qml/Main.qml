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
import Ubuntu.Components 1.1
import DND5eSpellBook 1.0
import QtQuick.Layouts 1.1
import QtQuick.Controls 1.3
import QtQuick.Controls.Styles 1.3

MainView {
  id: main

  // Note! applicationName needs to match the "name" field of the click manifest
  applicationName: "dnd5espellbook.brandontschaefer"

  automaticOrientation: true
  useDeprecatedToolbar: false

  width:  units.gu(100)
  height: units.gu(76)

  property bool menu_shown: false
  property bool card_shown: false

  FilterMenu {}

  Rectangle {
    id: spell_view
    anchors.fill: parent
    anchors.left: parent.right
    color: "#999999"

    transform: Translate {
      id: spell_view_move
      x: main_view.width
      Behavior on x { NumberAnimation { duration: 500; easing.type: Easing.InOutQuart } }
    }

    MouseArea {
      anchors.fill: parent
    }

    Rectangle {
      id: spell_menu_bar
      anchors.top: parent.top
      width:  parent.width
      height: units.gu(7.5)
      color: "grey"

      // Just need to eat menu bar events
      MouseArea {
        anchors.fill: parent
      }

      Rectangle {
        id: spell_menu_button
        anchors {
          left: parent.left
          verticalCenter: parent.verticalCenter
          margins: units.gu(2)
        }

        width:  units.gu(5)
        height: units.gu(5)
        color: "#CCCCCC"

        Text {
          anchors.centerIn: parent
          font.pixelSize: units.gu(5)
          text: "⬅"
        }

        MouseArea {
          anchors.fill: parent
          onClicked: main.moveCardView()
        }
      }

      Text {
        x: parent.width * 0.25
        anchors.centerIn: parent
        font.pixelSize: units.gu(5)
        font.bold: true
        text: spell_content.currentIndex >= 0 ? spellBookModel[spell_content.currentIndex].name : ""
      }

      BorderImage {
        id: spell_menu_shadow
        anchors.right:  parent.right
        anchors.left:   parent.left
        anchors.bottom: parent.bottom
        anchors.bottomMargin: -units.gu(0.5)
        z: -1
        source: "graphics/shadow.png"
        border {
          left:   units.gu(1)
          right:  units.gu(1)
          top:    units.gu(1)
          bottom: units.gu(1)
        }
      }
    }

    Rectangle {
      id: spell_card
      border.width: units.gu(0.5)
      border.color: "black"

      anchors {
        top:    spell_menu_bar.bottom
        bottom: parent.bottom
        left:   parent.left
        right:  parent.right
        leftMargin:   units.gu(2)
        rightMargin:  units.gu(2)
        bottomMargin: units.gu(1)
        topMargin: units.gu(0.5)
      }

      Flickable {
        anchors.fill: parent
        contentWidth:  parent.width
        contentHeight: spell_card_grid.height + spell_desc_text.height
        flickableDirection: Flickable.VerticalFlick
        clip: true

        GridLayout {
          id: spell_card_grid
          columns: 2
          anchors.top: parent.top
          anchors.left: parent.left
          anchors.right: parent.right
          anchors.margins: units.gu(2)
          rowSpacing: units.gu(2)
          columnSpacing: units.gu(2)
          Text {
            text: spell_content.currentIndex >= 0 ? "<i>" + spellBookModel[spell_content.currentIndex].level + " " +
                                                    spellBookModel[spell_content.currentIndex].school + "</i>" : ""
            Layout.fillWidth: true
            Layout.columnSpan: 2
          }

          Rectangle {
            height: units.gu(0.1)
            color: "black"
            Layout.fillWidth: true
            Layout.columnSpan: 2
          }

          Text {
            text: spell_content.currentIndex >= 0 ? "<b>Casting Time:</b> " + spellBookModel[spell_content.currentIndex].casting_time : ""
            Layout.fillWidth: true
          }
          Text {
            text: spell_content.currentIndex >= 0 ? "<b>Range:</b> " + spellBookModel[spell_content.currentIndex].range : ""
            Layout.fillWidth: true
          }

          Text {
            text: spell_content.currentIndex >= 0 ? "<b>Duration:</b> " + spellBookModel[spell_content.currentIndex].duration : ""
            Layout.fillWidth: true
          }
          Text {
            text: spell_content.currentIndex >= 0 ? "<b>Components:</b> " + spellBookModel[spell_content.currentIndex].components : ""
            Layout.fillWidth: true
          }

          Text {
            text: spell_content.currentIndex >= 0 ? "<b>Concentration:</b> " + spellBookModel[spell_content.currentIndex].concentration : ""
            Layout.fillWidth: true
          }
          Text {
            text: spell_content.currentIndex >= 0 ? "<b>Ritual:</b> " + spellBookModel[spell_content.currentIndex].ritual : ""
            Layout.fillWidth: true
          }

          Text {
            text: spell_content.currentIndex >= 0 ? "<b>Page:</b> " + spellBookModel[spell_content.currentIndex].page : ""
            Layout.fillWidth: true
          }
          Text {
            text: spell_content.currentIndex >= 0 ? "<b>Classes:</b> " + spellBookModel[spell_content.currentIndex].classes : ""
            Layout.fillWidth: true
          }
          Rectangle {
            height: units.gu(0.1)
            color: "black"
            Layout.fillWidth: true
            Layout.columnSpan: 2
          }
        }
        Text {
          id: spell_desc_text
          anchors.top: spell_card_grid.bottom
          anchors.left:  parent.left
          anchors.right: parent.right
          anchors.margins: units.gu(2)
          font.pixelSize:  units.gu(2)
          wrapMode: Text.WordWrap
          text: spell_content.currentIndex >= 0 ? spellBookModel[spell_content.currentIndex].desc : ""
        }
      }
    }
  }

  Rectangle {
    id: main_view
    anchors.fill: parent
    color: "#CCCCCC"

    Rectangle {
      anchors.fill: parent
      visible: spell_content.count > 0 ? false : true
      Text {
        anchors.centerIn: parent
        font.pixelSize: units.gu(2.5)
        font.bold: true
        text: "Sorry, there is nothing that matches your search"
      }
      color: "transparent"
    }

    transform: Translate {
      id: main_view_move
      x: 0
      Behavior on x { NumberAnimation { duration: 500; easing.type: Easing.InOutQuart } }
    }

    BorderImage {
      id: filter_shadow
      anchors.top: parent.top
      anchors.bottom: parent.bottom
      anchors.left: parent.left
      anchors.margins: -units.gu(0.5)
      visible: main_view_move.x != 0
      z: -1
      source: "graphics/shadow.png"
      border {
        left:   units.gu(1.5)
        right:  units.gu(1.5)
        top:    units.gu(1.5)
        bottom: units.gu(1.5)
      }
    }

    Rectangle {
      id: menu_bar
      anchors.top: parent.top
      width: parent.width
      height: units.gu(7.5)
      color: "grey"

      // Just need to eat menu bar events
      MouseArea {
        anchors.fill: parent
      }

      BorderImage {
        id: menu_shadow
        anchors.right: parent.right
        anchors.left: parent.left
        anchors.bottom: parent.bottom
        anchors.bottomMargin: -units.gu(0.5)
        z: -1
        source: "graphics/shadow.png"
        border {
          left:   units.gu(1)
          right:  units.gu(1)
          top:    units.gu(1)
          bottom: units.gu(1)
        }
      }

      Rectangle {
        id: menu_button
        anchors {
          left: parent.left
          verticalCenter: parent.verticalCenter
          margins: units.gu(2)
        }

        width:  units.gu(5)
        height: units.gu(5)
        color: "#CCCCCC"

        Text {
          anchors.centerIn: parent
          font.pixelSize: units.gu(5)
          text: "☰"
        }

        MouseArea {
          anchors.fill: parent
          onClicked: main.moveMainView()
        }
      }

      Text {
        x: parent.width * 0.25
        anchors.centerIn: parent
        font.pixelSize: units.gu(5)
        font.bold: true
        text: "D&D 5e Spell Book"
      }
    }

    ListView {
      id: spell_content
      anchors {
        top:    menu_bar.bottom
        bottom: main_footer.top
        left:   parent.left
        right:  parent.right
        leftMargin:   units.gu(2)
        rightMargin:  units.gu(2)
        bottomMargin: units.gu(1)
        topMargin:    units.gu(0.5)
      }

      spacing: units.gu(0.25)
      clip: true
      model: spellBookModel
      delegate: Rectangle {
        width: parent.width
        height: 40
        border.width: units.gu(0.5)
        border.color: "black"
        Row {
          anchors.fill: parent
          anchors.margins: units.gu(1)

          Rectangle {
            width:  parent.width * 0.25
            height: parent.height
            color: "transparent"
            Text {
              anchors.left: parent.left
              anchors.verticalCenter: parent.verticalCenter
              font.bold: true
              text: model.modelData.level
            }
          }

          Rectangle {
            width:  parent.width * 0.25
            height: parent.height
            color: "transparent"
            Text {
              anchors.centerIn: parent
              font.bold: true
              text: model.modelData.name
            }
          }

          Rectangle {
            width:  parent.width * 0.25
            height: parent.height
            color: "transparent"
            Text {
              anchors.centerIn: parent
              font.bold: true
              text: model.modelData.school
            }
          }

          Rectangle {
            width:  parent.width * 0.25
            height: parent.height
            color: "transparent"
            Text {
              anchors.right: parent.right
              anchors.verticalCenter: parent.verticalCenter
              font.bold: true
              text: model.modelData.page
            }
          }
        }

        MouseArea {
          anchors.fill: parent
          onClicked: {
            spell_content.currentIndex = index
            main.moveCardView()
          }
        }
      }
    }

    Rectangle {
      id: main_footer
      anchors.bottom: parent.bottom
      width: parent.width
      height: units.gu(5)
      color: "grey"

      TextField {
        id: search_bar
        anchors.centerIn: parent
        anchors.margins: units.gu(1)
        width: parent.width / 4
        height: parent.height / 1.5
        placeholderText: "search"
        onTextChanged: backend.EditingFinished(text)
        style: TextFieldStyle {
          placeholderTextColor: "#888888"
        }
      }

      Rectangle {
        id: clear_search_bar_button
        anchors.right: search_bar.left
        anchors.verticalCenter: parent.verticalCenter
        anchors.margins: units.gu(1)
        width: units.gu(2)
        height: units.gu(2)
        color: "#CCCCCC"

        Text {
          anchors.centerIn: parent
          text: "x"
        }

        MouseArea {
          anchors.fill: parent
          onClicked: search_bar.text = ""
        }
      }

      BorderImage {
        id: main_footer_shadow
        anchors.right: parent.right
        anchors.left:  parent.left
        anchors.top:   parent.top
        anchors.topMargin: -units.gu(0.5)
        z: -1
        source: "graphics/shadow.png"
        border {
          left:   units.gu(1)
          right:  units.gu(1)
          top:    units.gu(1)
          bottom: units.gu(1)
        }
      }
    }
  }

  function moveMainView()
  {
    main_view_move.x  = main.menu_shown ? 0 : main.width * 0.2
    spell_view_move.x = main.menu_shown ? main.width : main.width + main.width * 0.2
    main.menu_shown = !main.menu_shown
  }

  function moveCardView()
  {
    main_view_move.x  = main.card_shown ? 0 : -main.width
    spell_view_move.x = main.card_shown ? main.width : 0
    main.menu_shown = false
    main.card_shown = !main.card_shown
  }
}
