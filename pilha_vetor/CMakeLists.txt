add_library(pilha_vetor STATIC pilha_vetor.cpp)

install(TARGETS pilha_vetor DESTINATION lib)
install(FILES pilha_vetor.h DESTINATION include)
