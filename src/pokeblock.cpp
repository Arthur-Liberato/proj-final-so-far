#include "pokeblock.hpp"
#include <sstream>
#include <string>

Pokeblock Pokeblock::fromCSV(const std::string& linha) {
    Pokeblock p;
    std::stringstream ss(linha);
    std::string token;

    getline(ss, token, ','); p.id = Utils::safeStoi(token, "ID");
    getline(ss, p.nome, ',');
    getline(ss, p.cor, ',');
    getline(ss, token, ','); p.nivel = Utils::safeStoi(token, "Nivel");
    getline(ss, token, ','); p.picante = Utils::safeStoi(token, "Picante");
    getline(ss, token, ','); p.seco = Utils::safeStoi(token, "Seco");
    getline(ss, token, ','); p.doce = Utils::safeStoi(token, "Doce");
    getline(ss, token, ','); p.amargo = Utils::safeStoi(token, "Amargo");
    getline(ss, token, ','); p.azedo = Utils::safeStoi(token, "Azedo");
    getline(ss, p.condicao, ',');
    getline(ss, p.efeito, ',');
    getline(ss, p.raridade, ',');

    if(p.nome.empty()) throw std::invalid_argument("Campo Nome do Pokeblock nao pode ser vazio");
    if(p.cor.empty()) throw std::invalid_argument("Campo Cor do Pokeblock nao pode ser vazio");
    if(p.condicao.empty()) throw std::invalid_argument("Campo Condicao do Pokeblock nao pode ser vazio");
    if(p.efeito.empty()) throw std::invalid_argument("Campo Efeito do Pokeblock nao pode ser vazio");
    if(p.raridade.empty()) throw std::invalid_argument("Campo Raridade do Pokeblock nao pode ser vazio");


    // Limpar strings
    p.nome = Utils::trim(p.nome);
    p.cor = Utils::trim(p.cor);
    p.condicao = Utils::trim(p.condicao);
    p.efeito = Utils::trim(p.efeito);
    p.raridade = Utils::trim(p.raridade);

    return p;
}