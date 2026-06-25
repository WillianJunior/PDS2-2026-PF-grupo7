#include "Administrador.hpp"
#include "NivelDeAcesso.hpp"
#include <iostream>

Administrador::Administrador(
    const std::string &nome,
    const std::string &email,
    const std::string &senha)
    : usuario(nome, email, senha, static_cast<int>(NivelDeAcesso::Admin)) {}


void Administrador::gerenciarCatalogo() {}

void Administrador::gerenciarEstoque() {}