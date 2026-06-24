#include "Catalogo.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iomanip>

Catalogo Catalogo::carregarCatalogo(const std::string &txtpath)
{
    Catalogo catalogo;
    std::ifstream file(txtpath);

    if (!file.is_open())
    {
        std::cerr << "Erro: nao foi possivel abrir " << txtpath << std::endl;
        return catalogo;
    }

    std::string line;
    std::getline(file, line); // pula a primeira linha

    while (std::getline(file, line))
    {
        std::istringstream ss(line);
        std::string nome, plataforma, genero, precoStr;

        std::getline(ss, nome, ';');
        std::getline(ss, plataforma, ';');
        std::getline(ss, genero, ';');
        std::getline(ss, precoStr, ';');

        if (nome.empty())
            continue; //??

        double preco = std::stod(precoStr);                                 // converte preco pra double
        catalogo.jogos.push_back(Produto(nome, plataforma, genero, preco)); // adiciona jogo a lista
    }

    return catalogo;
}

void Catalogo::exibirCabecalho() const
{
    std::cout << std::left // justifica na esquerda
              << std::setw(35) << "Nome"
              << std::setw(10) << "Plataforma"
              << std::setw(15) << "Genero"
              << "Preco"
              << std::endl;
    std::cout << std::string(70, '-') << std::endl;
}

void Catalogo::listarJogos(const std::vector<Produto> &listaDeJogos) const
{
    if(listaDeJogos.empty()){
        std::cout << "Nenhum jogo encontrado." << std::endl;
        return;
    }
    for(const Produto &jogo : listaDeJogos){
        jogo.exibirProduto();
    }
    std::cout << std::string(70, '-') << std::endl;
    std::cout << listaDeJogos.size() << " jogo(s) encontrado(s)." << std::endl;
}

void Catalogo::exibirCatalogo()const{
    exibirCabecalho();
    listarJogos(jogos);
}

//FILTRO GENERO
void Catalogo::filtrarGenero(const std::string &genero) const{
    std::vector<Produto> jogosFiltrados;

    for(const Produto &jogo : jogos){
        if(jogo.genero == genero){
            jogosFiltrados.push_back(jogo);
        }
    }

    std::cout << "\n=== Filtro: Gênero \"" << genero << "\" ===" << std::endl;
    exibirCabecalho();
    listarJogos(jogosFiltrados);


}
//FILTRO PLATAFORMA
void Catalogo::filtrarPlataforma(const std::string &plataforma) const{
    std::vector<Produto> jogosFiltrados;

    for(const Produto &jogo : jogos){
        if(jogo.plataforma == plataforma){
            jogosFiltrados.push_back(jogo);
        }
    }

    std::cout << "\n=== Filtro: Plataforma \"" << plataforma << "\" ===" << std::endl;
    exibirCabecalho();
    listarJogos(jogosFiltrados);

}

void Catalogo::ordenarPreco() const{
    std::vector<Produto> ordenado = jogos; //copia lista inicial

    std::sort(ordenado.begin(), ordenado.end(),
    [](const Produto& a, const Produto& b){
        return a.preco < b.preco;
    });

    std::cout << "\n=== Catalogo Ordenado por Preco ===" << std::endl;
    exibirCabecalho();
    listarJogos(ordenado);
}


void Catalogo::adicionarProduto(const Produto &produto) {}

void Catalogo::removerProduto(int id) {}

std::vector<Produto> Catalogo::getProdutos() const { return {}; }

std::vector<Produto> Catalogo::filtrarPorCategoria(const std::string &categoria) { return {}; }

void Catalogo::ordenarPorPreco(bool crescente) {}

std::vector<Produto> Catalogo::buscarProduto(const std::string &termo) { return {}; }

std::string Catalogo::listarNomes() const { return {}; }

std::string Catalogo::listarPrecos() const { return {}; }