#pragma once
#include <string>
#include "Usuario.hpp"
#include "Carrinho.hpp"
#include "HistoricoDeCompras.hpp"

/**
 * @file Cliente.hpp
 * @brief Representa um cliente cadastrado na plataforma.
 *
 * Especializa Usuario com dados de contato e preferências, além de
 * agregar o Carrinho de compras ativo e o HistoricoDeCompras do cliente.
 * O cliente pode navegar no catálogo, avaliar produtos e efetuar compras.
 *
 * @see Usuario
 * @see Carrinho
 * @see HistoricoDeCompras
 * @see Catalogo
 */
class Cliente : public Usuario {
private:
    std::string        endereco;           ///< Endereço de entrega do cliente.
    std::string        telefone;           ///< Telefone de contato do cliente.
    std::string        perfil;             ///< Perfil ou preferências de compra do cliente.
    Carrinho           carrinho;           ///< Carrinho de compras ativo do cliente.
    HistoricoDeCompras historicoDeCompras; ///< Histórico de todas as compras realizadas pelo cliente.
};





#endif