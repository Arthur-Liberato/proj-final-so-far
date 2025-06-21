#include <iostream>
#include "dataloader.hpp"
#include <fstream>
#include <sstream>
#include <string>
#include <exception>

std::vector<Berry> DataLoader::carregarBerries(const std::string& arquivo) {
    std::vector<Berry> berries;
    std::ifstream file(arquivo);

    if (!file.is_open()) {
        std::cerr << "Erro ao abrir o arquivo " << arquivo << std::endl;
        return berries;
    }

    std::string linha;
    getline(file, linha); // Pular cabeçalho

    while (getline(file, linha)) {
        try {
            berries.push_back(Berry::fromCSV(linha));
        } catch (const std::exception& e) {
            std::cerr << "Erro ao processar linha de berry: " << e.what() << std::endl;
        }
    }

    file.close();
    return berries;
}

std::vector<Item> DataLoader::carregarItens(const std::string& arquivo) {
    std::vector<Item> items;
    std::ifstream file(arquivo);

    if (!file.is_open()) {
        std::cerr << "Erro ao abrir o arquivo " << arquivo << std::endl;
        return items;
    }

    std::string linha;
    getline(file, linha); // Pular cabeçalho

    while (getline(file, linha)) {
        try {
            items.push_back(Item::fromCSV(linha));
        } catch (const std::exception& e) {
            std::cerr << "Erro ao processar linha de item: " << e.what() << std::endl;
        }
    }

    file.close();
    return items;
}

std::vector<Pokemon> DataLoader::carregarPokemons(const std::string& arquivo) {
    std::vector<Pokemon> pokemons;
    std::ifstream file(arquivo);

    if (!file.is_open()) {
        std::cerr << "Erro ao abrir o arquivo " << arquivo << std::endl;
        return pokemons;
    }

    std::string linha;
    getline(file, linha); // Pular cabeçalho

    while (getline(file, linha)) {
        try {
            pokemons.push_back(Pokemon::fromCSV(linha));
        } catch (const std::exception& e) {
            std::cerr << "Erro ao processar linha de pokemon: " << e.what() << std::endl;
        }
    }

    file.close();
    return pokemons;
}

std::vector<Pokeblock> DataLoader::carregarPokeblocks(const std::string& arquivo) {
    std::vector<Pokeblock> pokeblocks;
    std::ifstream file(arquivo);

    if (!file.is_open()) {
        std::cerr << "Erro ao abrir o arquivo " << arquivo << std::endl;
        return pokeblocks;
    }

    std::string linha;
    getline(file, linha); // Pular cabeçalho

    while (getline(file, linha)) {
        try {
            pokeblocks.push_back(Pokeblock::fromCSV(linha));
        } catch (const std::exception& e) {
            std::cerr << "Erro ao processar linha de pokeblock: " << e.what() << std::endl;
        }
    }

    file.close();
    return pokeblocks;
}

std::vector<Nature> DataLoader::carregarNatures(const std::string& arquivo) {
    std::vector<Nature> natures;
    std::ifstream file(arquivo);

    if (!file.is_open()) {
        std::cerr << "Erro ao abrir o arquivo " << arquivo << std::endl;
        return natures;
    }

    std::string linha;
    while (getline(file, linha)) {
        try {
            natures.push_back(Nature::fromCSV(linha));
        } catch (const std::exception& e) {
            std::cerr << "Erro ao processar linha de nature: " << e.what() << std::endl;
        }
    }

    file.close();
    return natures;
}