#ifndef ESTADOS_DE_MENU_HPP
#define ESTADOS_DE_MENU_HPP

enum class EstadosDeMenu{

//Não autenticado
MenuInicial,
Login,
MenuPrincipal, //Testa o nivel de acesso e direciona
//Autenticado (CLiente)
MenuPrincipalCliente,
VerCatalogo,
Carrinho,
MinhasCompras,
EditarMeusDados,

//Autenticado (Admin)
MenuPrincipalAdmin,
GerenciarProduto,
GerenciarCatalogo,
GerenciarEstoque,
VerEstoque,

//Saída
Sair


};

#endif