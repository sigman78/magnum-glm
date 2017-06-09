
# On MSVC remove /W3, as we are replacing it with /W4
if(MSVC)
    string(REPLACE "/W3" "" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
endif()

set_directory_properties(PROPERTIES
    CORRADE_CXX_STANDARD 11
    CORRADE_USE_PEDANTIC_FLAGS ON)

# On Windows enable UNICODE/_UNICODE macros to avoid accidentally passing UTF-8
# values to ANSI functions
if(CORRADE_TARGET_WINDOWS)
    add_definitions("-DUNICODE" "-D_UNICODE")
endif()

add_subdirectory(Magnum)

# Magnum integration include dir for superprojects
set(MAGNUMINTEGRATION_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR} CACHE INTERNAL "")