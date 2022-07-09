#include "jogador.hpp"
using namespace std;

// Realiza a conversao do nome do jogador de char para string
string converterJogadorString(char *jog)
{
    string aux(jog);
    return aux;
}

// Realiza a conversao do nome do jogador de int e char para string concatenando os dois nessa ordem
string converterCartaString(int val_carta, char naipe)
{
    string aux;
    aux.push_back(naipe);
    return to_string(val_carta) + aux;
}

// Percorre e determina se ha o jogador na partida e retorna sua posição caso ela seja encontrada
int EncontraJogador(Jogador jogador[], string nome_buscado, int qtde_jogadores)
{
    for (int i = 0; i < qtde_jogadores; i++)
    {
        // leMemLog((long int)jogador[i]._nome.length(), (long int)jogador[i]._nome.length() * sizeof(char), jogador[i]._id);
        if (jogador[i]._nome == nome_buscado)
        {
            return i;
        }
    }
    return -1;
}

// Faz a anulação dos atributos do jogador que nao sejam o nome e dinheiro
void LimpaDadosJogador(Jogador jogador[], int qtd)
{
    for (int i = 0; i < qtd; i++)
    {
        for (int a = 0; a < 5; a++)
        {
            jogador[i].Cartas_jogador[a]._carta = " ";
            jogador[i].Cartas_jogador[a]._naipe_carta = ' ';
            jogador[i].Cartas_jogador[a]._valor_carta = -1;
        }
        jogador[i]._tipo_de_mao = 11;
        jogador[i]._tipo_jogada = " ";
        jogador[i]._ganhou_partida = -1;
        jogador[i]._valor_quarterto = -1;
        jogador[i]._valor_trinca = -1;
        jogador[i]._valor_par_1 = -1;
        jogador[i]._valor_par_2 = -1;
    }
}

// Adiciona a o montante do pote ao(s) jogador(es) vencedor(es)
void AtribuiGanhosVencedor(Jogador jogador[], int qtd, int ganhos)
{
    int vencedores = 0;

    for (int i = 0; i < qtd; i++)
    {
        if (jogador[i]._ganhou_partida == 1)
        {
            vencedores++;
        }
    }
    for (int j = 0; j < qtd; j++)
    {
        if (jogador[j]._ganhou_partida == 1)
        {
            jogador[j]._dinheiro += (ganhos / vencedores);
            ESCREVEMEMLOG((long int)jogador[j]._dinheiro, (long int)sizeof(int), jogador[j]._id);
        }
    }
}
