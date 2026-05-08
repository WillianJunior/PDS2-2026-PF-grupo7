#pragma once
#include <string>
#include "Usuario.hpp"

/**
 * @file Administrador.hpp
 * @brief Representa um administrador do sistema.
 *
 * Especializa Usuario com um nível de acesso que determina quais
 * operações administrativas estão disponíveis, como gerenciar o
 * catálogo, os clientes, as compras e o estoque.
 *
 * @see Usuario
 * @see Catalogo
 * @see Estoque
 * @see Compra
 */
class Administrador : public Usuario {
private:
    std::string nivelAcesso; ///< Nível de privilégio do administrador (ex.: "gerente", "operador").
};
