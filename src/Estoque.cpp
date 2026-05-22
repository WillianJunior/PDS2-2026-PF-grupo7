#include "Estoque.hpp"

Estoque::Estoque(int limiteAlerta) {}

void Estoque::setQuantidade(int produtoId, int quantidade) {}

int Estoque::getQuantidade(int produtoId) const {return 0;}

void Estoque::adicionarProduto(int produtoId, int quantidade) {}

void Estoque::removerProduto(int produtoId, int quantidade) {}

bool Estoque::temEstoque(int produtoId, int quantidade) const {return false;}

bool Estoque::estoqueBaixo(int produtoId) const {return false;}

bool Estoque::semEstoque(int produtoId) const {}

bool Estoque::reservarProduto(int produtoId, int quantidade) {return false;}

void Estoque::cancelarReserva(int produtoId, int quantidade) {}

std::string Estoque::gerarRelatorio() const {return {};}