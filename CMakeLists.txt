cmake_minimum_required(VERSION 2.8.12)
project(MagnumIntegration)

# CMake policies: enable MACOSX_RPATH by default
if(POLICY CMP0042)
    cmake_policy(SET CMP0042 NEW)
endif()
# Don't treat imported targets with :: as files
if(POLICY CMP0028)
    cmake_policy(SET CMP0028 NEW)
endif()

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/modules/")
find_package(Magnum REQUIRED)

include(CMakeDependentOption)
option(BUILD_STATIC "Build static libraries (default are shared)" OFF)
cmake_dependent_option(BUILD_STATIC_PIC "Build static libraries with position-independent code" ON "BUILD_STATIC" OFF)
option(BUILD_TESTS "Build unit tests" OFF)

if(BUILD_TESTS)
    find_package(Corrade REQUIRED TestSuite)
    if(CORRADE_TARGET_IOS)
        set(CORRADE_TESTSUITE_BUNDLE_IDENTIFIER_PREFIX "cz.mosra.magnum-integration")
    endif()
    enable_testing()
endif()

# Newlib toolchain supports only static linking
if(CORRADE_TARGET_NACL_NEWLIB)
    set(BUILD_STATIC ON)
endif()

if(NOT BUILD_STATIC)
    set(SHARED_OR_STATIC SHARED)
else()
    set(SHARED_OR_STATIC STATIC)
endif()

set(MAGNUMINTEGRATION_CMAKE_MODULE_INSTALL_DIR ${CMAKE_INSTALL_PREFIX}/share/cmake/MagnumIntegration)

#add_subdirectory(modules)
add_subdirectory(src)