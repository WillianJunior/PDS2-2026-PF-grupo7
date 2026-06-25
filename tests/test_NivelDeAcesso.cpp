#include "doctest.h"
#include "NivelDeAcesso.hpp"

TEST_SUITE("NivelDeAcesso") {
 
    TEST_CASE("Valores do enum NivelDeAcesso estão corretos") {
        CHECK(static_cast<int>(NivelDeAcesso::Cliente) == 1);
        CHECK(static_cast<int>(NivelDeAcesso::Admin)   == 2);
    }
 
    TEST_CASE("Cliente e Admin são valores distintos") {
        CHECK(NivelDeAcesso::Cliente != NivelDeAcesso::Admin);
    }
}
