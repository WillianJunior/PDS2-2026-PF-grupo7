#include "doctest.h"
#include "Cliente.hpp"

TEST_SUITE("Cliente") {
 
    TEST_CASE("Construtor inicializa usuário com nível de acesso Cliente") {
        Cliente cl("Pedro", "pedro@email.com", "senha456");
        CHECK(cl.usuario.nome  == "Pedro");
        CHECK(cl.usuario.email == "pedro@email.com");
        CHECK(cl.usuario.nivelDeAcesso ==
              static_cast<int>(NivelDeAcesso::Cliente));
    }
 
    TEST_CASE("Cliente possui carrinho vazio ao ser criado") {
        Cliente cl("Pedro", "pedro@email.com", "senha456");
        CHECK(cl.carrinho.estaVazio() == true);
        CHECK(cl.carrinho.total()     == doctest::Approx(0.0));
    }
 
    TEST_CASE("Carrinho do cliente aceita produtos") {
        Cliente cl("Pedro", "pedro@email.com", "senha456");
        cl.carrinho.adicionar(Produto("God of War", "PS5", "Ação", 199.90));
        CHECK(cl.carrinho.estaVazio() == false);
        CHECK(cl.carrinho.total()     == doctest::Approx(199.90));
    }
}
