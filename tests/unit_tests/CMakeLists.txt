enable_testing()
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(Unit_Tests_run
#        test_tournament.cpp
#        test_vertex_cover.cpp
#        test_connected_components.cpp
        test_graphs.cpp
        test_generators_classic.cpp utils.h utils.cpp itertools.h)

target_link_libraries(Unit_Tests_run gtest gtest_main)
target_link_libraries(Unit_Tests_run ${CMAKE_PROJECT_NAME}_lib)
add_test(Unit_Tests_run Unit_Tests_run)