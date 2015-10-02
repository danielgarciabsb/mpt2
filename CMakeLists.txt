cmake_minimum_required(VERSION 2.8)

# Nome do projeto
project(testa_pilha)

# Tipo da pilha: "pilha_lista" ou "pilha_vetor"
set(TIPO_PILHA pilha_lista)

# Localizar GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(INCLUDE_DIR include)
include_directories (${INCLUDE_DIR})

ADD_SUBDIRECTORY(${TIPO_PILHA})

# Configuracoes do GCOV
INCLUDE(CodeCoverage.cmake)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0 -fprofile-arcs -ftest-coverage --coverage")
SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -O0 -fprofile-arcs -ftest-coverage --coverage")
SET(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -g -O0 -fprofile-arcs -ftest-coverage --coverage")
SET(CMAKE_MODULE_LINKER_FLAGS "${CMAKE_MODULE_LINKER_FLAGS} -g -O0 -fprofile-arcs -ftest-coverage --coverage")
SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -g -O0 -fprofile-arcs -ftest-coverage --coverage")
SETUP_TARGET_FOR_COVERAGE(${PROJECT_NAME}_coverage ${PROJECT_NAME} coverage)


# Linkar projeto com a biblioteca GTest, pthread e gcov
add_executable(${PROJECT_NAME} testa_pilha.cpp)
target_link_libraries(${PROJECT_NAME} ${GTEST_LIBRARIES} pthread ${TIPO_PILHA} gcov)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)
