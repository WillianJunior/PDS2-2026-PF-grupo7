#include "doctest.h"
#include "Produto.hpp"

TEST_SUITE("Produto") {
 
    TEST_CASE("Construtor inicializa atributos corretamente") {
        Produto p("The Witcher 3", "PC", "RPG", 99.90);
        CHECK(p.nome       == "The Witcher 3");
        CHECK(p.plataforma == "PC");
        CHECK(p.genero     == "RPG");
        CHECK(p.preco      == doctest::Approx(99.90));
    }
 
    TEST_CASE("Preço zero é aceito") {
        Produto p("Jogo Grátis", "PC", "Ação", 0.0);
        CHECK(p.preco == doctest::Approx(0.0));
    }
 
    TEST_CASE("Preço negativo é armazenado como fornecido") {
        // O sistema não valida preço negativo no construtor — teste documenta o comportamento atual
        Produto p("Erro de Preço", "PS5", "Esporte", -10.0);
        CHECK(p.preco == doctest::Approx(-10.0));
    }
 
    TEST_CASE("Produtos com nomes diferentes são distintos") {
        Produto p1("FIFA 24", "PS5", "Esporte", 299.90);
        Produto p2("NBA 2K24", "PS5", "Esporte", 299.90);
        CHECK(p1.nome != p2.nome);
    }
 
    TEST_CASE("exibirProduto não lança exceção") {
        Produto p("Zelda", "Switch", "Aventura", 250.0);
        CHECK_NOTHROW(p.exibirProduto());
    }
}
