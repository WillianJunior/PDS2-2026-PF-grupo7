#include "Catalogo.hpp"

Catalogo::Catalogo() {}

void Catalogo::adicionarProduto(const Produto& produto) {}

void Catalogo::removerProduto(int id) {}

std::vector<Produto> Catalogo::getProdutos() const {return {}; }

std::vector<Produto> Catalogo::filtrarPorCategoria(const std::string& categoria) {return {}; }

void Catalogo::ordenarPorPreco(bool crescente) {}

std::vector<Produto> Catalogo::buscarProduto(const std::string& termo) {return {}; }

std::string Catalogo::listarNomes() const {return {}; }

std::string Catalogo::listarPrecos() const {return {}; }