cmake_minimum_required(VERSION 3.0.0)
project(imgregist VERSION 0.1.0)

include_directories(third_party/cimg)
add_subdirectory(third_party)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

add_subdirectory(src)
add_subdirectory(tests)
