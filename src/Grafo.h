#pragma once
#include <vector>
#include <map>
#include <string>
#include <string>
#include <unordered_map>

struct Aresta {
    std::string casa1;
    std::string casa2;
    int peso;
};

class Grafo {
public:
    std::vector<std::string> caminhoMinimo(const std::string& origem, const std::string& destino);
    std::vector<std::string> casas;
    std::vector<Aresta> arestas;

    Grafo() = default;
    Grafo(class Arvore* arv);

    int distanciaEntre(class noArvore* raiz, const std::string& nome1, const std::string& nome2);
    class noArvore* lca(class noArvore* raiz, const std::string& nome1, const std::string& nome2);
    bool caminho(class noArvore* raiz, const std::string& nome, std::vector<class noArvore*>& path);
private:
    void coletaCasas(noArvore* no, std::vector<noArvore*>& listaCasas);
};
