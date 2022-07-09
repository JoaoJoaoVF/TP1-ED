#include "pote.hpp"
using namespace std;

// Inicializa o montante do pote com o valor 0
void criaPote(Pote *pote_rodada, int id)
{
    pote_rodada->montante = 0;
    pote_rodada->_id = id;
}

// Realiza a adição do pingo de todos os jogadores no pote
void adicionaPingo(Jogador jogador[], Pote *pote_rodada, int valor_pingo, int num_jogadores)
{
    for (int i = 0; i < num_jogadores; i++)
    {
        pote_rodada->montante += valor_pingo;
        jogador[i]._dinheiro -= valor_pingo;
    }
}

// Realiza a aposta do jogador passado para a função
void adicionaAposta(Pote *pote_rodada, int valor_aposta)
{
    pote_rodada->montante += valor_aposta;
}

// Retorna o valor do montante guardado no pote
int GetMontante(Pote *pote_rodada)
{
    return pote_rodada->montante;
}
