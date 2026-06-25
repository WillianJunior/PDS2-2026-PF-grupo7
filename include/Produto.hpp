#ifndef PRODUTO_H
#define PRODUTO_H

#include <string>

/**
 * @file Produto.hpp
 * @brief Representa um jogo disponível no sistema de e-commerce.
 *
 * Armazena todas as informações de um produto do catálogo, incluindo
 * preço, nome, plataforma e gênero.
 */

class Produto
{ // jogos de videogame

public:
    std::string nome;
    std::string plataforma;
    std::string genero;
    double preco;

    Produto();

    Produto(const std::string &nome, const std::string &plataforma, const std::string &genero, double preco);

    /**
     * @brief Printa os dados do jogo
     * 
     */
    void exibirProduto() const;

};

#endif