#include "Arvore.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Arvore::Arvore() : raiz(nullptr) {}

noArvore* Arvore::getRaiz() const {
    return raiz;
}

noArvore* Arvore::criarNo(const std::string& nome, bool ehCasa, int numCasa){
    if(!raiz){
        raiz = new noArvore(nome, ehCasa, numCasa);
        return raiz;
    }
    inserirNo(raiz, nome, ehCasa, numCasa);
    return raiz;
}

void Arvore::inserirNo(noArvore*& atual, const std::string& nome, bool ehCasa, int numCasa){
    if(!atual){
        atual = new noArvore(nome, ehCasa, numCasa);
        return;
    }
    if(numCasa < atual->numCasa){
        inserirNo(atual->esquerdo, nome, ehCasa, numCasa);
    }
    else if(numCasa > atual->numCasa) {
        inserirNo(atual->direito, nome, ehCasa, numCasa);
    }
}

char nome = 'a';
void Arvore::inserirExemplos(){
    bool ehCasa = false;
    srand(time(nullptr));
    int n;
    for(int i=0; i<2; i++){
        std::string nomeStr(1, nome);
        int n = (0) + rand() % (100 - 0 +1);
        criarNo(nomeStr, ehCasa, n);
        ehCasa = !ehCasa;
        nome++;
    }
}

void Arvore::imprimir(noArvore* no, int nivel){
    if (!no) return;
    imprimir(no->direito, nivel + 1);
    for (int i = 0; i < nivel; ++i) std::cout << "   ";
    std::cout << no->nome << " (" << no->numCasa << ")\n";
    imprimir(no->esquerdo, nivel + 1);
}

noArvore* Arvore::buscarPorNome(noArvore* no, const std::string& nome) {
    if (!no) return nullptr;
    if (no->nome == nome) return no;
    noArvore* esq = buscarPorNome(no->esquerdo, nome);
    if (esq) return esq;
    return buscarPorNome(no->direito, nome);
}

noArvore* Arvore::minValueNode(noArvore* node) {
    noArvore* current = node;
    while (current && current->esquerdo != nullptr)
        current = current->esquerdo;
    return current;
}

noArvore* Arvore::removerNoRec(noArvore* raiz, int numCasa) {
    if (!raiz) return raiz;

    if (numCasa < raiz->numCasa) {
        raiz->esquerdo = removerNoRec(raiz->esquerdo, numCasa);
    } else if (numCasa > raiz->numCasa) {
        raiz->direito = removerNoRec(raiz->direito, numCasa);
    } else {
        if (!raiz->esquerdo) {
            noArvore* temp = raiz->direito;
            delete raiz;
            return temp;
        } else if (!raiz->direito) {
            noArvore* temp = raiz->esquerdo;
            delete raiz;
            return temp;
        }

        noArvore* temp = minValueNode(raiz->direito);

        raiz->nome = temp->nome;
        raiz->ehCasa = temp->ehCasa;
        raiz->numCasa = temp->numCasa;

        raiz->direito = removerNoRec(raiz->direito, temp->numCasa);
    }
    return raiz;
}

bool Arvore::removerPorNome(const std::string& nome) {
    noArvore* no = buscarPorNome(raiz, nome);
    if (!no) return false;

    raiz = removerNoRec(raiz, no->numCasa);
    return true;
}

void Arvore::libera(noArvore* no) {
    if (!no) return;
    libera(no->esquerdo);
    libera(no->direito);
    delete no;
}

Arvore::~Arvore() {
    libera(raiz);
}
