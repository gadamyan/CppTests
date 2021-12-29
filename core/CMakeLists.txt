
file(GLOB_RECURSE SOURCES *.cpp *.h)

add_library(core STATIC ${SOURCES})

target_include_directories(core PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCES})

install(TARGETS core DESTINATION lib)
