#include "Carrinho.hpp"
#include <iostream>

float Carrinho::calculaValorTotal(const std::vector<std::string>& produtos) {
    float valorTotal = 0.0;
    float valorAdicionado = 0.0;
    for (const auto &Produto : produtos)
    {
        valorTotal +=valorAdicionado;
    }
    return valorTotal;
}

float Carrinho::calculaTotalDeItens(const std::vector<std::string>& produtos) {
        return static_cast<float>(produtos.size());
    return 0;}

void Carrinho::_checkout() {
    std:: cout << "Inicio do checkout! " << std::endl;
    std:: cout <<"Fim do checkout! " << std::endl;
}

std::vector<Produto> Carrinho::_getProdutos(){return {}; }