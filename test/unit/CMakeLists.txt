
set(TARGET_NAME_UNIT_TEST slotmap-unit-test)
add_executable(${TARGET_NAME_UNIT_TEST})

find_package(GTest REQUIRED)

file(GLOB UNIT_TEST_CPP_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

target_include_directories(${TARGET_NAME_UNIT_TEST}
    PRIVATE
        ${INCLUDE_DIR})

target_sources(${TARGET_NAME_UNIT_TEST}
    PRIVATE
        ${HPP_FILES}
        ${UNIT_TEST_CPP_FILES}
        main.cpp)

target_link_libraries(${TARGET_NAME_UNIT_TEST} 
    PRIVATE
        gtest::gtest)
        
