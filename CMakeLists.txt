project(DND5eSpellBook C CXX)
cmake_minimum_required(VERSION 2.8.9)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g3 -fPIC -std=c++0x -Werror -Wall -pedantic -Wcast-align -Wempty-body -Wformat-security -Winit-self -Warray-bounds")

# Do not remove this line, its required for the correct functionality of the Ubuntu-SDK
set(UBUNTU_MANIFEST_PATH "manifest.json.in" CACHE INTERNAL "Tells QtCreator location and name of the manifest file")
set (CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

find_package(Qt5Core)
find_package(Qt5Qml)
find_package(Qt5Quick)
# find_package(ubuntu-sdk-libs)

# Automatically create moc files
set(CMAKE_AUTOMOC ON)

find_package(Jsoncpp)

# Components PATH
execute_process(
    COMMAND dpkg-architecture -qDEB_HOST_MULTIARCH
    OUTPUT_VARIABLE ARCH_TRIPLET
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

set(QT_IMPORTS_DIR "lib/${ARCH_TRIPLET}")

option(INSTALL_TESTS "Install the tests on make install" on)

set(APP_NAME          DND5eSpellBook)
set(APP_ID            "dnd5espellbook.brandontschaefer")
set(DND5ESPELLBOOK_DIR "share/DND5eSpellBook")
set(MAIN_QML          "Main.qml")
set(ICON              "${DND5ESPELLBOOK_DIR}/graphics/DND5eSpellBook.png")
set(JSONDIR           "${CMAKE_INSTALL_PREFIX}/${DND5ESPELLBOOK_DIR}/json")

# Set install paths
set(DATA_DIR "${CMAKE_INSTALL_PREFIX}/share/")
set(DESKTOP_DIR "${DATA_DIR}/applications")
set(DESKTOP_FILE_NAME "DND5eSpellBook.desktop")

set(EXEC "qmlscene $@ ${DND5ESPELLBOOK_DIR}/${MAIN_QML}")

# This command figures out the target architecture for use in the manifest file
execute_process(
  COMMAND dpkg-architecture -qDEB_HOST_ARCH
  OUTPUT_VARIABLE CLICK_ARCH
  OUTPUT_STRIP_TRAILING_WHITESPACE
)

configure_file(run.sh.cmake ${CMAKE_CURRENT_BINARY_DIR}/run.sh)

configure_file(manifest.json.in ${CMAKE_CURRENT_BINARY_DIR}/manifest.json)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/manifest.json
        DESTINATION ${CMAKE_INSTALL_PREFIX})

install(DIRECTORY "src/qml/graphics" DESTINATION ${DND5ESPELLBOOK_DIR})
#install(FILES "DND5eSpellBook.apparmor" DESTINATION ${DATA_DIR})

configure_file (${CMAKE_SOURCE_DIR}/config.h.cmake ${CMAKE_BINARY_DIR}/config.h)

add_subdirectory(src)
add_subdirectory(po)

add_custom_target("run" /usr/bin/qmlscene -I ${CMAKE_BINARY_DIR}/backend  ${CMAKE_SOURCE_DIR}/src/qml/Main.qml
                    DEPENDS DND5eSpellBookbackend DND5eSpellBookbackend-qmldir
                    WORKING_DIRECTORY ./app)

# No op custom target for all not compiled files, so they show up in the QtCreator project tree
add_custom_target("dnd5espellbook_ClickFiles" ALL SOURCES "DND5eSpellBook.apparmor" "manifest.json.in")
