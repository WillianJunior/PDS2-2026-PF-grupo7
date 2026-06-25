#ifndef ESTOQUE_HPP
#define ESTOQUE_HPP

#include <string>
#include <map>
#include "Produto.hpp"

/**
 * @file Estoque.hpp
 * @brief Gerencia a disponibilidade física e quantidades dos produtos em um arquivo .txt.
 */
class Estoque
{
private:
    // Mapeia o nome do produto (ou nome+plataforma se houver duplicata) para a sua quantidade
    std::string m_txtPath;
    std::map<std::string, std::pair<Produto, int>> m_itens;

public:
    /**
     * @brief Construtor que define o caminho do arquivo de estoque.
     * @param txtPath Caminho para o arquivo txt do estoque (padrão: "estoque.txt").
     */
    explicit Estoque(const std::string &txtPath = "estoque.txt");

    /**
     * @brief Carrega os dados do estoque a partir do arquivo configurado.
     * @return true se o arquivo foi aberto com sucesso, false caso contrário.
     */
    bool carregarEstoque();

    /**
     * @brief Salva o estado atual do estoque de volta no arquivo txt.
     */
    void salvarEstoque() const;

    /**
     * @brief Verifica se um produto específico possui unidades disponíveis (> 0).
     * @param nomeProduto O nome do produto a ser verificado.
     * @return true se houver estoque disponível, false caso contrário.
     */
    bool possuiEstoque(const std::string &nomeProduto) const;

    /**
     * @brief Reduz em 1 a quantidade de um produto no estoque (ao adicionar ao carrinho/comprar).
     * @param nomeProduto O nome do produto.
     * @return true se a baixa foi realizada com sucesso, false se não havia estoque.
     */
    bool darBaixa(const std::string &nomeProduto);

    /**
     * @brief Retorna a quantidade atual de um produto.
     * @param nomeProduto O nome do produto.
     * @return int Quantidade em estoque (retorna 0 se o produto não existir).
     */
    int obterQuantidade(const std::string &nomeProduto) const;

    /**
     * @brief Exibe na tela todo o estoque atualizado (opção do Menu do Admin).
     */
    void exibirEstoque() const;

    void adicionarItem(const Produto& produto, int quantidade);

    bool removerItem(const std::string &nomeProduto, int quantidade);

    bool jogoExiste(const std::string &nomeProduto) const;
};

#endif