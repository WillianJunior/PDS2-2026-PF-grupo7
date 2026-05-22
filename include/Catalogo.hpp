#pragma once

#include <string>
#include <vector>
#include "Produto.hpp"

/**
* @file Catalogo.hpp
* @brief Gerencia a coleção de produtos exibida aos clientes.
*
* Responsável por armazenar e disponibilizar os produtos,
* permitindo filtragem, busca e ordenação.
*
* @see Produto
* @see Administrador
*/
class Catalogo {
private:
	std::vector<Produto> produtos;   ///< Lista de produtos
	std::string filtroAtivo;     	///< Filtro atual (categoria, etc.)
	std::string ordenacaoAtiva;  	///< Tipo de ordenação
	std::string termoBusca;      	///< Termo de busca

public:
	/**
 	* @brief Construtor padrão
 	*/
	Catalogo();

	// ===============================
	// Gerenciamento de produtos
	// ===============================

	/**
 	* @brief Adiciona um produto ao catálogo
 	*/
	void adicionarProduto(const Produto& produto);

	/**
 	* @brief Remove um produto pelo ID
 	*/
	void removerProduto(int id);

	/**
 	* @brief Retorna todos os produtos
 	*/
	std::vector<Produto> getProdutos() const;

	// ===============================
	// Funcionalidades (CRC)
	// ===============================

	/**
 	* @brief Filtra produtos por categoria
 	*/
	std::vector<Produto> filtrarPorCategoria(const std::string& categoria);

	/**
 	* @brief Ordena produtos por preço
 	* @param crescente true = crescente, false = decrescente
 	*/
	void ordenarPorPreco(bool crescente);

	/**
 	* @brief Busca produto pelo nome
 	*/
	std::vector<Produto> buscarProduto(const std::string& termo);

	/**
 	* @brief Exibe nomes dos produtos
 	*/
	std::string listarNomes() const;

	/**
 	* @brief Exibe preços dos produtos
 	*/
	std::string listarPrecos() const;
};
