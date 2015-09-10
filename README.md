Dependices for debian/ubuntu:

    qtdeclarative5-ubuntu-ui-toolkit-plugin
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

![Main View](http://i.imgur.com/8MDDVPp.png)
![Card View](http://i.imgur.com/DVSRZVL.png)
![Filter View](http://i.imgur.com/huWE6iv.png)

