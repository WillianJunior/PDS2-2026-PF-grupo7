#include "Menu.hpp"
#include "NivelDeAcesso.hpp"
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

void Menu::showMenu(const Usuario &usuario){
    std::cout <<"\nBem vindo, " << usuario.nome << "!\n" << std::endl;

    if(usuario.possuiAcesso(static_cast<int>(NivelDeAcesso::Admin))){
        menuAdmin();
    }else if(usuario.possuiAcesso(static_cast<int>(NivelDeAcesso::Cliente))){
        menuCliente();
    }else{
        menuVisitante();
    }

    

}

void Menu::menuVisitante(){

    std::cout << "1. Login" << std::endl;
    std::cout << "2. Ver Catálogo" << std::endl;
    std::cout << "3. Sair" << std::endl;
}

void Menu::menuCliente(){
    std::cout << "1. Ver Catálogo" << std::endl;
    std::cout << "2. Carrinho" << std::endl;
    std::cout << "3. Minhas Compras" << std::endl;
    std::cout << "4. Editar Meus Dados" << std::endl;
    std::cout << "5. Sair" << std::endl;
}

void Menu::menuAdmin(){
    std::cout << "1. Ver Catálogo" << std::endl;
    std::cout << "2. Carrinho" << std::endl;
    std::cout << "3. Minhas Compras" << std::endl;
    std::cout << "4. Gerenciar Produto" << std::endl; //cria, exclui, altera produtos. 
    std::cout << "5. Gerenciar Catálogo" << std::endl; //adiciona, remove produtos do catálogo. 
    std::cout << "6. Gerenciar Estoque" << std::endl; //adiona, remove, altera qtd de produtos do estoque
    std::cout << "7. Ver Estoque" << std::endl;
    std::cout << "8. Sair" << std::endl;
}