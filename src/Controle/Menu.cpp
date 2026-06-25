#include "Menu.hpp"
#include "Catalogo.hpp"
#include "NivelDeAcesso.hpp"
#include "animacao.hpp"
#include <iostream>
#include <limits>

int Menu::lerComando()
{
    int opt;
    std::cout << "\n>> ";
    while (!(std::cin >> opt))
    {
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
    std::unique_ptr<Carrinho> carrinho;

    while (estado != EstadosDeMenu::Sair)
    {
        switch (estado)
        {
        case EstadosDeMenu::MenuInicial: // será verdadeiro ao inciar
            estado = menuInicial();
            break;

        case EstadosDeMenu::Login:
            usuario = fazerLogin();

            if (usuario)
            {
                carrinho = std::unique_ptr<Carrinho>(new Carrinho(*usuario));
                estado = EstadosDeMenu::MenuPrincipal;
            }
            else
            {
                estado = EstadosDeMenu::MenuInicial;
            }
            break;
        case EstadosDeMenu::MenuPrincipal:
            estado = menuPrincipal(*usuario);
            break;

        case EstadosDeMenu::VerCatalogo:
            estado = usuario ? verCatalogo(*usuario, *carrinho) : verCatalogo(); // chamar método que mostra o catálogo
            break;
        case EstadosDeMenu::Carrinho:
            estado = verCarrinho(*carrinho);

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

EstadosDeMenu Menu::menuPrincipal(const Usuario &usuario)
{

    if (usuario.possuiAcesso(static_cast<int>(NivelDeAcesso::Admin)))
    {
        return menuPrincipalAdmin(usuario);
    }

    return menuPrincipalCliente(usuario);
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


EstadosDeMenu Menu::verCatalogo(const Usuario &usuario, Carrinho &carrinho)
{
    Catalogo catalogo = Catalogo::carregarCatalogo("jogos.txt");
    catalogo.exibirCatalogo();

    int opcao;

    do
    {

        std::cout << "=== Catalogo ===" << std::endl;
        std::cout << "1. Ver todos os jogos" << std::endl;
        std::cout << "2. Filtrar por genero" << std::endl;
        std::cout << "3. Filtrar por plataforma" << std::endl;
        std::cout << "4. Ordenar por preco" << std::endl;
        std::cout << "5. Comprar um Jogo" << std::endl;
        std::cout << "6. Ver carrinho" << std::endl;
        std::cout << "0. Voltar" << std::endl;

        opcao = lerComando();

        if (opcao == 1)
        {
            catalogo.exibirCatalogo();
        }
        else if (opcao == 2)
        {
            std::string genero;
            std::cout << "Genero: ";
            std::cin >> genero;
            catalogo.filtrarGenero(genero);
        }
        else if (opcao == 3)
        {
            std::string plataforma;
            std::cout << "Plataforma: ";
            std::cin >> plataforma;
            catalogo.filtrarPlataforma(plataforma);
        }
        else if (opcao == 4)
        {
            catalogo.ordenarPreco();
        }
        else if (opcao == 5)
        {
            catalogo.comprar(carrinho); //Adiciona jogo ao carrinho
        }else if(opcao == 6){
            carrinho.exibirCarrinho();
        }

        if (opcao != 0)
        {
            std::cout << "\nPressione Enter para continuar...";
            std::cin.get();
        }

    } while (opcao != 0);

    return EstadosDeMenu::MenuPrincipal;
}

EstadosDeMenu Menu::verCatalogo()
{
    Catalogo catalogo = Catalogo::carregarCatalogo("jogos.txt");
    catalogo.exibirCatalogo();

    int opcao;

    do
    {

        std::cout << "=== Catalogo ===" << std::endl;
        std::cout << "1. Ver todos os jogos" << std::endl;
        std::cout << "2. Filtrar por genero" << std::endl;
        std::cout << "3. Filtrar por plataforma" << std::endl;
        std::cout << "4. Ordenar por preco" << std::endl;
        std::cout << "0. Voltar" << std::endl;

        opcao = lerComando();

        if (opcao == 1)
        {
            catalogo.exibirCatalogo();
        }
        else if (opcao == 2)
        {
            std::string genero;
            std::cout << "Genero: ";
            std::cin >> genero;
            catalogo.filtrarGenero(genero);
        }
        else if (opcao == 3)
        {
            std::string plataforma;
            std::cout << "Plataforma: ";
            std::cin >> plataforma;
            catalogo.filtrarPlataforma(plataforma);
        }
        else if (opcao == 4)
        {
            catalogo.ordenarPreco();
        }

        if (opcao != 0)
        {
            std::cout << "\nPressione Enter para continuar...";
            std::cin.get();
        }

    } while (opcao != 0);

    return EstadosDeMenu::MenuInicial;
}


EstadosDeMenu Menu::verCarrinho(Carrinho& carrinho){
    int opcao;

    do{
        carrinho.exibirCarrinho();

        std::cout <<"\n1. Remover item" <<std::endl;
        std::cout <<"0. Voltar" <<std::endl;

        opcao = lerComando();

        if (opcao == 1) {
            std::cout << "Numero do item a remover: ";
            int indice;
            std::cin >> indice;
            std::cin.ignore();
            carrinho.remover(indice - 1);
        }

        if (opcao != 0) {
            std::cout << "\nPressione Enter para continuar...";
            std::cin.get();
        }

    } while (opcao != 0);

    return EstadosDeMenu::MenuPrincipal;
}