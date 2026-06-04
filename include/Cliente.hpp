#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include "Carrinho.hpp"
#include "Compra.hpp"
#include "Usuario.hpp"

class Cliente : public Usuario {
    private:
    Carrinho carrinho; //Composição -> Cada cliente possui um carrinho.
    
    protected:
    std::string endereco;
    std::string nome;

    public:
    Cliente();
    void _getCatalogo(); /**@brief Printa o catálogo atual para o cliente na tela.  */
    void _addProdutoCarrinho(int idProduto, Carrinho carrinho); // O Produto com o ID informado será adicionado ao carrinho do cliente. 
    void _delProdutoCarrinho(int idProduto, Carrinho carrinho); // O Produto com o ID informado será removido do carrinho do cliente. 
    void _limparCarrinho(Carrinho carrinho); // TODOS os itens do carrinho são apagagos 
    void _alterarNome(std::string nome);
    void _alterarEndereco(std::string endereco);
    std::vector<Compra>_getHistoricoCompras(); //Retorna uma lista de itens comprados pelo cliente. Precisará de getCompra(cliente)
    void _classificarProduto(int id, int nota); //adiciona uma nota a um vetor de notas dentro de um produto que faz a média e muda a nota do produto
    std::string getEndereco(); // Getter para o endereço, necessário para os testes
    std::string getNome(); // Getter para o nome, necessário para os testes

};

#endif