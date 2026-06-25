#include "Carrinho.hpp"
#include <iostream>
#include <iomanip>

Carrinho::Carrinho(Usuario &usuario) : usuario(usuario) {}

void Carrinho::adicionar(const Produto &jogo)
{
    itens.push_back(jogo);
    std::cout << "\"" << jogo.nome << "\" adicionado ao carrinho!" << std::endl;
}

void Carrinho::remover(int indice)
{
    if (indice < 0 || indice >= static_cast<int>(itens.size()))
    {
        std::cout << "ID Inválido." << std::endl;
        return;
    }

    itens.erase(itens.begin() + indice);
    std::cout << "\"" << itens[indice].nome << "\" removido do carrinho." << std::endl;
}

double Carrinho::total() const
{
    double soma = 0.0f;
    for (const Produto &jogo : itens)
    {
        soma += jogo.preco;
    }
    return soma;
}

bool Carrinho::estaVazio() const
{
    return itens.empty();
}

const std::vector<Produto>& Carrinho::getItens() const
{
    return itens;
}

Compra Carrinho::finalizarCompra()
{
    Compra compra(usuario.email, itens);
    Compra::salvarHistorico(compra);
    itens.clear();
    return compra;
}

void Carrinho::exibirCarrinho() const
{
    std::cout << "\n=== Carrinho de " << usuario.nome << " ===" << std::endl;

    if (estaVazio())
    {
        std::cout << "Seu carrinho está vazio." << std::endl;
        return;
    }

    std::cout << std::left
              << std::setw(5) << "ID."
              << std::setw(35) << "Nome"
              << std::setw(10) << "Plataforma"
              << std::setw(15) << "Genero"
              << "Preco"
              << std::endl;
    std::cout << std::string(75, '-') << std::endl;

      for (int i = 0; i < static_cast<int>(itens.size()); i++) {
        std::cout << std::left
                  << std::setw(5)  << (i + 1)
                  << std::setw(35) << itens[i].nome
                  << std::setw(10) << itens[i].plataforma
                  << std::setw(15) << itens[i].genero
                  << "R$ " << std::fixed << std::setprecision(2) << itens[i].preco
                  << std::endl;
    }

    std::cout << std::string(75, '-') << std::endl;
    std::cout << std::right << std::setw(70)
              << "Total: R$ " + std::to_string(total()) << std::endl;

}