#ifndef ADMINISTRADOR_HPP
#define ADMINISTRADOR_HPP

#include <string>
#include "Usuario.hpp"
#include "NivelDeAcesso.hpp"

/**
 * @file Administrador.hpp
 * @brief Representa um administrador do sistema.
 *
 * Especializa Usuario com privilégios para gerenciamento do sistema,
 * incluindo catálogo, estoque, compras e clientes.
 *
 * @see Usuario
 * @see Catalogo
 * @see Estoque
 * @see Compra
 */
class Administrador
{

public:
	Usuario usuario; // Composição
	/**
	 * @brief Construtor do administrador
	 */
	Administrador(
		const std::string &nome,
		const std::string &email,
		const std::string &senha);

	// ===============================
	// Getter
	// ===============================

	std::string getNivelAcesso() const;

	// ===============================
	// Comportamentos (CRC)
	// ===============================

	/**
	 * @brief Gerencia o catálogo (CRUD de produtos)
	 */
	void gerenciarCatalogo();

	/**
	 * @brief Acessa dados de clientes
	 */
	void acessarDadosClientes();

	/**
	 * @brief Gerencia compras realizadas
	 */
	void gerenciarCompras();

	/**
	 * @brief Gerencia estoque
	 */
	void gerenciarEstoque();

	/**
	 * @brief Gerencia perfis de clientes
	 */
	void gerenciarPerfisClientes();

	/**
	 * @brief Implementa autenticação do usuário
	 */
	// bool autenticar(const std::string& senha) const override;
};

#endif