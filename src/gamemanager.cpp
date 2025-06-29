#include "gamemanager.hpp"
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <limits>
#include <sstream>

GameManager::GameManager() {
    srand(time(0)); // inicializa gerador de números aleatórios
}

void GameManager::carregarDados() {
    berries = DataLoader::carregarBerries("textos/berries.txt");
    items = DataLoader::carregarItens("textos/items.txt");
    pokemons = DataLoader::carregarPokemons("textos/pokemon.txt");
    pokeblocks = DataLoader::carregarPokeblocks("textos/pokeblock.txt");
    natures = DataLoader::carregarNatures("textos/nature.txt");
}

int GameManager::gerarIV() {
    return rand() % 32; // IV de 0 a 31
}

std::string GameManager::escolherHabilidadeAleatoria(const std::string& habilidades) {
    // habilidades separadas por ';' (exemplo)
    std::vector<std::string> habs;
    std::stringstream ss(habilidades);
    std::string token;
    while(std::getline(ss, token, ';')) {
        habs.push_back(Utils::trim(token));
    }
    if(habs.empty()) return "";
    int idx = rand() % habs.size();
    return habs[idx];
}

Nature GameManager::escolherNatureAleatoria() {
    if(natures.empty()) throw std::runtime_error("Nenhuma natureza carregada");
    int idx = rand() % natures.size();
    return natures[idx];
}

PokemonJogador GameManager::calcularStatusPokemon(const Pokemon& base, int level, const Nature& natureza) {
    PokemonJogador pj;
    pj.setBase(base);
    pj.setLevel(level);
    pj.setNatureza(natureza.getNome());

    // Exemplo simples: stats base + IV + level (fórmula simplificada)
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

    // Aplicar modificador de Natureza (simplificado)
    // Aumenta stat, diminui outro - aqui só exemplo genérico, ajustar conforme necessidade

    return pj;
}

void GameManager::exibirPokemon(const PokemonJogador& pj) {
    std::cout << "Nome: " << pj.getBase().getNome() << "  Level: " << pj.getLevel() << std::endl;
    std::cout << "HP: " << pj.getIvHP() << "  Ataque: " << pj.getAttack() << "  Defesa: " << pj.getDefense() << std::endl;
    std::cout << "Sp. Ataque: " << pj.getSpAttack() << "  Sp. Defesa: " << pj.getSpDefense() << "  Velocidade: " << pj.getSpeed() << std::endl;
    std::cout << "Natureza: " << pj.getNatureza() << std::endl;
    std::cout << "Habilidade: " << escolherHabilidadeAleatoria(pj.getBase().getAbilities()) << std::endl;
}

void GameManager::exibirPokemonPokedex(const Pokemon& p) {
    std::cout << "Pokemon ID: " << p.getId() << " - " << p.getNome() << std::endl;
    std::cout << "Tipo 1: " << p.getTipo1() << " | Tipo 2: " << p.getTipo2() << std::endl;
    std::cout << "Categoria: " << p.getCategory() << std::endl;
    std::cout << "Resistências: " << p.getResistances() << std::endl;
    std::cout << "Fraquezas: " << p.getWeaknesses() << std::endl;
    std::cout << "Habilidades: " << p.getAbilities() << std::endl;
}

void GameManager::exibirItem(const Item& item) {
    std::cout << "Item ID: " << item.getId() << " - " << item.getNome() << std::endl;
    std::cout << "Categoria: " << item.getCategoria() << " | Preço: " << item.getPreco() << std::endl;
    std::cout << "Raridade: " << item.getRaridade() << std::endl;
    std::cout << "Efeito Contest: " << item.getEfeitoContest() << std::endl;
    std::cout << "Descrição: " << item.getDescricao() << std::endl;
}

void GameManager::exibirBerry(const Berry& berry) {
    std::cout << "Berry ID: " << berry.getId() << " - " << berry.getNome() << std::endl;
    std::cout << "Picante: " << berry.getPicante() << " | Seco: " << berry.getSeco() << " | Doce: " << berry.getDoce() << std::endl;
    std::cout << "Amargo: " << berry.getAmargo() << " | Azedo: " << berry.getAzedo() << std::endl;
    std::cout << "Raridade: " << berry.getRaridade() << std::endl;
    std::cout << "Descrição: " << berry.getDescricao() << std::endl;
}

void GameManager::exibirPokeblock(const Pokeblock& pblock) {
    std::cout << "Pokeblock ID: " << pblock.getId() << " - " << pblock.getNome() << std::endl;
    std::cout << "Cor: " << pblock.getCor() << " | Nível: " << pblock.getNivel() << std::endl;
    std::cout << "Picante: " << pblock.getPicante() << " | Seco: " << pblock.getSeco() << " | Doce: " << pblock.getDoce() << std::endl;
    std::cout << "Amargo: " << pblock.getAmargo() << " | Azedo: " << pblock.getAzedo() << std::endl;
    std::cout << "Condição: " << pblock.getCondicao() << std::endl;
    std::cout << "Efeito: " << pblock.getEfeito() << std::endl;
    std::cout << "Raridade: " << pblock.getRaridade() << std::endl;
}

// Exemplo simples de consultar berry por ID
void GameManager::consultarBerryPorID(int id) {
    auto it = std::find_if(berries.begin(), berries.end(), [id](const Berry& b){ return b.getId() == id; });
    if(it != berries.end()) {
        exibirBerry(*it);
    } else {
        std::cout << "Berry com ID " << id << " não encontrada." << std::endl;
    }
}

// Consultar berry por nome
void GameManager::consultarBerryPorNome() {
    std::string nome;
    std::cout << "Digite o nome da Berry: ";
    std::getline(std::cin, nome);
    nome = Utils::toLower(Utils::trim(nome));

    for(const auto& b : berries) {
        if(Utils::toLower(b.getNome()) == nome) {
            exibirBerry(b);
            return;
        }
    }
    std::cout << "Berry com nome \"" << nome << "\" não encontrada." << std::endl;
}

// Consultar berries por raridade
void GameManager::consultarBerryPorRaridade() {
    std::string raridade;
    std::cout << "Digite a raridade: ";
    std::getline(std::cin, raridade);
    raridade = Utils::toLower(Utils::trim(raridade));

    bool achou = false;
    for(const auto& b : berries) {
        if(Utils::toLower(b.getRaridade()) == raridade) {
            exibirBerry(b);
            std::cout << "------------------------" << std::endl;
            achou = true;
        }
    }
    if(!achou) std::cout << "Nenhuma Berry encontrada com raridade \"" << raridade << "\"" << std::endl;
}

// Exemplo de menu para consulta de berries
void GameManager::menuConsultaBerries() {
    int opcao = 0;
    do {
        std::cout << "\n=== Consulta Berries ===\n";
        std::cout << "1. Consultar por ID\n";
        std::cout << "2. Consultar por Nome\n";
        std::cout << "3. Consultar por Raridade\n";
        std::cout << "0. Voltar\n";
        std::cout << "Escolha: ";
        std::cin >> opcao;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // limpar buffer

        switch(opcao) {
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
                std::cout << "Opção inválida.\n";
        }
    } while(opcao != 0);
}

// Implementar menus e consultas para os demais (Itens, Pokeblocks, Pokemons, etc)
// seguindo a mesma estrutura acima.

// Métodos para salvar/carregar jogo (exemplo simples)
void GameManager::salvarJogo() {
    std::ofstream ofs("savegame.txt");
    if(!ofs) {
        std::cout << "Erro ao salvar o jogo." << std::endl;
        return;
    }
    // Exemplo: salvar nome do jogador
    ofs << jogador.getNome() << std::endl;
    // Pode salvar mais dados aqui
    ofs.close();
    std::cout << "Jogo salvo com sucesso." << std::endl;
}

bool GameManager::carregarJogoSalvo() {
    std::ifstream ifs("savegame.txt");
    if(!ifs) {
        std::cout << "Nenhum jogo salvo encontrado." << std::endl;
        return false;
    }
    std::string nomeJogador;
    std::getline(ifs, nomeJogador);
    jogador.setNome(nomeJogador);
    ifs.close();
    std::cout << "Jogo carregado para o jogador " << nomeJogador << std::endl;
    return true;
}

void GameManager::iniciarJogo() {
    std::cout << "=== Bem-vindo ao Mundo Pokemon! ===\n";

    if(!carregarJogoSalvo()) {
        std::string nome;
        std::cout << "Digite seu nome, treinador: ";
        std::getline(std::cin, nome);

        PokemonJogador inicial = escolherPokemonInicial(nome);
        std::cout << "Seu Pokémon inicial é " << inicial.getBase().getNome() << "!\n";
    }

    menuPrincipal();
}

PokemonJogador GameManager::escolherPokemonInicial(const std::string& nomeJogador) {    
    if(pokemons.empty()) {
        throw std::runtime_error("Lista de pokemons vazia");
    }
    Pokemon base = pokemons[0];
    Nature nat = escolherNatureAleatoria();
    PokemonJogador pj = calcularStatusPokemon(base, 5, nat);
    jogador.setNome(nomeJogador);
    jogador.addPokemon(pj);
    return pj;
}

void GameManager::menuPrincipal() {
    int opcao = 0;
    do {
        std::cout << "\n=== Menu Principal ===\n";
        std::cout << "1. Consultar Pokemons\n";
        std::cout << "2. Consultar Itens\n";
        std::cout << "3. Consultar Berries\n";
        std::cout << "4. Consultar Pokeblocks\n";
        std::cout << "5. Salvar Jogo\n";
        std::cout << "6. Carregar Jogo\n";
        std::cout << "0. Sair\n";
        std::cout << "Escolha: ";
        std::cin >> opcao;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch(opcao) {
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
            case 0:
                std::cout << "Saindo..." << std::endl;
                break;
            default:
                std::cout << "Opção inválida." << std::endl;
        }
    } while(opcao != 0);
}

// Aqui o esqueleto para os menus de outros itens:
void GameManager::menuConsultaPokemon() {
    std::cout << "[Menu consultar Pokemons ainda não implementado]" << std::endl;
}

void GameManager::menuConsultaItens() {
    std::cout << "[Menu consultar Itens ainda não implementado]" << std::endl;
}

void GameManager::menuConsultaPokeblocks() {
    std::cout << "[Menu consultar Pokeblocks ainda não implementado]" << std::endl;
}

void GameManager::mostrarBolsaItens() {
    std::cout << "[Mostrar bolsa itens ainda não implementado]" << std::endl;
}

void GameManager::mostrarBolsaBerries() {
    std::cout << "[Mostrar bolsa berries ainda não implementado]" << std::endl;
}

void GameManager::mostrarBolsaPokeblocks() {
    std::cout << "[Mostrar bolsa pokeblocks ainda não implementado]" << std::endl;
}

void GameManager::menuBolsa() {
    std::cout << "[Menu bolsa ainda não implementado]" << std::endl;
}

void GameManager::exibirTime() {
    std::cout << "[Exibir time ainda não implementado]" << std::endl;
}

void GameManager::consultarItemPorID(int id) {
    std::cout << "[Consultar item por ID ainda não implementado]" << std::endl;
}

void GameManager::consultarItemPorNome() {
    std::cout << "[Consultar item por nome ainda não implementado]" << std::endl;
}

void GameManager::consultarPokeblockPorID(int id) {
    std::cout << "[Consultar pokeblock por ID ainda não implementado]" << std::endl;
}

void GameManager::consultarPokeblockPorNome() {
    std::cout << "[Consultar pokeblock por nome ainda não implementado]" << std::endl;
}

void GameManager::consultarPokeblockPorCor() {
    std::cout << "[Consultar pokeblock por cor ainda não implementado]" << std::endl;
}

void GameManager::consultarPokeblockPorRaridade() {
    std::cout << "[Consultar pokeblock por raridade ainda não implementado]" << std::endl;
}

void GameManager::consultarPokemonPorID(int id) {
    std::cout << "[Consultar pokemon por ID ainda não implementado]" << std::endl;
}

void GameManager::consultarPokemonPorNome() {
    std::cout << "[Consultar pokemon por nome ainda não implementado]" << std::endl;
}

void GameManager::consultarPokemonPorTipo() {
    std::cout << "[Consultar pokemon por tipo ainda não implementado]" << std::endl;
}
