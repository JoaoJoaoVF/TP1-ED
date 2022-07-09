#include "partida.hpp"

int main()
{
    char nome[100] = "/tmp/PokerFace.out";
    iniciaMemLog(nome);
    ativaMemLog();

    ExecutaPartida();

    return finalizaMemLog();
    return 0;
}