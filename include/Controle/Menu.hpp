#ifndef MENU_HPP
#define MENU_HPP

#include "Usuario.hpp"
#include "EstadosDeMenu.hpp"
#include "Carrinho.hpp"

/**
 * @file Menu.hpp
 * @brief Controla as interfaces de menus e fluxos de navegação do sistema.
 */

/**
 * @class Menu
 * @brief Classe estática responsável por renderizar as telas e gerenciar as entradas do usuário.
 */
class Menu
{
public:
    /**
     * @brief Exibe o menu para usuários não autenticados.
     * @return EstadosDeMenu O próximo estado selecionado (ex: Login ou Sair).
     */
    static EstadosDeMenu menuInicial();

    /**
     * @brief Inicia o loop principal do sistema de menus.
     */
    static void iniciar();
    
private:
    /**
     * @brief Captura e processa as credenciais fornecidas pelo usuário.
     * @return std::unique_ptr<Usuario> Ponteiro polimórfico para o usuário autenticado, ou nullptr se falhar.
     */
    static std::unique_ptr<Usuario> fazerLogin();

    /**
     * @brief Exibe o formulário de cadastro e cria um novo usuário (Cliente).
     * @return std::unique_ptr<Usuario> Ponteiro para o usuário recém-cadastrado, ou nullptr se falhar.
     */
    static std::unique_ptr<Usuario> fazerCadastro();

    /**
     * @brief Direciona o usuário para o menu correto com base em seu nível de acesso.
     * @param usuario O usuário autenticado.
     * @return EstadosDeMenu Próximo estado da aplicação.
     */
    static EstadosDeMenu menuPrincipal(const Usuario &usuario);

    /**
     * @brief Renderiza o menu principal exclusivo para Clientes.
     * @param usuario O cliente autenticado.
     * @return EstadosDeMenu Estado interno escolhido pelo cliente.
     */
    static EstadosDeMenu menuPrincipalCliente(const Usuario &usuario);

    /**
     * @brief Renderiza o menu principal exclusivo para Administradores.
     * @param usuario O administrador autenticado.
     * @return EstadosDeMenu Estado interno escolhido pelo administrador.
     */
    static EstadosDeMenu menuPrincipalAdmin(const Usuario &usuario);

    /**
     * @brief Exibe o catálogo para um cliente logado, permitindo interações com o carrinho.
     * @param usuario O cliente atual.
     * @param carrinho O carrinho do cliente para adicionar itens.
     * @return EstadosDeMenu O próximo estado após sair do catálogo.
     */
    static EstadosDeMenu verCatalogo(const Usuario &usuario, Carrinho& carrinho);

    /**
     * @brief Sobrecarga para exibir o catálogo em modo de visualização simples (visitante).
     * @return EstadosDeMenu O próximo estado do menu.
     */
    static EstadosDeMenu verCatalogo();

    /**
     * @brief Exibe os itens do carrinho e gerencia opções de remoção ou checkout.
     * @param carrinho O carrinho a ser inspecionado.
     * @return EstadosDeMenu O próximo estado do menu.
     */
    static EstadosDeMenu verCarrinho(Carrinho &carrinho);

    /**
     * @brief Exibe o histórico de compras de um cliente específico.
     * @param usuario O cliente dono do histórico.
     * @return EstadosDeMenu O próximo estado do menu.
     */
    static EstadosDeMenu verMinhasCompras(const Usuario &usuario);

    /**
     * @brief Tela de formulário para edição de dados cadastrais (nome, email, senha).
     * @param usuario O usuário que deseja alterar os dados.
     * @return EstadosDeMenu O próximo estado do menu.
     */
    static EstadosDeMenu verEditarMeusDados(const Usuario &usuario);

    /**
     * @brief Permite visualizar a quantidade de itens no estoque (visão do admin).
     * @param usuario O administrador logado.
     * @return EstadosDeMenu O próximo estado do menu.
     */
    static EstadosDeMenu verEstoque();

    /**
     * @brief Submenu administrativo para gerenciar criação ou remoção de produtos.
     * @param usuario O administrador logado.
     * @return EstadosDeMenu O próximo estado do menu.
     */
    static EstadosDeMenu menuGerenciarProduto(const Usuario &usuario);

    /**
     * @brief Submenu administrativo para gerenciar o catálogo global.
     * @param usuario O administrador logado.
     * @return EstadosDeMenu O próximo estado do menu.
     */
    static EstadosDeMenu menuGerenciarCatalogo(const Usuario &usuario);

    /**
     * @brief Submenu administrativo para reposição ou baixa de produtos no estoque.
     * @param usuario O administrador logado.
     * @return EstadosDeMenu O próximo estado do menu.
     */
    static EstadosDeMenu menuGerenciarEstoque(const Usuario &usuario);

    /**
     * @brief Lê a opção digitada pelo usuário no console com validação de entrada de dados.
     * @return int O número correspondente à opção escolhida.
     */
    static int lerComando();

    /**
     * @brief Renderiza visualmente o layout do menu do Cliente.
     */
    static void menuCliente();

    /**
     * @brief Renderiza visualmente o layout do menu do Administrador.
     */
    static void menuAdmin();

    /**
     * @brief Renderiza visualmente o layout do menu de visitantes.
     */
    static void menuVisitante();
};

#endif