#include "Carrinho.hpp"
#include <iostream>

float Carrinho::calculaValorTotal(const std::vector<std::string>& produtos) {
    float valorTotal = 0.0f;
    for (const auto &produto : produtos)
    {
        (void)produto;
    }
    return valorTotal;
}

float Carrinho::calculaTotalDeItens(const std::vector<std::string>& produtos) {
        return static_cast<float>(produtos.size());
}

void Carrinho::_checkout() {
    std:: cout << "Inicio do checkout! " << std::endl;
    std:: cout <<"Fim do checkout! " << std::endl;
}

std::vector<Produto> Carrinho::_getProdutos(){return {}; }