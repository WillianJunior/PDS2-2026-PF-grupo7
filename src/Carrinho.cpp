#include "Carrinho.hpp"
#include "Catalogo.hpp"
#include <iostream>
Carrinho :: Carrinho(): valorTotal(0.0f), quantidadeTotalItens(0){} //construtor

float Carrinho::calculaValorTotal(const std::vector<std::string>& nomesprodutos) {
    float valorTotal = 0.0f;
    for (const std::string& nome : nomesprodutos){
        for (const Produto& produto: produtos)
        {
            if (produto.getNome()==nome)
            {
                valorTotal += produto.getPreco();
                break;
            }   
        }    
  }

  return valorTotal;
}

int Carrinho::calculaTotalDeItens(const std::vector<std::string>& produtos) {  
    return produtos.size();
}

void Carrinho::_checkout() {
    valorTotal = 0.0f;
    quantidadeTotalItens = produtos.size();
    
    for (const Produto&p : produtos){
        valorTotal += p.getPreco();
    }
    
    std:: cout << "Valor total da compra: " << valorTotal << std::endl;
    std:: cout <<"Quantidade de itens: " << quantidadeTotalItens << std::endl;
}

std::vector<Produto> Carrinho::_getProdutos(){
    return produtos; 
}