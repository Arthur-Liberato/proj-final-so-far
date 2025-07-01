#ifndef POKEMONJOGADOR_H
#define POKEMONJOGADOR_H

#include <string>
#include "pokemon.hpp"

/**
 * @class PokemonJogador
 * @brief Representa um Pokémon capturado/treinado por um jogador, com estatísticas
 *        calculadas (IVs, stats finais, nível, habilidade e natureza).
 */
class PokemonJogador {
private:
    Pokemon base;          /**< Dados básicos do Pokémon (nome, tipos, estatísticas base, etc.) */
    int level;             /**< Nível atual do Pokémon */
    int ivHP;              /**< Valor individual (IV) de HP */
    int ivAttack;          /**< Valor individual (IV) de Attack */
    int ivSpAttack;        /**< Valor individual (IV) de Special Attack */
    int ivDefense;         /**< Valor individual (IV) de Defense */
    int ivSpDefense;       /**< Valor individual (IV) de Special Defense */
    int ivSpeed;           /**< Valor individual (IV) de Speed */
    std::string habilidade;/**< Habilidade especial (Ability) do Pokémon */
    int currentHP;         /**< HP atual durante batalhas */
    int maxHP;             /**< HP máximo calculado */
    int attack;            /**< Attack final calculado */
    int spAttack;          /**< Special Attack final calculado */
    int defense;           /**< Defense final calculado */
    int spDefense;         /**< Special Defense final calculado */
    int speed;             /**< Speed final calculado */
    std::string natureza;  /**< Natureza aplicada ao cálculo de stats */

public:
    /** @name Getters */
    ///@{
    /** @brief Retorna os dados básicos do Pokémon. */
    Pokemon getBase() const { return base; }

    /** @brief Retorna o nível atual. */
    int getLevel() const { return level; }

    /** @brief Retorna o IV de HP. */
    int getIvHP() const { return ivHP; }

    /** @brief Retorna o IV de Attack. */
    int getIvAttack() const { return ivAttack; }

    /** @brief Retorna o IV de Special Attack. */
    int getIvSpAttack() const { return ivSpAttack; }

    /** @brief Retorna o IV de Defense. */
    int getIvDefense() const { return ivDefense; }

    /** @brief Retorna o IV de Special Defense. */
    int getIvSpDefense() const { return ivSpDefense; }

    /** @brief Retorna o IV de Speed. */
    int getIvSpeed() const { return ivSpeed; }

    /** @brief Retorna a habilidade (Ability). */
    std::string getHabilidade() const { return habilidade; }

    /** @brief Retorna o HP atual. */
    int getCurrentHP() const { return currentHP; }

    /** @brief Retorna o HP máximo calculado. */
    int getMaxHP() const { return maxHP; }

    /** @brief Retorna o Attack calculado. */
    int getAttack() const { return attack; }

    /** @brief Retorna o Special Attack calculado. */
    int getSpAttack() const { return spAttack; }

    /** @brief Retorna o Defense calculado. */
    int getDefense() const { return defense; }

    /** @brief Retorna o Special Defense calculado. */
    int getSpDefense() const { return spDefense; }

    /** @brief Retorna o Speed calculado. */
    int getSpeed() const { return speed; }

    /** @brief Retorna a Natureza aplicada. */
    std::string getNatureza() const { return natureza; }
    ///@}

    /** @name Setters */
    ///@{
    /** @brief Define os dados básicos do Pokémon. */
    void setBase(Pokemon b) { base = b; }

    /** @brief Define o nível. */
    void setLevel(int l) { level = l; }

    /** @brief Define o IV de HP. */
    void setIvHP(int iv) { ivHP = iv; }

    /** @brief Define o IV de Attack. */
    void setIvAttack(int iv) { ivAttack = iv; }

    /** @brief Define o IV de Special Attack. */
    void setIvSpAttack(int iv) { ivSpAttack = iv; }

    /** @brief Define o IV de Defense. */
    void setIvDefense(int iv) { ivDefense = iv; }

    /** @brief Define o IV de Special Defense. */
    void setIvSpDefense(int iv) { ivSpDefense = iv; }

    /** @brief Define o IV de Speed. */
    void setIvSpeed(int iv) { ivSpeed = iv; }

    /** @brief Define a habilidade (Ability). */
    void setHabilidade(const std::string& h) { habilidade = h; }

    /** @brief Define o HP atual. */
    void setCurrentHP(int hp) { currentHP = hp; }

    /** @brief Define o HP máximo calculado. */
    void setMaxHP(int hp) { maxHP = hp; }

    /** @brief Define o Attack calculado. */
    void setAttack(int a) { attack = a; }

    /** @brief Define o Special Attack calculado. */
    void setSpAttack(int sa) { spAttack = sa; }

    /** @brief Define o Defense calculado. */
    void setDefense(int d) { defense = d; }

    /** @brief Define o Special Defense calculado. */
    void setSpDefense(int sd) { spDefense = sd; }

    /** @brief Define o Speed calculado. */
    void setSpeed(int s) { speed = s; }

    /** @brief Define a Natureza aplicada. */
    void setNatureza(const std::string& n) { natureza = n; }
    ///@}
};

#endif // POKEMONJOGADOR_H
