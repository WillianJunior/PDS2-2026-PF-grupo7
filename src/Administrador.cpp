#include "Administrador.hpp"

Administrador::Administrador(int id,
    const std::string& nome,
    const std::string& email,
    const std::string& senha,
    const std::string& nivelAcesso) {}

std::string Administrador::getNivelAcesso() const {return {}; }

void Administrador::gerenciarCatalogo() {}

void Administrador::acessarDadosClientes() {}

void Administrador::gerenciarCompras() {}

void Administrador::gerenciarEstoque() {}

void Administrador::gerenciarPerfisClientes() {}

//bool Administrador::autenticar(const std::string& senha) const {}