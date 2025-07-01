/**
 * @file gamemanager.hpp
 * @brief Declaração da classe GameManager que gerencia o fluxo principal do jogo.
 *
 * A classe GameManager encapsula todas as operações de inicialização,
 * carregamento de dados, exibição na tela, menus de consulta e
 * persistência de estado (salvar/carregar jogo) para o jogo Pokémon.
 */

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

/**
 * @class GameManager
 * @brief Responsável por toda a lógica de jogo: menus, carregamento, consultas, exibição e persistência.
 *
 * Armazena coleções de berries, itens, pokémons, pokeblocks e natures,
 * além do jogador atual. Fornece métodos para:
 * - carregar dados via DataLoader
 * - gerar IVs e escolher atributos aleatórios
 * - calcular status de um Pokémon de jogador
 * - exibir informações na tela (tabelas, detalhes de itens, pokémons etc.)
 * - navegar em menus de consulta e seleção
 * - salvar/carregar progresso do jogo
 */
class GameManager {
private:
    /// Todas as berries disponíveis no jogo
    std::vector<Berry> berries;
    /// Todos os itens disponíveis no jogo
    std::vector<Item> items;
    /// Todos os pokémons-base disponíveis no jogo
    std::vector<Pokemon> pokemons;
    /// Todos os pokeblocks disponíveis no jogo
    std::vector<Pokeblock> pokeblocks;
    /// Todas as natures disponíveis no jogo
    std::vector<Nature> natures;
    /// Dados do jogador atual
    Jogador jogador;

    /**
     * @brief Exibe uma linha de tabela formatada para um Pokémon de jogador.
     * @param pj PokémonJogador a ser exibido
     * @param larguraColuna Largura fixa de cada coluna para alinhamento
     */
    void exibirPokemonTabela(const PokemonJogador& pj, int larguraColuna);

    /**
     * @brief Renderiza uma linha genérica de status no console.
     * @param label Texto do rótulo (ex.: "HP", "Ataque")
     * @param valor Valor a ser exibido ao lado do rótulo
     * @param larguraColuna Largura total da célula para alinhamento
     */
    void exibirLinhaStatus(const std::string& label,
                           const std::string& valor,
                           int larguraColuna);

public:
    /**
     * @brief Construtor padrão: inicializa o GameManager sem dados carregados.
     */
    GameManager();

    /**
     * @brief Carrega todos os dados (berries, itens, pokémons, pokeblocks, natures).
     * 
     * Internamente usa DataLoader para cada tipo de dado.
     */
    void carregarDados();

    /**
     * @brief Gera um valor de IV (Valor Individual) aleatório para um stat.
     * @return Um inteiro entre 0 e 31 representando o IV.
     */
    int gerarIV();

    /**
     * @brief Seleciona aleatoriamente uma das habilidades listadas.
     * @param habilidades String contendo habilidades separadas por vírgula.
     * @return O nome da habilidade escolhida.
     */
    std::string escolherHabilidadeAleatoria(const std::string& habilidades);

    /**
     * @brief Escolhe uma Nature aleatoriamente dentre as disponíveis.
     * @return Uma instância de Nature escolhida ao acaso.
     */
    Nature escolherNatureAleatoria();

    /**
     * @brief Calcula o status final de um Pokémon de jogador com base na base e Nature.
     * @param base Objeto Pokemon com estatísticas-base.
     * @param level Nível do Pokémon (1–100).
     * @param natureza Nature a influenciar os stats.
     * @return Objeto PokemonJogador com todos os stats e habilidades definidos.
     */
    PokemonJogador calcularStatusPokemon(const Pokemon& base,
                                         int level,
                                         const Nature& natureza);

    /**
     * @brief Exibe detalhes formatados de um Pokémon de jogador.
     * @param pj PokémonJogador a ser exibido.
     */
    void exibirPokemon(const PokemonJogador& pj);

    /**
     * @brief Exibe detalhes formato Pokedex de um Pokémon-base.
     * @param p Pokémon a ser exibido.
     */
    void exibirPokemonPokedex(const Pokemon& p);

    /**
     * @brief Exibe detalhes de um item no console.
     * @param item Item a ser exibido.
     */
    void exibirItem(const Item& item);

    /**
     * @brief Exibe detalhes de uma berry no console.
     * @param berry Berry a ser exibida.
     */
    void exibirBerry(const Berry& berry);

    /**
     * @brief Exibe detalhes de um pokeblock no console.
     * @param pokeblock Pokeblock a ser exibido.
     */
    void exibirPokeblock(const Pokeblock& pokeblock);

    /**
     * @brief Exibe todos os pokémons do time do jogador em formato de tabela.
     */
    void exibirTime();

    /** @name Consultas de itens */
    ///@{
    void consultarItemPorID(int id);
    void consultarItemPorNome();
    ///@}

    /** @name Consultas de berries */
    ///@{
    void consultarBerryPorID(int id);
    void consultarBerryPorNome();
    void consultarBerryPorRaridade();
    ///@}

    /** @name Consultas de pokeblocks */
    ///@{
    void consultarPokeblockPorID(int id);
    void consultarPokeblockPorNome();
    void consultarPokeblockPorCor();
    void consultarPokeblockPorRaridade();
    ///@}

    /** @name Menus de consulta específicos */
    ///@{
    void menuConsultaPokeblocks();
    void menuConsultaItens();
    void menuConsultaBerries();
    ///@}

    /** @name Consultas de pokémons */
    ///@{
    void consultarPokemonPorID(int id);
    void consultarPokemonPorNome();
    void consultarPokemonPorTipo();
    void menuConsultaPokemon();
    ///@}

    /**
     * @brief Persiste o estado do jogo atual em arquivo.
     */
    void salvarJogo();

    /**
     * @brief Tenta carregar um jogo salvo previamente.
     * @return true se o carregamento for bem-sucedido, false caso contrário.
     */
    bool carregarJogoSalvo();

    /** @name Exibição de bolsas do jogador */
    ///@{
    void mostrarBolsaItens();
    void mostrarBolsaBerries();
    void mostrarBolsaPokeblocks();
    void menuBolsa();
    ///@}

    /**
     * @brief Exibe o menu de Pokedex e trata interações do usuário.
     */
    void menuPokedex();

    /**
     * @brief Permite ao jogador escolher o Pokémon inicial.
     * @param nomeJogador Nome digitado pelo jogador para saudação.
     * @return Objeto PokemonJogador correspondente à escolha.
     */
    PokemonJogador escolherPokemonInicial(const std::string& nomeJogador);

    /** @name Fluxos principais do jogo */
    ///@{
    /**
     * @brief Exibe o menu principal e executa operações conforme escolha.
     */
    void menuPrincipal();

    /**
     * @brief Inicia o fluxo completo do jogo (tela de boas-vindas, carregamento, loops).
     */
    void iniciarJogo();
    ///@}
};

#endif // GAMEMANAGER_H
