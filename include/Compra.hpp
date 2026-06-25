#ifndef COMPRA_HPP
#define COMPRA_HPP

#include <string>
#include <vector>
#include "Produto.hpp"

/**
 * @file Compra.hpp
 * @brief Representa o registro de uma compra finalizada por um cliente.
 *
 * Armazena os itens, o valor total e a data de uma compra, e oferece
 * persistência simples em arquivo de texto para consulta posterior
 * (histórico de compras).
 *
 * @see Carrinho
 * @see Produto
 */
class Compra
{
public:
    /**
     * @brief Constrói uma nova Compra a partir dos itens do carrinho no momento do checkout.
     * @param emailCliente Email do cliente que realizou a compra.
     * @param itens Itens (produtos) que fazem parte da compra.
     */
    Compra(const std::string &emailCliente, const std::vector<Produto> &itens);

    /**
     * @brief Exibe no console os dados da compra (data, itens e total).
     */
    void exibirCompra() const;

    double getTotal() const;
    const std::string &getData() const;
    const std::vector<Produto> &getItens() const;

    /**
     * @brief Salva uma compra no arquivo de histórico (modo "append").
     */
    static void salvarHistorico(const Compra &compra, const std::string &txtpath = "compras.txt");

    /**
     * @brief Carrega o histórico de compras de um cliente específico.
     */
    static std::vector<Compra> carregarHistorico(const std::string &emailCliente,
                                                  const std::string &txtpath = "compras.txt");

private:
    std::string emailCliente;
    std::string data;
    std::vector<Produto> itens;
    double total;

    /**
     * @brief Construtor da classe Compra.
     * * @param emailCliente O email do utilizador que efetuou a compra.
     * @param data A data e hora em que a compra foi efetuada.
     * @param itens Lista (vector) de produtos adquiridos.
     * @param total O valor total final da compra.
     */
    Compra(const std::string &emailCliente, const std::string &data,
           const std::vector<Produto> &itens, double total);

    /**
     * @brief Gera a data e hora atuais do sistema.
     * @return Uma string formatada com a data atual (ex: "DD/MM/AAAA HH:MM").
     */
    static std::string gerarDataAtual();

    /**
     * @brief Converte a lista de produtos numa única string para ser guardada no txt.
     * Utiliza vírgulas (,) para separar os atributos do produto e barras verticais (|) 
     * para separar os diferentes produtos.
     * * @param itens O vetor de produtos a serializar.
     * @return std::string A string formatada contendo todos os itens.
     */
    static std::string serializarItens(const std::vector<Produto> &itens);

    /**
     * @brief Lê uma string formatada e reconstrói a lista de objetos Produto.
     * * @param itensStr A string gerada anteriormente pelo método serializarItens().
     * @return std::vector<Produto> O vetor reconstruído com os produtos.
     */
    static std::vector<Produto> desserializarItens(const std::string &itensStr);
};

#endif