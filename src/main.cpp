#include "animacao.hpp"
#include "Menu.hpp"

int main() {

    animacao::load_ps();
    animacao::abertura();

    int menu_item = 0;

    //FAZER: Nova Classe para printar os Menus de seleção
    Menu::Menu_01();

    std::cin >> menu_item;

    switch (menu_item)
    {
    case 1:
        animacao::abertura(); //Precisa sempre dessa função pra manter o banner???
        Menu::Login();
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

}