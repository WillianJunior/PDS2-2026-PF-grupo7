#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include "Produto.hpp"
#include "Catalogo.hpp"
#include "Carrinho.hpp"
#include "Compra.hpp"

class Cliente {
    private:
    Carrinho carrinho; //Composição -> Cada cliente possui um carrinho.
    void _alterarNome();
    void _alterarEndereco();
    void _getHistoricoCompras(); //Retorna uma lista de itens comprados pelo cliente. Precisará de getCompra(cliente)

    protected:
    std::string endereco;
    std::string nome;
    void _classificarProduto(int id, int nota); //adiciona uma nota a um vetor de notas dentro de um produto que faz a média e muda a nota do produto
    
    

    public:
    void _getCatalogo(); /**@brief Printa o catálogo atual para o cliente na tela.  */
    void _addProdutoCarrinho(int idProduto, Carrinho carrinho); // O Produto com o ID informado será adicionado ao carrinho do cliente. 
    void _delProdutoCarrinho(int idProduto, Carrinho carrinho); // O Produto com o ID informado será removido do carrinho do cliente. 
    void _limparCarrinho(Carrinho carrinho); // TODOS os itens do carrinho são apagagos 


};

#endif