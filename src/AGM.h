#pragma once
#include "Grafo.h"
#include <vector>
#include <unordered_set>
#include <queue>

class AGM{
public:
    static std::vector<Aresta> calcular(const Grafo& grafo);
};
