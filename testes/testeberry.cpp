#include "doctest.hpp"
#include "../include/berry.hpp"
#include <stdexcept>
#include <string>

TEST_CASE("Entradas validas") {
    std::string linha = "001,Cheri Berry,10,0,2,0,0,Common,Berry that slightly boosts Coolness";
    Berry b = Berry::fromCSV(linha);

    CHECK(b.getId() == 001);
    CHECK(b.getNome() == "Cheri Berry");
    CHECK(b.getPicante() == 10);
    CHECK(b.getSeco() == 0);
    CHECK(b.getDoce() == 2);
    CHECK(b.getAmargo() == 0);
    CHECK(b.getAzedo() == 0);
    CHECK(b.getRaridade() == "Common");
    CHECK(b.getDescricao() == "Berry that slightly boosts Coolness");
}

TEST_CASE("Campo Nome vazio") {
    std::string linha = "001,,10,0,2,0,0,Common,Berry that slightly boosts Coolness";
    CHECK_THROWS_AS(Berry::fromCSV(linha), std::invalid_argument);
}

TEST_CASE("Campo raridade vazio") {
    std::string linha = "001,Cheri Berry,10,0,2,0,0,,Berry that slightly boosts Coolness";
    CHECK_THROWS_AS(Berry::fromCSV(linha), std::invalid_argument);
}

TEST_CASE("Campo Descricao vazio") {
    std::string linha = "001,Cheri Berry,10,0,2,0,0,Common,";
    CHECK_THROWS_AS(Berry::fromCSV(linha), std::invalid_argument);
}