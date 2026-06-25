#include <cstdio>
#include <fstream>

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
    TEST_CASE("cadastrar cria um novo usuario Cliente e persiste no arquivo") {
        const std::string arquivoTeste = "tmp_usuarios_teste.txt";
        std::remove(arquivoTeste.c_str());

        auto usuario = Usuario::cadastrar("Fernanda Lima", "fernanda@teste.com", "senha123", arquivoTeste);

        REQUIRE(usuario != nullptr);
        CHECK(usuario->nome  == "Fernanda Lima");
        CHECK(usuario->nivelDeAcesso == static_cast<int>(NivelDeAcesso::Cliente));
        CHECK(Usuario::login("fernanda@teste.com", "senha123", arquivoTeste) != nullptr);

        std::remove(arquivoTeste.c_str());
    }

    TEST_CASE("cadastrar rejeita email ja existente") {
        const std::string arquivoTeste = "tmp_usuarios_teste2.txt";
        std::remove(arquivoTeste.c_str());
        Usuario::cadastrar("Primeiro", "duplicado@teste.com", "senha1", arquivoTeste);
        CHECK(Usuario::cadastrar("Segundo", "duplicado@teste.com", "senha2", arquivoTeste) == nullptr);
        std::remove(arquivoTeste.c_str());
    }

    TEST_CASE("cadastrar rejeita campos vazios") {
        const std::string arquivoTeste = "tmp_usuarios_teste3.txt";
        std::remove(arquivoTeste.c_str());
        CHECK(Usuario::cadastrar("", "valido@teste.com", "senha123", arquivoTeste) == nullptr);
        CHECK(Usuario::cadastrar("Nome", "", "senha123", arquivoTeste) == nullptr);
        CHECK(Usuario::cadastrar("Nome", "valido@teste.com", "", arquivoTeste) == nullptr);
        std::remove(arquivoTeste.c_str());
    }

    TEST_CASE("cadastrar nao corrompe registro existente sem quebra de linha final") {
        const std::string arquivoTeste = "tmp_usuarios_teste4.txt";
        std::remove(arquivoTeste.c_str());
        std::ofstream arquivo(arquivoTeste);
        arquivo << "email;senha;nome;nivelDeAcesso\n";
        arquivo << "antigo@teste.com;123;Usuario Antigo;1"; // sem '\n' final, simulando o usuarios.txt real
        arquivo.close();

        Usuario::cadastrar("Novo", "novo@teste.com", "456", arquivoTeste);

        CHECK(Usuario::login("antigo@teste.com", "123", arquivoTeste) != nullptr);
        CHECK(Usuario::login("novo@teste.com", "456", arquivoTeste) != nullptr);
        std::remove(arquivoTeste.c_str());
    }
}
