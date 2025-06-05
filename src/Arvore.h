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
    noArvore* buscarPorNome(noArvore* no, const std::string& nome);
    bool removerPorNome(const std::string& nome);

private:

    noArvore* removerNoRec(noArvore* raiz, int numCasa);
    void inserirNo(noArvore*& atual, const std::string& nome, bool ehCasa, int numCasa);
    noArvore* minValueNode(noArvore* node);
    noArvore* raiz;
};
