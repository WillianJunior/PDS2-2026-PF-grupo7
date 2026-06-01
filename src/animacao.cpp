#include <chrono>   // Necessário para o tempo (std::chrono)
#include <thread>   // Necessário para fazer o programa esperar (std::this_thread)
#include "animacao.hpp"
#include "desenhos.hpp"

void animacao::load_ps() {
    //==============================================================================================
    std::system("clear");                                 //   Limpa o terminal
                                                          //  (Linux), usamos "clear"
    desenhos::triangulo_ps();
    std::this_thread::sleep_for(std::chrono::seconds(1)); //   Faz o programa esperar por 1 segundo
    //==============================================================================================    
    std::system("clear");

    desenhos::bolinha_ps();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    //==============================================================================================    
    std::system("clear");

    desenhos::x_ps();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    //============================================================================================== 
    std::system("clear");

    desenhos::quadrado_ps();   
    std::this_thread::sleep_for(std::chrono::seconds(1));  
    std::system("clear");
    //============================================================================================== 
}       //fim da função load_ps()

void animacao::abertura() {
    std::system("clear");

    desenhos::controles();                                 // DESENHO 1
    std::this_thread::sleep_for(std::chrono::seconds(1));  
    std::system("clear");
    
    desenhos::controle_super_nintendo();                  // DESENHO 2
    std::this_thread::sleep_for(std::chrono::seconds(1));  
    std::system("clear");
    
    desenhos::controle_arcade();                         // DESENHO 3
    std::this_thread::sleep_for(std::chrono::seconds(1));  
    std::system("clear");

    desenhos::nome_loja();                               // DESENHO 4
    std::this_thread::sleep_for(std::chrono::seconds(1));  
    std::system("clear");
}     //fim da função abertura()