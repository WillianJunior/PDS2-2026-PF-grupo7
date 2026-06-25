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

void Catalogo::listarJogosNumerados(const std::vector<Produto> &listaDeJogos) const {
    if (listaDeJogos.empty()) {
        std::cout << "Nenhum jogo encontrado." << std::endl;
        return;
    }

    std::cout << std::left
              << std::setw(5)  << "No."
              << std::setw(35) << "Nome"
              << std::setw(10) << "Plataforma"
              << std::setw(15) << "Genero"
              << "Preco"
              << std::endl;
    std::cout << std::string(75, '-') << std::endl;

    for (int i = 0; i < static_cast<int>(listaDeJogos.size()); i++) {
        std::cout << std::left
                  << std::setw(5) << (i + 1);
        listaDeJogos[i].exibirProduto();
    }
    std::cout << std::string(75, '-') << std::endl;
}

void Catalogo::comprar(Carrinho &carrinho) const {
    listarJogosNumerados(jogos);

    std::cout << "\nDigite o numero do jogo para adicionar ao carrinho" << std::endl;
    std::cout << "(0 para cancelar): ";

    int opcao;
    std::cin >> opcao;
    std::cin.ignore(); //limpa entrada

      if (opcao == 0) return;

    int indice = opcao - 1;
    if (indice < 0 || indice >= static_cast<int>(jogos.size())) {
        std::cout << "Opcao invalida." << std::endl;
        return;
    }

    carrinho.adicionar(jogos[indice]);
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

void Catalogo::removerJogo(const std::string &nome) {
    // Remove todos os jogos com o nome especificado do vector interno
    jogos.erase(std::remove_if(jogos.begin(), jogos.end(),
        [&nome](const Produto &p) { return p.nome == nome; }),
        jogos.end());
}

void Catalogo::salvarCatalogo(const std::string &txtpath) const {
    std::ofstream file(txtpath);
    if (!file.is_open()) {
        std::cerr << "Erro: nao foi possivel salvar o catalogo em " << txtpath << std::endl;
        return;
    }

    // Reescreve o cabeçalho padrão do seu projeto
    file << "nome;plataforma;genero;preco\n";
    
    // Salva os jogos restantes
    for (const auto &jogo : jogos) {
        file << jogo.nome << ";" << jogo.plataforma << ";" << jogo.genero << ";" << jogo.preco << "\n";
    }
    
    file.close();
}

void Catalogo::adicionarJogo(const Produto &jogo) {
    jogos.push_back(jogo);
}

bool Catalogo::editarJogo(const std::string &nome, const std::string &novaPlat, const std::string &novoGen, double novoPreco) {
    for (auto &jogo : jogos) {
        if (jogo.nome == nome) {
            jogo.plataforma = novaPlat;
            jogo.genero = novoGen;
            jogo.preco = novoPreco;
            return true;
        }
    }
    return false;
}