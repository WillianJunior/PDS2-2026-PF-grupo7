#include "Cliente.hpp"

Cliente::Cliente() {}

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