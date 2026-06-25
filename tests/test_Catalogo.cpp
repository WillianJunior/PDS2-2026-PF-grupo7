#include "doctest.h"
#include "Catalogo.hpp"

TEST_SUITE("Catalogo") {
 
    TEST_CASE("carregarCatalogo com arquivo inexistente não lança exceção") {
        // Deve retornar um catálogo vazio ou tratado sem crash
        Catalogo cat;
        CHECK_NOTHROW(cat = Catalogo::carregarCatalogo("arquivo_inexistente.txt"));
    }
 
    TEST_CASE("exibirCatalogo não lança exceção em catálogo vazio") {
        Catalogo cat = Catalogo::carregarCatalogo("jogos.txt");
        CHECK_NOTHROW(cat.exibirCatalogo());
    }
 
    TEST_CASE("filtrarGenero não lança exceção") {
        Catalogo cat = Catalogo::carregarCatalogo("jogos.txt");
        CHECK_NOTHROW(cat.filtrarGenero("RPG"));
    }
 
    TEST_CASE("filtrarPlataforma não lança exceção") {
        Catalogo cat = Catalogo::carregarCatalogo("jogos.txt");
        CHECK_NOTHROW(cat.filtrarPlataforma("PC"));
    }
 
    TEST_CASE("ordenarPreco não lança exceção") {
        Catalogo cat = Catalogo::carregarCatalogo("jogos.txt");
        CHECK_NOTHROW(cat.ordenarPreco());
    }
 
    /*TEST_CASE("comprar recebe referência de Carrinho sem lançar exceção") {
        Usuario u("Test", "t@t.com", "p", static_cast<int>(NivelDeAcesso::Cliente));
        Carrinho carrinho(u);
        Catalogo cat = Catalogo::carregarCatalogo("jogos.txt");
        CHECK_NOTHROW(cat.comprar(carrinho));
    }*/ 
}
 
