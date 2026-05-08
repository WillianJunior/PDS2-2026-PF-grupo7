#ifndef COMPRA_HPP
#define COMPRA_HPP

/**
 * @file Compra.hpp
 * @brief Representa o registro de uma transação finalizada.
 *
 * Armazena os dados de uma venda concluída, incluindo o histórico
 * de itens, status do pagamento e informações para entrega.
 */

#include <string>
#include <vector>
#include "Produto.hpp"

class Compra {
private:
    int                  idCompra;
    int                  idCliente;
    std::vector<Produto> itens;
    std::string          dataCompra;
    std::string          status;
    std::string          metodoPagamento;
};

#endif