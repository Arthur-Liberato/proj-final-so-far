#include "nature.hpp"
#include <sstream>
#include <string>
#include <stdexcept>

Nature Nature::fromCSV(const std::string& linha) {
    Nature n;
    std::stringstream ss(linha);
    std::string token;

    getline(ss, n.nome, ',');
    getline(ss, n.aumento, ',');
    getline(ss, n.diminuicao, ',');

    if(n.nome.empty()) throw std::invalid_argument("Campo Nome do nature nao pode ser vazio");
    if(n.aumento.empty()) throw std::invalid_argument("Campo Aumento do nature nao pode ser vazio");
    if(n.diminuicao.empty()) throw std::invalid_argument("Campo Diminuicao do nature nao pode ser vazio");

    // Limpar e remover espaços em branco
    n.nome = Utils::trim(n.nome);
    n.aumento = Utils::trim(n.aumento);
    n.diminuicao = Utils::trim(n.diminuicao);

    return n;
}