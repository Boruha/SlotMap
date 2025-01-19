
set(TARGET_NAME_BENCHMARK_TEST slotmap-benchmark-test)
add_executable(${TARGET_NAME_BENCHMARK_TEST})

find_package(benchmark REQUIRED)

file(GLOB BENCHMARK_TEST_CPP_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

target_include_directories(${TARGET_NAME_BENCHMARK_TEST}
    PRIVATE
        ${INCLUDE_DIR})

target_sources(${TARGET_NAME_BENCHMARK_TEST}
    PRIVATE
        ${HPP_FILES}
        ${BENCHMARK_TEST_CPP_FILES}
        main.cpp)

target_link_libraries(${TARGET_NAME_BENCHMARK_TEST} 
    PRIVATE
        benchmark::benchmark)
        
