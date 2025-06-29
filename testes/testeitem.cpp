#include "doctest.hpp"
#include "../include/item.hpp"
#include <stdexcept>
#include <string>

TEST_CASE("Entradas validas") {
  std::string linha = "0001,Ability Capsule,Held Item,3000,Rare,Coolness +7,Allows Pokémon to switch abilities during performance";

  Item i = Item::fromCSV(linha);

  CHECK(i.getId() == 0001);
  CHECK(i.getNome() == "Ability Capsule");
  CHECK(i.getCategoria() == "Held Item");
  CHECK(i.getPreco() == 3000);
  CHECK(i.getRaridade() == "Rare");
  CHECK(i.getEfeitoContest() == "Coolness +7");
  CHECK(i.getDescricao() == "Allows Pokémon to switch abilities during performance");
}


