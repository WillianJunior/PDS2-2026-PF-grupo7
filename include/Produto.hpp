#ifndef PRODUTO_H
#define PRODUTO_H

/**
 * @file Produto.hpp
 * @brief Representa um produto disponível no sistema de e-commerce.
 *
 * Armazena todas as informações de um produto do catálogo, incluindo
 * preço, disponibilidade em estoque e avaliação dos clientes.
 */

#include <string>
 
class Produto { //jogos de videogame
private:
    int         id;
    std::string nome;
    std::string categoria;
    float       preco;
    int         quantidadeEstoque;
    protected:
    public:
    Produto();
    Produto(int id, const std::string& nome, const std::string& categoria, float preco, int quantidadeEstoque);
    int getId() const;
    std::string getNome() const;
    std::string getCategoria() const;
    float getPreco() const;
    int getQuantidadeEstoque() const;
    void setId(int id);
    void setNome(const std::string& nome);
    void setCategoria(const std::string& categoria);
    void setPreco(float preco);
    void setQuantidadeEstoque(int quantidadeEstoque);
};  

#endif