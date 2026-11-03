cmake_minimum_required(VERSION 3.15)
include(${CMAKE_CURRENT_SOURCE_DIR}/../shared/cmake/Common.cmake)
project(ProjectEuler LANGUAGES CXX)
puzzles_init()

# NNNN/solve.{cpp,rs}  ->  euler_<N>
file(GLOB PUZZLES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/[0-9][0-9][0-9][0-9])
foreach(DIR ${PUZZLES})
    if(IS_DIRECTORY ${DIR} AND DIR MATCHES "/0*([0-9]+)$")
        puzzles_add_puzzle(euler_${CMAKE_MATCH_1} ${DIR})
    endif()
endforeach()
