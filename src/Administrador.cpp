#include "Administrador.hpp"
#include "NivelDeAcesso.hpp"
#include <iostream>

Administrador::Administrador(
    const std::string &nome,
    const std::string &email,
    const std::string &senha)
    : usuario(nome, email, senha, static_cast<int>(NivelDeAcesso::Admin)) {}

std::string Administrador::getNivelAcesso() const { return {}; }

void Administrador::gerenciarCatalogo() {}

void Administrador::acessarDadosClientes() {}

void Administrador::gerenciarCompras() {}

void Administrador::gerenciarEstoque() {}

void Administrador::gerenciarPerfisClientes() {}

// bool Administrador::autenticar(const std::string& senha) const {}