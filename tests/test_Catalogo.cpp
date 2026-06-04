#include "doctest.h"
#include "Catalogo.hpp"

TEST_CASE("Teste de criação de Catalogo") {
    Catalogo catalogo;
    CHECK(catalogo.getProdutos().empty() == true); // Verifica se a lista de produtos está vazia
}

TEST_CASE("Teste de adição e remoção de produtos") {
    Catalogo catalogo;
    Produto produto(1, "Produto A", "Categoria X", 10.0f, 100);
    catalogo.adicionarProduto(produto); // Adiciona um produto ao catálogo
    CHECK(catalogo.getProdutos().size() == 1); // Verifica se o produto foi adicionado

    catalogo.removerProduto(1); // Remove o produto do catálogo
    CHECK(catalogo.getProdutos().empty() == true); // Verifica se o produto foi removido
}

TEST_CASE("Teste de filtragem por categoria") {
    Catalogo catalogo;
    Produto produto1(1, "Produto A", "Categoria X", 10.0f, 100);
    Produto produto2(2, "Produto B", "Categoria Y", 20.0f, 50);
    catalogo.adicionarProduto(produto1);
    catalogo.adicionarProduto(produto2);

    auto produtosCategoriaX = catalogo.filtrarPorCategoria("Categoria X");
    CHECK(produtosCategoriaX.size() == 1); // Verifica se apenas um produto foi filtrado
    CHECK(produtosCategoriaX[0].getNome() == "Produto A"); // Verifica se o produto filtrado é o correto
}