/**
 * @file item.hpp
 * @brief Declaração da classe Item que representa um item do jogo Pokémon.
 *
 * A classe Item encapsula os atributos básicos de um item:
 * identificador, nome, categoria, preço, raridade,
 * efeito em concursos e descrição detalhada.
 */

#ifndef ITEM_H
#define ITEM_H

#include <string>
#include "utils.hpp"

/**
 * @class Item
 * @brief Representa um item que pode ser usado ou vendido no jogo.
 *
 * Cada Item possui um ID único, nome, categoria (como Potion, Poké Ball etc.),
 * preço de compra/venda, raridade, efeito em concursos (contest) e uma descrição
 * completa para uso no jogo.
 */
class Item {
private:
    /// Identificador único do item
    int id;
    /// Nome do item
    std::string nome;
    /// Categoria do item (e.g., Potion, Poké Ball, Berry)
    std::string categoria;
    /// Preço de compra/venda em Pokédollars
    int preco;
    /// Grau de raridade (e.g., Comum, Raro, Lendário)
    std::string raridade;
    /// Descrição do efeito em concursos (contest)
    std::string efeitoContest;
    /// Descrição detalhada do item
    std::string descricao;

public:
    /**
     * @brief Construtor padrão
     *
     * Inicializa um Item sem dados. Utilize os setters ou fromCSV para povoar.
     */
    Item() = default;

    /**
     * @brief Cria um Item a partir de uma linha CSV.
     * @param linha String contendo os campos separados por vírgula na ordem:
     *              id, nome, categoria, preco, raridade, efeitoContest, descricao
     * @return Instância de Item preenchida com os valores extraídos.
     *
     * Exemplo de formato de linha CSV:
     * "10,Potion,Consumível,300,Comum,Nenhum,Restaura 20 HP"
     */
    static Item fromCSV(const std::string& linha);

    /** @name Getters */
    ///@{
    /**
     * @brief Obtém o ID do item.
     * @return Valor inteiro do identificador.
     */
    int getId() const { return id; }

    /**
     * @brief Obtém o nome do item.
     * @return String com o nome.
     */
    std::string getNome() const { return nome; }

    /**
     * @brief Obtém a categoria do item.
     * @return String com a categoria.
     */
    std::string getCategoria() const { return categoria; }

    /**
     * @brief Obtém o preço do item.
     * @return Valor inteiro do preço em Pokédollars.
     */
    int getPreco() const { return preco; }

    /**
     * @brief Obtém a raridade do item.
     * @return String indicando a raridade.
     */
    std::string getRaridade() const { return raridade; }

    /**
     * @brief Obtém o efeito em concursos (contest) do item.
     * @return String com a descrição do efeito em concursos.
     */
    std::string getEfeitoContest() const { return efeitoContest; }

    /**
     * @brief Obtém a descrição detalhada do item.
     * @return String contendo a descrição completa.
     */
    std::string getDescricao() const { return descricao; }
    ///@}
};

#endif // ITEM_H
