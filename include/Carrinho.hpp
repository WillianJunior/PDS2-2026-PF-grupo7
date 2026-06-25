#ifndef CARRINHO_HPP
#define CARRINHO_HPP

#include <vector>
#include "Produto.hpp"
#include "Usuario.hpp"
#include "Compra.hpp"

/**
 * @file Carrinho.hpp
 * @brief Gerencia os itens selecionados por um cliente antes da compra.
 */

/**
 * @class Carrinho
 * @brief Classe que representa o carrinho de compras de um usuário.
 * * Permite a adição, remoção e cálculo do valor total dos produtos selecionados.
 */
class Carrinho
{
private:
    Usuario &usuario;             ///< Referência ao usuário dono do carrinho
    std::vector<Produto> itens;   ///< Vetor de produtos adicionados ao carrinho

public:
    /**
     * @brief Construtor explícito do Carrinho.
     * @param usuario Referência ao Usuário que será dono deste carrinho.
     */
    explicit Carrinho(Usuario &usuario);

    /**
     * @brief Adiciona um produto ao carrinho.
     * @param jogo O objeto Produto (jogo) a ser inserido.
     */
    void adicionar(const Produto &jogo);

    /**
     * @brief Remove um produto do carrinho com base no seu índice.
     * @param indice Posição do produto no vetor de itens.
     */
    void remover(int indice);

    /**
     * @brief Exibe no console todos os produtos atualmente no carrinho.
     */
    void exibirCarrinho() const;

    /**
     * @brief Calcula o valor total somando o preço de todos os itens.
     * @return double O valor total do carrinho.
     */
    double total() const;

    /**
     * @brief Verifica se o carrinho está sem nenhum item.
     * @return true Se o carrinho estiver vazio.
     * @return false Se houver pelo menos um item no carrinho.
     */
    bool estaVazio() const;

    /**
     * @brief Finaliza a compra: registra os itens no histórico do cliente
     * (persistido em arquivo) e esvazia o carrinho.
     * @pre O carrinho não deve estar vazio (verificar com estaVazio() antes de chamar).
     * @return Compra O registro da compra finalizada.
     */
    Compra finalizarCompra();
};

#endif