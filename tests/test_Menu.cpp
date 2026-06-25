#include "doctest.h"
#include "Menu.hpp"
#include "EstadosDeMenu.hpp"
#include <sstream>
#include <iostream>

struct StreamRedirect {
    std::streambuf* oldCin;
    std::streambuf* oldCout;
    std::istringstream fakeIn;
    std::ostringstream fakeOut;

    StreamRedirect(const std::string& input) : fakeIn(input) {
        oldCin  = std::cin.rdbuf(fakeIn.rdbuf());
        oldCout = std::cout.rdbuf(fakeOut.rdbuf());
    }
    ~StreamRedirect() {
        std::cin.rdbuf(oldCin);
        std::cout.rdbuf(oldCout);
    }
};

// ─────────────────────────────────────────────
// lerComando
// ─────────────────────────────────────────────
TEST_CASE("lerComando retorna o inteiro digitado") {
    StreamRedirect io("3\n");
    Menu menu;
    CHECK(menu.lerComando() == 3);
}

TEST_CASE("lerComando aceita entrada negativa") {
    StreamRedirect io("-1\n");
    Menu menu;
    CHECK(menu.lerComando() == -1);
}

TEST_CASE("lerComando recupera de entrada invalida e le o proximo inteiro") {
    StreamRedirect io("abc\n2\n");
    Menu menu;
    CHECK(menu.lerComando() == 2);
}

// ─────────────────────────────────────────────
// menuInicial
// ─────────────────────────────────────────────
TEST_CASE("menuInicial: opcao 1 retorna Login") {
    StreamRedirect io("1\n");
    Menu menu;
    CHECK(menu.menuInicial() == EstadosDeMenu::Login);
}

TEST_CASE("menuInicial: opcao 2 retorna VerCatalogo") {
    StreamRedirect io("2\n");
    Menu menu;
    CHECK(menu.menuInicial() == EstadosDeMenu::VerCatalogo);
}

TEST_CASE("menuInicial: opcao 3 retorna Cadastro") {
    StreamRedirect io("3\n");
    Menu menu;
    CHECK(menu.menuInicial() == EstadosDeMenu::Cadastro);
}

TEST_CASE("menuInicial: opcao 4 retorna Sair") {
    StreamRedirect io("4\n");
    Menu menu;
    CHECK(menu.menuInicial() == EstadosDeMenu::Sair);
}

TEST_CASE("menuInicial: opcao invalida permanece em MenuInicial") {
    StreamRedirect io("99\n");
    Menu menu;
    CHECK(menu.menuInicial() == EstadosDeMenu::MenuInicial);
}