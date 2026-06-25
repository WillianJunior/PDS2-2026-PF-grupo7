#include "Menu.hpp"
#include "Catalogo.hpp"
#include "Compra.hpp"
#include "NivelDeAcesso.hpp"
#include "Estoque.hpp"
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
        case EstadosDeMenu::Cadastro:
            usuario = fazerCadastro();

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
            break;

        case EstadosDeMenu::MinhasCompras:
            estado = verMinhasCompras(*usuario);
            break;

        case EstadosDeMenu::VerEstoque:
            estado = verEstoque();
            break;

        case EstadosDeMenu::GerenciarProduto:
            estado = gerenciarProduto();
            break; //faltava um break aqui

        case EstadosDeMenu::EditarMeusDados:
            estado = editarMeusDados(*usuario);
            break;

        case EstadosDeMenu::Sair:
            break;
        }
    }
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

std::unique_ptr<Usuario> Menu::fazerCadastro()
{
    std::string nome, email, senha;

    std::cout << "=== Cadastro de novo usuario ===" << std::endl;
    std::cout << "Nome completo: ";
    std::getline(std::cin, nome);
    std::cout << "Email: ";
    std::getline(std::cin, email);
    std::cout << "Senha: ";
    std::getline(std::cin, senha);

    auto usuario = Usuario::cadastrar(nome, email, senha);

    if (!usuario)
    {
        std::cout << "Nao foi possivel concluir o cadastro." << std::endl;
        std::cin.get();
    }
    else
    {
        std::cout << "Cadastro realizado com sucesso! Bem-vindo, " << usuario->nome << "." << std::endl;
    }
    return usuario;
}

EstadosDeMenu Menu::menuInicial()
{
    std::cout << "1. Login" << std::endl;
    std::cout << "2. Ver Catálogo" << std::endl;
    std::cout << "3. Cadastrar" << std::endl;
    std::cout << "4. Sair" << std::endl;

    switch (lerComando())
    {
    case 1:
        return EstadosDeMenu::Login;
    case 2:
        return EstadosDeMenu::VerCatalogo;
    case 3:
        return EstadosDeMenu::Cadastro;
    case 4:
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
    std::cout << "4. Gerenciar Produto" << std::endl; // cria, exclui, altera produtos.
    std::cout << "5. Ver Estoque" << std::endl;
    std::cout << "6. Sair" << std::endl;

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
        return EstadosDeMenu::VerEstoque;
    case 6:
        return EstadosDeMenu::Sair;
    default:
        return EstadosDeMenu::MenuPrincipal; // fica no mesmo menu se input inválido.
    }
}

EstadosDeMenu Menu::verEstoque()
{
    Estoque estoque("estoque.txt");
    int opcao;

    do
    {
        // Carrega o arquivo a cada iteração para garantir sincronia
        if (!estoque.carregarEstoque())
        {
            std::cout << "\n[Erro] Nao foi possivel carregar o arquivo de estoque.\n";
            return EstadosDeMenu::MenuPrincipalAdmin;
        }

        // Exibe a tabela do estoque atual
        estoque.exibirEstoque();

        // Menu de opções
        std::cout << "\n1. Adicionar / Incrementar Item\n";
        std::cout << "2. Remover / Decrementar Item\n";
        std::cout << "0. Voltar\n";

        opcao = lerComando();

        if (opcao == 1)
        {
            std::string nome;
            int qtd;

            std::cout << "Digite o nome do jogo: ";
            std::getline(std::cin, nome);

            if (estoque.jogoExiste(nome))
            {
                // Se já existe, só pede a quantidade para somar
                std::cout << "Jogo encontrado! Digite a quantidade a adicionar: ";
                std::cin >> qtd;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                if (qtd > 0)
                {
                    // Puxamos um produto genérico aqui só pelo nome, pois o método de adicionar
                    // do estoque só vai somar a quantidade se o nome já estiver lá.
                    estoque.adicionarItem(Produto(nome, "", "", 0.0), qtd);
                    std::cout << "\n[Sucesso] Quantidade atualizada!\n";
                }
            }
            else
            {
                // Jogo novo: Pedimos todos os dados baseados na estrutura de inserção e extração de C++
                std::string plataforma, genero;
                double preco;

                std::cout << "Plataforma: ";
                std::getline(std::cin, plataforma);

                std::cout << "Genero: ";
                std::getline(std::cin, genero);

                std::cout << "Preco: ";
                std::cin >> preco;

                std::cout << "Quantidade inicial: ";
                std::cin >> qtd;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                if (qtd > 0 && preco >= 0)
                {
                    Produto novoProduto(nome, plataforma, genero, preco);
                    estoque.adicionarItem(novoProduto, qtd);
                    std::cout << "\n[Sucesso] Novo jogo catalogado e adicionado ao estoque!\n";

                    // adiciona ao catalogo
                    Catalogo catalogo = Catalogo::carregarCatalogo("jogos.txt");
                    catalogo.adicionarJogo(novoProduto);
                    catalogo.salvarCatalogo("jogos.txt");
                }
                else
                {
                    std::cout << "\n[Erro] Valores invalidos.\n";
                }
            }
            estoque.salvarEstoque();
        }
        else if (opcao == 2)
        {
            std::string nome;
            int qtd;

            std::cout << "Digite o nome do jogo a remover/reduzir: ";
            std::getline(std::cin, nome);

            // Verifica se o jogo existe antes de tentar remover
            if (estoque.jogoExiste(nome))
            {
                std::cout << "Digite a quantidade a remover: ";
                std::cin >> qtd;

                // Limpa o buffer após ler o inteiro
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                if (qtd > 0)
                {
                    // Tenta remover a quantidade especificada
                    if (estoque.removerItem(nome, qtd))
                    {
                        estoque.salvarEstoque(); // Grava a alteração no ficheiro .txt
                        std::cout << "\n[Sucesso] Estoque atualizado com sucesso!\n";

                        if (!estoque.jogoExiste(nome))
                        {
                            // Carrega o catálogo atual do arquivo jogos.txt
                            Catalogo catalogo = Catalogo::carregarCatalogo("jogos.txt");

                            // Remove o jogo da memória e reescreve o arquivo
                            catalogo.removerJogo(nome);
                            catalogo.salvarCatalogo("jogos.txt");
                        }
                    }
                    else
                    {
                        // Ocorre se tentar remover, por exemplo, 10 itens mas só existirem 5
                        std::cout << "\n[Erro] Quantidade indisponivel. Nao pode remover mais do que o existente.\n";
                    }
                }
                else
                {
                    std::cout << "\n[Erro] A quantidade tem de ser maior que zero.\n";
                }
            }
            else
            {
                std::cout << "\n[Erro] Jogo nao encontrado no estoque.\n";
            }
        }
        else if (opcao != 0)
        {
            std::cout << "Opcao invalida.\n";
        }

        if (opcao != 0)
        {
            std::cout << "\nPressione Enter para continuar...";
            std::cin.get();
        }
    } while (opcao != 0);

    return EstadosDeMenu::MenuPrincipal;
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
            catalogo.comprar(carrinho); // Adiciona jogo ao carrinho
        }
        else if (opcao == 6)
        {
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

EstadosDeMenu Menu::verCarrinho(Carrinho &carrinho)
{
    int opcao;

    do
    {
        carrinho.exibirCarrinho();

        std::cout << "\n1. Remover item" << std::endl;
        std::cout << "2. Finalizar Compra" << std::endl;
        std::cout << "0. Voltar" << std::endl;

        opcao = lerComando();

        if (opcao == 1)
        {
            std::cout << "Numero do item a remover: ";
            int indice;
            std::cin >> indice;
            std::cin.ignore();
            carrinho.remover(indice - 1);
        }
        else if (opcao == 2)
                {
                    if (carrinho.estaVazio())
                    {
                        std::cout << "Carrinho vazio. Adicione itens antes de finalizar a compra." << std::endl;
                    }
                    else
                    {
                        Estoque estoque("estoque.txt");
                        
                        if (!estoque.carregarEstoque())
                        {
                            std::cout << "\n[Erro] Nao foi possivel acessar o estoque para processar a compra.\n";
                        }
                        else
                        {
                            Compra compra = carrinho.finalizarCompra();

                            for (const Produto &item : compra.getItens())
                            {
                                estoque.darBaixa(item.nome);
                            }
                            
                            estoque.salvarEstoque();

                            std::cout << "\nCompra finalizada com sucesso!" << std::endl;
                            compra.exibirCompra();
                        }
                    }
                }

        if (opcao != 0)
        {
            std::cout << "\nPressione Enter para continuar...";
            std::cin.get();
        }

    } while (opcao != 0);

    return EstadosDeMenu::MenuPrincipal;
}

EstadosDeMenu Menu::gerenciarProduto()
{
    Estoque estoque("estoque.txt");
    if (!estoque.carregarEstoque())
    {
        std::cout << "\n[Erro] Nao foi possivel carregar o arquivo de estoque.\n";
        return EstadosDeMenu::MenuPrincipal;
    }

    std::cout << "\n================ GERENCIAR PRODUTO ================\n";
    std::string nome;
    std::cout << "Digite o nome do jogo que deseja editar: ";
    std::getline(std::cin, nome);

    // Verifica se o produto realmente existe para ser editado
    if (!estoque.jogoExiste(nome))
    {
        std::cout << "\n[Erro] Jogo nao encontrado no sistema.\n";
        std::cout << "Pressione Enter para voltar...";
        std::cin.get();
        return EstadosDeMenu::MenuPrincipal;
    }

    std::string novaPlataforma, novoGenero;
    double novoPreco;

    std::cout << "\n--- Digite os novos dados para o jogo \"" << nome << "\" ---\n";
    std::cout << "Nova Plataforma: ";
    std::getline(std::cin, novaPlataforma);

    std::cout << "Novo Genero: ";
    std::getline(std::cin, novoGenero);

    std::cout << "Novo Preco: ";
    std::cin >> novoPreco;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpa o buffer

    if (novoPreco >= 0)
    {
        // 1. Modifica e salva no estoque.txt (preservando a quantidade)
        estoque.editarProduto(nome, novaPlataforma, novoGenero, novoPreco);
        estoque.salvarEstoque();

        // 2. Modifica e salva no jogos.txt
        Catalogo catalogo = Catalogo::carregarCatalogo("jogos.txt");
        catalogo.editarJogo(nome, novaPlataforma, novoGenero, novoPreco);
        catalogo.salvarCatalogo("jogos.txt");

        std::cout << "\n[Sucesso] Dados do produto atualizados!\n";
    }
    else
    {
        std::cout << "\n[Erro] Preco invalido. Alteracoes descartadas.\n";
    }
}

EstadosDeMenu Menu::verMinhasCompras(const Usuario &usuario)
{
    std::vector<Compra> historico = Compra::carregarHistorico(usuario.email);

    std::cout << "\n=== Minhas Compras ===" << std::endl;

    if (historico.empty())
    {
        std::cout << "Você ainda não realizou nenhuma compra." << std::endl;
    }
    else
    {
        for (const Compra &compra : historico)
        {
            compra.exibirCompra();
        }
    }

    std::cout << "\nPressione Enter para continuar...";
    std::cin.get();

    return EstadosDeMenu::MenuPrincipal;
}

EstadosDeMenu Menu::editarMeusDados(const Usuario &usuario) {
    std::cout << "\n================ EDITAR MEUS DADOS ================\n";
    std::cout << "Pressione Enter sem digitar nada para manter o dado atual.\n\n";

    std::string novoNome, novoEmail, novaSenha;
    
    std::string emailAntigo = usuario.email; 

    Usuario usuarioAtualizado = usuario;

    std::cout << "Nome atual (" << usuario.nome << "): ";
    std::getline(std::cin, novoNome);
    if (!novoNome.empty()) usuarioAtualizado.nome = novoNome; 

    std::cout << "Email atual (" << usuario.email << "): ";
    std::getline(std::cin, novoEmail);
    if (!novoEmail.empty()) usuarioAtualizado.email = novoEmail; 

    std::cout << "Senha atual (" << usuario.senha << "): ";
    std::getline(std::cin, novaSenha);
    if (!novaSenha.empty()) usuarioAtualizado.senha = novaSenha; 

    if (Usuario::atualizarUsuarioNoArquivo(emailAntigo, usuarioAtualizado, "usuarios.txt")) {
        std::cout << "\n[Sucesso] Dados atualizados! Por seguranca, faca login novamente.\n";
        std::cout << "Pressione Enter para continuar...";
        std::cin.get();
        return EstadosDeMenu::MenuInicial; 

    } else {
        std::cout << "\n[Erro] Nao foi possivel salvar as alteracoes no arquivo.\n";
        std::cout << "Pressione Enter para voltar...";
        std::cin.get();
        return EstadosDeMenu::MenuPrincipal;
    }
}