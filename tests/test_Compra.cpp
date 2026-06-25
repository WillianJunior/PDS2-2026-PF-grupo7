#include "doctest.h"
#include "Compra.hpp"
#include "Carrinho.hpp"
#include "Usuario.hpp"
#include <cstdio>

TEST_SUITE("Compra") {

    TEST_CASE("Compra calcula o total corretamente a partir dos itens") {
        std::vector<Produto> itens{
            Produto("Elden Ring", "PS5", "RPG", 249.90),
            Produto("Stardew Valley", "PC", "Simulacao", 37.90)
        };
        Compra compra("maria@email.com", itens);
        CHECK(compra.getItens().size() == 2);
        CHECK(compra.getTotal() == doctest::Approx(287.80));
    }

    TEST_CASE("salvarHistorico e carregarHistorico mantem os dados da compra") {
        const std::string arquivo = "tmp_compras_teste.txt";
        std::remove(arquivo.c_str());

        std::vector<Produto> itens{ Produto("Halo Infinite", "Xbox", "FPS", 149.90) };
        Compra compra("joao@email.com", itens);
        Compra::salvarHistorico(compra, arquivo);

        auto historico = Compra::carregarHistorico("joao@email.com", arquivo);
        REQUIRE(historico.size() == 1);
        CHECK(historico[0].getItens()[0].nome == "Halo Infinite");
        CHECK(historico[0].getTotal() == doctest::Approx(149.90));

        std::remove(arquivo.c_str());
    }

    TEST_CASE("carregarHistorico filtra apenas as compras do email solicitado") {
        const std::string arquivo = "tmp_compras_teste2.txt";
        std::remove(arquivo.c_str());

        Compra::salvarHistorico(Compra("ana@email.com", {Produto("Jogo A", "PC", "Acao", 100.0)}), arquivo);
        Compra::salvarHistorico(Compra("bruno@email.com", {Produto("Jogo B", "PC", "RPG", 50.0)}), arquivo);
        Compra::salvarHistorico(Compra("ana@email.com", {Produto("Jogo C", "PC", "FPS", 75.0)}), arquivo);

        CHECK(Compra::carregarHistorico("ana@email.com", arquivo).size() == 2);
        CHECK(Compra::carregarHistorico("bruno@email.com", arquivo).size() == 1);

        std::remove(arquivo.c_str());
    }

    TEST_CASE("carregarHistorico retorna lista vazia se o arquivo nao existe") {
        std::remove("tmp_compras_inexistente.txt");
        auto historico = Compra::carregarHistorico("alguem@email.com", "tmp_compras_inexistente.txt");
        CHECK(historico.empty());
    }

    TEST_CASE("Carrinho::finalizarCompra esvazia o carrinho e registra a compra") {
        std::remove("compras.txt");

        Usuario u("Maria", "maria.teste@email.com", "pass", static_cast<int>(NivelDeAcesso::Cliente));
        Carrinho carrinho(u);
        carrinho.adicionar(Produto("Zelda", "Switch", "Aventura", 250.0));
        CHECK(carrinho.estaVazio() == false);

        Compra compra = carrinho.finalizarCompra();

        CHECK(carrinho.estaVazio() == true);
        CHECK(compra.getTotal() == doctest::Approx(250.0));

        auto historico = Compra::carregarHistorico("maria.teste@email.com");
        REQUIRE(historico.size() == 1);
        CHECK(historico[0].getItens()[0].nome == "Zelda");

        std::remove("compras.txt");
    }
}