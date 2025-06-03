#pragma once
#include "noArvore.h"
#include <vector>

class Arvore {
public:
    Arvore();
    ~Arvore();

    noArvore* getRaiz() const;
    noArvore* criarNo(const std::string& nome, bool ehCasa, int numCasa);
    void inserirExemplos();
    void libera(noArvore* no);
    void imprimir(noArvore* no, int nivel );
    noArvore* removerNo(noArvore* root, int numCasa);


private:
    void inserirNo(noArvore*& atual, const std::string& nome, bool ehCasa, int numCasa);
    noArvore* minValueNode(noArvore* node);
    noArvore* raiz;
};
