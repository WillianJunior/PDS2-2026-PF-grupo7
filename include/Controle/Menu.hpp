#ifndef CARRINHO_HPP
#define CARRINHO_HPP

#include <string>

/**
 * @brief Menu para controle dos Menus da aplicação
 * 
 */
class Menu
{
public:
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

    static void Login_Action(std::string usuario, std::string senha); //Só leitura?? usar &??

};

#endif