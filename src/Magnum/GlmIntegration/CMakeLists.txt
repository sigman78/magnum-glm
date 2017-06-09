
find_package(Magnum REQUIRED)
#find_package(glm REQUIRED)

set(MagnumGlmIntegration_HEADERS
    Integration.h)

set(MagnumGlmIntegration_SRCS
    Dummy.cpp)

add_library(MagnumGlmIntegration ${SHARED_OR_STATIC}
    ${MagnumGlmIntegration_SRCS}
    ${MagnumGlmIntegration_HEADERS})
target_include_directories(MagnumGlmIntegration PUBLIC
    ${PROJECT_SOURCE_DIR}/src
    ${PROJECT_BINARY_DIR}/src)
# Silence pedantic warnings in Bullet headers
target_include_directories(MagnumGlmIntegration SYSTEM PUBLIC ${GLM_INCLUDE_DIRS})
set_target_properties(MagnumGlmIntegration PROPERTIES DEBUG_POSTFIX "-d")
if(BUILD_STATIC_PIC)
    set_target_properties(MagnumGlmIntegration PROPERTIES POSITION_INDEPENDENT_CODE ON)
endif()
target_link_libraries(MagnumGlmIntegration
    Magnum::Magnum)

install(TARGETS MagnumGlmIntegration
    RUNTIME DESTINATION ${MAGNUM_BINARY_INSTALL_DIR}
    LIBRARY DESTINATION ${MAGNUM_LIBRARY_INSTALL_DIR}
    ARCHIVE DESTINATION ${MAGNUM_LIBRARY_INSTALL_DIR})
install(FILES ${MagnumGlmIntegration_HEADERS} DESTINATION ${MAGNUM_INCLUDE_INSTALL_DIR}/GlmIntegration)
# install(FILES ${CMAKE_CURRENT_BINARY_DIR}/configure.h DESTINATION ${MAGNUM_INCLUDE_INSTALL_DIR}/GlmIntegration)

if(BUILD_TESTS)
    add_subdirectory(Test)
endif()

# Magnum Bullet integration target alias for superprojects
add_library(MagnumIntegration::Glm ALIAS MagnumGlmIntegration)