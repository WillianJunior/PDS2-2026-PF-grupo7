#ifndef MENU_HPP
#define MENU_HPP

#include "Usuario.hpp"
#include "EstadosDeMenu.hpp"
#include "Carrinho.hpp"

/**
 * @brief Controla os Menus do sistema
 *
 */
class Menu
{
public:
    /**
     * @brief Menu para usuários não autenticados
     * 
     * @return EstadosDeMenu 
     */
    static EstadosDeMenu menuInicial();
    /**
     * @brief Inicia o sistema
     *
     */
    static void iniciar();
    
private:
    /**
     * @brief Busca o usuário e realiza o login se existir
     *
     * @return std::unique_ptr<Usuario>
     */
    static std::unique_ptr<Usuario> fazerLogin();

    // Retorna os Menus Principais
    static EstadosDeMenu menuPrincipal(const Usuario &usuario);
    static EstadosDeMenu menuPrincipalCliente(const Usuario &usuario);
    static EstadosDeMenu menuPrincipalAdmin(const Usuario &Usuario);

    // Retorna os Sub-Menus
    static EstadosDeMenu verCatalogo(const Usuario &usuario, Carrinho& carrinho);
    static EstadosDeMenu verCatalogo();
    static EstadosDeMenu verCarrinho(Carrinho &carrinho);
    static EstadosDeMenu verMinhasCompras(const Usuario &usuario);
    static EstadosDeMenu verEditarMeusDados(const Usuario &usuario);
    static EstadosDeMenu verEstoque(const Usuario &usuario);

    static EstadosDeMenu menuGerenciarProduto(const Usuario &usuario);
    static EstadosDeMenu menuGerenciarCatalogo(const Usuario &usuario);
    static EstadosDeMenu menuGerenciarEstoque(const Usuario &usuario);

    /**
     * @brief Lê a opção escolhida pelo usuário e retorna o número escolhido
     *
     *
     * @return int
     */
    static int lerComando();

    /**
     * @brief Mostra menu de Cliente autenticado
     *
     */
    static void menuCliente();
    /**
     * @brief Mostra menu de Administrador
     *
     */
    static void menuAdmin();
    /**
     * @brief Mostra menu de visitantes
     *
     */
    static void menuVisitante();
};

#endif