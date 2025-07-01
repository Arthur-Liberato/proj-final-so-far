/**
 * @file berry.hpp
 * @brief Declara a classe Berry, que representa uma berry do jogo.
 *
 * Cada Berry possui atributos de sabor (picante, seco, doce, amargo, azedo),
 * além de identificador, nome, raridade e descrição.
 */

#ifndef BERRY_H
#define BERRY_H

#include <string>
#include "utils.hpp"

/**
 * @class Berry
 * @brief Representa uma berry com atributos de sabor e metadados.
 *
 * A classe Berry encapsula os dados de uma berry (fruta) utilizada
 * para melhorar atributos de um Pokémon. É possível criar uma instância
 * a partir de uma linha CSV e recuperar cada atributo via getters.
 */
class Berry {
private:
    int id;                ///< Identificador único da berry
    std::string nome;      ///< Nome da berry
    int picante;           ///< Intensidade do sabor picante
    int seco;              ///< Intensidade do sabor seco
    int doce;              ///< Intensidade do sabor doce
    int amargo;            ///< Intensidade do sabor amargo
    int azedo;             ///< Intensidade do sabor azedo
    std::string raridade;  ///< Grau de raridade da berry
    std::string descricao; ///< Descrição detalhada da berry

public:
    /**
     * @brief Construtor padrão.
     *
     * Cria uma Berry com valores padrão (construtor compilado automaticamente).
     */
    Berry() = default;

    /**
     * @brief Cria uma Berry a partir de uma linha CSV.
     *
     * Espera uma string no formato:
     * `id;nome;picante;seco;doce;amargo;azedo;raridade;descricao`
     *
     * @param linha A linha lida do CSV contendo todos os campos.
     * @return Uma instância de Berry populada com os valores do CSV.
     */
    static Berry fromCSV(const std::string& linha);

    // Getters

    /**
     * @brief Retorna o identificador da berry.
     * @return Valor inteiro do ID.
     */
    int getId() const { return id; }

    /**
     * @brief Retorna o nome da berry.
     * @return Nome como std::string.
     */
    std::string getNome() const { return nome; }

    /**
     * @brief Recupera o nível de sabor picante.
     * @return Valor inteiro de picância.
     */
    int getPicante() const { return picante; }

    /**
     * @brief Recupera o nível de sabor seco.
     * @return Valor inteiro de secura.
     */
    int getSeco() const { return seco; }

    /**
     * @brief Recupera o nível de sabor doce.
     * @return Valor inteiro de doçura.
     */
    int getDoce() const { return doce; }

    /**
     * @brief Recupera o nível de sabor amargo.
     * @return Valor inteiro de amargor.
     */
    int getAmargo() const { return amargo; }

    /**
     * @brief Recupera o nível de sabor azedo.
     * @return Valor inteiro de acidez.
     */
    int getAzedo() const { return azedo; }

    /**
     * @brief Retorna a raridade da berry.
     * @return Texto indicando raridade.
     */
    std::string getRaridade() const { return raridade; }

    /**
     * @brief Retorna a descrição da berry.
     * @return Descrição detalhada como std::string.
     */
    std::string getDescricao() const { return descricao; }
};

#endif // BERRY_H
