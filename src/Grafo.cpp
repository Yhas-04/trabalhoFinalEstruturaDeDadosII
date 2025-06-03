#include "Grafo.h"
#include "Arvore.h"
#include <queue>
#include <set>
#include <iostream>
#include <cstdlib>
#include <queue>
#include <limits>
#include <unordered_map>
#include <algorithm>

Grafo::Grafo(Arvore* arv) {
    std::vector<noArvore*> listaCasas;
    coletaCasas(arv->getRaiz(), listaCasas);

    for (size_t i = 0; i < listaCasas.size(); ++i) {
        for (size_t j = i + 1; j < listaCasas.size(); ++j) {
            int dist = distanciaEntre(arv->getRaiz(), listaCasas[i]->nome, listaCasas[j]->nome);
            arestas.push_back({listaCasas[i]->nome, listaCasas[j]->nome, dist});
        }
    }

    for (size_t i = 0; i < listaCasas.size(); ++i) {
        for (size_t j = i + 1; j < listaCasas.size(); ++j) {
            int dist = distanciaEntre(arv->getRaiz(), listaCasas[i]->nome, listaCasas[j]->nome);
            arestas.push_back({listaCasas[i]->nome, listaCasas[j]->nome, dist});
        }
    }
}

noArvore* Grafo::lca(noArvore* raiz, const std::string& nome1, const std::string& nome2) {
    if (!raiz) return nullptr;
    if (raiz->nome == nome1 || raiz->nome == nome2)
        return raiz;
    noArvore* esq = lca(raiz->esquerdo, nome1, nome2);
    noArvore* dir = lca(raiz->direito, nome1, nome2);
    if (esq && dir) return raiz;
    return esq ? esq : dir;
}

int Grafo::distanciaEntre(noArvore* raiz, const std::string& nome1, const std::string& nome2) {
    noArvore* ancestor = lca(raiz, nome1, nome2);
    std::vector<noArvore*> path1, path2;
    caminho(ancestor, nome1, path1);
    caminho(ancestor, nome2, path2);
    return path1.size() + path2.size() - 1;
}

void Grafo::coletaCasas(noArvore* no, std::vector<noArvore*>& listaCasas) {
    if (!no) return;
    if (no->ehCasa) {
        casas.push_back(no->nome);
        listaCasas.push_back(no);
    }
    coletaCasas(no->esquerdo, listaCasas);
    coletaCasas(no->direito, listaCasas);
}

std::vector<std::string> Grafo::caminhoMinimo(const std::string& origem, const std::string& destino) {
    std::unordered_map<std::string, int> dist;
    std::unordered_map<std::string, std::string> prev;
    for (const auto& c : casas) dist[c] = std::numeric_limits<int>::max();
    dist[origem] = 0;

    using P = std::pair<int, std::string>;
    std::priority_queue<P, std::vector<P>, std::greater<P>> pq;
    pq.push({0, origem});

    std::unordered_map<std::string, std::vector<std::pair<std::string, int>>> adj;
    for (const auto& a : arestas) {
        adj[a.casa1].push_back({a.casa2, a.peso});
        adj[a.casa2].push_back({a.casa1, a.peso});
    }

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;
        for (auto [v, peso] : adj[u]) {
            if (dist[u] + peso < dist[v]) {
                dist[v] = dist[u] + peso;
                prev[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    std::vector<std::string> caminho;
    for (std::string at = destino; !at.empty(); at = prev[at]) {
        caminho.push_back(at);
        if (at == origem) break;
    }
    std::reverse(caminho.begin(), caminho.end());
    if (caminho.front() != origem) caminho.clear();
    return caminho;
}

bool Grafo::caminho(noArvore* raiz, const std::string& nome, std::vector<noArvore*>& path) {
    if (!raiz) return false;
    path.push_back(raiz);
    if (raiz->nome == nome)
        return true;
    if (caminho(raiz->esquerdo, nome, path) || caminho(raiz->direito, nome, path))
        return true;
    path.pop_back();
    return false;
}

