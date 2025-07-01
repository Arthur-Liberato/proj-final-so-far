/**
 * @file dataloader.hpp
 * @brief Declarações da classe DataLoader para carregamento de dados de CSV.
 *
 * A classe DataLoader fornece métodos estáticos para ler diferentes tipos
 * de entidades (Berry, Item, Pokemon, Pokeblock, Nature) a partir de arquivos CSV.
 */

#ifndef DATALOADER_H
#define DATALOADER_H

#include <vector>
#include <string>
#include "berry.hpp"
#include "item.hpp"
#include "pokemon.hpp"
#include "pokeblock.hpp"
#include "nature.hpp"

/**
 * @class DataLoader
 * @brief Classe utilitária para carregar coleções de objetos a partir de arquivos.
 *
 * Todos os métodos retornam um std::vector com instâncias do respectivo tipo,
 * lidas de um arquivo CSV cujo caminho é informado como parâmetro.
 */
class DataLoader {
public:
    /**
     * @brief Carrega todas as berries de um arquivo CSV.
     * @param arquivo Caminho para o arquivo CSV contendo as linhas de Berry.
     * @return Vetor de objetos Berry populados a partir de cada linha do arquivo.
     */
    static std::vector<Berry> carregarBerries(const std::string& arquivo);

    /**
     * @brief Carrega todos os itens de um arquivo CSV.
     * @param arquivo Caminho para o arquivo CSV contendo as linhas de Item.
     * @return Vetor de objetos Item populados a partir de cada linha do arquivo.
     */
    static std::vector<Item> carregarItens(const std::string& arquivo);

    /**
     * @brief Carrega todos os pokémons de um arquivo CSV.
     * @param arquivo Caminho para o arquivo CSV contendo as linhas de Pokemon.
     * @return Vetor de objetos Pokemon populados a partir de cada linha do arquivo.
     */
    static std::vector<Pokemon> carregarPokemons(const std::string& arquivo);

    /**
     * @brief Carrega todos os pokeblocks de um arquivo CSV.
     * @param arquivo Caminho para o arquivo CSV contendo as linhas de Pokeblock.
     * @return Vetor de objetos Pokeblock populados a partir de cada linha do arquivo.
     */
    static std::vector<Pokeblock> carregarPokeblocks(const std::string& arquivo);

    /**
     * @brief Carrega todas as natures de um arquivo CSV.
     * @param arquivo Caminho para o arquivo CSV contendo as linhas de Nature.
     * @return Vetor de objetos Nature populados a partir de cada linha do arquivo.
     */
    static std::vector<Nature> carregarNatures(const std::string& arquivo);
};

#endif // DATALOADER_H
