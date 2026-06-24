#include "Menu.hpp"
#include "NivelDeAcesso.hpp"
#include "animacao.hpp"
#include <iostream>
#include <limits>

int Menu::lerComando()
{
    int opt;
    std::cout << "\n>> ";
    while (true)
    {
        if(std::cin >> opt){
            return opt;
        }

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Entrada invalida.\n>>";
        
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return opt;
}

void Menu::iniciar()
{
    animacao::load_ps();
    animacao::abertura();

    EstadosDeMenu estado = EstadosDeMenu::MenuInicial;
    std::unique_ptr<Usuario> usuario;

    while (estado != EstadosDeMenu::Sair)
    {
        switch (estado)
        {
        case EstadosDeMenu::MenuInicial: // será verdadeiro ao inciar
            estado = menuInicial();
            break;

        case EstadosDeMenu::Login:
            usuario = fazerLogin();
            // Se o usuario está logado, vai para o menu do tipo de usuario, caso contrário retorna para o menu inicial
            estado = usuario ? EstadosDeMenu::MenuPrincipal : EstadosDeMenu::MenuInicial;
            break;
        case EstadosDeMenu::MenuPrincipal:
            estado = menuPrincipal(*usuario);
            break;

        case EstadosDeMenu::VerCatalogo:
            // chamar método que mostra o catálogo
            break;

        case EstadosDeMenu::Sair:
            break;
        }
    }

    animacao::encerramento();
}

std::unique_ptr<Usuario> Menu::fazerLogin()
{
    std::string email, senha;

    std::cout << "=== Login ===" << std::endl;
    std::cout << "Email: ";
    std::cin >> email;
    std::cout << "Senha: ";
    std::cin >> senha;
    auto usuario = Usuario::login(email, senha);

    if (!usuario)
    {
        std::cout << "Email ou senha invalidos." << std::endl;
        std::cin.get();
    }
    return usuario;
}

EstadosDeMenu Menu::menuInicial()
{
    std::cout << "1. Login" << std::endl;
    std::cout << "2. Ver Catálogo" << std::endl;
    std::cout << "3. Sair" << std::endl;

    switch (lerComando())
    {
    case 1:
        return EstadosDeMenu::Login;
    case 2:
        return EstadosDeMenu::VerCatalogo;
    case 3:
        return EstadosDeMenu::Sair;
    default:
        return EstadosDeMenu::MenuInicial;
    }
}

void Menu::Menu_01()
{

    std::cout << "1. Login" << std::endl;
    std::cout << "2. Ver Catálogo" << std::endl;
    std::cout << "3. Sair" << std::endl;
}

void Menu::Login_Action(std::string usuario, std::string senha)
{

    // Deverá utilizar os parametros para buscar em um txt o usuario e senha correspondente.
}

void Menu::Login()
{

    std::string usuario;
    std::string senha;

    std::cout << "Usuário: " << std::endl;
    std::cin >> usuario;

    std::cout << "Senha: " << std::endl;
    std::cin >> senha;

    Menu::Login_Action(usuario, senha);
}

EstadosDeMenu Menu::menuPrincipal(const Usuario &usuario)
{

    if (usuario.possuiAcesso(static_cast<int>(NivelDeAcesso::Admin)))
    {
        return menuPrincipalAdmin(usuario);
    }

    return menuPrincipalCliente(usuario);
}

void Menu::showMenu(const Usuario &usuario)
{
    std::cout << "\nBem vindo, " << usuario.nome << "!\n"
              << std::endl;

    if (usuario.possuiAcesso(static_cast<int>(NivelDeAcesso::Admin)))
    {
        menuAdmin();
    }
    else if (usuario.possuiAcesso(static_cast<int>(NivelDeAcesso::Cliente)))
    {
        menuCliente();
    }
    else
    {
        menuVisitante();
    }
}

void Menu::menuVisitante()
{

    std::cout << "1. Login" << std::endl;
    std::cout << "2. Ver Catálogo" << std::endl;
    std::cout << "3. Sair" << std::endl;
}

EstadosDeMenu Menu::menuPrincipalCliente(const Usuario &usuario)
{

    std::cout << "Bem-vindo, " << usuario.nome << "!\n"
              << std::endl;
    std::cout << "1. Ver Catálogo" << std::endl;
    std::cout << "2. Carrinho" << std::endl;
    std::cout << "3. Minhas Compras" << std::endl;
    std::cout << "4. Editar Meus Dados" << std::endl;
    std::cout << "5. Sair" << std::endl;

    switch (lerComando())
    {

    case 1:
        return EstadosDeMenu::VerCatalogo;
    case 2:
        return EstadosDeMenu::Carrinho;
    case 3:
        return EstadosDeMenu::MinhasCompras;
    case 4:
        return EstadosDeMenu::EditarMeusDados;
    case 5:
        return EstadosDeMenu::Sair;
    default:
        return EstadosDeMenu::MenuPrincipal; // fica no mesmo menu se input inválido.
    }
}

void Menu::menuCliente()
{
    std::cout << "1. Ver Catálogo" << std::endl;
    std::cout << "2. Carrinho" << std::endl;
    std::cout << "3. Minhas Compras" << std::endl;
    std::cout << "4. Editar Meus Dados" << std::endl;
    std::cout << "5. Sair" << std::endl;
}

EstadosDeMenu Menu::menuPrincipalAdmin(const Usuario &usuario)
{

    std::cout << "Bem-vindo, " << usuario.nome << "!\n"
              << std::endl;
    std::cout << "1. Ver Catálogo" << std::endl;
    std::cout << "2. Carrinho" << std::endl;
    std::cout << "3. Minhas Compras" << std::endl;
    std::cout << "4. Gerenciar Produto" << std::endl;  // cria, exclui, altera produtos.
    std::cout << "5. Gerenciar Catálogo" << std::endl; // adiciona, remove produtos do catálogo.
    std::cout << "6. Gerenciar Estoque" << std::endl;  // adiona, remove, altera qtd de produtos do estoque
    std::cout << "7. Ver Estoque" << std::endl;
    std::cout << "8. Sair" << std::endl;

    switch (lerComando())
    {

    case 1:
        return EstadosDeMenu::VerCatalogo;
    case 2:
        return EstadosDeMenu::Carrinho;
    case 3:
        return EstadosDeMenu::MinhasCompras;
    case 4:
        return EstadosDeMenu::GerenciarProduto;
    case 5:
        return EstadosDeMenu::GerenciarCatalogo;
    case 6:
        return EstadosDeMenu::GerenciarEstoque;
    case 7:
        return EstadosDeMenu::VerEstoque;
    case 8:
        return EstadosDeMenu::Sair;
    default:
        return EstadosDeMenu::MenuPrincipal; // fica no mesmo menu se input inválido.
    }
}

void Menu::menuAdmin()
{
    std::cout << "1. Ver Catálogo" << std::endl;
    std::cout << "2. Carrinho" << std::endl;
    std::cout << "3. Minhas Compras" << std::endl;
    std::cout << "4. Gerenciar Produto" << std::endl;  // cria, exclui, altera produtos.
    std::cout << "5. Gerenciar Catálogo" << std::endl; // adiciona, remove produtos do catálogo.
    std::cout << "6. Gerenciar Estoque" << std::endl;  // adiona, remove, altera qtd de produtos do estoque
    std::cout << "7. Ver Estoque" << std::endl;
    std::cout << "8. Sair" << std::endl;
}