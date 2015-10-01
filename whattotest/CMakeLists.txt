cmake_minimum_required(VERSION 2.8)

project(whattotest)

add_library(whattotest STATIC whattotest.cpp)

install(TARGETS whattotest DESTINATION lib)
install(FILES whattotest.h DESTINATION include)
