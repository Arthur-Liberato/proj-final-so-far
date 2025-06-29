#include "item.hpp"
#include <sstream>
#include <string>
#include <stdexcept>

Item Item::fromCSV(const std::string& linha) {
    Item item;
    std::stringstream ss(linha);
    std::string token;

    getline(ss, token, ','); item.id = Utils::safeStoi(token, "ID");
    getline(ss, item.nome, ',');
    getline(ss, item.categoria, ',');
    getline(ss, token, ','); item.preco = Utils::safeStoi(token, "Preço");
    getline(ss, item.raridade, ',');
    getline(ss, item.efeitoContest, ',');
    getline(ss, item.descricao, ',');

    if(item.nome.empty()) throw std::invalid_argument("Campo Nome do Item nao pode ser vazio");
    if(item.categoria.empty()) throw std::invalid_argument("Campo Categoria do Item nao pode ser vazio");
    if(item.raridade.empty()) throw std::invalid_argument("Campo Raridade do Item nao pode ser vazio");
    if(item.efeitoContest.empty()) throw std::invalid_argument("Campo Efeito Contest do Item nao pode ser vazio");
    if(item.descricao.empty()) throw std::invalid_argument("Campo Descricao do Item nao pode ser vazio");
    

    // Limpar strings
    item.nome = Utils::trim(item.nome);
    item.categoria = Utils::trim(item.categoria);
    item.raridade = Utils::trim(item.raridade);
    item.efeitoContest = Utils::trim(item.efeitoContest);
    item.descricao = Utils::trim(item.descricao);

    return item;
}