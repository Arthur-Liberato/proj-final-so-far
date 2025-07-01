/**
 * @file jogador.hpp
 * @brief Declaração da classe Jogador, representando o jogador e seu inventário.
 *
 * A classe Jogador gerencia as informações do jogador: nome, dinheiro
 * e coleções de Pokémon, itens, berries e pokeblocks.
 */

#ifndef JOGADOR_H
#define JOGADOR_H

#include <string>
#include <vector>
#include "pokejogador.hpp"
#include "item.hpp"
#include "berry.hpp"
#include "pokeblock.hpp"

/**
 * @class Jogador
 * @brief Representa o jogador, mantendo seu estado e inventário.
 *
 * Esta classe armazena o nome do jogador, sua quantidade de dinheiro
 * e as coleções de PokémonJogador, Item, Berry e Pokeblock que ele possui.
 */
class Jogador {
private:
    /// Nome do jogador
    std::string nome;
    /// Quantidade de dinheiro (em Pokédollars)
    int dinheiro;
    /// Lista de Pokémons do jogador
    std::vector<PokemonJogador> pokemons;
    /// Lista de itens do jogador
    std::vector<Item> itens;
    /// Lista de berries do jogador
    std::vector<Berry> berries;
    /// Lista de pokeblocks do jogador
    std::vector<Pokeblock> pokeblocks;

public:
    /** @name Getters */
    ///@{
    /**
     * @brief Obtém o nome do jogador.
     * @return Nome atual.
     */
    std::string getNome() const { return nome; }

    /**
     * @brief Obtém a quantidade de dinheiro do jogador.
     * @return Quantidade de Pokédollars.
     */
    int getDinheiro() const { return dinheiro; }

    /**
     * @brief Obtém a coleção de PokémonJogador.
     * @return Vetor de PokémonJogador.
     */
    std::vector<PokemonJogador> getPokemons() const { return pokemons; }

    /**
     * @brief Obtém a coleção de itens.
     * @return Vetor de Item.
     */
    std::vector<Item> getItens() const { return itens; }

    /**
     * @brief Obtém a coleção de berries.
     * @return Vetor de Berry.
     */
    std::vector<Berry> getBerries() const { return berries; }

    /**
     * @brief Obtém a coleção de pokeblocks.
     * @return Vetor de Pokeblock.
     */
    std::vector<Pokeblock> getPokeblocks() const { return pokeblocks; }
    ///@}

    /** @name Setters */
    ///@{
    /**
     * @brief Define o nome do jogador.
     * @param n Novo nome.
     */
    void setNome(const std::string& n) { nome = n; }

    /**
     * @brief Define a quantidade de dinheiro do jogador.
     * @param d Novo valor em Pokédollars.
     */
    void setDinheiro(int d) { dinheiro = d; }

    /**
     * @brief Define a coleção de PokémonJogador.
     * @param p Vetor com os Pokémons.
     */
    void setPokemons(const std::vector<PokemonJogador>& p) { pokemons = p; }

    /**
     * @brief Define a coleção de itens.
     * @param i Vetor com os itens.
     */
    void setItens(const std::vector<Item>& i) { itens = i; }

    /**
     * @brief Define a coleção de berries.
     * @param b Vetor com as berries.
     */
    void setBerries(const std::vector<Berry>& b) { berries = b; }

    /**
     * @brief Define a coleção de pokeblocks.
     * @param p Vetor com os pokeblocks.
     */
    void setPokeblocks(const std::vector<Pokeblock>& p) { pokeblocks = p; }
    ///@}

    /** @name Métodos de adição */
    ///@{
    /**
     * @brief Adiciona um PokémonJogador ao inventário.
     * @param p PokémonJogador a adicionar.
     */
    void addPokemon(const PokemonJogador& p) { pokemons.push_back(p); }

    /**
     * @brief Adiciona um item ao inventário.
     * @param i Item a adicionar.
     */
    void addItem(const Item& i) { itens.push_back(i); }

    /**
     * @brief Adiciona uma berry ao inventário.
     * @param b Berry a adicionar.
     */
    void addBerry(const Berry& b) { berries.push_back(b); }

    /**
     * @brief Adiciona um pokeblock ao inventário.
     * @param p Pokeblock a adicionar.
     */
    void addPokeblock(const Pokeblock& p) { pokeblocks.push_back(p); }
    ///@}
};

#endif // JOGADOR_H
