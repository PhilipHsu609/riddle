cmake_minimum_required(VERSION 3.15)
include(${CMAKE_CURRENT_SOURCE_DIR}/../shared/cmake/Common.cmake)
project(EverybodyCodes LANGUAGES CXX)
puzzles_init()

# <year>/QuestNN/solve.{cpp,rs}  ->  ec_<year>_q<N>
file(GLOB PUZZLES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/[0-9][0-9][0-9][0-9]/Quest[0-9]*)
foreach(DIR ${PUZZLES})
    if(IS_DIRECTORY ${DIR} AND DIR MATCHES "/([0-9]+)/Quest0*([0-9]+)$")
        puzzles_add_puzzle(ec_${CMAKE_MATCH_1}_q${CMAKE_MATCH_2} ${DIR})
    endif()
endforeach()
