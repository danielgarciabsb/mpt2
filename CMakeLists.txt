cmake_minimum_required(VERSION 2.8)

project(testa_pilha)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(INCLUDE_DIR include)
include_directories (${INCLUDE_DIR})

#ADD_SUBDIRECTORY(whattotest)
ADD_SUBDIRECTORY(pilha_lista)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/CMakeModules)

INCLUDE(CodeCoverage.cmake)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0 -fprofile-arcs -ftest-coverage --coverage")
SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -O0 -fprofile-arcs -ftest-coverage --coverage")
SET(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -g -O0 -fprofile-arcs -ftest-coverage --coverage")
SET(CMAKE_MODULE_LINKER_FLAGS "${CMAKE_MODULE_LINKER_FLAGS} -g -O0 -fprofile-arcs -ftest-coverage --coverage")
SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -g -O0 -fprofile-arcs -ftest-coverage --coverage")
SETUP_TARGET_FOR_COVERAGE(${PROJECT_NAME}_coverage ${PROJECT_NAME} coverage)


# Link runTests with what we want to test and the GTest and pthread library
add_executable(testa_pilha testa_pilha.cpp)
target_link_libraries(testa_pilha ${GTEST_LIBRARIES} pthread pilha_lista gcov)

install(TARGETS testa_pilha DESTINATION bin)
