#ifndef POTE_H
#define POTE_H

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

struct Pote
{
    int montante;
    int _id;
};

void criaPote(Pote *pote_rodada, int _id);
void adicionaPingo(Jogador jogador[], Pote *pote_rodada, int valor_pingo, int num_jogadores);
void adicionaAposta(Pote *pote_rodada, int valor_aposta);
int GetMontante(Pote *pote_rodada);

#endif