#ifndef RODADA_H
#define RODADA_H

//#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>
#include <iostream>
#include <iostream>
#include "jogador.hpp"
#include "memlog.h"
#include "msgassert.h"
using namespace std;

void Ordena(Jogador *jogador, int posicao);
void OrdenaJogadores(Jogador *jogador, int qtde_jog);
int BuscaRepeticaoNaipe(Jogador *jogador, int num_jogador);
int BuscaRepeticaoValor(Jogador *jogador, int num_jogador);
int AnalisaOrdemFlush(Jogador *jogador, int num_jogador);
int AnalisaOrdemCrescente(Jogador *jogador, int num_jogador);
void AnalisaJogada(Jogador *jogador, int posicao);
void BuscaRepeticaoDeCarta(Jogador *jogador, int num_jogador);
int BuscaRepeticaoDeMao(Jogador *jogador, int tipo_retorno, int qtde_jog);
string VenceuPartida(Jogador *jogador, int num_jogadores, int pote, int qtde_jog);
int ResolveEmpate(Jogador *jogador, int jog_a, int jog_b);

#endif
