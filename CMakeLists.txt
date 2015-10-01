cmake_minimum_required(VERSION 2.8)

project(testa_pilha)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(INCLUDE_DIR include)
include_directories (${INCLUDE_DIR})

ADD_SUBDIRECTORY(whattotest)

# Link runTests with what we want to test and the GTest and pthread library
add_executable(testa_pilha tests.cpp)
target_link_libraries(testa_pilha ${GTEST_LIBRARIES} pthread whattotest)

install(TARGETS testa_pilha DESTINATION bin)
