#ifndef DATALOADER_H
#define DATALOADER_H

#include <vector>
#include <string>
#include "berry.hpp"
#include "item.hpp"
#include "pokemon.hpp"
#include "pokeblock.hpp"
#include "nature.hpp"

class DataLoader {
public:
    static std::vector<Berry> carregarBerries(const std::string& arquivo);
    static std::vector<Item> carregarItens(const std::string& arquivo);
    static std::vector<Pokemon> carregarPokemons(const std::string& arquivo);
    static std::vector<Pokeblock> carregarPokeblocks(const std::string& arquivo);
    static std::vector<Nature> carregarNatures(const std::string& arquivo);
};

#endif