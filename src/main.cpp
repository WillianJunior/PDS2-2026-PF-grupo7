#include "animacao.hpp"
#include "Usuario.hpp"
#include "Menu.hpp"
#include <iostream>
#include <memory>

int main()
{
    Menu::iniciar();
    return 0;
/*
    animacao::load_ps();
    animacao::abertura();

    std::string email, senha;

    int menu_item = 0;

    // FAZER: Nova Classe para printar os Menus de seleção
    Menu::Menu_01();

    std::cin >> menu_item;
    std::unique_ptr<Usuario> usuario;
    switch (menu_item)
    {
    case 1:
        animacao::abertura(); // Precisa sempre dessa função pra manter o banner???

        std::cout << "=== Login ===" << std::endl;
        std::cout << "Email: ";
        std::cin >> email;
        std::cout << "Senha: ";
        std::cin >> senha;
        usuario = Usuario::login(email, senha);

        if (!usuario)
        {
            std::cout << "Email ou senha invalidos." << std::endl;
            return 1;
        }

        Menu::showMenu(*usuario);

        break;
    case 2:

        break;

    case 3:
        animacao::encerramento();
        return 0;
        break; //?????
    default:
        break;
    }

    return 0;

    */
}