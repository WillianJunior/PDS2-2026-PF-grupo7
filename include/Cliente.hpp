#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include "Carrinho.hpp"
#include "Usuario.hpp"

class Cliente
{
private:
    
public:
    Usuario usuario; // Composição
    Carrinho carrinho; // Composição -> Cada cliente possui um carrinho.

    Cliente(const std::string &nome, const std::string &email, const std::string &senha);

};

#endif