#ifndef ESTOQUE_HPP
#define ESTOQUE_HPP

/**
 * @file Estoque.hpp
 * @brief Gerencia a disponibilidade física dos produtos.
 *
 * Controla as quantidades em estoque, gerencia alertas de falta de itens
 * e lida com a reserva de produtos durante o processo de compra.
 */

#include <map>
#include <string>

class Estoque {
private:
    std::map<int, int> quantidades;
    int                limiteAlerta;
    bool               reservaAtiva;
};

#endif