#pragma once

#include <string>
#include <vector>
#include "Produto.hpp"
#include "Carrinho.hpp"
#include "Estoque.hpp"

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
class Catalogo
{
public:
	/**
	 * @brief Construtor padrão
	 */
	Catalogo() {}

	/**
	 * @brief Carrega o catálogo de jogos de jogos.txt
	 *
	 * @param txtpath
	 * @return Catalogo
	 */
	static Catalogo carregarCatalogo(const std::string &txtpath = "jogos.txt");

	void exibirCatalogo() const;
	void filtrarGenero(const std::string &genero) const;
	void filtrarPlataforma(const std::string &plataforma) const;
	void ordenarPreco() const;

	void comprar(Carrinho &carrinho) const;

	void removerJogo(const std::string &nome);
	void salvarCatalogo(const std::string &txtpath) const;

	void adicionarJogo(const Produto &jogo);

private:
	std::vector<Produto> jogos; ///< Lista de produtos

	void exibirCabecalho() const;
	void listarJogos(const std::vector<Produto> &listaDeJogos) const;
	void listarJogosNumerados(const std::vector<Produto> &listaDeJogos) const;
};
