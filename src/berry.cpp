#include "berry.hpp"
#include <sstream>
#include <string>
#include <stdexcept>

Berry Berry::fromCSV(const std::string& linha) {
    Berry b;
    std::stringstream ss(linha);
    std::string token;

    getline(ss, token, ','); b.id = Utils::safeStoi(token, "ID");
    getline(ss, b.nome, ',');
    getline(ss, token, ','); b.picante = Utils::safeStoi(token, "Picante");
    getline(ss, token, ','); b.seco = Utils::safeStoi(token, "Seco");
    getline(ss, token, ','); b.doce = Utils::safeStoi(token, "Doce");
    getline(ss, token, ','); b.amargo = Utils::safeStoi(token, "Amargo");
    getline(ss, token, ','); b.azedo = Utils::safeStoi(token, "Azedo");
    getline(ss, b.raridade, ',');
    getline(ss, b.descricao, ',');

    if(b.nome.empty()) {
        throw std::invalid_argument("Campo Nome da berry nao pode ser vazio");
    }
    if(b.raridade.empty()) {
        throw std::invalid_argument("Campo Raridade da berry nao pode ser vazio");
    }
    if(b.descricao.empty()) {
        throw std::invalid_argument("Campo Descricao da berry nao pode ser vazio");
    } 
        

    // Limpar strings
    b.nome = Utils::trim(b.nome);
    b.raridade = Utils::trim(b.raridade);
    b.descricao = Utils::trim(b.descricao);

    return b;
}