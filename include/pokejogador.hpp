#ifndef POKEMONJOGADOR_H
#define POKEMONJOGADOR_H

#include "pokemon.hpp"

class PokemonJogador {
private:
    Pokemon base;
    int level;
    int ivHP;
    int ivAttack;
    int ivSpAttack;
    int ivDefense;
    int ivSpDefense;
    int ivSpeed;
    std::string habilidade;
    int currentHP;
    int maxHP;
    int attack;
    int spAttack;
    int defense;
    int spDefense;
    int speed;
    std::string natureza;

public:
    // Getters e Setters
    Pokemon getBase() const { return base; }
    int getLevel() const { return level; }
    int getIvHP() const { return ivHP; }
    int getIvAttack() const { return ivAttack; }
    int getIvSpAttack() const { return ivSpAttack; }
    int getIvDefense() const { return ivDefense; }
    int getIvSpDefense() const { return ivSpDefense; }
    int getIvSpeed() const { return ivSpeed; }
    std::string getHabilidade() const { return habilidade; }
    int getCurrentHP() const { return currentHP; }
    int getMaxHP() const { return maxHP; }
    int getAttack() const { return attack; }
    int getSpAttack() const { return spAttack; }
    int getDefense() const { return defense; }
    int getSpDefense() const { return spDefense; }
    int getSpeed() const { return speed; }
    std::string getNatureza() const { return natureza; }

    void setBase(Pokemon b) { base = b; }
    void setLevel(int l) { level = l; }
    void setIvHP(int iv) { ivHP = iv; }
    void setIvAttack(int iv) { ivAttack = iv; }
    void setIvSpAttack(int iv) { ivSpAttack = iv; }
    void setIvDefense(int iv) { ivDefense = iv; }
    void setIvSpDefense(int iv) { ivSpDefense = iv; }
    void setIvSpeed(int iv) { ivSpeed = iv; }
    void setHabilidade(std::string h) { habilidade = h; }
    void setCurrentHP(int hp) { currentHP = hp; }
    void setMaxHP(int hp) { maxHP = hp; }
    void setAttack(int a) { attack = a; }
    void setSpAttack(int sa) { spAttack = sa; }
    void setDefense(int d) { defense = d; }
    void setSpDefense(int sd) { spDefense = sd; }
    void setSpeed(int s) { speed = s; }
    void setNatureza(std::string n) { natureza = n; }
};

#endif