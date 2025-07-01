#ifndef POKEMON_H
#define POKEMON_H

#include <string>
#include "utils.hpp"

/**
 * @class Pokemon
 * @brief Representa os dados básicos de um Pokémon, conforme carregados de CSV.
 *
 * Contém estatísticas base, tipos, habilidades, categorias, evoluções e
 * características de concursos e resistências/fraquezas.
 */
class Pokemon {
private:
    int id;                       /**< Identificador único do Pokémon */
    std::string nome;             /**< Nome do Pokémon */
    std::string tipo1;            /**< Tipo primário */
    std::string tipo2;            /**< Tipo secundário (pode ser vazio) */
    int hp;                       /**< HP base */
    int attack;                   /**< Attack base */
    int spAttack;                 /**< Special Attack base */
    int defense;                  /**< Defense base */
    int spDefense;                /**< Special Defense base */
    int speed;                    /**< Speed base */
    std::string abilities;        /**< Lista de habilidades (comma-separated) */
    std::string category;         /**< Categoria/classificação (ex: “Lagarto Pokémon”) */
    std::string evolutions;       /**< Evoluções possíveis (comma-separated) */
    int contestBeauty;            /**< Pontuação em Contest Beauty */
    int contestCool;              /**< Pontuação em Contest Cool */
    int contestCute;              /**< Pontuação em Contest Cute */
    int contestSmart;             /**< Pontuação em Contest Smart */
    int contestTough;             /**< Pontuação em Contest Tough */
    std::string resistances;      /**< Tipos aos quais é resistente (CSV) */
    std::string weaknesses;       /**< Tipos aos quais é fraco (CSV) */

public:
    /**
     * @brief Construtor padrão.
     */
    Pokemon() = default;

    /**
     * @brief Cria um objeto Pokemon a partir de uma linha CSV.
     *
     * A linha deve conter os campos na ordem:
     * id, nome, tipo1, tipo2, hp, attack, spAttack, defense, spDefense,
     * speed, abilities, category, evolutions, contestBeauty, contestCool,
     * contestCute, contestSmart, contestTough, resistances, weaknesses.
     *
     * @param linha Linha CSV com os valores separados por vírgula.
     * @return Instância de Pokemon populada conforme o CSV.
     */
    static Pokemon fromCSV(const std::string& linha);

    /** @name Getters */
    ///@{
    /** @brief Retorna o ID do Pokémon. */
    int getId() const { return id; }

    /** @brief Retorna o nome do Pokémon. */
    std::string getNome() const { return nome; }

    /** @brief Retorna o tipo primário. */
    std::string getTipo1() const { return tipo1; }

    /** @brief Retorna o tipo secundário (ou vazio). */
    std::string getTipo2() const { return tipo2; }

    /** @brief Retorna o HP base. */
    int getHp() const { return hp; }

    /** @brief Retorna o Attack base. */
    int getAttack() const { return attack; }

    /** @brief Retorna o Special Attack base. */
    int getSpAttack() const { return spAttack; }

    /** @brief Retorna o Defense base. */
    int getDefense() const { return defense; }

    /** @brief Retorna o Special Defense base. */
    int getSpDefense() const { return spDefense; }

    /** @brief Retorna o Speed base. */
    int getSpeed() const { return speed; }

    /** @brief Retorna as habilidades (CSV). */
    std::string getAbilities() const { return abilities; }

    /** @brief Retorna a categoria/classificação. */
    std::string getCategory() const { return category; }

    /** @brief Retorna as evoluções possíveis (CSV). */
    std::string getEvolutions() const { return evolutions; }

    /** @brief Retorna a pontuação em Contest Beauty. */
    int getContestBeauty() const { return contestBeauty; }

    /** @brief Retorna a pontuação em Contest Cool. */
    int getContestCool() const { return contestCool; }

    /** @brief Retorna a pontuação em Contest Cute. */
    int getContestCute() const { return contestCute; }

    /** @brief Retorna a pontuação em Contest Smart. */
    int getContestSmart() const { return contestSmart; }

    /** @brief Retorna a pontuação em Contest Tough. */
    int getContestTough() const { return contestTough; }

    /** @brief Retorna os tipos de resistência (CSV). */
    std::string getResistances() const { return resistances; }

    /** @brief Retorna os tipos de fraqueza (CSV). */
    std::string getWeaknesses() const { return weaknesses; }
    ///@}
};

#endif // POKEMON_H
