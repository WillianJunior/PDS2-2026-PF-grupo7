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

	/**
     * @brief Exibe todo o catálogo de jogos disponível na lista.
     */
    void exibirCatalogo() const;

    /**
     * @brief Filtra e exibe os jogos de um determinado gênero.
     * @param genero O nome do gênero a ser filtrado (ex: "RPG", "Ação").
     */
    void filtrarGenero(const std::string &genero) const;

    /**
     * @brief Filtra e exibe os jogos disponíveis em uma plataforma específica.
     * @param plataforma O nome da plataforma (ex: "PC", "PS5").
     */
    void filtrarPlataforma(const std::string &plataforma) const;

    /**
     * @brief Ordena a lista de jogos por preço (do menor para o maior) e exibe o resultado.
     */
    void ordenarPreco() const;

    /**
     * @brief Inicia o processo de compra, permitindo ao usuário selecionar itens para o carrinho.
     * @param carrinho Referência ao objeto Carrinho onde os itens serão adicionados.
     */
    void comprar(Carrinho &carrinho) const;

    /**
     * @brief Remove um jogo do catálogo pelo nome.
     * @param nome O nome exato do jogo a ser removido.
     */
    void removerJogo(const std::string &nome);

    /**
     * @brief Salva o estado atual da lista de jogos em um arquivo de texto.
     * @param txtpath O caminho para o arquivo .txt de destino.
     */
    void salvarCatalogo(const std::string &txtpath) const;

    /**
     * @brief Adiciona um novo produto ao catálogo.
     * @param jogo O objeto Produto a ser incluído na lista.
     */
    void adicionarJogo(const Produto &jogo);

    /**
     * @brief Edita as informações de um jogo existente no catálogo.
     * @param nome O nome do jogo a ser editado.
     * @param novaPlat A nova plataforma do jogo.
     * @param novoGen O novo gênero do jogo.
     * @param novoPreco O novo preço do produto.
     * @return true Se o jogo foi encontrado e editado com sucesso, false caso contrário.
     */
    bool editarJogo(const std::string &nome, const std::string &novaPlat, const std::string &novoGen, double novoPreco);
private:
	std::vector<Produto> jogos; ///< Lista interna de todos os produtos do catálogo.

    /**
     * @brief Exibe o cabeçalho formatado da tabela de listagem de jogos.
     */
    void exibirCabecalho() const;

    /**
     * @brief Exibe uma lista de jogos formatada em tabela.
     * @param listaDeJogos O vetor de produtos a ser listado.
     */
    void listarJogos(const std::vector<Produto> &listaDeJogos) const;

    /**
     * @brief Exibe uma lista de jogos com numeração lateral, permitindo seleção por índice.
     * @param listaDeJogos O vetor de produtos a ser listado e numerado.
     */
    void listarJogosNumerados(const std::vector<Produto> &listaDeJogos) const;
};
