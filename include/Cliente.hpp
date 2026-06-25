#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include "Carrinho.hpp"
#include "Usuario.hpp"

/**
 * @file Cliente.hpp
 * @brief Define o ator 'Cliente' no e-commerce.
 */

/**
 * @class Cliente
 * @brief Representa um cliente no sistema.
 * * Utiliza composição para agregar os dados base de um Usuario e um Carrinho de compras próprio.
 */
class Cliente
{
public:
    Usuario usuario;   ///< Dados cadastrais e credenciais do cliente (Composição)
    Carrinho carrinho; ///< Carrinho de compras vinculado a este cliente (Composição)

    /**
     * @brief Construtor da classe Cliente.
     * @param nome Nome completo do cliente.
     * @param email E-mail de login.
     * @param senha Senha de acesso.
     */
    Cliente(const std::string &nome, const std::string &email, const std::string &senha);
};

#endif