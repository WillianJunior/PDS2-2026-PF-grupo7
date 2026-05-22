#include "Compra.hpp"

Compra::Compra(int idCompra,
    int idCliente,
    const std::vector<Produto>& itens,
    const std::string& dataCompra,
    const std::string& metodoPagamento) {}

int Compra::getIdCompra() const { return 0; }
int Compra::getIdCliente() const { return 0; }
std::vector<Produto> Compra::getItens() const { return {}; }
std::string Compra::getDataCompra() const { return {}; }
std::string Compra::getStatus() const { return {}; }
std::string Compra::getMetodoPagamento() const { return {}; }
bool Compra::processarPagamento() { return false; }

void Compra::atualizarStatus(const std::string& novoStatus) {}

void Compra::atualizarEstoque() {}

std::string Compra::gerarResumo() const { return {}; }