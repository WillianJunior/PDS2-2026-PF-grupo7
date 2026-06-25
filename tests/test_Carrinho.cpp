#include "doctest.h"
#include "Carrinho.hpp"
TEST_SUITE("Carrinho") {
 
    TEST_CASE("Carrinho começa vazio") {
        Usuario u("Maria", "maria@email.com", "pass",
                  static_cast<int>(NivelDeAcesso::Cliente));
        Carrinho c(u);
        CHECK(c.estaVazio() == true);
        CHECK(c.total()     == doctest::Approx(0.0));
    }
 
    TEST_CASE("Adicionar produto faz carrinho não ficar vazio") {
        Usuario u("Maria", "maria@email.com", "pass",
                  static_cast<int>(NivelDeAcesso::Cliente));
        Carrinho c(u);
        Produto p("Elden Ring", "PS5", "RPG", 299.90);
        c.adicionar(p);
        CHECK(c.estaVazio() == false);
    }
 
    TEST_CASE("Total reflete soma dos itens adicionados") {
        Usuario u("Maria", "maria@email.com", "pass",
                  static_cast<int>(NivelDeAcesso::Cliente));
        Carrinho c(u);
        c.adicionar(Produto("Jogo A", "PC", "Ação", 100.0));
        c.adicionar(Produto("Jogo B", "PC", "RPG",  50.0));
        CHECK(c.total() == doctest::Approx(150.0));
    }
 
     TEST_CASE("Remover item reduz total") {
        Usuario u("Maria", "maria@email.com", "pass",
                  static_cast<int>(NivelDeAcesso::Cliente));
        Carrinho c(u);
        c.adicionar(Produto("Jogo A", "PC", "Ação", 100.0));
        c.adicionar(Produto("Jogo B", "PC", "RPG",  50.0));
        c.remover(0); // remove o primeiro item
        CHECK(c.total() == doctest::Approx(50.0));
    }
 
    TEST_CASE("Remover único item deixa carrinho vazio") {
        Usuario u("Maria", "maria@email.com", "pass",
                  static_cast<int>(NivelDeAcesso::Cliente));
        Carrinho c(u);
        c.adicionar(Produto("Jogo A", "PC", "Ação", 100.0));
        c.remover(0);
        CHECK(c.estaVazio() == true);
    }
 
    TEST_CASE("exibirCarrinho não lança exceção com itens") {
        Usuario u("Maria", "maria@email.com", "pass",
                  static_cast<int>(NivelDeAcesso::Cliente));
        Carrinho c(u);
        c.adicionar(Produto("Jogo A", "PC", "Ação", 100.0));
        CHECK_NOTHROW(c.exibirCarrinho());
    }
 
    TEST_CASE("exibirCarrinho não lança exceção com carrinho vazio") {
        Usuario u("Maria", "maria@email.com", "pass",
                  static_cast<int>(NivelDeAcesso::Cliente));
        Carrinho c(u);
        CHECK_NOTHROW(c.exibirCarrinho());
    }
}
