#include "doctest.h"
#include "Estoque.hpp"
#include <fstream>

// Função auxiliar para criar um arquivo de estoque controlado para os testes
void criarArquivoEstoqueTeste(const std::string& path) {
    std::ofstream file(path);
    file << "Nome;Quantidade\n";
    file << "The Witcher 3;5\n";
    file << "GTA V;0\n";
    file << "Minecraft;1\n";
    file.close();
}

TEST_CASE("Testando a classe Estoque - Fluxo de leitura e validação") {
    std::string txtTeste = "estoque_teste.txt";
    criarArquivoEstoqueTeste(txtTeste);

    Estoque estoque(txtTeste);
    
    SUBCASE("Carregamento do arquivo de estoque") {
        CHECK(estoque.carregarEstoque() == true);
    }

    SUBCASE("Verificação de disponibilidade (> 0)") {
        estoque.carregarEstoque();
        // Produto com quantidade 5 deve retornar true
        CHECK(estoque.possuiEstoque("The Witcher 3") == true);
        CHECK(estoque.obterQuantidade("The Witcher 3") == 5);

        // Produto com quantidade 0 deve retornar false
        CHECK(estoque.possuiEstoque("GTA V") == false);
        CHECK(estoque.obterQuantidade("GTA V") == 0);

        // Produto inexistente deve retornar false e quantidade 0
        CHECK(estoque.possuiEstoque("Jogo Inexistente") == false);
        CHECK(estoque.obterQuantidade("Jogo Inexistente") == 0);
    }

    SUBCASE("Dar baixa no estoque") {
        estoque.carregarEstoque();
        
        // Reduzindo item com estoque
        CHECK(estoque.darBaixa("Minecraft") == true);
        CHECK(estoque.obterQuantidade("Minecraft") == 0);
        CHECK(estoque.possuiEstoque("Minecraft") == false);

        // Tentar dar baixa em item esgotado deve falhar
        CHECK(estoque.darBaixa("GTA V") == false);
    }

    SUBCASE("Persistência e salvamento do estoque") {
        estoque.carregarEstoque();
        estoque.darBaixa("The Witcher 3"); // 5 -> 4
        estoque.salvarEstoque();

        // Criar nova instância para ler o arquivo modificado e checar se salvou
        Estoque novoEstoque(txtTeste);
        novoEstoque.carregarEstoque();
        CHECK(novoEstoque.obterQuantidade("The Witcher 3") == 4);
    }
}