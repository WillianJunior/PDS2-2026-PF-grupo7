#include "Cliente.hpp"
#include "NivelDeAcesso.hpp"
#include <iostream>

Cliente::Cliente(const std::string& nome,
                 const std::string& email,
                 const std::string& senha)
                 : usuario(nome, email, senha, static_cast<int>(NivelDeAcesso::Cliente)),
                 carrinho(usuario){}
            