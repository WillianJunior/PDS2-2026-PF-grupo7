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
 
class Produto {
private:
    int         id;
    std::string nome;
    std::string descricao;
    float       preco;
    std::string categoria;
    bool        disponivel;
    int         quantidadeEstoque;
};
 







#endif