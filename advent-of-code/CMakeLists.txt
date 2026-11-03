cmake_minimum_required(VERSION 3.15)
include(${CMAKE_CURRENT_SOURCE_DIR}/../shared/cmake/Common.cmake)
project(AdventOfCode LANGUAGES CXX)
puzzles_init()

# <year>/DayNN/solve.{cpp,rs}  ->  aoc_<year>_d<N>
file(GLOB PUZZLES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/[0-9][0-9][0-9][0-9]/Day[0-9]*)
foreach(DIR ${PUZZLES})
    if(IS_DIRECTORY ${DIR} AND DIR MATCHES "/([0-9]+)/Day0*([0-9]+)$")
        puzzles_add_puzzle(aoc_${CMAKE_MATCH_1}_d${CMAKE_MATCH_2} ${DIR})
    endif()
endforeach()
