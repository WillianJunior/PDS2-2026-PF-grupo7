#ifndef ESTOQUE_HPP
#define ESTOQUE_HPP

#include <map>
#include <string>

/**
* @file Estoque.hpp
* @brief Gerencia a disponibilidade física dos produtos.
*
* Controla quantidades em estoque, gerencia alertas de itens
* e realiza reservas durante o processo de compra.
*
* @see Produto
* @see Administrador
*/
class Estoque {
private:
	std::map<int, int> quantidades; ///< ID do produto -> quantidade
	int limiteAlerta;           	///< Limite mínimo para alerta de estoque baixo

public:
	/**
 	* @brief Construtor do estoque
 	* @param limiteAlerta Quantidade mínima para alerta
 	*/
	Estoque(int limiteAlerta);

	// ===============================
	// Controle de Estoque
	// ===============================

	/**
 	* @brief Define a quantidade de um produto
 	* @param produtoId ID do produto
 	* @param quantidade Nova quantidade
 	*/
	void setQuantidade(int produtoId, int quantidade);

	/**
 	* @brief Retorna a quantidade disponível
 	* @param produtoId ID do produto
 	*/
	int getQuantidade(int produtoId) const;

	/**
 	* @brief Adiciona unidades ao estoque
 	*/
	void adicionarProduto(int produtoId, int quantidade);

	/**
 	* @brief Remove unidades do estoque
 	*/
	void removerProduto(int produtoId, int quantidade);

	// ===============================
	// Validações e Alertas
	// ===============================

	/**
 	* @brief Verifica se há estoque suficiente
 	*/
	bool temEstoque(int produtoId, int quantidade) const;

	/**
 	* @brief Verifica se o estoque está baixo
 	*/
	bool estoqueBaixo(int produtoId) const;

	/**
 	* @brief Verifica se o produto está em falta
 	*/
	bool semEstoque(int produtoId) const;

	// ===============================
	// Reserva (Carrinho)
	// ===============================

	/**
 	* @brief Reserva itens para compra
 	* @return true se a reserva foi bem-sucedida
 	*/
	bool reservarProduto(int produtoId, int quantidade);

	/**
 	* @brief Cancela reserva (devolve ao estoque)
 	*/
	void cancelarReserva(int produtoId, int quantidade);

	// ===============================
	// Relatórios
	// ===============================

	/**
 	* @brief Gera relatório textual do estoque
 	*/
	std::string gerarRelatorio() const;
};

#endif
