#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Administrador.hpp"

TEST_CASE("Teste de criação de Administrador") {
    Administrador admin(1, "Admin", "admin@example.com", "senha123", "administrador");
    CHECK(admin.getNivelAcesso() == "administrador");
    CHECK(admin.getNome() == "Admin");
    CHECK(admin.getEmail() == "admin@example.com");
    CHECK(admin.getSenha() == "senha123");
}


