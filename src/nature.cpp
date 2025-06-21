#include "nature.hpp"
#include <sstream>
#include <string>

Nature Nature::fromCSV(const std::string& linha) {
    Nature n;
    std::stringstream ss(linha);
    std::string token;

    getline(ss, n.nome, ',');
    getline(ss, n.aumento, ',');
    getline(ss, n.diminuicao, ',');

    // Limpar e remover espaços em branco
    n.nome = Utils::trim(n.nome);
    n.aumento = Utils::trim(n.aumento);
    n.diminuicao = Utils::trim(n.diminuicao);

    return n;
}