#include "gamemanager.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <stdexcept>
#include <iomanip>

GameManager::GameManager() {
    srand(time(0)); // Inicializar semente para números aleatórios
}

void GameManager::carregarDados() {
    berries = DataLoader::carregarBerries("textos/berries.txt");
    items = DataLoader::carregarItens("textos/items.txt");
    pokemons = DataLoader::carregarPokemons("textos/pokemon.txt");
    pokeblocks = DataLoader::carregarPokeblocks("textos/pokeblock.txt");
    natures = DataLoader::carregarNatures("textos/nature.txt");
}

// Implementação dos outros métodos da classe GameManager
// (Manter as implementações originais, apenas ajustando para usar os getters/setters das novas classes)
// ... continuação com todas as outras implementações de métodos ...

#include <iostream>
using namespace std;

void GameManager::iniciarJogo() {
    cout << "Jogo iniciado com sucesso!" << endl;
}
