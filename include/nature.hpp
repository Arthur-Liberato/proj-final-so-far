#ifndef NATURE_H
#define NATURE_H

#include <string>
#include "utils.hpp"

class Nature {
private:
    std::string nome;
    std::string aumento;
    std::string diminuicao;

public:
    Nature() = default;
    static Nature fromCSV(const std::string& linha);
    
    // Getters
    std::string getNome() const { return nome; }
    std::string getAumento() const { return aumento; }
    std::string getDiminuicao() const { return diminuicao; }
};

#endif