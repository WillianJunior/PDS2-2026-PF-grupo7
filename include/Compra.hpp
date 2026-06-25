#ifndef COMPRA_HPP
#define COMPRA_HPP

#include <string>
#include <vector>
#include "Produto.hpp"

/**
 * @file Compra.hpp
 * @brief Representa o registro de uma compra finalizada por um cliente.
 *
 * Armazena os itens, o valor total e a data de uma compra, e oferece
 * persistência simples em arquivo de texto para consulta posterior
 * (histórico de compras).
 *
 * @see Carrinho
 * @see Produto
 */
class Compra
{
public:
    /**
     * @brief Constrói uma nova Compra a partir dos itens do carrinho no momento do checkout.
     * @param emailCliente Email do cliente que realizou a compra.
     * @param itens Itens (produtos) que fazem parte da compra.
     */
    Compra(const std::string &emailCliente, const std::vector<Produto> &itens);

    /**
     * @brief Exibe no console os dados da compra (data, itens e total).
     */
    void exibirCompra() const;

    double getTotal() const;
    const std::string &getData() const;
    const std::vector<Produto> &getItens() const;

    /**
     * @brief Salva uma compra no arquivo de histórico (modo "append").
     */
    static void salvarHistorico(const Compra &compra, const std::string &txtpath = "compras.txt");

    /**
     * @brief Carrega o histórico de compras de um cliente específico.
     */
    static std::vector<Compra> carregarHistorico(const std::string &emailCliente,
                                                  const std::string &txtpath = "compras.txt");

private:
    std::string emailCliente;
    std::string data;
    std::vector<Produto> itens;
    double total;

    Compra(const std::string &emailCliente, const std::string &data,
           const std::vector<Produto> &itens, double total);

    static std::string gerarDataAtual();
    static std::string serializarItens(const std::vector<Produto> &itens);
    static std::vector<Produto> desserializarItens(const std::string &itensStr);
};

#endif