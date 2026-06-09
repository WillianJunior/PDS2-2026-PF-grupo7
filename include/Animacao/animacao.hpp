#ifndef ANIMACAO_HPP
#define ANIMACAO_HPP

#include <chrono>   // Necessário para o tempo (std::chrono)
#include<iostream>
#include <thread>   // Necessário para fazer o programa esperar (std::this_thread)
#include <cstdlib>  // Necessário para a função system()


class animacao{
public:
    static void load_ps();
    static void abertura();
    static void encerramento();
};

#endif