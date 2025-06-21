#ifndef POKEBLOCK_H
#define POKEBLOCK_H

#include <string>
#include "utils.hpp"

class Pokeblock {
private:
    int id;
    std::string nome;
    std::string cor;
    int nivel;
    int picante;
    int seco;
    int doce;
    int amargo;
    int azedo;
    std::string condicao;
    std::string efeito;
    std::string raridade;

public:
    Pokeblock() = default;
    static Pokeblock fromCSV(const std::string& linha);
    
    // Getters
    int getId() const { return id; }
    std::string getNome() const { return nome; }
    std::string getCor() const { return cor; }
    int getNivel() const { return nivel; }
    int getPicante() const { return picante; }
    int getSeco() const { return seco; }
    int getDoce() const { return doce; }
    int getAmargo() const { return amargo; }
    int getAzedo() const { return azedo; }
    std::string getCondicao() const { return condicao; }
    std::string getEfeito() const { return efeito; }
    std::string getRaridade() const { return raridade; }
};

#endif