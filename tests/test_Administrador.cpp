#include "doctest.h"
#include "Administrador.hpp"

TEST_SUITE("Administrador") {
 
    TEST_CASE("Construtor inicializa usuário com nível de acesso Admin") {
        Administrador adm("Root", "root@loja.com", "adminSecret");
        CHECK(adm.usuario.nome  == "Root");
        CHECK(adm.usuario.email == "root@loja.com");
        CHECK(adm.usuario.nivelDeAcesso ==
              static_cast<int>(NivelDeAcesso::Admin));
    }
 
 
    TEST_CASE("Admin possui acesso de Admin") {
        Administrador adm("Root", "root@loja.com", "adminSecret");
        CHECK(adm.usuario.possuiAcesso(
                  static_cast<int>(NivelDeAcesso::Admin)) == true);
    }
 
    TEST_CASE("Admin não deve ser confundido com Cliente") {
        Administrador adm("Root", "root@loja.com", "adminSecret");
        CHECK(adm.usuario.nivelDeAcesso !=
              static_cast<int>(NivelDeAcesso::Cliente));
    }
 
    TEST_CASE("gerenciarCatalogo não lança exceção") {
        Administrador adm("Root", "root@loja.com", "adminSecret");
        CHECK_NOTHROW(adm.gerenciarCatalogo());
    }
 
    TEST_CASE("gerenciarEstoque não lança exceção") {
        Administrador adm("Root", "root@loja.com", "adminSecret");
        CHECK_NOTHROW(adm.gerenciarEstoque());
    }
}
