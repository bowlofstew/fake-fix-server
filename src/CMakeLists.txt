project(FakeFixServer)
set( CMAKE_VERBOSE_MAKEFILE on )
set(CMAKE_CXX_FLAGS "-std=c++11")
externalproject_add(quickfix
    GIT_REPOSITORY https://github.com/quickfix/quickfix.git
    GIT_TAG cc1b035080e01559fc157861961ab31955349240
    SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../thirdparty/quickfix
    CONFIGURE_COMMAND ./bootstrap  --prefix=${CMAKE_INSTALL_PREFIX} COMMAND ./configure --prefix=${CMAKE_INSTALL_PREFIX}
    BUILD_COMMAND make
    INSTALL_COMMAND make install
    BUILD_IN_SOURCE 1
)
set(QUICKFIX_INC ${CMAKE_CURRENT_SOURCE_DIR}/../thirdparty/quickfix/include)
set(SOURCES main.cpp
            application.cpp
)
include_directories(
    ../inc
    ${QUICKFIX_INC}
)
add_executable(FakeFixServer 
               ${SOURCES}
)
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/../thirdparty/quickfix/lib)
target_link_libraries(FakeFixServer
    libquickfix.a
)
add_dependencies(FakeFixServer quickfix)
add_custom_command(TARGET FakeFixServer
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/fix/FIX44.xml ${EXECUTABLE_OUTPUT_PATH}/${CMAKE_BUILD_TYPE}/FIX44.xml
)
add_custom_command(TARGET FakeFixServer
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/config/session_settings.txt ${EXECUTABLE_OUTPUT_PATH}/${CMAKE_BUILD_TYPE}/session_settings.txt
)

