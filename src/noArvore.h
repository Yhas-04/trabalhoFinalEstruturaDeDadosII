#pragma once
#include <string>

struct noArvore {
    std::string nome;
    bool ehCasa;
    int numCasa;
    noArvore* esquerdo;
    noArvore* direito;

    noArvore(const std::string& nome, bool ehCasa = false, int numCasa = -1)
        : nome(nome), ehCasa(ehCasa), numCasa(numCasa), esquerdo(nullptr), direito(nullptr) {}
};
