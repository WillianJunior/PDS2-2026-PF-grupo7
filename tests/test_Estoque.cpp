#include "doctest.h"
#include "Estoque.hpp"

TEST_CASE("Teste de criação de Estoque") {
    Estoque estoque(10); // Limite de alerta definido como 10
    CHECK(estoque.getQuantidade(1) == 0); // Verifica se a quantidade do produto ID 1 é inicializada como 0
}
TEST_CASE("Teste de adição e remoção de produtos") {
    Estoque estoque(10);
    estoque.adicionarProduto(1, 20); // Adiciona 20 unidades do produto ID 1
    CHECK(estoque.getQuantidade(1) == 20); // Verifica se a quantidade foi atualizada para 20

    estoque.removerProduto(1, 5); // Remove 5 unidades do produto ID 1
    CHECK(estoque.getQuantidade(1) == 15); // Verifica se a quantidade foi atualizada para 15
}