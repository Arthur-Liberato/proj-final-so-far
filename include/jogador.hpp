#ifndef JOGADOR_H
#define JOGADOR_H

#include <string>
#include <vector>
#include "pokejogador.hpp"
#include "item.hpp"
#include "berry.hpp"
#include "pokeblock.hpp"

class Jogador {
private:
    std::string nome;
    int dinheiro;
    std::vector<PokemonJogador> pokemons;
    std::vector<Item> itens;
    std::vector<Berry> berries;
    std::vector<Pokeblock> pokeblocks;

public:
    // Getters e Setters
    std::string getNome() const { return nome; }
    int getDinheiro() const { return dinheiro; }
    std::vector<PokemonJogador> getPokemons() const { return pokemons; }
    std::vector<Item> getItens() const { return itens; }
    std::vector<Berry> getBerries() const { return berries; }
    std::vector<Pokeblock> getPokeblocks() const { return pokeblocks; }

    void setNome(std::string n) { nome = n; }
    void setDinheiro(int d) { dinheiro = d; }
    void setPokemons(std::vector<PokemonJogador> p) { pokemons = p; }
    void setItens(std::vector<Item> i) { itens = i; }
    void setBerries(std::vector<Berry> b) { berries = b; }
    void setPokeblocks(std::vector<Pokeblock> p) { pokeblocks = p; }

    // Métodos para adicionar elementos
    void addPokemon(PokemonJogador p) { pokemons.push_back(p); }
    void addItem(Item i) { itens.push_back(i); }
    void addBerry(Berry b) { berries.push_back(b); }
    void addPokeblock(Pokeblock p) { pokeblocks.push_back(p); }
};

#endif