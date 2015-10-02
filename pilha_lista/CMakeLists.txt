add_library(pilha_lista STATIC pilha_lista.cpp)

install(TARGETS pilha_lista DESTINATION lib)
install(FILES pilha_lista.h DESTINATION include)
