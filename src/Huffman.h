#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <string>
#include <unordered_map>
#include <queue>
#include <utility>

// Nó da árvore de Huffman
struct HuffmanNode {
    std::string simbolo;
    int frequencia;
    HuffmanNode* esquerda;
    HuffmanNode* direita;

    HuffmanNode(std::string s, int f)
        : simbolo(std::move(s)), frequencia(f), esquerda(nullptr), direita(nullptr) {}
};

// Comparador para a fila de prioridade (min-heap)
struct Comparador {
    bool operator()(HuffmanNode* a, HuffmanNode* b) {
        return a->frequencia > b->frequencia;
    }
};

// Classe principal do algoritmo de Huffman
class Huffman {
public:
    // Constrói a árvore e retorna o mapa de códigos
    std::unordered_map<std::string, std::string> construir(const std::unordered_map<std::string, int>& frequencias);

private:
    // Gera os códigos a partir da árvore
    void gerarCodigos(HuffmanNode* raiz, const std::string& prefixo, std::unordered_map<std::string, std::string>& codigos);

    // Libera memória da árvore
    void liberar(HuffmanNode* raiz);
};

#endif // HUFFMAN_H
