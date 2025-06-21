#ifndef ITEM_H
#define ITEM_H

#include <string>
#include "utils.hpp"

class Item {
private:
    int id;
    std::string nome;
    std::string categoria;
    int preco;
    std::string raridade;
    std::string efeitoContest;
    std::string descricao;

public:
    Item() = default;
    static Item fromCSV(const std::string& linha);
    
    // Getters
    int getId() const { return id; }
    std::string getNome() const { return nome; }
    std::string getCategoria() const { return categoria; }
    int getPreco() const { return preco; }
    std::string getRaridade() const { return raridade; }
    std::string getEfeitoContest() const { return efeitoContest; }
    std::string getDescricao() const { return descricao; }
};

#endif