# Projeto Final – Jogo Pokémon

## Descrição do Problema

Este projeto implementa um jogo estilo Pokémon em linha de comando, onde cada criatura (Pokémon) possui atributos de combate (HP, Attack, Defense etc.) e atributos de concurso (Beauty, Cool, Cute, Smart, Tough). O jogador pode carregar dados de diferentes fontes (berries, itens, pokéblocks, natures e pokémons) a partir de arquivos CSV, consultar, visualizar e interagir com esses elementos, além de salvar e carregar seu progresso.

## Visão Geral da Solução

A solução foi construída em C++ seguindo uma arquitetura em camadas:

1. **Modelos (`include/`)**  
   - **`Berry`**, **`Item`**, **`Pokeblock`**, **`Nature`**, **`Pokemon`**, **`PokemonJogador`**, **`Jogador`**: representam as entidades do domínio, com getters, setters e conversão de linhas CSV (`fromCSV`).

2. **Carregamento de Dados (`src/dataloader.cpp`)**  
   - **`DataLoader`**: carrega todos os CSVs e transforma cada linha em instâncias das classes modelo, retornando vetores de objetos.

3. **Lógica de Jogo (`src/gamemanager.cpp`)**  
   - **`GameManager`**: responsável pelo loop principal, menus de consulta (por ID, nome, tipo, cor, raridade etc.), exibição formatada em tabelas, geração de IVs aleatórios, escolha de habilidades e natures, cálculo de status dos pokémons do jogador e persistência (salvar/carregar jogo).

4. **Funções Auxiliares (`include/utils.hpp`)**  
   - Métodos estáticos para converter strings em inteiros com segurança (`safeStoi`), transformar texto em minúsculas (`toLower`) e remover espaços extras (`trim`).

5. **Ponto de Entrada (`src/main.cpp`)**  
   - Inicializa o `GameManager`, carrega dados e inicia o menu principal.

<img src="https://raw.githubusercontent.com/Arthur-Liberato/PDS2-20251-TF-Jogo-Pokemon/main/textos/fluxograma.png" alt="Fluxograma do Jogo" width="600"/>

## Principais Dificuldades

- **Parser CSV robusto**: lidar com campos de texto que podem conter vírgulas e espaços em branco.
- **Formatação de saída**: criar tabelas legíveis no console, alinhando colunas dinamicamente.
- **Persistência de estado**: projetar um formato simples para salvar e carregar o progresso do jogador, incluindo seu time de pokémons e inventário.
- **Estrutura de menus**: permitir navegação intuitiva entre consultas a diferentes tipos de objetos (berries, itens, pokéblocks, pokémons).

## Extras Implementados

- **Salvamento/Carregamento de Jogo**  
  - Métodos `salvarJogo()` e `carregarJogoSalvo()` para gravar/recuperar o estado completo do jogador (nome, dinheiro, pokémons, itens, berries e pokéblocks).

- **Menus de Consulta Avançados**  
  - Filtros por raridade, cor, tipo e busca por substring de nome.
  - Submenus separados para cada categoria de objeto.

- **Pokédex Interativa**  
  - Exibe informações detalhadas de cada Pokémon base (tipos, estatísticas, habilidades, evoluções, resistências e fraquezas).

- **Sistema de Concursos**  
  - Exibição dos valores de contest (beauty, cool, cute, smart, tough) e aplicação de efeitos de berries/pokéblocks nessas categorias.

- **Geração Aleatória de IVs e Nature**  
  - Implementação de funções para criar valores de IVs randômicos e escolher aleatoriamente a natureza que aumenta/diminui atributos.

- **Documentação Auto-gerada**  
  - Configuração de Doxygen para extrair comentários de todas as classes (`EXTRACT_ALL = YES`) e gerar documentação HTML em `docs/html/`.
