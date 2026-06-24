#include "Produto.hpp"

#include <iostream>
#include <iomanip>

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

int Produto::getId() const { return 0; }

std::string Produto::getNome() const { return {}; }

std::string Produto::getCategoria() const { return {}; }

float Produto::getPreco() const { return 0; }

int Produto::getQuantidadeEstoque() const { return 0; }

void Produto::setId(int id) {}

void Produto::setNome(const std::string &nome) {}

void Produto::setCategoria(const std::string &categoria) {}

void Produto::setPreco(float preco) {}

void Produto::setQuantidadeEstoque(int quantidadeEstoque) {}