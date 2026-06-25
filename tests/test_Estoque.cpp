#include "doctest.h"
#include "Estoque.hpp"

TEST_SUITE("Estoque") {
 
    TEST_CASE("Instanciar Estoque não lança exceção") {
        CHECK_NOTHROW(Estoque e);
    }
 
    // Testes adicionais devem ser adicionados à medida que
    // a classe Estoque for implementada.
}
 
