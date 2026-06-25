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

    /**
     * @brief Adiciona um novo produto ao estoque ou incrementa a quantidade de um já existente.
     * * Se o produto ainda não estiver cadastrado no estoque, ele será inserido juntamente 
     * com a quantidade informada. Se já existir, a quantidade atual será somada à nova.
     * * @param produto Objeto da classe Produto contendo os dados completos do jogo.
     * @param quantidade A quantidade de unidades a serem adicionadas.
     */
    void adicionarItem(const Produto& produto, int quantidade);

    /**
     * @brief Remove uma quantidade específica de um produto do estoque.
     * * Reduz a quantidade disponível do item. Caso a quantidade do produto chegue a zero 
     * após a remoção, ele é retirado completamente do registro do estoque.
     * * @param nomeProduto O nome do produto que terá sua quantidade reduzida.
     * @param quantidade A quantidade de unidades a serem subtraídas.
     * @return true Se a operação foi bem-sucedida (produto encontrado e com quantidade suficiente).
     * @return false Se o produto não for encontrado ou se a quantidade desejada for maior que a disponível em estoque.
     */
    bool removerItem(const std::string &nomeProduto, int quantidade);

    /**
     * @brief Verifica se um determinado jogo está cadastrado no sistema de estoque.
     * * @param nomeProduto O nome do jogo a ser pesquisado.
     * @return true Se o jogo constar na lista do estoque.
     * @return false Se o jogo não existir no estoque.
     */
    bool jogoExiste(const std::string &nomeProduto) const;

    /**
     * @brief Atualiza os dados cadastrais de um produto já existente no estoque.
     * * Permite modificar a plataforma, o gênero e o preço do jogo sem alterar
     * a sua quantidade armazenada ou o seu nome (chave de busca).
     * * @param nome O nome atual do produto que será editado.
     * @param novaPlat A nova plataforma para a qual o jogo está disponível (ex: "PS5", "PC").
     * @param novoGen O novo gênero do jogo (ex: "RPG", "Aventura").
     * @param novoPreco O novo preço de venda do jogo.
     * @return true Se o produto foi encontrado e atualizado com sucesso.
     * @return false Se o produto especificado não foi encontrado no estoque.
     */
    bool editarProduto(const std::string &nome, const std::string &novaPlat, const std::string &novoGen, double novoPreco);

};

#endif