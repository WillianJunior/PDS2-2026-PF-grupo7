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
private:
    int id;
    int quantidadeEstoque;

public:
    std::string nome;
    std::string plataforma;
    std::string genero;
    double preco;

    Produto(const std::string &nome, const std::string &plataforma, const std::string &genero, double preco);

    /**
     * @brief Printa os dados do jogo
     * 
     */
    void exibirProduto() const;

    int getId() const;
    std::string getNome() const;
    std::string getCategoria() const;
    float getPreco() const;
    int getQuantidadeEstoque() const;
    void setId(int id);
    void setNome(const std::string &nome);
    void setCategoria(const std::string &categoria);
    void setPreco(float preco);
    void setQuantidadeEstoque(int quantidadeEstoque);
};

#endif