#include "doctest.hpp"
#include "../include/pokemon.hpp"
#include <stdexcept>
#include <string>

TEST_CASE("Entradas validas") {
    std::string linha = "001,Bulbasaur,Grass,Poison,45,49,65,49,65,45,60,50,70,65,50,Grass/Poison/Water/Electric/Fighting/Fairy,Fire/Ice/Flying/Psychic,Overgrow/Chlorophyll,Seed Pokémon,002/Ivysaur/16";
    Pokemon pk = Pokemon::fromCSV(linha);

    CHECK(pk.getId() == 001);
    CHECK(pk.getNome() == "Bulbasaur");
    CHECK(pk.getTipo1() == "Grass");
    CHECK(pk.getTipo2() == "Poison");
    CHECK(pk.getHp() == 45);
    CHECK(pk.getAttack() == 49);
    CHECK(pk.getSpAttack() == 65);
    CHECK(pk.getDefense() == 49);
    CHECK(pk.getSpDefense() == 65);
    CHECK(pk.getSpeed() == 45);
    CHECK(pk.getContestBeauty() == 60);
    CHECK(pk.getContestCool() == 50);
    CHECK(pk.getContestCute() == 70);
    CHECK(pk.getContestSmart() == 65);
    CHECK(pk.getContestTough() == 50);
    CHECK(pk.getResistances() == "Grass/Poison/Water/Electric/Fighting/Fairy");
    CHECK(pk.getWeaknesses() == "Fire/Ice/Flying/Psychic");
    CHECK(pk.getAbilities() == "Overgrow/Chlorophyll");
    CHECK(pk.getCategory() == "Seed Pokémon");
    CHECK(pk.getEvolutions() == "002/Ivysaur/16");

}

TEST_CASE("Campo Nome vazio") {
    std::string linha = "001,,Grass,Poison,45,49,65,49,65,45,60,50,70,65,50,Grass/Poison/Water/Electric/Fighting/Fairy,Fire/Ice/Flying/Psychic,Overgrow/Chlorophyll,Seed Pokémon,002/Ivysaur/16";
    CHECK_THROWS_AS(Pokemon::fromCSV(linha), std::invalid_argument);
}

TEST_CASE("Campo Tipo1 vazio") {
    std::string linha = "001,Bulbasaur,,Poison,45,49,65,49,65,45,60,50,70,65,50,Grass/Poison/Water/Electric/Fighting/Fairy,Fire/Ice/Flying/Psychic,Overgrow/Chlorophyll,Seed Pokémon,002/Ivysaur/16";
    CHECK_THROWS_AS(Pokemon::fromCSV(linha), std::invalid_argument);
}

TEST_CASE("Campo Resistences vazio") {
    std::string linha = "001,Bulbasaur,Grass,Poison,45,49,65,49,65,45,60,50,70,65,50,,Fire/Ice/Flying/Psychic,Overgrow/Chlorophyll,Seed Pokémon,002/Ivysaur/16";
    CHECK_THROWS_AS(Pokemon::fromCSV(linha), std::invalid_argument);
}

TEST_CASE("Campo Weakness vazio") {
    std::string linha = "001,Bulbasaur,Grass,Poison,45,49,65,49,65,45,60,50,70,65,50,Grass/Poison/Water/Electric/Fighting/Fairy,,Overgrow/Chlorophyll,Seed Pokémon,002/Ivysaur/16";
    CHECK_THROWS_AS(Pokemon::fromCSV(linha), std::invalid_argument);
}

TEST_CASE("Campo Abilities vazio") {
    std::string linha = "001,Bulbasaur,Grass,Poison,45,49,65,49,65,45,60,50,70,65,50,Grass/Poison/Water/Electric/Fighting/Fairy,Fire/Ice/Flying/Psychic,,Seed Pokémon,002/Ivysaur/16";
    CHECK_THROWS_AS(Pokemon::fromCSV(linha), std::invalid_argument);
}

TEST_CASE("Campo Categories vazio") {
    std::string linha = "001,Bulbasaur,Grass,Poison,45,49,65,49,65,45,60,50,70,65,50,Grass/Poison/Water/Electric/Fighting/Fairy,Fire/Ice/Flying/Psychic,Overgrow/Chlorophyll,,002/Ivysaur/16";
    CHECK_THROWS_AS(Pokemon::fromCSV(linha), std::invalid_argument);
}


