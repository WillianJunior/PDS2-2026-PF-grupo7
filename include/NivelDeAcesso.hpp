#ifndef NIVEL_DE_ACESSO_HPP
#define NIVEL_DE_ACESSO_HPP

/**
 * @file NivelDeAcesso.hpp
 * @brief Define as permissões de acesso dos usuários no sistema.
 */

/**
 * @enum NivelDeAcesso
 * @brief Enumeração para controle de privilégios de Usuários.
 */
enum class NivelDeAcesso {
    Cliente = 1, ///< Acesso restrito a compras e dados pessoais
    Admin = 2    ///< Acesso total de gerenciamento do sistema
};

#endif