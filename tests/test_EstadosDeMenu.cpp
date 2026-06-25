#include "doctest.h"
#include "EstadosDeMenu.hpp"

TEST_SUITE("EstadosDeMenu") {
 
    TEST_CASE("Estados de menu existem e são distintos") {
        CHECK(EstadosDeMenu::MenuInicial       != EstadosDeMenu::Login);
        CHECK(EstadosDeMenu::MenuPrincipal     != EstadosDeMenu::MenuPrincipalCliente);
        CHECK(EstadosDeMenu::MenuPrincipalAdmin!= EstadosDeMenu::MenuPrincipalCliente);
        CHECK(EstadosDeMenu::Sair              != EstadosDeMenu::MenuInicial);
    }
 
    TEST_CASE("Estados de cliente estão definidos") {
        // Garante que os estados do fluxo do cliente compilam e existem
        EstadosDeMenu e1 = EstadosDeMenu::VerCatalogo;
        EstadosDeMenu e2 = EstadosDeMenu::Carrinho;
        EstadosDeMenu e3 = EstadosDeMenu::MinhasCompras;
        EstadosDeMenu e4 = EstadosDeMenu::EditarMeusDados;
        CHECK(e1 != e2);
        CHECK(e3 != e4);
    }
 
    TEST_CASE("Estados de admin estão definidos") {
        EstadosDeMenu e1 = EstadosDeMenu::GerenciarProduto;
        EstadosDeMenu e2 = EstadosDeMenu::GerenciarCatalogo;
        EstadosDeMenu e3 = EstadosDeMenu::GerenciarEstoque;
        EstadosDeMenu e4 = EstadosDeMenu::VerEstoque;
        CHECK(e1 != e2);
        CHECK(e3 != e4);
    }
}
