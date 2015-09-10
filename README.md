Dependices for debian/ubuntu:

    libjsoncpp-dev

To compile:

    mkdir build
    cd build
    cmake ..
    make -j4
    make install

CMake options:

    -DCMAKE_BUILD_TYPE=[Debug|Release]

Environment Variables:

    DND_SPELL_BOOK_JSON_PATH=/path/to/json/file/spells.json
