#include "baralho.hpp"
using namespace std;

// Inicializa todas as posicoes do baralho como 0
void PopulaBaralho(Baralho *BaralhoJogo)
{
    for (int i = 1; i < 5; i++)
    {
        for (int j = 1; j < 14; j++)
        {
            BaralhoJogo->BaralhoCompleto[i][j] = 0;
        }
    }
}
void ImprimeBaralho(Baralho *BaralhoJogo)
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 14; j++)
        {
            cout << BaralhoJogo->BaralhoCompleto[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Verifica se ha alguma carta repetida no baralho, atraves da troca da posicao da carta por 1 e retorna esse valor caso ele seja encontrado
int VerificaRepeticaoCarta(Baralho *BaralhoJogo, int valorcarta, char naipecarta)
{
    if (naipecarta == 'C')
    {
        if (BaralhoJogo->BaralhoCompleto[1][valorcarta - 1] == 0)
        {
            BaralhoJogo->BaralhoCompleto[1][valorcarta - 1] = 1;
        }
        else
        {
            return 1;
        }
    }
    else if (naipecarta == 'E')
    {
        if (BaralhoJogo->BaralhoCompleto[2][valorcarta - 1] == 0)
        {
            BaralhoJogo->BaralhoCompleto[2][valorcarta - 1] = 1;
        }
        else
        {
            return 1;
        }
    }
    else if (naipecarta == 'O')
    {
        if (BaralhoJogo->BaralhoCompleto[3][valorcarta - 1] == 0)
        {
            BaralhoJogo->BaralhoCompleto[3][valorcarta - 1] = 1;
        }
        else
        {
            return 1;
        }
    }
    else if (naipecarta == 'P')
    {
        if (BaralhoJogo->BaralhoCompleto[4][valorcarta - 1] == 0)
        {
            BaralhoJogo->BaralhoCompleto[4][valorcarta - 1] = 1;
        }
        else
        {
            return 1;
        }
    }
    return 0;
}