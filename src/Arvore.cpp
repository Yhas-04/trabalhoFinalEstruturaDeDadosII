//
// Created by yhas on 6/2/25.
//

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
    if(numCasa < atual->numCasa){ inserirNo(atual->esquerdo, nome, ehCasa, numCasa);}
    else if(numCasa > atual->numCasa) { inserirNo(atual->direito, nome, ehCasa, numCasa);}
}

char nome = 'a';
void Arvore::inserirExemplos(){
    bool ehCasa = false;
    srand(time(nullptr));
    int n;
    for(int i=0; i<2; i++){
        std::string nomeStr(1, nome);
        int n = (-50) + rand() % (100 - (-50) +1);
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

noArvore* Arvore::minValueNode(noArvore* node) {
    noArvore* current = node;
    while (current && current->esquerdo != nullptr)
        current = current->esquerdo;
    return current;
}


noArvore* Arvore::removerNo(noArvore* root, int numCasa) {
    if (root == nullptr) return root;

    if (numCasa < root->numCasa) {
        root->esquerdo = removerNo(root->esquerdo, numCasa);
    } else if (numCasa > root->numCasa) {
        root->direito = removerNo(root->direito, numCasa);
    } else {

        if (root->esquerdo == nullptr) {
            noArvore* temp = root->direito;
            delete root;
            return temp;
        } else if (root->direito == nullptr) {
            noArvore* temp = root->esquerdo;
            delete root;
            return temp;
        }

        noArvore* temp = minValueNode(root->direito);

        root->nome = temp->nome;
        root->numCasa = temp->numCasa;
        root->ehCasa = temp->ehCasa;

        root->direito = removerNo(root->direito, temp->numCasa);
    }
    return root;
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
