#ifndef USUARIO_HPP
#define USUARIO_HPP

#include <string>
#include <memory>
#include "NivelDeAcesso.hpp"

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
class Usuario
{

public:
	int nivelDeAcesso; ///< Nível de acesso ao sistema
	std::string nome;  ///< Nome completo
	std::string email; ///< Email de login
	std::string senha; ///< Senha

	/**
	 * @brief Construtor da classe Usuario
	 * @param nivelDeAcesso Nível de acesso ao sistema cliente = 1, admin = 3
	 * @param nome Nome completo
	 * @param email Email de acesso
	 * @param senha Senha do usuário
	 */
	Usuario(const std::string &nome, const std::string &email, const std::string &senha, int nivelDeAcesso);

	/**
	 * @brief Verifica se o usuario possui o acesso requerido
	 *
	 * @param acesso
	 * @return true
	 * @return false
	 */
	bool possuiAcesso(int acesso) const;

	/**
	 * @brief Método para realizar o login do usuário buscando os dados em um arquivo txt
	 *
	 * @param email
	 * @param senha
	 * @param txtpath
	 * @return std::unique_ptr<Usuario>
	 */
	static std::unique_ptr<Usuario> login(const std::string &email,
										  const std::string &senha,
										  const std::string &txtpath = "usuarios.txt");

	static bool emailJaCadastrado(const std::string &email,
								  const std::string &txtpath = "usuarios.txt");

	static std::unique_ptr<Usuario> cadastrar(const std::string &nome,
											  const std::string &email,
											  const std::string &senha,
											  const std::string &txtpath = "usuarios.txt");

	
	static bool atualizarUsuarioNoArquivo(const std::string &emailAntigo, const Usuario &usuarioAtualizado, const std::string &txtpath);
};

#endif
