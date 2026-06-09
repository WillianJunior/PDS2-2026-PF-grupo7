#include "Menu.hpp"
#include <iostream>
#include <string>

void Menu::Menu_01(){

    std::cout << "1. Login" << std::endl;
    std::cout << "2. Ver Catálogo" << std::endl;
    std::cout << "3. Sair" << std::endl;

}

void Menu::Login_Action(std::string usuario, std::string senha){
    
    //Deverá utilizar os parametros para buscar em um txt o usuario e senha correspondente. 

}



void Menu::Login(){

    std::string usuario;
    std::string senha;

    std::cout << "Usuário: " << std::endl;
    std::cin >> usuario;

    std::cout << "Senha: " << std::endl;
    std::cin >> senha;

    Menu::Login_Action(usuario, senha);

}

