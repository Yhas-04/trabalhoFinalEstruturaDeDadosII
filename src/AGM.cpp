#include "AGM.h"

std::vector<Aresta> AGM::calcular(const Grafo& grafo) {
    std::vector<Aresta> resultado;
    std::unordered_set<std::string> visitado;

    auto cmp = [](const Aresta& a, const Aresta& b) {
        return a.peso > b.peso;
    };
    std::priority_queue<Aresta, std::vector<Aresta>, decltype(cmp)> pq(cmp);

    const auto& casas = grafo.getCasas();
    const auto& arestas = grafo.getArestas();

    if (casas.empty()) return resultado;

    visitado.insert(casas[0]);

    for (const auto& a : arestas) {
        if (a.casa1 == casas[0] || a.casa2 == casas[0])
            pq.push(a);
    }

    while (!pq.empty() && visitado.size() < casas.size()) {
        Aresta atual = pq.top(); pq.pop();

        std::string novoNo = "";
        if (visitado.count(atual.casa1) && !visitado.count(atual.casa2)) {
            novoNo = atual.casa2;
        } else if (visitado.count(atual.casa2) && !visitado.count(atual.casa1)) {
            novoNo = atual.casa1;
        }

        if (!novoNo.empty()) {
            visitado.insert(novoNo);
            resultado.push_back(atual);

            for (const auto& a : arestas) {
                if ((a.casa1 == novoNo && !visitado.count(a.casa2)) ||
                    (a.casa2 == novoNo && !visitado.count(a.casa1))) {
                    pq.push(a);
                }
            }
        }
    }

    return resultado;
}
