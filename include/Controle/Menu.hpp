#ifndef MENU_HPP
#define MENU_HPP

#include "Usuario.hpp"

/**
 * @brief Controla os Menus do sistema
 *
 */
class Menu
{
public:
    /**
     * @brief Apresenta menu de entrada
     * 
     */
    static void showMenu(const Usuario& usuario);
    /**
     * @brief Primeiro Menu de entrada para usuários sem autenticação
     *
     */
    static void Menu_01();

    /**
     * @brief Apreseta o menu de login e recebe dados do usuário. Chama login_action
     *
     */
    static void Login();

    static void Login_Action(std::string usuario, std::string senha); // Só leitura?? usar &??

private:
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