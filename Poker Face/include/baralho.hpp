#ifndef BARALHO_H
#define BARALHO_H

//#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>
#include <iostream>
#include <iostream>
#include "memlog.h"
#include "msgassert.h"
using namespace std;

struct Baralho
{
    string _carta;
    char _naipe_carta;
    int _valor_carta;
    int BaralhoCompleto[5][14];
};

void PopulaBaralho(Baralho *BaralhoJogo);
void ImprimeBaralho(Baralho *BaralhoJogo);
int VerificaRepeticaoCarta(Baralho *BaralhoJogo, int valorcarta, char naipecarta);
#endif