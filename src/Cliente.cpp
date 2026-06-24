#include "Cliente.hpp"
#include "NivelDeAcesso.hpp"
#include <iostream>

Cliente::Cliente(const std::string& nome,
                 const std::string& email,
                 const std::string& senha)
                 : usuario(nome, email, senha, static_cast<int>(NivelDeAcesso::Cliente)){}
                

void Cliente::_alterarNome(std::string nome) {}

void Cliente::_alterarEndereco(std::string endereco) {}

std::vector<Compra> Cliente::_getHistoricoCompras() {return {}; }

void Cliente::_classificarProduto(int id, int nota) {}

void Cliente::_getCatalogo() {}

void Cliente::_addProdutoCarrinho(int idProduto, Carrinho carrinho) {}

void Cliente::_delProdutoCarrinho(int idProduto, Carrinho carrinho) {}

void Cliente::_limparCarrinho(Carrinho carrinho) {}

std::string Cliente::getEndereco() {return {}; }
std::string Cliente::getNome() {return {}; }