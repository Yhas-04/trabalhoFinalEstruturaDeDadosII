#ifndef GRAFO_H
#define GRAFO_H

#include "Arvore.h"
#include <vector>
#include <string>
#include <unordered_map>

struct Aresta {
    std::string casa1, casa2;
    int peso;
};

class Grafo {
public:
    Grafo() = default;
    Grafo(Arvore* arv);

    std::vector<Aresta> getArestas() const { return arestas; }
    std::vector<std::string> getCasas() const { return casas; }
    void removerVertice(const std::string& nome);
    std::vector<std::string> caminhoMinimo(const std::string& origem, const std::string& destino);
    int contaAncestraisComuns(const std::vector<noArvore*>& path1, const std::vector<noArvore*>& path2);

private:
    std::vector<std::string> casas;
    std::vector<Aresta> arestas;

    void coletaCasas(noArvore* no, std::vector<noArvore*>& lista);
    bool caminho(noArvore* raiz, const std::string& nome, std::vector<noArvore*>& path);
    noArvore* lca(noArvore* raiz, const std::string& nome1, const std::string& nome2);
    int distanciaEntre(noArvore* raiz, const std::string& nome1, const std::string& nome2);
    int profundidade(noArvore* raiz, const std::string& nome, int nivel);
};

#endif // GRAFO_H
