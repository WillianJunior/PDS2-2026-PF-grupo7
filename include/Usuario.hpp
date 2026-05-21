#ifndef USUARIO_HPP
#define USUARIO_HPP
#include <string>
#include <vector>

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
class Usuario
{
protected:
    int id;             ///< Identificador único do usuário no sistema.
    std::string classe; // Cliente ou Admin??
    std::string nome;   ///< Nome completo do usuário.
    std::string email;  ///< Endereço de e-mail utilizado no login.
    std::string senha;  ///< Hash da senha do usuário.
    std::vector<Usuario> usuarios; //Vetor de usuários para verificação no login
public:
    /**@brief Inicializa um usuário com nome, email, classe, senha
     * ?? - criar um vetor de usuários aos quais o admin tem acesso??
     */
    Usuario::Usuario(std::string classe, std::string nome, std::string email, std::string senha){}
};


#endif
