#include "pokemon.hpp"
#include <sstream>
#include <string>
#include <stdexcept>

Pokemon Pokemon::fromCSV(const std::string& linha) {
    Pokemon p;
    std::stringstream ss(linha);
    std::string token;

    getline(ss, token, ','); p.id = Utils::safeStoi(token, "ID");
    getline(ss, p.nome, ',');
    getline(ss, p.tipo1, ',');
    getline(ss, p.tipo2, ',');
    getline(ss, token, ','); p.hp = Utils::safeStoi(token, "HP");
    getline(ss, token, ','); p.attack = Utils::safeStoi(token, "Attack");
    getline(ss, token, ','); p.spAttack = Utils::safeStoi(token, "SpAttack");
    getline(ss, token, ','); p.defense = Utils::safeStoi(token, "Defense");
    getline(ss, token, ','); p.spDefense = Utils::safeStoi(token, "SpDefense");
    getline(ss, token, ','); p.speed = Utils::safeStoi(token, "Speed");
    getline(ss, token, ','); p.contestBeauty = Utils::safeStoi(token, "ContestBeauty");
    getline(ss, token, ','); p.contestCool = Utils::safeStoi(token, "ContestCool");
    getline(ss, token, ','); p.contestCute = Utils::safeStoi(token, "ContestCute");
    getline(ss, token, ','); p.contestSmart = Utils::safeStoi(token, "ContestSmart");
    getline(ss, token, ','); p.contestTough = Utils::safeStoi(token, "ContestTough");
    getline(ss, p.resistances, ',');
    getline(ss, p.weaknesses, ',');
    getline(ss, p.abilities, ',');
    getline(ss, p.category, ',');
    getline(ss, p.evolutions, ',');

    if(p.nome.empty()) throw std::invalid_argument("Campo Nome do Pokemon não pode ser vazio.");
    if(p.tipo1.empty()) throw std::invalid_argument("Campo Tipo1 do Pokemon não pode ser vazio.");    
    if(p.resistances.empty()) throw std::invalid_argument("Campo Resistances do Pokemon não pode ser vazio.");
    if(p.weaknesses.empty()) throw std::invalid_argument("Campo Weaknesses do Pokemon não pode ser vazio.");
    if(p.abilities.empty()) throw std::invalid_argument("Campo Abilities do Pokemon não pode ser vazio.");
    if(p.category.empty()) throw std::invalid_argument("Campo Category do Pokemon não pode ser vazio.");    

    // Limpar strings
    p.nome = Utils::trim(p.nome);
    p.tipo1 = Utils::trim(p.tipo1);
    p.tipo2 = Utils::trim(p.tipo2);
    p.resistances = Utils::trim(p.resistances);
    p.weaknesses = Utils::trim(p.weaknesses);
    p.abilities = Utils::trim(p.abilities);
    p.category = Utils::trim(p.category);
    p.evolutions = Utils::trim(p.evolutions);

    return p;
}