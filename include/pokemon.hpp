#ifndef POKEMON_H
#define POKEMON_H

#include <string>
#include "utils.hpp"

class Pokemon {
private:
    int id;
    std::string nome;
    std::string tipo1;
    std::string tipo2;
    int hp;
    int attack;
    int spAttack;
    int defense;
    int spDefense;
    int speed;
    std::string abilities;
    std::string category;
    std::string evolutions;
    int contestBeauty;
    int contestCool;
    int contestCute;
    int contestSmart;
    int contestTough;
    std::string resistances;
    std::string weaknesses;

public:
    Pokemon() = default;
    static Pokemon fromCSV(const std::string& linha);
    
    // Getters
    int getId() const { return id; }
    std::string getNome() const { return nome; }
    std::string getTipo1() const { return tipo1; }
    std::string getTipo2() const { return tipo2; }
    int getHp() const { return hp; }
    int getAttack() const { return attack; }
    int getSpAttack() const { return spAttack; }
    int getDefense() const { return defense; }
    int getSpDefense() const { return spDefense; }
    int getSpeed() const { return speed; }
    std::string getAbilities() const { return abilities; }
    std::string getCategory() const { return category; }
    std::string getEvolutions() const { return evolutions; }
    int getContestBeauty() const { return contestBeauty; }
    int getContestCool() const { return contestCool; }
    int getContestCute() const { return contestCute; }
    int getContestSmart() const { return contestSmart; }
    int getContestTough() const { return contestTough; }
    std::string getResistances() const { return resistances; }
    std::string getWeaknesses() const { return weaknesses; }
};

#endif