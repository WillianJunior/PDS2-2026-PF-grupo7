#include "doctest.h"
#include "Cliente.hpp"

TEST_CASE("Teste de criação de Cliente") {
    Cliente cliente;
    CHECK(cliente.getNome() == "");
    CHECK(cliente.getEmail() == "");
    CHECK(cliente.getSenha() == "");
}

TEST_CASE("Teste de histórico de compras") {
    Cliente cliente;
    CHECK(cliente._getHistoricoCompras().empty() == true);
}

TEST_CASE("Teste de classificação de produto") {
    Cliente cliente;
    cliente._classificarProduto(1, 5); // Classifica o produto com ID 1 com nota 5
    //implementar teste para ver se a nota foi dada ao produto
};

TEST_CASE("Teste de alteração de nome e endereço") {
    Cliente cliente;
    cliente._alterarNome("Novo Nome");
    cliente._alterarEndereco("Novo Endereço");
    CHECK(cliente.getNome() == "Novo Nome");
    CHECK(cliente.getEndereco() == "Novo Endereço");
}

TEST_CASE("Teste de gerenciamento do carrinho") {
    Cliente cliente;
    Carrinho carrinho;
    cliente._addProdutoCarrinho(1, carrinho); // Adiciona o produto com ID 1 ao carrinho
    CHECK(carrinho._getProdutos().size() >= 1);

    cliente._delProdutoCarrinho(1, carrinho); // Remove o produto com ID 1 do carrinho
    CHECK(carrinho._getProdutos().size() == 0); //implementar teste para ver se o produto foi removido do carrinho
    cliente._limparCarrinho(carrinho); // Limpa o carrinho
    CHECK(carrinho._getProdutos().size() == 0); //implementar teste para ver se o carrinho foi limpo
}
