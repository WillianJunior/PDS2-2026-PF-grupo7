#include "Produto.hpp"

#include <iostream>
#include <iomanip>

Produto::Produto() : nome(""), plataforma(""), genero(""), preco(0.0) {}

Produto::Produto(const std::string &nome, const std::string &plataforma,
                 const std::string &genero, double preco)
    : nome(nome), plataforma(plataforma), genero(genero), preco(preco) {}

void Produto::exibirProduto() const{
    std::cout << std::left //alinha à esquerda
              << std::setw(35) << nome
              << std::setw(10) << plataforma
              << std::setw(15) << genero
              << "R$ " << std::fixed << std::setprecision(2) << preco
              << std::endl;
}