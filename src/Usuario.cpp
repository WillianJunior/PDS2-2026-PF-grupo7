#include "Usuario.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

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