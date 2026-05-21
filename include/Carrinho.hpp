#ifndef CARRINHO_HPP
#define CARRINHO_HPP

#include <vector>
#include <Produto.hpp>

class Carrinho
{
private:
    float valorTotal;              // Soma dos preços de todos os itens no carrinho.
    int quantidadeTotalItens;      // Número total de unidades de produto no carrinho.
    std::vector<Produto> produtos; // O carrinho é um vetor de produtos

protected:
    float calculaValorTotal(const std::vector<std::string> &produtos); // pega os produtos do carrinho e soma o preço de todos
    float calculaTotalDeItens(const std::vector<std::string> &produtos); // pega os produtos do carrinho e soma a quantidade
    void _checkout(); //Finaliza a compra com os itens do carrinho retornando preço total e a quantidade de itens. Forma de pagamento???
};

#endif