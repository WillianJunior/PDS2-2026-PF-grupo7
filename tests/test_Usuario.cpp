#include "doctest.h"
#include "Usuario.hpp"

TEST_SUITE("Usuario") {
 
    TEST_CASE("Construtor inicializa atributos corretamente") {
        Usuario u("Ana Silva", "ana@email.com", "senha123",
                  static_cast<int>(NivelDeAcesso::Cliente));
        CHECK(u.nome          == "Ana Silva");
        CHECK(u.email         == "ana@email.com");
        CHECK(u.senha         == "senha123");
        CHECK(u.nivelDeAcesso == static_cast<int>(NivelDeAcesso::Cliente));
    }
 
    TEST_CASE("possuiAcesso retorna true para o próprio nível") {
        Usuario u("João", "joao@email.com", "abc",
                  static_cast<int>(NivelDeAcesso::Cliente));
        CHECK(u.possuiAcesso(static_cast<int>(NivelDeAcesso::Cliente)) == true);
    }
 
    TEST_CASE("possuiAcesso retorna false para nível superior") {
        Usuario u("João", "joao@email.com", "abc",
                  static_cast<int>(NivelDeAcesso::Cliente));
        CHECK(u.possuiAcesso(static_cast<int>(NivelDeAcesso::Admin)) == false);
    }
 
    TEST_CASE("Admin possui acesso de admin") {
        Usuario u("Carlos", "carlos@email.com", "adminpass",
                  static_cast<int>(NivelDeAcesso::Admin));
        CHECK(u.possuiAcesso(static_cast<int>(NivelDeAcesso::Admin)) == true);
    }
 
    TEST_CASE("login retorna nullptr para credenciais inexistentes") {
        // Arquivo inexistente deve retornar nullptr sem lançar exceção
        std::unique_ptr<Usuario> resultado;
        CHECK_NOTHROW(resultado = Usuario::login("naoexiste@x.com", "errado",
                                                  "usuarios.txt"));
        CHECK(resultado == nullptr);
    }
}
