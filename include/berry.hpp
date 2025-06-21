#ifndef BERRY_H
#define BERRY_H

#include <string>
#include "utils.hpp"

class Berry {
private:
    int id;
    std::string nome;
    int picante;
    int seco;
    int doce;
    int amargo;
    int azedo;
    std::string raridade;
    std::string descricao;

public:
    Berry() = default;
    static Berry fromCSV(const std::string& linha);
    
    // Getters
    int getId() const { return id; }
    std::string getNome() const { return nome; }
    int getPicante() const { return picante; }
    int getSeco() const { return seco; }
    int getDoce() const { return doce; }
    int getAmargo() const { return amargo; }
    int getAzedo() const { return azedo; }
    std::string getRaridade() const { return raridade; }
    std::string getDescricao() const { return descricao; }
};

#endif