#ifndef CARRINHO_HPP
#define CARRINHO_HPP

#include <vector>
#include <Produto.hpp>

class Carrinho
{
private:
    float valorTotal;              // Soma dos preços de todos os itens no carrinho.
    int quantidadeTotalItens;      // Número total de unidades de produto no carrinho.
    
public:
    
std::vector<Produto> produtos; // O carrinho é um vetor de produtos

    float calculaValorTotal(const std::vector<std::string> &produtos); // pega os produtos do carrinho e soma o preço de todos. Const porque só queremos ler os produtos
    float calculaTotalDeItens(const std::vector<std::string> &produtos); // pega os produtos do carrinho e soma a quantidade. Const porque só queremos ler os produtos
    void _checkout(); //Finaliza a compra com os itens do carrinho retornando preço total e a quantidade de itens. Forma de pagamento???
    std::vector<Produto> _getProdutos(); // Getter para acessar os produtos do carrinho, necessário para os testes
};

#endif