import QtQuick 2.0
import Ubuntu.Components 1.1
import DND5eSpellBook 1.0

/*!
    \brief MainView with Tabs element.
           First Tab has a single Label and
           second Tab has a single ToolbarAction.
*/

MainView {
    id: main

    // Note! applicationName needs to match the "name" field of the click manifest
    applicationName: "dnd5espellbook.brandontschaefer"

    /*
     This property enables the application to change orientation
     when the device is rotated. The default is false.
    */
    //automaticOrientation: true

    // Removes the old toolbar and enables new features of the new header.
    useDeprecatedToolbar: false

    width: units.gu(100)
    height: units.gu(76)

    property bool menu_shown: false
    Page {
      title: i18n.tr("DND Spell Book")

      Rectangle {
        id: menu_view
        anchors.fill: parent
        color: "#303030"

        MouseArea {
          id: menu_mouse
          anchors.fill: parent
          onClicked: Qt.quit()
        }
      }

      Rectangle {
        id: main_view
        anchors.fill: parent
        color: "#CCCCCC"

        transform: Translate {
          id: main_view_move
          x: 0
          Behavior on x { NumberAnimation { duration: 400; easing.type: Easing.InOutQuart } }
        }

        MyType {
            id: myType

            Component.onCompleted: {
                myType.helloWorld = i18n.tr("Hello world..")
            }
        }

        Column {
            spacing: units.gu(1)
            anchors {
                margins: units.gu(2)
                fill: parent
            }

            Label {
                id: label
                objectName: "label"

                text: myType.helloWorld
            }

            Button {
                objectName: "button"
                width: parent.width

                text: i18n.tr("Tap me! Please Yeah :::)")

                onClicked: {
                    myType.helloWorld = i18n.tr("..from Cpp Backend")
                    main.moveMainView()
                }
            }
        }
        /*

        MouseArea {
          id: main_mouse
          anchors.fill: parent
          onClicked: main.moveMainView()
        }
        */
      }
    }

    function moveMainView()
    {
      main_view_move.x = main.menu_shown ? 0 : main.width * 0.25
      main.menu_shown = !main.menu_shown
    }
}
  /*
      Page {
          title: i18n.tr("DND5eSpellBook")

          MyType {
              id: myType

              Component.onCompleted: {
                  myType.helloWorld = i18n.tr("Hello world..")
              }
          }

          Column {
              spacing: units.gu(1)
              anchors {
                  margins: units.gu(2)
                  fill: parent
              }

              Label {
                  id: label
                  objectName: "label"

                  text: myType.helloWorld
              }

              Button {
                  objectName: "button"
                  width: parent.width

                  text: i18n.tr("Tap me! Please Yeah :::)")

                  onClicked: {
                      myType.helloWorld = i18n.tr("..from Cpp Backend")
                  }
              }
          }
      }
      */
