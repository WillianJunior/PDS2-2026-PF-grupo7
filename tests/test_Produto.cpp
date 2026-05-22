#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Produto.hpp"

TEST_CASE("Teste de criação de Produto") {
    Produto produto;
    CHECK(produto.getId() == 0); // Verifica se o ID é inicializado como 0
    CHECK(produto.getNome() == ""); // Verifica se o nome é inicializado como vazio
    CHECK(produto.getCategoria() == ""); // Verifica se a categoria é inicializada como vazia
    CHECK(produto.getPreco() == 0.0f); // Verifica se o preço é inicializado como 0.0
    CHECK(produto.getQuantidadeEstoque() == 0); // Verifica se a quantidade em estoque é inicializada como 0
}