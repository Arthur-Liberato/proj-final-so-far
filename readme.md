# Projeto Final – Jogo Pokémon

## Descrição do Problema

Este projeto implementa um jogo estilo Pokémon em linha de comando, onde cada criatura possui atributos de combate (HP, Attack, Defense etc.) e atributos de concurso (Beauty, Cool, Cute, Smart, Tough). O jogador pode carregar dados de diferentes fontes (berries, itens, pokéblocks, natures e pokémons) a partir de arquivos CSV, consultar, visualizar e interagir com esses elementos, além de salvar e carregar seu progresso.

---

## Visão Geral da Solução

A solução foi construída em C++, seguindo uma arquitetura modular organizada em camadas:

### 1. Modelos
`include/`


- `Berry`, `Item`, `Pokeblock`, `Nature`, `Pokemon`, `PokemonJogador`, `Jogador`  
  Representam as entidades do domínio, com atributos privados, métodos getters/setters e método estático `fromCSV` para construir instâncias a partir de linhas dos arquivos CSV.

---

### 2. Carregamento de Dados 
`src/dataloader.cpp`

- **DataLoader**  
  Responsável por ler todos os CSVs e transformar cada linha em instâncias das classes modelo, retornando vetores de objetos prontos para uso.

---

### 3. Lógica de Jogo 
`src/gamemanager.cpp`

- **GameManager**  
  Controla o fluxo principal do programa:
  - Exibe menus interativos para o jogador.
  - Permite consultas por ID, nome, tipo, cor ou raridade.
  - Gera IVs aleatórios para Pokémon.
  - Escolhe habilidades e natures de forma aleatória.
  - Calcula status completos dos Pokémon do jogador.
  - Gerencia o inventário (itens, berries, pokéblocks).
  - Salva e carrega o progresso do jogo.

---

### 4. Funções Auxiliares 
`include/utils.hpp`

- Contém métodos estáticos para:
  - Conversão segura de string para inteiro (`safeStoi`).
  - Transformação de texto para minúsculas (`toLower`).
  - Remoção de espaços extras (`trim`).

---

### 5. Ponto de Entrada 
`src/main.cpp`

- Inicializa o **GameManager**, carrega os dados e inicia o menu principal.


## Principais Dificuldades

- **Leitura e parse de CSVs**: lidar com campos de texto contendo vírgulas ou espaços.
- **Formatação no terminal**: criar tabelas legíveis com colunas alinhadas.
- **Persistência de estado**: salvar e carregar o progresso do jogador, incluindo time e inventário.
- **Navegação de menus**: desenhar fluxos intuitivos para consultas por diferentes filtros (nome, tipo, cor, raridade).

---

## Extras Implementados

- **Salvamento e Carregamento de Jogo**  
  - Funções `salvarJogo()` e `carregarJogoSalvo()` para gravar e restaurar o estado completo do jogador (nome, dinheiro, pokémons, itens, berries, pokéblocks).

- **Menus de Consulta Avançada**  
  - Filtros por raridade, cor, tipo, além de buscas parciais por nome.
  - Submenus organizados por categoria (berries, itens, pokéblocks, pokémons).

- **Pokédex Interativa**  
  - Exibe informações detalhadas dos Pokémon: tipos, estatísticas base, habilidades, evoluções, resistências e fraquezas.

- **Sistema de Concursos**  
  - Mostra atributos de contest (beauty, cool, cute, smart, tough).
  - Aplica efeitos de berries e pokéblocks nesses atributos.

- **Geração Aleatória de IVs e Nature**  
  - Algoritmo para atribuir IVs randômicos aos Pokémon do jogador.
  - Seleção aleatória de naturezas que modificam os atributos.

- **Documentação Automática (Doxygen)**  
  - Configurada com `EXTRACT_ALL = YES`, gera documentação HTML completa com base nos comentários das classes, disponível em `docs/html/`.
