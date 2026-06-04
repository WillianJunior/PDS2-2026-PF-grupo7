#include "doctest.h"
#include "Usuario.hpp"

TEST_CASE("Teste de criação de Usuario") {
    Usuario usuario;
    CHECK(usuario.getId() == 0); // Verifica se o ID é inicializado como 0
    CHECK(usuario.getNome() == ""); // Verifica se o nome é inicializado como vazio
    CHECK(usuario.getEmail() == ""); // Verifica se o email é inicializado como vazio
    CHECK(usuario.getSenha() == ""); // Verifica se a senha é inicializada como vazia
}

TEST_CASE("Teste de setters de Usuario") {
    Usuario usuario;
    usuario.setNome("Novo Nome");
    usuario.setEmail("novoemail@example.com");
    usuario.setSenha("nova senha");

    CHECK(usuario.getNome() == "Novo Nome");
    CHECK(usuario.getEmail() == "novoemail@example.com");
    CHECK(usuario.getSenha() == "nova senha");
}
