#include "item.hpp"
#include <sstream>
#include <string>

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

    // Limpar strings
    item.nome = Utils::trim(item.nome);
    item.categoria = Utils::trim(item.categoria);
    item.raridade = Utils::trim(item.raridade);
    item.efeitoContest = Utils::trim(item.efeitoContest);
    item.descricao = Utils::trim(item.descricao);

    return item;
}