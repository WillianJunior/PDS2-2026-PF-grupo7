#include "doctest.h"
#include "Compra.hpp"

TEST_CASE("Teste de criação de Compra") {
    std::vector<Produto> itens; // Lista de produtos vazia para o teste
    Compra compra(1, 1, itens, "2024-06-01", "Cartão de Crédito");
    
    CHECK(compra.getIdCompra() == 1); // Verifica se o ID da compra é 1
    CHECK(compra.getIdCliente() == 1); // Verifica se o ID do cliente é 1
    CHECK(compra.getItens().empty() == true); // Verifica se a lista de itens está vazia
    CHECK(compra.getDataCompra() == "2024-06-01"); // Verifica se a data da compra é correta
    CHECK(compra.getMetodoPagamento() == "Cartão de Crédito"); // Verifica se o método de pagamento é correto
}