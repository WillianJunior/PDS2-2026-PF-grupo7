#include "doctest.h"
#include "Estoque.hpp"
#include "Produto.hpp"
#include <cstdio> // Para usar std::remove e limpar os arquivos de teste

TEST_CASE("Testando manipulacao em memoria do Estoque") {
    // Usamos um arquivo de teste para não sobrescrever o estoque real
    Estoque estoque("estoque_teste.txt");
    Produto p1("Hollow Knight", "PC", "Metroidvania", 49.90);
    Produto p2("Sekiro", "PS4", "Acao", 199.90);

    SUBCASE("Adicionar item novo") {
        estoque.adicionarItem(p1, 10);
        
        CHECK(estoque.jogoExiste("Hollow Knight") == true);
        CHECK(estoque.obterQuantidade("Hollow Knight") == 10);
        CHECK(estoque.possuiEstoque("Hollow Knight") == true);
    }

    SUBCASE("Adicionar quantidade a um item existente") {
        estoque.adicionarItem(p1, 5);
        estoque.adicionarItem(p1, 3); // Deve somar
        
        CHECK(estoque.obterQuantidade("Hollow Knight") == 8);
    }

    SUBCASE("Dar baixa no estoque (reduzir 1 unidade)") {
        estoque.adicionarItem(p2, 2);
        
        CHECK(estoque.darBaixa("Sekiro") == true);
        CHECK(estoque.obterQuantidade("Sekiro") == 1);
        
        CHECK(estoque.darBaixa("Sekiro") == true);
        CHECK(estoque.obterQuantidade("Sekiro") == 0);
        
        // Não deve ser possível dar baixa se não tem estoque
        CHECK(estoque.darBaixa("Sekiro") == false);
    }

    SUBCASE("Remover item parcialmente e totalmente") {
        estoque.adicionarItem(p1, 15);
        
        // Remoção parcial
        CHECK(estoque.removerItem("Hollow Knight", 5) == true);
        CHECK(estoque.obterQuantidade("Hollow Knight") == 10);
        
        // Tentar remover mais do que tem deve falhar
        CHECK(estoque.removerItem("Hollow Knight", 20) == false);
        CHECK(estoque.obterQuantidade("Hollow Knight") == 10); // Quantidade deve ser mantida
        
        // Remoção total (deve apagar do mapa se a lógica implementada excluir quando chega a 0)
        CHECK(estoque.removerItem("Hollow Knight", 10) == true);
        CHECK(estoque.jogoExiste("Hollow Knight") == false); 
    }

    SUBCASE("Editar dados do produto no estoque") {
        estoque.adicionarItem(p1, 5);
        
        // Edita o produto existente
        CHECK(estoque.editarProduto("Hollow Knight", "Switch", "Aventura", 59.90) == true);
        
        // Tentar editar um produto que não existe
        CHECK(estoque.editarProduto("Jogo Inexistente", "PC", "RPG", 10.0) == false);
    }
}

TEST_CASE("Testando persistencia de arquivos (Salvar e Carregar)") {
    const std::string arquivoTeste = "estoque_io_teste.txt";
    Produto p1("Elden Ring", "PS5", "RPG", 250.00);
    Produto p2("Celeste", "PC", "Plataforma", 36.99);

    SUBCASE("Salvar e carregar dados mantendo a integridade") {
        // 1. Cria um estoque, adiciona itens e salva
        {
            Estoque estoqueIn(arquivoTeste);
            estoqueIn.adicionarItem(p1, 12);
            estoqueIn.adicionarItem(p2, 4);
            estoqueIn.salvarEstoque();
        }

        // 2. Cria uma nova instância para carregar o arquivo salvo
        {
            Estoque estoqueOut(arquivoTeste);
            bool carregou = estoqueOut.carregarEstoque();
            
            CHECK(carregou == true);
            CHECK(estoqueOut.jogoExiste("Elden Ring") == true);
            CHECK(estoqueOut.obterQuantidade("Elden Ring") == 12);
            
            CHECK(estoqueOut.jogoExiste("Celeste") == true);
            CHECK(estoqueOut.obterQuantidade("Celeste") == 4);
            
            CHECK(estoqueOut.jogoExiste("Zelda") == false); // Jogo que nunca foi adicionado
        }
        
        // Limpa o arquivo de teste gerado pelo teste
        std::remove(arquivoTeste.c_str());
    }

    SUBCASE("Tentar carregar um arquivo inexistente") {
        Estoque estoqueFantasma("arquivo_que_nao_existe_123.txt");
        CHECK(estoqueFantasma.carregarEstoque() == false);
    }
}