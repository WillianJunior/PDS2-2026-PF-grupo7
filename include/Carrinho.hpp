#pragma once
#include <vector>
#include <utility>
#include "Produto.hpp"

/**
 * @file Carrinho.hpp
 * @brief Representa o carrinho de compras de um cliente.
 *
 * Mantém os produtos selecionados pelo cliente antes da efetivação
 * da compra, controlando quantidades e calculando o valor total acumulado.
 *
 * @see Produto
 * @see Cliente
 * @see Compra
 */
class Carrinho {
private:
    std::vector<std::pair<Produto, int>> itens;               ///< Pares (produto, quantidade) adicionados ao carrinho.
    float                                valorTotal;           ///< Soma dos preços de todos os itens no carrinho.
    int                                  quantidadeTotalItens; ///< Número total de unidades no carrinho.
};
