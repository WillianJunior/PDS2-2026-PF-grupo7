#ifndef ESTADOS_DE_MENU_HPP
#define ESTADOS_DE_MENU_HPP

/**
 * @file EstadosDeMenu.hpp
 * @brief Define a máquina de estados para a navegação dos menus do sistema.
 */

/**
 * @enum EstadosDeMenu
 * @brief Enumeração que representa cada tela ou estado possível do sistema.
 */
enum class EstadosDeMenu {
    // Não autenticado
    MenuInicial,          ///< Tela inicial para visitantes (Login / Sair)
    Login,                ///< Tela de inserção de credenciais
    Cadastro,              ///< Tela de cadastro de novo usuário (Cliente)
    MenuPrincipal,        ///< Estado intermediário que checa o nível de acesso e redireciona

    // Autenticado (Cliente)
    MenuPrincipalCliente, ///< Menu principal com opções exclusivas do cliente
    VerCatalogo,          ///< Visualização e filtragem de produtos
    Carrinho,             ///< Visualização e gerenciamento do carrinho de compras
    MinhasCompras,        ///< Histórico de compras do cliente
    EditarMeusDados,      ///< Tela para atualização cadastral do cliente

    // Autenticado (Admin)
    MenuPrincipalAdmin,   ///< Menu principal com opções administrativas
    GerenciarProduto,     ///< CRUD e operações básicas de produtos
    GerenciarCatalogo,    ///< Controle de exibição do catálogo global
    GerenciarEstoque,     ///< Controle de entradas, saídas e alertas de estoque
    VerEstoque,           ///< Visualização da situação atual do estoque

    // Saída
    Sair                  ///< Encerramento do programa
};

#endif