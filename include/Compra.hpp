#ifndef COMPRA_HPP
#define COMPRA_HPP

#include <string>
#include <vector>
#include "Produto.hpp"

/**
* @file Compra.hpp
* @brief Representa uma transação finalizada no sistema.
*
* Responsável por armazenar os dados de uma compra, processar pagamento,
* atualizar status e interagir com o estoque.
*
* @see Estoque
* @see Cliente
* @see Administrador
*/
class Compra {
private:
	int idCompra;                 	///< Identificador da compra
	int idCliente;                	///< ID do cliente
	std::vector<Produto> itens;   	///< Produtos comprados
	std::string dataCompra;       	///< Data da compra
	std::string status;           	///< Status da compra (ex: "Pendente", "Pago", "Cancelado")
	std::string metodoPagamento;  	///< Método de pagamento

public:
	/**
 	* @brief Construtor da compra
 	*/
	Compra(int idCompra,
       	int idCliente,
       	const std::vector<Produto>& itens,
       	const std::string& dataCompra,
       	const std::string& metodoPagamento);

	// ===============================
	// Getters
	// ===============================

	int getIdCompra() const;
	int getIdCliente() const;
	std::vector<Produto> getItens() const;
	std::string getDataCompra() const;
	std::string getStatus() const;
	std::string getMetodoPagamento() const;

	// ===============================
	// Comportamentos (CRC)
	// ===============================

	/**
 	* @brief Processa o pagamento da compra
 	* @return true se pagamento aprovado
 	*/
	bool processarPagamento();

	/**
 	* @brief Atualiza o status da compra
 	*/
	void atualizarStatus(const std::string& novoStatus);

	/**
 	* @brief Atualiza o estoque com base nos itens comprados
 	*/
	void atualizarEstoque();

	/**
 	* @brief Gera um resumo da compra
 	*/
	std::string gerarResumo() const;
};

#endif
