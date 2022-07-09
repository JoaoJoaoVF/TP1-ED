#ifndef JOGADOR_H
#define JOGADOR_H

#include "baralho.hpp"

using namespace std;

struct Jogador
{
    string _nome;
    int _dinheiro;
    Baralho Cartas_jogador[5];
    int _tipo_de_mao;
    string _tipo_jogada;
    int _ganhou_partida;
    int _valor_quarterto;
    int _valor_trinca;
    int _valor_par_1;
    int _valor_par_2;
    int _id;
};

string converterJogadorString(char *jog);
string converterCartaString(int val_carta, char naipe);
int EncontraJogador(Jogador jogador[], string nome_buscado, int qtde_jogadores);
void LimpaDadosJogador(Jogador jogador[], int qtd);
void AtribuiGanhosVencedor(Jogador jogador[], int qtd, int ganhos);

#endif