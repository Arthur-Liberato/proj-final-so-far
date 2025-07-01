#ifndef POKEBLOCK_H
#define POKEBLOCK_H

#include <string>
#include "utils.hpp"

/**
 * @class Pokeblock
 * @brief Representa um Pokéblock, um item consumível usado para alterar
 *        estatísticas de Pokémon baseando-se em sabores e outras propriedades.
 */
class Pokeblock {
private:
    int id;                 /< Identificador único do Pokéblock */
    std::string nome;       /< Nome do Pokéblock */
    std::string cor;        /< Cor do Pokéblock */
    int nivel;              /< Nível de qualidade do Pokéblock */
    int picante;            /< Intensidade do sabor picante */
    int seco;               /< Intensidade do sabor seco */
    int doce;               /< Intensidade do sabor doce */
    int amargo;             /< Intensidade do sabor amargo */
    int azedo;              /< Intensidade do sabor azedo */
    std::string condicao;   /< Condição necessária para usar (e.g. "Nivel>=5") */
    std::string efeito;     /< Efeito especial (e.g. bônus em concursos) */
    std::string raridade;   /< Raridade do Pokéblock (e.g. "Comum", "Raro") */

public:
    /**
     * @brief Construtor padrão.
     */
    Pokeblock() = default;

    /**
     * @brief Constrói um Pokéblock a partir de uma linha de CSV.
     * @param linha Linha do arquivo CSV contendo os campos na ordem correta:
     *        id,nome,cor,nivel,picante,seco,doce,amargo,azedo,condicao,efeito,raridade.
     * @return Objeto Pokeblock preenchido de acordo com os valores do CSV.
     */
    static Pokeblock fromCSV(const std::string& linha);

    /** @name Getters */
    ///@{
    /**
     * @brief Retorna o identificador.
     * @return id do Pokéblock.
     */
    int getId() const { return id; }

    /**
     * @brief Retorna o nome.
     * @return nome do Pokéblock.
     */
    std::string getNome() const { return nome; }

    /**
     * @brief Retorna a cor.
     * @return cor do Pokéblock.
     */
    std::string getCor() const { return cor; }

    /**
     * @brief Retorna o nível.
     * @return nível de qualidade.
     */
    int getNivel() const { return nivel; }

    /**
     * @brief Retorna a intensidade do sabor picante.
     * @return valor de picante.
     */
    int getPicante() const { return picante; }

    /**
     * @brief Retorna a intensidade do sabor seco.
     * @return valor de seco.
     */
    int getSeco() const { return seco; }

    /**
     * @brief Retorna a intensidade do sabor doce.
     * @return valor de doce.
     */
    int getDoce() const { return doce; }

    /**
     * @brief Retorna a intensidade do sabor amargo.
     * @return valor de amargo.
     */
    int getAmargo() const { return amargo; }

    /**
     * @brief Retorna a intensidade do sabor azedo.
     * @return valor de azedo.
     */
    int getAzedo() const { return azedo; }

    /**
     * @brief Retorna a condição de uso.
     * @return condição necessária para uso.
     */
    std::string getCondicao() const { return condicao; }

    /**
     * @brief Retorna o efeito especial.
     * @return descrição do efeito.
     */
    std::string getEfeito() const { return efeito; }

    /**
     * @brief Retorna a raridade.
     * @return raridade do Pokéblock.
     */
    std::string getRaridade() const { return raridade; }
    ///@}
};

#endif // POKEBLOCK_H
