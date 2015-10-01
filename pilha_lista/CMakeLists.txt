cmake_minimum_required(VERSION 2.8)

project(pilha_lista)

add_library(pilha_lista STATIC pilha_lista.c)

install(TARGETS pilha_lista DESTINATION lib)
install(FILES pilha_lista.h DESTINATION include)
