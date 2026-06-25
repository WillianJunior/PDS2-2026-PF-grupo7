#include "Usuario.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

Usuario::Usuario(const std::string &nome, const std::string &email, const std::string &senha, int nivelDeAcesso)
    : nome(nome), email(email), senha(senha), nivelDeAcesso(nivelDeAcesso) {}

bool Usuario::possuiAcesso(int acesso) const{
    return nivelDeAcesso >= acesso;
}

std::unique_ptr<Usuario> Usuario::login(const std::string &email,
                                        const std::string &senha,
                                        const std::string &txtpath)
{
    std::ifstream file(txtpath);
    if(!file.is_open()){
        std::cerr << "Erro: nao foi possivel abrir " << txtpath << std::endl;
        return nullptr;
    }

    std::string line;
    std::getline(file, line); //para pular a primeira linha

    while(std::getline(file, line)){
        std::istringstream ss(line);
        std::string readEmail, readSenha, readNome, readNivel;

        std::getline(ss, readEmail, ';');
        std::getline(ss, readSenha, ';');
        std::getline(ss, readNome, ';');
        std::getline(ss, readNivel, ';');

        if(readEmail == email && readSenha == senha){
            int nivel = std::stoi(readNivel); //converte string para int
            return std::unique_ptr<Usuario>(new Usuario(readNome, readEmail, readSenha, nivel));
        }

    }

    return nullptr; 
}

bool Usuario::emailJaCadastrado(const std::string &email, const std::string &txtpath)
{
    std::ifstream file(txtpath);
    if (!file.is_open()) {
        return false; // arquivo nao existe -> nenhum email cadastrado ainda
    }

    std::string line;
    std::getline(file, line); // pula o cabecalho

    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string readEmail;
        std::getline(ss, readEmail, ';');
        if (readEmail == email) return true;
    }
    return false;
}

std::unique_ptr<Usuario> Usuario::cadastrar(const std::string &nome,
                                             const std::string &email,
                                             const std::string &senha,
                                             const std::string &txtpath)
{
    if (nome.empty() || email.empty() || senha.empty()) {
        std::cerr << "Erro: nome, email e senha sao obrigatorios." << std::endl;
        return nullptr;
    }
    if (email.find('@') == std::string::npos) {
        std::cerr << "Erro: email invalido." << std::endl;
        return nullptr;
    }
    if (emailJaCadastrado(email, txtpath)) {
        std::cerr << "Erro: ja existe um usuario cadastrado com este email." << std::endl;
        return nullptr;
    }

    std::ifstream checagem(txtpath);
    bool arquivoExiste = checagem.good();
    checagem.close();

    std::ofstream file(txtpath, std::ios::app);
    if (!file.is_open()) {
        std::cerr << "Erro: nao foi possivel abrir " << txtpath << " para cadastro." << std::endl;
        return nullptr;
    }

    if (!arquivoExiste) {
        file << "email;senha;nome;nivelDeAcesso\n";
    } else {
        // Garante quebra de linha mesmo se o ultimo registro nao terminar com '\n'
        std::ifstream verificacao(txtpath, std::ios::ate);
        std::streampos tamanho = verificacao.tellg();
        if (tamanho > 0) {
            verificacao.seekg(-1, std::ios::end);
            char ultimoChar;
            verificacao.get(ultimoChar);
            if (ultimoChar != '\n') file << "\n";
        }
    }

    int nivel = static_cast<int>(NivelDeAcesso::Cliente);
    file << email << ";" << senha << ";" << nome << ";" << nivel << "\n";

    return std::unique_ptr<Usuario>(new Usuario(nome, email, senha, nivel));
}

bool Usuario::atualizarUsuarioNoArquivo(const std::string& emailAntigo, const Usuario& usuarioAtualizado, const std::string& txtpath) {
    std::ifstream fileIn(txtpath);
    if (!fileIn.is_open()) return false;

    std::vector<std::string> linhas;
    std::string line;
    
    // Lê o cabeçalho e guarda
    if (std::getline(fileIn, line)) {
        linhas.push_back(line);
    }

    // Lê o restante dos usuários
    while (std::getline(fileIn, line)) {
        std::istringstream ss(line);
        std::string readEmail, readSenha, readNome, readNivel;

        std::getline(ss, readEmail, ';');
        std::getline(ss, readSenha, ';');
        std::getline(ss, readNome, ';');
        std::getline(ss, readNivel, ';');

        // Se encontrou o usuário antigo, substitui pela nova versão
        if (readEmail == emailAntigo) {
            linhas.push_back(usuarioAtualizado.email + ";" + 
                             usuarioAtualizado.senha + ";" + 
                             usuarioAtualizado.nome + ";" + 
                             std::to_string(usuarioAtualizado.nivelDeAcesso));
        } else {
            // Se for outro usuário, apenas copia a linha original
            linhas.push_back(line);
        }
    }
    fileIn.close();

    // Sobrescreve o arquivo com os dados atualizados
    std::ofstream fileOut(txtpath);
    if (!fileOut.is_open()) return false;
    
    for (const auto& l : linhas) {
        fileOut << l << "\n";
    }
    
    fileOut.close();
    return true;
}