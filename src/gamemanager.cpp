#include "gamemanager.hpp"
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <limits>
#include <sstream>

// ----- Construtor -----
GameManager::GameManager() {
    srand(static_cast<unsigned int>(time(nullptr)));
}

// ----- Carregar dados -----
void GameManager::carregarDados() {
    berries = DataLoader::carregarBerries("textos/berries.txt");
    items = DataLoader::carregarItens("textos/items.txt");
    pokemons = DataLoader::carregarPokemons("textos/pokemon.txt");
    pokeblocks = DataLoader::carregarPokeblocks("textos/pokeblock.txt");
    natures = DataLoader::carregarNatures("textos/nature.txt");
}

// ----- Utilitarios -----
int GameManager::gerarIV() {
    return rand() % 32;
}

std::string GameManager::escolherHabilidadeAleatoria(const std::string& habilidades) {
    std::vector<std::string> habs;
    std::stringstream ss(habilidades);
    std::string token;
    while (std::getline(ss, token, ';')) {
        habs.push_back(Utils::trim(token));
    }
    if (habs.empty()) return "";
    return habs[rand() % habs.size()];
}

Nature GameManager::escolherNatureAleatoria() {
    if (natures.empty()) throw std::runtime_error("Nenhuma natureza carregada");
    return natures[rand() % natures.size()];
}

PokemonJogador GameManager::calcularStatusPokemon(const Pokemon& base, int level, const Nature& natureza) {
    PokemonJogador pj;
    pj.setBase(base);
    pj.setLevel(level);
    pj.setNatureza(natureza.getNome());

    int iv_hp = gerarIV();
    int iv_atk = gerarIV();
    int iv_def = gerarIV();
    int iv_spatk = gerarIV();
    int iv_spdef = gerarIV();
    int iv_speed = gerarIV();

    pj.setIvHP(((2 * base.getHp() + iv_hp) * level) / 100 + level + 10);
    pj.setAttack(((2 * base.getAttack() + iv_atk) * level) / 100 + 5);
    pj.setDefense(((2 * base.getDefense() + iv_def) * level) / 100 + 5);
    pj.setSpAttack(((2 * base.getSpAttack() + iv_spatk) * level) / 100 + 5);
    pj.setSpDefense(((2 * base.getSpDefense() + iv_spdef) * level) / 100 + 5);
    pj.setSpeed(((2 * base.getSpeed() + iv_speed) * level) / 100 + 5);

    return pj;
}

// ----- Exibicao -----
void GameManager::exibirPokemon(const PokemonJogador& pj) {
    const Pokemon& base = pj.getBase();
    std::cout << "Nome: " << base.getNome() << " | Level: " << pj.getLevel() << "\n";
    std::cout << "HP: " << pj.getIvHP() << " | Ataque: " << pj.getAttack() << " | Defesa: " << pj.getDefense() << "\n";
    std::cout << "Sp. Ataque: " << pj.getSpAttack() << " | Sp. Defesa: " << pj.getSpDefense() << " | Velocidade: " << pj.getSpeed() << "\n";
    std::cout << "Natureza: " << pj.getNatureza() << "\n";
    std::cout << "Habilidade: " << escolherHabilidadeAleatoria(base.getAbilities()) << "\n";
}

void GameManager::exibirPokemonPokedex(const Pokemon& p) {
    std::cout << "ID: " << p.getId() << " | Nome: " << p.getNome() << "\n";
    std::cout << "Tipo1: " << p.getTipo1() << " | Tipo2: " << p.getTipo2() << "\n";
    std::cout << "Categoria: " << p.getCategory() << "\n";
    std::cout << "Resistencias: " << p.getResistances() << "\n";
    std::cout << "Fraquezas: " << p.getWeaknesses() << "\n";
    std::cout << "Habilidades: " << p.getAbilities() << "\n";
}

void GameManager::exibirItem(const Item& item) {
    std::cout << "ID: " << item.getId() << " | Nome: " << item.getNome() << "\n";
    std::cout << "Categoria: " << item.getCategoria() << " | Preco: " << item.getPreco() << "\n";
    std::cout << "Raridade: " << item.getRaridade() << "\n";
    std::cout << "Efeito Contest: " << item.getEfeitoContest() << "\n";
    std::cout << "Descricao: " << item.getDescricao() << "\n";
}

void GameManager::exibirBerry(const Berry& berry) {
    std::cout << "ID: " << berry.getId() << " | Nome: " << berry.getNome() << "\n";
    std::cout << "Picante: " << berry.getPicante() << " | Seco: " << berry.getSeco() << " | Doce: " << berry.getDoce()
              << " | Amargo: " << berry.getAmargo() << " | Azedo: " << berry.getAzedo() << "\n";
    std::cout << "Raridade: " << berry.getRaridade() << "\n";
    std::cout << "Descricao: " << berry.getDescricao() << "\n";
}

void GameManager::exibirPokeblock(const Pokeblock& pokeblock) {
    std::cout << "ID: " << pokeblock.getId() << " | Nome: " << pokeblock.getNome() << "\n";
    std::cout << "Cor: " << pokeblock.getCor() << " | Nivel: " << pokeblock.getNivel() << "\n";
    std::cout << "Picante: " << pokeblock.getPicante() << " | Seco: " << pokeblock.getSeco() << " | Doce: " << pokeblock.getDoce()
              << " | Amargo: " << pokeblock.getAmargo() << " | Azedo: " << pokeblock.getAzedo() << "\n";
    std::cout << "Condicao: " << pokeblock.getCondicao() << " | Efeito: " << pokeblock.getEfeito() << "\n";
    std::cout << "Raridade: " << pokeblock.getRaridade() << "\n";
}

// void GameManager::exibirTime() {
//     std::cout << "\n=== Seu Time ===\n";
//     const std::vector<PokemonJogador>& time = jogador.getTime();
//     if (time.empty()) {
//         std::cout << "Seu time esta vazio.\n";
//         return;
//     }
//     for (const auto& pj : time) {
//         exibirPokemon(pj);
//         std::cout << "--------------------------\n";
//     }
// }

// ----- Consultas -----
void GameManager::consultarItemPorID(int id) {
    auto it = std::find_if(items.begin(), items.end(),
                           [id](const Item& i) { return i.getId() == id; });
    if (it != items.end()) exibirItem(*it);
    else std::cout << "Item com ID " << id << " nao encontrado.\n";
}

void GameManager::consultarItemPorNome() {
    std::string nome;
    std::cout << "Digite o nome do item: ";
    std::getline(std::cin, nome);
    nome = Utils::toLower(Utils::trim(nome));

    for (const auto& item : items) {
        if (Utils::toLower(item.getNome()) == nome) {
            exibirItem(item);
            return;
        }
    }
    std::cout << "Item nao encontrado.\n";
}

void GameManager::consultarBerryPorID(int id) {
    auto it = std::find_if(berries.begin(), berries.end(),
                           [id](const Berry& b) { return b.getId() == id; });
    if (it != berries.end()) exibirBerry(*it);
    else std::cout << "Berry com ID " << id << " nao encontrada.\n";
}

void GameManager::consultarBerryPorNome() {
    std::string nome;
    std::cout << "Digite o nome da Berry: ";
    std::getline(std::cin, nome);
    nome = Utils::toLower(Utils::trim(nome));

    for (const auto& berry : berries) {
        if (Utils::toLower(berry.getNome()) == nome) {
            exibirBerry(berry);
            return;
        }
    }
    std::cout << "Berry com nome \"" << nome << "\" nao encontrada.\n";
}

void GameManager::consultarBerryPorRaridade() {
    std::string raridade;
    std::cout << "Digite a raridade: ";
    std::getline(std::cin, raridade);
    raridade = Utils::toLower(Utils::trim(raridade));

    bool achou = false;
    for (const auto& berry : berries) {
        if (Utils::toLower(berry.getRaridade()) == raridade) {
            exibirBerry(berry);
            std::cout << "------------------------\n";
            achou = true;
        }
    }
    if (!achou) std::cout << "Nenhuma Berry encontrada com raridade \"" << raridade << "\"\n";
}

void GameManager::consultarPokeblockPorID(int id) {
    auto it = std::find_if(pokeblocks.begin(), pokeblocks.end(),
                           [id](const Pokeblock& p) { return p.getId() == id; });
    if (it != pokeblocks.end()) exibirPokeblock(*it);
    else std::cout << "Pokeblock com ID " << id << " nao encontrado.\n";
}

void GameManager::consultarPokeblockPorNome() {
    std::string nome;
    std::cout << "Digite o nome do Pokeblock: ";
    std::getline(std::cin, nome);
    nome = Utils::toLower(Utils::trim(nome));

    for (const auto& pblock : pokeblocks) {
        if (Utils::toLower(pblock.getNome()) == nome) {
            exibirPokeblock(pblock);
            return;
        }
    }
    std::cout << "Pokeblock nao encontrado.\n";
}

void GameManager::consultarPokeblockPorCor() {
    std::string cor;
    std::cout << "Digite a cor do Pokeblock: ";
    std::getline(std::cin, cor);
    cor = Utils::toLower(Utils::trim(cor));

    bool achou = false;
    for (const auto& pblock : pokeblocks) {
        if (Utils::toLower(pblock.getCor()) == cor) {
            exibirPokeblock(pblock);
            std::cout << "------------------------\n";
            achou = true;
        }
    }
    if (!achou) std::cout << "Nenhum Pokeblock encontrado com cor \"" << cor << "\"\n";
}

void GameManager::consultarPokeblockPorRaridade() {
    std::string raridade;
    std::cout << "Digite a raridade do Pokeblock: ";
    std::getline(std::cin, raridade);
    raridade = Utils::toLower(Utils::trim(raridade));

    bool achou = false;
    for (const auto& pblock : pokeblocks) {
        if (Utils::toLower(pblock.getRaridade()) == raridade) {
            exibirPokeblock(pblock);
            std::cout << "------------------------\n";
            achou = true;
        }
    }
    if (!achou) std::cout << "Nenhum Pokeblock encontrado com raridade \"" << raridade << "\"\n";
}

void GameManager::consultarPokemonPorID(int id) {
    auto it = std::find_if(pokemons.begin(), pokemons.end(),
                           [id](const Pokemon& p) { return p.getId() == id; });
    if (it != pokemons.end()) exibirPokemonPokedex(*it);
    else std::cout << "Pokemon com ID " << id << " nao encontrado.\n";
}

void GameManager::consultarPokemonPorNome() {
    std::string nome;
    std::cout << "Digite o nome do Pokemon: ";
    std::getline(std::cin, nome);
    nome = Utils::toLower(Utils::trim(nome));

    for (const auto& p : pokemons) {
        if (Utils::toLower(p.getNome()) == nome) {
            exibirPokemonPokedex(p);
            return;
        }
    }
    std::cout << "Pokemon nao encontrado.\n";
}

void GameManager::consultarPokemonPorTipo() {
    std::string tipo;
    std::cout << "Digite o tipo do Pokemon: ";
    std::getline(std::cin, tipo);
    tipo = Utils::toLower(Utils::trim(tipo));

    bool achou = false;
    for (const auto& p : pokemons) {
        if (Utils::toLower(p.getTipo1()) == tipo || Utils::toLower(p.getTipo2()) == tipo) {
            exibirPokemonPokedex(p);
            std::cout << "------------------------\n";
            achou = true;
        }
    }
    if (!achou) std::cout << "Nenhum Pokemon encontrado com o tipo \"" << tipo << "\"\n";
}

// ----- Menus -----
void GameManager::menuConsultaBerries() {
    int opcao;
    do {
        std::cout << "\n=== Consulta Berries ===\n";
        std::cout << "1. Por ID\n";
        std::cout << "2. Por Nome\n";
        std::cout << "3. Por Raridade\n";
        std::cout << "0. Voltar\n";
        std::cout << "Escolha: ";
        std::cin >> opcao;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (opcao) {
            case 1: {
                int id;
                std::cout << "Digite ID: ";
                std::cin >> id;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                consultarBerryPorID(id);
                break;
            }
            case 2:
                consultarBerryPorNome();
                break;
            case 3:
                consultarBerryPorRaridade();
                break;
            case 0:
                break;
            default:
                std::cout << "Opcao invalida.\n";
        }
    } while (opcao != 0);
}

void GameManager::menuConsultaItens() {
    int opcao;
    do {
        std::cout << "\n=== Consulta Itens ===\n";
        std::cout << "1. Por ID\n";
        std::cout << "2. Por Nome\n";
        std::cout << "0. Voltar\n";
        std::cout << "Escolha: ";
        std::cin >> opcao;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (opcao) {
            case 1: {
                int id;
                std::cout << "Digite ID: ";
                std::cin >> id;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                consultarItemPorID(id);
                break;
            }
            case 2:
                consultarItemPorNome();
                break;
            case 0:
                break;
            default:
                std::cout << "Opcao invalida.\n";
        }
    } while (opcao != 0);
}

void GameManager::menuConsultaPokeblocks() {
    int opcao;
    do {
        std::cout << "\n=== Consulta Pokeblocks ===\n";
        std::cout << "1. Por ID\n";
        std::cout << "2. Por Nome\n";
        std::cout << "3. Por Cor\n";
        std::cout << "4. Por Raridade\n";
        std::cout << "0. Voltar\n";
        std::cout << "Escolha: ";
        std::cin >> opcao;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (opcao) {
            case 1: {
                int id;
                std::cout << "Digite ID: ";
                std::cin >> id;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                consultarPokeblockPorID(id);
                break;
            }
            case 2:
                consultarPokeblockPorNome();
                break;
            case 3:
                consultarPokeblockPorCor();
                break;
            case 4:
                consultarPokeblockPorRaridade();
                break;
            case 0:
                break;
            default:
                std::cout << "Opcao invalida.\n";
        }
    } while (opcao != 0);
}

void GameManager::menuConsultaPokemon() {
    int opcao;
    do {
        std::cout << "\n=== Consulta Pokemon ===\n";
        std::cout << "1. Por ID\n";
        std::cout << "2. Por Nome\n";
        std::cout << "3. Por Tipo\n";
        std::cout << "0. Voltar\n";
        std::cout << "Escolha: ";
        std::cin >> opcao;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (opcao) {
            case 1: {
                int id;
                std::cout << "Digite ID: ";
                std::cin >> id;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                consultarPokemonPorID(id);
                break;
            }
            case 2:
                consultarPokemonPorNome();
                break;
            case 3:
                consultarPokemonPorTipo();
                break;
            case 0:
                break;
            default:
                std::cout << "Opcao invalida.\n";
        }
    } while (opcao != 0);
}

// ----- Salvar / carregar jogo -----
void GameManager::salvarJogo() {
    std::ofstream ofs("savegame.txt");
    if (!ofs) {
        std::cout << "Erro ao salvar o jogo.\n";
        return;
    }
    ofs << jogador.getNome() << '\n';
    // Pode salvar mais dados conforme necessidade
    ofs.close();
    std::cout << "Jogo salvo com sucesso.\n";
}

bool GameManager::carregarJogoSalvo() {
    std::ifstream ifs("savegame.txt");
    if (!ifs) {
        std::cout << "Nenhum jogo salvo encontrado.\n";
        return false;
    }
    std::string nomeJogador;
    std::getline(ifs, nomeJogador);
    jogador.setNome(nomeJogador);
    ifs.close();
    std::cout << "Jogo carregado para o jogador " << nomeJogador << "\n";
    return true;
}

// ----- Bolsa -----
void GameManager::mostrarBolsaItens() {
    std::cout << "\n=== Bolsa de Itens ===\n";
    std::cout << "[Funcionalidade nao implementada]\n";
}

void GameManager::mostrarBolsaBerries() {
    std::cout << "\n=== Bolsa de Berries ===\n";
    std::cout << "[Funcionalidade nao implementada]\n";
}

void GameManager::mostrarBolsaPokeblocks() {
    std::cout << "\n=== Bolsa de Pokeblocks ===\n";
    std::cout << "[Funcionalidade nao implementada]\n";
}

void GameManager::menuBolsa() {
    std::cout << "[Menu Bolsa ainda nao implementado]\n";
}

void GameManager::menuPokedex() {
    std::cout << "[Menu Pokedex ainda nao implementado]\n";
}

// ----- Escolher Pokemon Inicial -----
PokemonJogador GameManager::escolherPokemonInicial(const std::string& nomeJogador) {
    if (pokemons.empty())
        throw std::runtime_error("Lista de pokemons vazia");

    Pokemon base = pokemons[0];
    Nature nat = escolherNatureAleatoria();
    PokemonJogador pj = calcularStatusPokemon(base, 5, nat);
    jogador.setNome(nomeJogador);
    jogador.addPokemon(pj);
    return pj;
}

// ----- Menu Principal -----
void GameManager::menuPrincipal() {
    int opcao = 0;
    do {
        std::cout << "\n=== Menu Principal ===\n";
        std::cout << "1. Consultar Pokemon\n";
        std::cout << "2. Consultar Itens\n";
        std::cout << "3. Consultar Berries\n";
        std::cout << "4. Consultar Pokeblocks\n";
        std::cout << "5. Salvar Jogo\n";
        std::cout << "6. Carregar Jogo\n";
        // std::cout << "7. Mostrar Time\n";
        std::cout << "0. Sair\n";
        std::cout << "Escolha: ";
        std::cin >> opcao;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (opcao) {
            case 1:
                menuConsultaPokemon();
                break;
            case 2:
                menuConsultaItens();
                break;
            case 3:
                menuConsultaBerries();
                break;
            case 4:
                menuConsultaPokeblocks();
                break;
            case 5:
                salvarJogo();
                break;
            case 6:
                carregarJogoSalvo();
                break;
            // case 7:
            //     exibirTime();
            //     break;
            case 0:
                std::cout << "Saindo...\n";
                break;
            default:
                std::cout << "Opcao invalida.\n";
        }
    } while (opcao != 0);
}

// ----- Iniciar jogo -----
void GameManager::iniciarJogo() {
    std::cout << "=== Bem-vindo ao Mundo Pokemon! ===\n";

    if (!carregarJogoSalvo()) {
        std::string nome;
        std::cout << "Digite seu nome, treinador: ";
        std::getline(std::cin, nome);

        PokemonJogador inicial = escolherPokemonInicial(nome);
        std::cout << "Seu Pokemon inicial e " << inicial.getBase().getNome() << "!\n";
    }

    menuPrincipal();
}
