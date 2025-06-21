#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <vector>
#include <string>
#include "berry.hpp"
#include "item.hpp"
#include "pokemon.hpp"
#include "pokeblock.hpp"
#include "nature.hpp"
#include "jogador.hpp"
#include "pokejogador.hpp"
#include "dataloader.hpp"

class GameManager {
private:
    std::vector<Berry> berries;
    std::vector<Item> items;
    std::vector<Pokemon> pokemons;
    std::vector<Pokeblock> pokeblocks;
    std::vector<Nature> natures;
    Jogador jogador;

    void exibirPokemonTabela(const PokemonJogador& pj, int larguraColuna);
    void exibirLinhaStatus(const std::string& label, const std::string& valor, int larguraColuna);

public:
    GameManager();
    void carregarDados();
    int gerarIV();
    std::string escolherHabilidadeAleatoria(const std::string& habilidades);
    Nature escolherNatureAleatoria();
    PokemonJogador calcularStatusPokemon(const Pokemon& base, int level, const Nature& natureza);
    void exibirPokemon(const PokemonJogador& pj);
    void exibirPokemonPokedex(const Pokemon& p);
    void exibirItem(const Item& item);
    void exibirBerry(const Berry& berry);
    void exibirPokeblock(const Pokeblock& pokeblock);
    void exibirTime();
    void consultarItemPorID(int id);
    void consultarItemPorNome();
    void consultarBerryPorID(int id);
    void consultarBerryPorNome();
    void consultarBerryPorRaridade();
    void consultarPokeblockPorID(int id);
    void consultarPokeblockPorNome();
    void consultarPokeblockPorCor();
    void consultarPokeblockPorRaridade();
    void menuConsultaPokeblocks();
    void menuConsultaItens();
    void menuConsultaBerries();
    void consultarPokemonPorID(int id);
    void consultarPokemonPorNome();
    void consultarPokemonPorTipo();
    void menuConsultaPokemon();
    void salvarJogo();
    bool carregarJogoSalvo();
    void mostrarBolsaItens();
    void mostrarBolsaBerries();
    void mostrarBolsaPokeblocks();
    void menuBolsa();
    void menuPokedex();
    PokemonJogador escolherPokemonInicial(const std::string& nomeJogador);
    void menuPrincipal();
    void iniciarJogo();
};

#endif