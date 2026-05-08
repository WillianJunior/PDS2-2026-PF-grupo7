#pragma once
#include <string>

/**
 * @file Usuario.hpp
 * @brief Classe base abstrata para todos os usuários do sistema.
 *
 * Centraliza os atributos de identificação e autenticação comuns a
 * qualquer ator que interaja com o sistema, sendo especializada pelas
 * classes Cliente e Administrador.
 *
 * @see Cliente
 * @see Administrador
 */
class Usuario {
protected:
    int         id;    ///< Identificador único do usuário no sistema.
    std::string nome;  ///< Nome completo do usuário.
    std::string email; ///< Endereço de e-mail utilizado no login.
    std::string senha; ///< Hash da senha do usuário.
};
