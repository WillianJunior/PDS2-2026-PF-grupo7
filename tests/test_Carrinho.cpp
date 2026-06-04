#include "doctest.h"
#include "Carrinho.hpp"


TEST_CASE("Teste de criação de Carrinho") {
    Carrinho carrinho;
    CHECK(carrinho._getProdutos().empty() == true); // Verifica se a lista de produtos está vazia
}

TEST_CASE("Teste de cálculo do valor total e quantidade de itens") {
    Carrinho carrinho;
    std::vector<std::string> produtos; // Lista de produtos vazia para o teste
    CHECK(carrinho.calculaValorTotal(produtos) == 0.0f); // Verifica se o valor total é 0.0 para uma lista vazia
    CHECK(carrinho.calculaTotalDeItens(produtos) == 0); // Verifica se a quantidade total de itens é 0 para uma lista vazia
}