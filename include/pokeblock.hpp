/**
 * @file pokeblock.hpp
 * @brief Declaração da classe Pokeblock, item consumível que altera estatísticas
 *        de Pokémon com base em sabores e propriedades específicas.
 */
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
    int id;                 ///< Identificador único do Pokéblock
    std::string nome;       ///< Nome do Pokéblock
    std::string cor;        ///< Cor do Pokéblock
    int nivel;              ///< Nível de qualidade do Pokéblock
    int picante;            ///< Intensidade do sabor picante
    int seco;               ///< Intensidade do sabor seco
    int doce;               ///< Intensidade do sabor doce
    int amargo;             ///< Intensidade do sabor amargo
    int azedo;              ///< Intensidade do sabor azedo
    std::string condicao;   ///< Condição necessária para uso (ex: "Nivel>=5")
    std::string efeito;     ///< Efeito especial (ex: bônus em concursos)
    std::string raridade;   ///< Raridade (ex: "Comum", "Raro")

public:
    /**
     * @brief Construtor padrão.
     */
    Pokeblock() = default;

    /** @name Conversão CSV */
    ///@{
    /**
     * @brief Constrói um Pokéblock a partir de uma linha CSV.
     * @param linha Linha CSV no formato:
     *        id,nome,cor,nivel,picante,seco,doce,amargo,azedo,condicao,efeito,raridade
     * @return Objeto Pokeblock preenchido.
     */
    static Pokeblock fromCSV(const std::string& linha);
    ///@}

    /** @name Getters */
    ///@{
    int getId()        const { return id; }        ///< Retorna o identificador.
    std::string getNome() const { return nome; }   ///< Retorna o nome.
    std::string getCor()  const { return cor; }    ///< Retorna a cor.
    int getNivel()      const { return nivel; }    ///< Retorna o nível de qualidade.
    int getPicante()    const { return picante; }  ///< Retorna intensidade de picante.
    int getSeco()       const { return seco; }     ///< Retorna intensidade de seco.
    int getDoce()       const { return doce; }     ///< Retorna intensidade de doce.
    int getAmargo()     const { return amargo; }   ///< Retorna intensidade de amargo.
    int getAzedo()      const { return azedo; }    ///< Retorna intensidade de azedo.
    std::string getCondicao() const { return condicao; } ///< Retorna condição de uso.
    std::string getEfeito()   const { return efeito; }   ///< Retorna o efeito especial.
    std::string getRaridade() const { return raridade; } ///< Retorna a raridade.
    ///@}
};

#endif // POKEBLOCK_H