#ifndef USUARIO_HPP
#define USUARIO_HPP

#include <string>

/**
* @file Usuario.hpp
* @brief Classe base abstrata para todos os usuários do sistema.
*
* Centraliza atributos e comportamentos comuns a qualquer ator
* que interaja com o sistema, sendo especializada por Cliente
* e Administrador.
*
* @see Cliente
* @see Administrador
*/
class Usuario {
protected:
	int id;             	///< Identificador único do usuário
	std::string nome;   	///< Nome completo
	std::string email;  	///< Email de login
	std::string senha;  	///< Senha (hash)

public:
	/**
 	* @brief Construtor da classe Usuario
 	* @param id Identificador do usuário
 	* @param nome Nome completo
 	* @param email Email de acesso
 	* @param senha Senha do usuário
 	*/
	Usuario(int id, const std::string& nome, const std::string& email, const std::string& senha);

	/**
 	* @brief Destrutor virtual da classe Usuario
 	*/
	virtual ~Usuario() = default;

	// Getters

	/**
 	* @brief Retorna o ID do usuário
 	*/
	int getId() const;

	/**
 	* @brief Retorna o nome do usuário
 	*/
	std::string getNome() const;

	/**
 	* @brief Retorna o email do usuário
 	*/
	std::string getEmail() const;

	/**
 	* @brief Retorna a senha do usuário
 	*/
	std::string getSenha() const;

	// Setters

	/**
 	* @brief Define o nome do usuário
 	*/
	void setNome(const std::string& nome);

	/**
 	* @brief Define o email do usuário
 	*/
	void setEmail(const std::string& email);

	/**
 	* @brief Define a senha do usuário
 	*/
	void setSenha(const std::string& senha);

	/**
 	* @brief Método abstrato para autenticação
 	* @param senha Senha informada
 	* @return true se autenticação for válida
 	*/
	virtual bool autenticar(const std::string& senha) const = 0;
};

#endif
