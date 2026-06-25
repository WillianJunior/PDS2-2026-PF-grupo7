#include "Estoque.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

Estoque::Estoque(const std::string &txtPath) : m_txtPath(txtPath) {}

bool Estoque::carregarEstoque() {
    std::ifstream file(m_txtPath);
    if (!file.is_open()) return false;

    m_itens.clear();
    std::string line;
    std::getline(file, line); // Pula o cabeçalho

    while (std::getline(file, line)) {
        if (line.empty()) continue;

        std::istringstream ss(line);
        std::string nome, plataforma, genero, precoStr, qtdStr;

        std::getline(ss, nome, ';');
        std::getline(ss, plataforma, ';');
        std::getline(ss, genero, ';');
        std::getline(ss, precoStr, ';');
        std::getline(ss, qtdStr, ';');

        if (!nome.empty() && !qtdStr.empty()) {
            try {
                double preco = std::stod(precoStr);
                int quantidade = std::stoi(qtdStr);
                
                // Cria o produto e o adiciona no map junto com a quantidade
                Produto p(nome, plataforma, genero, preco);
                m_itens[nome] = std::make_pair(p, quantidade);
            } catch (...) {
                continue;
            }
        }
    }
    file.close();
    return true;
}

void Estoque::salvarEstoque() const {
    std::ofstream file(m_txtPath);
    if (!file.is_open()) return;

    file << "nome;plataforma;genero;preco;quantidade\n";
    for (const auto &par : m_itens) {
        const Produto& p = par.second.first; // Acessa o Produto dentro do pair
        int qtd = par.second.second;         // Acessa a Quantidade dentro do pair
        
        file << p.nome << ";" << p.plataforma << ";" << p.genero << ";" 
             << p.preco << ";" << qtd << "\n";
    }
    file.close();
}

void Estoque::adicionarItem(const Produto& produto, int quantidade) {
    auto it = m_itens.find(produto.nome);
    if (it != m_itens.end()) {
        it->second.second += quantidade; // Apenas soma se o jogo já existe
    } else {
        m_itens[produto.nome] = std::make_pair(produto, quantidade); // Cadastra novo
    }
}

bool Estoque::removerItem(const std::string &nomeProduto, int quantidade) {
    auto it = m_itens.find(nomeProduto);
    if (it != m_itens.end()) {
        if (it->second.second >= quantidade) {
            it->second.second -= quantidade;
            if (it->second.second == 0) {
                m_itens.erase(it);
            }
            return true;
        }
    }
    return false; 
}

bool Estoque::jogoExiste(const std::string &nomeProduto) const {
    return m_itens.find(nomeProduto) != m_itens.end();
}

// ---- METODOS AUXILIARES ADAPTADOS ----
bool Estoque::possuiEstoque(const std::string &nomeProduto) const {
    auto it = m_itens.find(nomeProduto);
    return (it != m_itens.end() && it->second.second > 0);
}

bool Estoque::darBaixa(const std::string &nomeProduto) {
    auto it = m_itens.find(nomeProduto);
    if (it != m_itens.end() && it->second.second > 0) {
        it->second.second--;
        return true;
    }
    return false;
}

int Estoque::obterQuantidade(const std::string &nomeProduto) const {
    auto it = m_itens.find(nomeProduto);
    if (it != m_itens.end()) {
        return it->second.second;
    }
    return 0;
}

void Estoque::exibirEstoque() const {
    std::cout << "\n======================== ESTOQUE ATUAL ========================\n";
    std::cout << std::left 
              << std::setw(30) << "Nome" 
              << std::setw(12) << "Plataforma" 
              << std::setw(15) << "Genero" 
              << std::setw(10) << "Preco" 
              << "Quantidade\n";
    std::cout << std::string(80, '-') << std::endl;

    for (const auto &par : m_itens) {
        const Produto& p = par.second.first;
        std::cout << std::left 
                  << std::setw(30) << p.nome
                  << std::setw(12) << p.plataforma
                  << std::setw(15) << p.genero
                  << "R$ " << std::setw(7) << std::fixed << std::setprecision(2) << p.preco
                  << par.second.second << "\n";
    }
    std::cout << std::string(80, '-') << std::endl;
}