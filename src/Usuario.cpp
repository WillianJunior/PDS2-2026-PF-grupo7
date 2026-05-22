#include "Usuario.hpp"

Usuario::Usuario(int id, const std::string& nome, const std::string& email, const std::string& senha) {}

Usuario::Usuario() {}

int Usuario::getId() const {return 0; }

std::string Usuario::getNome() const {return {}; }

std::string Usuario::getEmail() const {return {}; }

std::string Usuario::getSenha() const {return {}; }

void Usuario::setNome(const std::string& nome) {}

void Usuario::setEmail(const std::string& email) {}

void Usuario::setSenha(const std::string& senha) {}