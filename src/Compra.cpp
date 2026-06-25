#include "Compra.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <ctime>

Compra::Compra(const std::string &emailCliente, const std::vector<Produto> &itens)
    : emailCliente(emailCliente), itens(itens), total(0.0)
{
    data = gerarDataAtual();
    for (const Produto &item : itens) {
        total += item.preco;
    }
}

Compra::Compra(const std::string &emailCliente, const std::string &data,
               const std::vector<Produto> &itens, double total)
    : emailCliente(emailCliente), data(data), itens(itens), total(total) {}

std::string Compra::gerarDataAtual()
{
    std::time_t agora = std::time(nullptr);
    std::tm *tmAgora = std::localtime(&agora);
    std::ostringstream oss;
    oss << std::put_time(tmAgora, "%d/%m/%Y %H:%M");
    return oss.str();
}

double Compra::getTotal() const { return total; }
const std::string &Compra::getData() const { return data; }
const std::vector<Produto> &Compra::getItens() const { return itens; }

void Compra::exibirCompra() const
{
    std::cout << "\nData: " << data << std::endl;
    std::cout << std::string(40, '-') << std::endl;
    for (const Produto &item : itens) {
        item.exibirProduto();
    }
    std::cout << std::string(40, '-') << std::endl;
    std::cout << "Total: R$ " << std::fixed << std::setprecision(2) << total << std::endl;
}

std::string Compra::serializarItens(const std::vector<Produto> &itens)
{
    std::ostringstream oss;
    for (size_t i = 0; i < itens.size(); ++i) {
        if (i > 0) oss << ",";
        oss << itens[i].nome << "|" << itens[i].plataforma << "|"
            << itens[i].genero << "|" << itens[i].preco;
    }
    return oss.str();
}

std::vector<Produto> Compra::desserializarItens(const std::string &itensStr)
{
    std::vector<Produto> resultado;
    std::istringstream itemStream(itensStr);
    std::string itemToken;

    while (std::getline(itemStream, itemToken, ',')) {
        std::istringstream campoStream(itemToken);
        std::string nome, plataforma, genero, precoStr;
        std::getline(campoStream, nome, '|');
        std::getline(campoStream, plataforma, '|');
        std::getline(campoStream, genero, '|');
        std::getline(campoStream, precoStr, '|');

        if (nome.empty()) continue;

        double preco = std::stod(precoStr);
        resultado.push_back(Produto(nome, plataforma, genero, preco));
    }
    return resultado;
}

void Compra::salvarHistorico(const Compra &compra, const std::string &txtpath)
{
    std::ifstream checagem(txtpath);
    bool arquivoExiste = checagem.good();
    checagem.close();

    std::ofstream file(txtpath, std::ios::app);
    if (!file.is_open()) {
        std::cerr << "Erro: nao foi possivel salvar o historico em " << txtpath << std::endl;
        return;
    }

    if (!arquivoExiste) {
        file << "email;data;total;itens\n";
    } else {
        std::ifstream verificacao(txtpath, std::ios::ate);
        std::streampos tamanho = verificacao.tellg();
        if (tamanho > 0) {
            verificacao.seekg(-1, std::ios::end);
            char ultimoChar;
            verificacao.get(ultimoChar);
            if (ultimoChar != '\n') file << "\n";
        }
    }

    file << compra.emailCliente << ";" << compra.data << ";"
         << compra.total << ";" << serializarItens(compra.itens) << "\n";
}

std::vector<Compra> Compra::carregarHistorico(const std::string &emailCliente, const std::string &txtpath)
{
    std::vector<Compra> resultado;
    std::ifstream file(txtpath);
    if (!file.is_open()) return resultado;

    std::string line;
    std::getline(file, line); // pula o cabecalho

    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string email, data, totalStr, itensStr;
        std::getline(ss, email, ';');
        std::getline(ss, data, ';');
        std::getline(ss, totalStr, ';');
        std::getline(ss, itensStr);

        if (email != emailCliente) continue;

        double total = std::stod(totalStr);
        resultado.push_back(Compra(email, data, desserializarItens(itensStr), total));
    }
    return resultado;
}