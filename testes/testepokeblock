#include "doctest.hpp"
#include "../include/pokeblock.hpp"
#include <stdexcept>
#include <string>

TEST_CASE("Entradas validas") {
    std::string linha = "PB001,Basic Red,Red,10,15,0,0,0,0,Spicy ≥ 60%,Coolness +10,Common";
    Pokeblock p = Pokeblock::fromCSV(linha);

    CHECK(p.getId() == 001);
    CHECK(p.getNome() == "Basic Red");
    CHECK(p.getCor() == "Red");
    CHECK(p.getNivel() == 10);
    CHECK(p.getPicante() == 15);
    CHECK(p.getSeco() == 0);
    CHECK(p.getDoce() == 0);
    CHECK(p.getAmargo() == 0);
    CHECK(p.getAzedo() == 0);
    CHECK(p.getCondicao() == "Spicy ≥ 60%");
    CHECK(p.getEfeito() == "Coolness +10");
    CHECK(p.getRaridade() == "Common");
}

TEST_CASE("Campo Nome vazio") {
    std::string linha = "PB001,,Red,10,15,0,0,0,0,Spicy ≥ 60%,Coolness +10,Common";
    CHECK_THROWS_AS(Pokeblock::fromCSV(linha), std::invalid_argument);
}

TEST_CASE("Campo Cor vazio") {
    std::string linha = "PB001,Basic Red,,10,15,0,0,0,0,Spicy ≥ 60%,Coolness +10,Common";
    CHECK_THROWS_AS(Pokeblock::fromCSV(linha), std::invalid_argument);
}

TEST_CASE("Campo Condicao vazio") {
    std::string linha = "PB001,Basic Red,Red,10,15,0,0,0,0,,Coolness +10,Common";
    CHECK_THROWS_AS(Pokeblock::fromCSV(linha), std::invalid_argument);
}

TEST_CASE("Campo Efeito vazio") {
    std::string linha = "PB001,,Red,10,15,0,0,0,0,Spicy ≥ 60%,,Common";
    CHECK_THROWS_AS(Pokeblock::fromCSV(linha), std::invalid_argument);
}

TEST_CASE("Campo Raridade vazio") {
    std::string linha = "PB001,,Red,10,15,0,0,0,0,Spicy ≥ 60%,Coolness +10,";
    CHECK_THROWS_AS(Pokeblock::fromCSV(linha), std::invalid_argument);
}

