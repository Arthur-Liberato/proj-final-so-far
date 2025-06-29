#include "doctest.hpp"
#include "../include/nature.hpp"
#include <stdexcept>
#include <string>

TEST_CASE("Entradas validas") {
    std::string linha = "Lonely,Ataque,Defesa";
    Nature n = Nature::fromCSV(linha);

    CHECK(n.getNome() == "Lonely");
    CHECK(n.getAumento() == "Ataque");
    CHECK(n.getDiminuicao() == "Defesa");
    
}

TEST_CASE("Campo Nome vazio") {
    std::string linha = ",Ataque,Defesa";
    CHECK_THROWS_AS(Nature::fromCSV(linha), std::invalid_argument);
}

TEST_CASE("Campo Aumento vazio") {
    std::string linha = "Lonely,,Defesa";
    CHECK_THROWS_AS(Nature::fromCSV(linha), std::invalid_argument);
}

TEST_CASE("Campo Diminuicao vazio") {
    std::string linha = "Lonely,Ataque,";
    CHECK_THROWS_AS(Nature::fromCSV(linha), std::invalid_argument);
}