# Shared build logic for every site (advent-of-code, project-euler, everybody-codes).
#
# Site CMakeLists.txt usage:
#   cmake_minimum_required(VERSION 3.15)
#   include(${CMAKE_CURRENT_SOURCE_DIR}/../shared/cmake/Common.cmake)
#   project(Site LANGUAGES CXX)
#   puzzles_init()
#   puzzles_add_puzzle(<target> <puzzle dir>)   # once per puzzle directory

get_filename_component(PUZZLES_ROOT "${CMAKE_CURRENT_LIST_DIR}/../.." ABSOLUTE)

# Call after project(): defines flags, shared library and output directories.
macro(puzzles_init)
    set(CMAKE_CXX_STANDARD 23)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
    set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

    include(FetchContent)
    FetchContent_Declare(fmt
        GIT_REPOSITORY https://github.com/fmtlib/fmt.git
        GIT_TAG 12.2.0
    )
    FetchContent_MakeAvailable(fmt)
    find_program(PUZZLES_RUSTC rustc)

    add_library(compile_flags_interface INTERFACE)
    target_compile_options(compile_flags_interface INTERFACE
        -Wall
        -Wextra
        -Wshadow
        -Wnon-virtual-dtor
        -Wold-style-cast
        -Wcast-align
        -Woverloaded-virtual
        -Wmisleading-indentation
        -Wnull-dereference
        -pedantic
        $<$<CONFIG:DEBUG>:-g>
        $<$<CONFIG:RELEASE>:-O3>
    )

    add_library(aoc_utils ${PUZZLES_ROOT}/shared/src/utils.cpp)
    target_include_directories(aoc_utils PUBLIC ${PUZZLES_ROOT}/shared/include)
    target_link_libraries(aoc_utils PUBLIC compile_flags_interface)
endmacro()

# Adds <target> (C++) for DIR/solve.cpp and <target>_rs (Rust) for DIR/solve.rs,
# whichever exist.
function(puzzles_add_puzzle TARGET DIR)
    if(EXISTS ${DIR}/solve.cpp)
        add_executable(${TARGET} ${DIR}/solve.cpp)
        target_link_libraries(${TARGET} PRIVATE compile_flags_interface fmt::fmt aoc_utils)
    endif()

    if(EXISTS ${DIR}/solve.rs AND PUZZLES_RUSTC)
        set(OUT ${PROJECT_SOURCE_DIR}/bin/${TARGET}_rs)
        add_custom_command(
            OUTPUT ${OUT}
            COMMAND ${CMAKE_COMMAND} -E make_directory ${PROJECT_SOURCE_DIR}/bin
            COMMAND ${PUZZLES_RUSTC} -O ${DIR}/solve.rs -o ${OUT}
            DEPENDS ${DIR}/solve.rs
            COMMENT "Building ${TARGET}_rs"
        )
        add_custom_target(${TARGET}_rs ALL DEPENDS ${OUT})
    endif()
endfunction()
