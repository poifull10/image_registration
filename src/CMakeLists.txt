set(CMAKE_CXX_STANDARD 17)
include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/third_party/cimg)
include_directories(${CMAKE_SOURCE_DIR}/third_party/eigen)
file(GLOB SRCS ${CMAKE_SOURCE_DIR}/src/*.cpp)
add_library(imgregist ${SRCS})