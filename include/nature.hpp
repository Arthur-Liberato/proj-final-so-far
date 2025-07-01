/**
 * @file nature.hpp
 * @brief Declaração da classe Nature, representando a natureza de um Pokémon.
 *
 * A classe Nature define o nome da natureza e os atributos que são aumentados
 * e diminuídos por essa natureza.
 */

#ifndef NATURE_H
#define NATURE_H

#include <string>
#include "utils.hpp"

/**
 * @class Nature
 * @brief Representa a Natureza de um Pokémon.
 *
 * Cada instância de Nature contém:
 * - nome: o nome da natureza (por exemplo, "Hardy", "Lonely", etc.);
 * - aumento: o atributo que receberá um bônus;
 * - diminuicao: o atributo que receberá uma penalidade.
 */
class Nature {
private:
    /// Nome da natureza
    std::string nome;
    /// Atributo que recebe aumento
    std::string aumento;
    /// Atributo que recebe diminuição
    std::string diminuicao;

public:
    /**
     * @brief Construtor padrão.
     */
    Nature() = default;

    /**
     * @brief Cria uma instância de Nature a partir de uma linha CSV.
     * @param linha String no formato CSV: nome,aumento,diminuicao
     * @return Objeto Nature preenchido com os campos da linha
     */
    static Nature fromCSV(const std::string& linha);

    /** @name Getters */
    ///@{
    /**
     * @brief Obtém o nome da natureza.
     * @return Nome da natureza
     */
    std::string getNome() const { return nome; }

    /**
     * @brief Obtém o atributo que recebe aumento.
     * @return Atributo de aumento
     */
    std::string getAumento() const { return aumento; }

    /**
     * @brief Obtém o atributo que recebe diminuição.
     * @return Atributo de diminuição
     */
    std::string getDiminuicao() const { return diminuicao; }
    ///@}
};

#endif // NATURE_H
