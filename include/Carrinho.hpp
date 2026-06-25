#ifndef CARRINHO_HPP
#define CARRINHO_HPP

#include <vector>
#include "Produto.hpp"
#include "Usuario.hpp"

class Carrinho
{
private:
    Usuario &usuario;
    std::vector<Produto> itens;

public:
    explicit Carrinho(Usuario &usuario);

    void adicionar(const Produto &jogo);
    void remover(int indice);
    void exibirCarrinho() const;
    double total() const;
    bool estaVazio() const;
};

#endif