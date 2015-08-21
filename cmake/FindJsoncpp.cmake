# - Try to find Jsoncpp
# Once done, this will define
#
#  Jsoncpp_FOUND - system has Jsoncpp
#  Jsoncpp_INCLUDE_DIRS - the Jsoncpp include directories
#  Jsoncpp_LIBRARIES - link these to use Jsoncpp

#include(LibFindMacros)

# Use pkg-config to get hints about paths
#libfind_pkg_check_modules(Jsoncpp_PKGCONF jsoncpp)

find_package(PkgConfig)

pkg_check_modules(JSON REQUIRED jsoncpp)

# Include dir
find_path(JSON_INCLUDE_DIR json/json.h
          HINTS ${JSON_INCLUDEDIR} ${JSON_INCLUDE_DIRS}
)

# Finally the library itself
find_library(JSON_LIBRARY jsoncpp
             HINTS ${JSON_LIBDIR} ${JSON_LIBRARY_DIRS}
)

set (JSON_LIBRARIES    ${JSON_LIBRARY})
set (JSON_INCLUDE_DIRS ${JSON_INCLUDE_DIR})

find_package_handle_standard_args(jsoncpp DEFAULT_MSG
                                  JSON_LIBRARY JSON_INCLUDE_DIR)

mark_as_advanced(${JSON_LIBRARY} ${JSON_INCLUDE_DIR})
