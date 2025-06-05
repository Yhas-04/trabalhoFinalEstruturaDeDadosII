#include "Grafo.h"
#include <queue>
#include <limits>
#include <unordered_map>
#include <algorithm>
#include "iostream"

Grafo::Grafo(Arvore* arv) {
    std::vector<noArvore*> listaCasas;
    coletaCasas(arv->getRaiz(), listaCasas);
    noArvore* raiz = arv->getRaiz();

    std::unordered_map<std::string, std::vector<noArvore*>> caminhos;
    for (auto casa : listaCasas) {
        std::vector<noArvore*> path;
        caminho(raiz, casa->nome, path);
        caminhos[casa->nome] = path;
    }

    for (size_t i = 0; i < listaCasas.size(); ++i) {
        for (size_t j = i + 1; j < listaCasas.size(); ++j) {
            const auto& caminho1 = caminhos[listaCasas[i]->nome];
            const auto& caminho2 = caminhos[listaCasas[j]->nome];

            int comuns = contaAncestraisComuns(caminho1, caminho2);

            if (comuns >= 2) {
                int dist = distanciaEntre(raiz, listaCasas[i]->nome, listaCasas[j]->nome);
                arestas.push_back({listaCasas[i]->nome, listaCasas[j]->nome, dist});
                std::cout << "Conectando " << listaCasas[i]->nome << " <-> " << listaCasas[j]->nome
                          << " (ancestrais em comum: " << comuns << ")\n";
            }
        }
    }

    for (auto casa : listaCasas) {
        if (casa->nome == raiz->nome) continue;

        bool jaConectado = false;
        for (auto& a : arestas) {
            if ((a.casa1 == casa->nome && a.casa2 == raiz->nome) ||
                (a.casa2 == casa->nome && a.casa1 == raiz->nome)) {
                jaConectado = true;
                break;
            }
        }

        if (!jaConectado) {
            int dist = distanciaEntre(raiz, casa->nome, raiz->nome);
            arestas.push_back({casa->nome, raiz->nome, dist});
            std::cout << "Conectando " << casa->nome << " <-> " << raiz->nome << " (conexão direta com raiz)\n";
        }
    }
}

void Grafo::removerVertice(const std::string& nome) {
    casas.erase(std::remove(casas.begin(), casas.end(), nome), casas.end());

    arestas.erase(
        std::remove_if(arestas.begin(), arestas.end(),
                       [&](const Aresta& a) {
                           return a.casa1 == nome || a.casa2 == nome;
                       }),
        arestas.end());
}

int Grafo::contaAncestraisComuns(const std::vector<noArvore*>& caminho1, const std::vector<noArvore*>& caminho2) {
    int i = 0, j = 0;
    int comuns = 0;
    while (i < (int)caminho1.size() && j < (int)caminho2.size()) {
        if (caminho1[i]->nome == caminho2[j]->nome) {
            comuns++;
            i++;
            j++;
        } else {
            break;
        }
    }
    return comuns;
}



void Grafo::coletaCasas(noArvore* no, std::vector<noArvore*>& lista) {
    if (!no) return;
    if (no->ehCasa) {
        casas.push_back(no->nome);
        lista.push_back(no);
    }
    coletaCasas(no->esquerdo, lista);
    coletaCasas(no->direito, lista);
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

bool Grafo::caminho(noArvore* raiz, const std::string& nome, std::vector<noArvore*>& path) {
    if (!raiz) return false;
    path.push_back(raiz);
    if (raiz->nome == nome) return true;
    if (caminho(raiz->esquerdo, nome, path) || caminho(raiz->direito, nome, path))
        return true;
    path.pop_back();
    return false;
}

int Grafo::profundidade(noArvore* raiz, const std::string& nome, int nivel) {
    if (!raiz) return -1;
    if (raiz->nome == nome) return nivel;
    int esq = profundidade(raiz->esquerdo, nome, nivel + 1);
    if (esq != -1) return esq;
    return profundidade(raiz->direito, nome, nivel + 1);
}

int Grafo::distanciaEntre(noArvore* raiz, const std::string& nome1, const std::string& nome2) {
    noArvore* ancestor = lca(raiz, nome1, nome2);
    std::vector<noArvore*> path1, path2;
    caminho(ancestor, nome1, path1);
    caminho(ancestor, nome2, path2);
    return path1.size() + path2.size() - 1;
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
        adj[a.casa1].emplace_back(a.casa2, a.peso);
        adj[a.casa2].emplace_back(a.casa1, a.peso);
    }

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;
        for (auto& [v, peso] : adj[u]) {
            if (dist[u] + peso < dist[v]) {
                dist[v] = dist[u] + peso;
                prev[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    std::vector<std::string> caminho;
    std::string at = destino;
    while (!at.empty()) {
        caminho.push_back(at);
        if (at == origem) break;
        if (prev.find(at) == prev.end()) {
            caminho.clear();
            break;
        }
        at = prev[at];
    }

    std::reverse(caminho.begin(), caminho.end());
    return caminho;
}

