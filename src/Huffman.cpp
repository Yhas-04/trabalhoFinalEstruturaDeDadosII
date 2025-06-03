#include "Huffman.h"

HuffmanNode* criarArvore(const std::unordered_map<std::string, int>& frequencias) {
    std::priority_queue<HuffmanNode*, std::vector<HuffmanNode*>, Comparador> fila;

    for (const auto& [simbolo, freq] : frequencias) {
        fila.push(new HuffmanNode(simbolo, freq));
    }

    while (fila.size() > 1) {
        HuffmanNode* esq = fila.top(); fila.pop();
        HuffmanNode* dir = fila.top(); fila.pop();

        auto* novo = new HuffmanNode("", esq->frequencia + dir->frequencia);
        novo->esquerda = esq;
        novo->direita = dir;

        fila.push(novo);
    }

    return fila.empty() ? nullptr : fila.top();
}

void Huffman::gerarCodigos(HuffmanNode* raiz, const std::string& prefixo, std::unordered_map<std::string, std::string>& codigos) {
    if (!raiz) return;

    if (!raiz->esquerda && !raiz->direita) {
        codigos[raiz->simbolo] = prefixo;
    }

    gerarCodigos(raiz->esquerda, prefixo + "0", codigos);
    gerarCodigos(raiz->direita, prefixo + "1", codigos);
}

void Huffman::liberar(HuffmanNode* raiz) {
    if (!raiz) return;
    liberar(raiz->esquerda);
    liberar(raiz->direita);
    delete raiz;
}

std::unordered_map<std::string, std::string> Huffman::construir(const std::unordered_map<std::string, int>& frequencias) {
    HuffmanNode* raiz = criarArvore(frequencias);
    std::unordered_map<std::string, std::string> codigos;
    gerarCodigos(raiz, "", codigos);
    liberar(raiz);
    return codigos;
}
