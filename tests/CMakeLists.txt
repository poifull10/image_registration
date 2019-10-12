
set(CMAKE_CXX_STANDARD 17)
file(GLOB TESTS ${CMAKE_SOURCE_DIR}/tests/*.cpp)

include_directories(${PROJECT_SOURCE_DIR}/third_party/googletest/googletest/include)
include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/third_party/cimg)
include_directories(${CMAKE_SOURCE_DIR}/third_party/eigen)

add_executable(tester ${TESTS})
target_link_libraries(tester gtest)
target_link_libraries(tester imgregist)
