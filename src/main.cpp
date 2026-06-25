#include "animacao.hpp"
#include "Usuario.hpp"
#include "Menu.hpp"

int main()
{
    animacao::load_ps();
    animacao::abertura();
    Menu::iniciar();
    animacao::encerramento();
    return 0;

}