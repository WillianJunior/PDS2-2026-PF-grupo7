#include "Produto.hpp"

Produto::Produto() {}

Produto::Produto(int id, const std::string& nome, const std::string& categoria, float preco, int quantidadeEstoque) {}

int Produto::getId() const {return 0; }

std::string Produto::getNome() const {return {}; }

std::string Produto::getCategoria() const {return {}; }

float Produto::getPreco() const {return 0; }

int Produto::getQuantidadeEstoque() const {return 0; }

void Produto::setId(int id) {}

void Produto::setNome(const std::string& nome) {}

void Produto::setCategoria(const std::string& categoria) {}

void Produto::setPreco(float preco) {}

void Produto::setQuantidadeEstoque(int quantidadeEstoque) {}