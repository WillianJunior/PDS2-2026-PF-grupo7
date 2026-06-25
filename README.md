# 🎮 E-Commerce de Jogos de Videogame - GRUPO 07

Este projeto consiste em um sistema de e-commerce baseado em linha de comando (CLI) voltado para a venda, gerenciamento e controle de estoque de jogos de videogame. O software foi desenvolvido em C++ utilizando conceitos avançados de Programação Orientada a Objetos (POO).

---

## 👥 Integrantes do Grupo
* **Murilo Barbosa**
* **Nome do Integrante 2**
* **Nome do Integrante 3**
* **Nome do Integrante 4**

---

## 📝 Descrição do Problema, Objetivos e Motivação

O mercado de jogos digitais e físicos expandiu de forma astronômica nos últimos anos, demandando sistemas robustos para o processamento de catálogos volumosos, controle preciso de unidades físicas e atendimento personalizado para diferentes perfis de usuários.

O objetivo principal deste sistema é fornecer uma plataforma integrada onde **Clientes** possam navegar por jogos filtrados por gênero ou plataforma, organizar itens em um carrinho virtual e simular compras com segurança, enquanto **Administradores** possuem controle total sobre o ciclo de vida dos produtos, manipulação de estoque e relatórios de vendas. A motivação para a escolha deste tema reside na oportunidade de aplicar os conhecimetos adquirios durante o curso em um cenário comercial, simulando as regras de negócio de lojas da indústria de jogos.

---

## 🏗️ Arquitetura e Estrutura do Projeto

O sistema foi arquitetado com base no desacoplamento de responsabilidades e na forte tipagem do C++. Abaixo estão os principais componentes estruturais mapeados através dos arquivos `.hpp`:

* **`Usuario` / `Cliente` / `Administrador`**: Separação de privilégios através de composição. O `Cliente` possui um `Carrinho` de compras dinâmico, enquanto o `Administrador` possui permissões exclusivas para invocar comportamentos de gerência.
* **`Catalogo` / `Estoque` / `Produto`**: Módulos dedicados à manipulação dos dados dos jogos. O catálogo lê dados a partir de persistência em arquivos planos (`jogos.txt`) e oferece suporte a operações de busca, ordenação por preço e filtragem avançada.
* **`Menu` / `EstadosDeMenu`**: O fluxo de navegação do sistema é controlado por uma Máquina de Estados Finita encapsulada através de um `enum class`. Isso garante uma navegação robusta e à prova de falhas, impedindo que visitantes sem autenticação acessem menus administrativos.

### Fluxo de Estados do Menu

```text
       [ Menu Inicial ] ──( Visitante )──> Ver Catálogo (Apenas leitura)
              │
          ( Login )
              │
              ▼
       [ Menu Principal ]
              │
              ├─> ( Nível 1: Cliente ) ──> Carrinho, Ver Catálogo, Histórico de Compras
              │
              └─> ( Nível 2: Admin )   ──> Gerenciar Estoque, Modificar Catálogo

```


## Instruções de Uso

Compilação

$ make

Atenção: Criar antes um diretório ./build/
Execução

$ make run

Compilação Testes

$ make tests

Execução Testes

$ make run-tests

Relatório de Cobertura

Para imprimir o relatório simplificado no próprio Terminal, utilizar:

$ make coverage

Para gerar o relatório em HTML, utilizar:

$ make html-coverage
