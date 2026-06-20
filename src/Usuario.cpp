#include "Usuario.hpp"

Usuario::Usuario(int id, const std::string& nome, const std::string& email, const std::string& senha)
 
:id(id),nome(nome),email(email), senha(senha) //lista de inicialização 
 {
}

Usuario::Usuario(): id(0), nome(""),email(""), senha("")
{   
}

int Usuario::getId() const {
    return id;
}
std::string Usuario::getNome() const {
    return nome;
}

std::string Usuario::getEmail() const {
   return email;
}

std::string Usuario::getSenha() const {
    return senha; 
}

void Usuario::setNome(const std::string& nome) {
    this-> nome = nome;
}
void Usuario::setEmail(const std::string& email) {
    this -> email = email;
}

void Usuario::setSenha(const std::string& senha) {
    this->senha = senha;
}