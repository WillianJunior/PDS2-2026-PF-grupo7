#pragma once
#include <string>
#include <vector>
#include "Produto.hpp"

/**
 * @file Catalogo.hpp
 * @brief Gerencia a coleção de produtos exibida aos clientes.
 *
 * Responsável por armazenar e expor os produtos disponíveis no sistema,
 * suportando busca, filtragem e ordenação conforme critérios definidos
 * pelo usuário ou pelo administrador.
 *
 * @see Produto
 * @see Administrador
 */
class Catalogo {
private:
    std::vector<Produto> produtos;        ///< Lista de produtos presentes no catálogo.
    std::string          filtroAtivo;     ///< Filtro de categoria ou atributo aplicado atualmente.
    std::string          ordenacaoAtiva;  ///< Critério de ordenação ativo (ex.: "preco_asc").
    std::string          termoBusca;      ///< Termo digitado pelo usuário na busca.
};
