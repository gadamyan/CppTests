
include("${CMAKE_SOURCE_DIR}/cmake/setup_gtest.cmake")

setup_gtest()

file(GLOB_RECURSE SOURCES *.cpp *.h)

include_directories(${CMAKE_SOURCE_DIR}/core ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(core_test ${SOURCES})

target_link_libraries(core_test PRIVATE core gtest_main gmock)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCES})

install(TARGETS core_test DESTINATION bin)