include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
)

set(
    DND5eSpellBookbackend_SRCS
    modules/DND5eSpellBook/BackendPlugin.cpp
    modules/DND5eSpellBook/Filter.cpp
    modules/DND5eSpellBook/JSonSpellParser.cpp
    modules/DND5eSpellBook/Spell.cpp
    modules/DND5eSpellBook/SpellBookModel.cpp
    #modules/DND5eSpellBook/SpellBookSearchEngine.cpp
)

include_directories (${JSON_INCLUDE_DIRS} ${CMAKE_BINARY_DIR})

add_library(DND5eSpellBookbackend MODULE
    ${DND5eSpellBookbackend_SRCS}
)

target_link_libraries(DND5eSpellBookbackend ${JSON_LIBRARIES})

set_target_properties(DND5eSpellBookbackend PROPERTIES
         LIBRARY_OUTPUT_DIRECTORY DND5eSpellBook)

qt5_use_modules(DND5eSpellBookbackend Gui Qml Quick)

# Install plugin file
install(TARGETS DND5eSpellBookbackend DESTINATION ${QT_IMPORTS_DIR}/DND5eSpellBook/)
install(FILES   modules/DND5eSpellBook/qmldir DESTINATION ${QT_IMPORTS_DIR}/DND5eSpellBook/)
install(FILES   modules/json/spells.json DESTINATION ${JSONDIR}/)
