#include "rodada.hpp"
using namespace std;

// Realiza da troca de conteudo entre 2 strings
#define Troca_string(A, B)          \
    {                               \
        string string_auxiliar = A; \
        A = B;                      \
        B = string_auxiliar;        \
    }

// Realiza da troca de conteudo entre 2 char
#define Troca_char(A, B)        \
    {                           \
        char char_auxiliar = A; \
        A = B;                  \
        B = char_auxiliar;      \
    }

// Realiza da troca de conteudo entre 2 int
#define Troca_int(A, B)       \
    {                         \
        int int_auxiliar = A; \
        A = B;                \
        B = int_auxiliar;     \
    }

// Realiza a ordenação das cartas que os jogadores possuem na mao na rodada, o algoritmo de ordenação é o Bubble Sort
void Ordena(Jogador *jogador, int posicao)
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = i + 1; j < 5; j++)
        {
            leMemLog((long int)jogador[posicao].Cartas_jogador[i]._valor_carta, (long int)sizeof(int), jogador[posicao]._id);
            leMemLog((long int)jogador[posicao].Cartas_jogador[j]._valor_carta, (long int)sizeof(int), jogador[posicao]._id);

            if (jogador[posicao].Cartas_jogador[j]._valor_carta < jogador[posicao].Cartas_jogador[i]._valor_carta)
            {
                Troca_string(jogador[posicao].Cartas_jogador[i]._carta, jogador[posicao].Cartas_jogador[j]._carta);
                Troca_char(jogador[posicao].Cartas_jogador[i]._naipe_carta, jogador[posicao].Cartas_jogador[j]._naipe_carta);
                Troca_int(jogador[posicao].Cartas_jogador[i]._valor_carta, jogador[posicao].Cartas_jogador[j]._valor_carta);

                ESCREVEMEMLOG((long int)jogador[posicao].Cartas_jogador[i]._carta[0], (long int)jogador[posicao].Cartas_jogador[i]._carta.length() * sizeof(char), jogador[posicao]._id);
                ESCREVEMEMLOG((long int)jogador[posicao].Cartas_jogador[i]._naipe_carta, (long int)sizeof(char), jogador[posicao]._id);
                ESCREVEMEMLOG((long int)jogador[posicao].Cartas_jogador[i]._valor_carta, (long int)sizeof(int), jogador[posicao]._id);
                ESCREVEMEMLOG((long int)jogador[posicao].Cartas_jogador[j]._carta[0], (long int)jogador[posicao].Cartas_jogador[j]._carta.length() * sizeof(char), jogador[posicao]._id);
                ESCREVEMEMLOG((long int)jogador[posicao].Cartas_jogador[j]._naipe_carta, (long int)sizeof(char), jogador[posicao]._id);
                ESCREVEMEMLOG((long int)jogador[posicao].Cartas_jogador[j]._valor_carta, (long int)sizeof(int), jogador[posicao]._id);
            }
        }
    }
}

// Realiza a ordenação dos jogadores da partida do maior ao menor valor, o algoritmo de ordenação é o Bubble Sort
void OrdenaJogadores(Jogador *jogador, int qtde_jog)
{
    for (int i = 0; i <= qtde_jog - 1; i++)
    {
        for (int j = i + 1; j <= qtde_jog - 1; j++)
        {
            leMemLog((long int)jogador[i]._dinheiro, (long int)sizeof(int), jogador[i]._id);
            leMemLog((long int)jogador[j]._dinheiro, (long int)sizeof(int), jogador[j]._id);

            if (jogador[j]._dinheiro > jogador[i]._dinheiro)
            {
                Troca_string(jogador[i]._nome, jogador[j]._nome);
                Troca_int(jogador[i]._dinheiro, jogador[j]._dinheiro);

                ESCREVEMEMLOG((long int)jogador[i]._nome[0], (long int)jogador[i]._nome.length() * sizeof(char), jogador[i]._id);
                ESCREVEMEMLOG((long int)jogador[j]._nome[0], (long int)jogador[j]._nome.length() * sizeof(char), jogador[j]._id);
                ESCREVEMEMLOG((long int)jogador[i]._dinheiro, (long int)sizeof(int), jogador[i]._id);
                ESCREVEMEMLOG((long int)jogador[j]._dinheiro, (long int)sizeof(int), jogador[j]._id);
            }
        }
    }
}

// Verifica se todas as cartas da mao possuem o mesmo Naipe
int BuscaRepeticaoNaipe(Jogador *jogador, int num_jogador)
{
    int num_carta, repeticao = 1;
    for (num_carta = 0; num_carta < 5; num_carta++)
    {
        leMemLog((long int)jogador[num_jogador].Cartas_jogador[num_carta]._naipe_carta, (long int)sizeof(char), jogador[num_jogador]._id);
        leMemLog((long int)jogador[num_jogador].Cartas_jogador[num_carta + 1]._naipe_carta, (long int)sizeof(char), jogador[num_jogador]._id);

        if (jogador[num_jogador].Cartas_jogador[num_carta]._naipe_carta == jogador[num_jogador].Cartas_jogador[num_carta + 1]._naipe_carta && num_carta + 1 <= 5)
        {
            repeticao++;
        }
    }
    return repeticao;
}

// Determina se ha repetição no valor das cartas, e a partir do tipo de repetição classifica se e um quarteto, trinca, 1 ou 2 pares
int BuscaRepeticaoValor(Jogador *jogador, int num_jogador)
{
    int num_carta, repeticao = 1, total = 0;
    for (num_carta = 0; num_carta < 5; num_carta++)
    {
        leMemLog((long int)jogador[num_jogador].Cartas_jogador[num_carta]._valor_carta, (long int)sizeof(int), jogador[num_jogador]._id);
        leMemLog((long int)jogador[num_jogador].Cartas_jogador[num_carta + 1]._valor_carta, (long int)sizeof(int), jogador[num_jogador]._id);

        if (jogador[num_jogador].Cartas_jogador[num_carta]._valor_carta == jogador[num_jogador].Cartas_jogador[num_carta + 1]._valor_carta && num_carta + 1 <= 5)
        {
            repeticao++;
        }
        else
        {
            if (repeticao > 1)
            {
                if (repeticao == 2)
                {
                    total += 2;
                    repeticao = 1;
                }
                if (repeticao == 3)
                {
                    total += 3;
                    repeticao = 1;
                }
                if (repeticao == 4)
                {
                    total = 10;
                }
            }
        }
    }
    return total;
}

// Analisa as cartas para determinar se todas sao maiores que 10 classificando um RSF ou se são menores que 10 um SF
int AnalisaOrdemFlush(Jogador *jogador, int num_jogador)
{
    int maior = 0;

    if (jogador[num_jogador].Cartas_jogador[1]._valor_carta >= 10 &&
        jogador[num_jogador].Cartas_jogador[0]._valor_carta == 1)
    {
        return 4;
    }

    if (jogador[num_jogador].Cartas_jogador[0]._valor_carta != 1 &&
        jogador[num_jogador].Cartas_jogador[0]._valor_carta == jogador[num_jogador].Cartas_jogador[1]._valor_carta - 1 &&
        jogador[num_jogador].Cartas_jogador[1]._valor_carta == jogador[num_jogador].Cartas_jogador[2]._valor_carta - 1 &&
        jogador[num_jogador].Cartas_jogador[2]._valor_carta == jogador[num_jogador].Cartas_jogador[3]._valor_carta - 1 &&
        jogador[num_jogador].Cartas_jogador[3]._valor_carta == jogador[num_jogador].Cartas_jogador[4]._valor_carta - 1)
    {
        maior = -4;
    }

    return maior;
}

// Analisa se as cartas estao em ordem crescente
int AnalisaOrdemCrescente(Jogador *jogador, int num_jogador)
{
    int maior = 1;
    for (int j = 0; j < 4; j++)
    {
        leMemLog((long int)jogador[num_jogador].Cartas_jogador[j]._valor_carta, (long int)sizeof(int), jogador[num_jogador]._id);
        leMemLog((long int)jogador[num_jogador].Cartas_jogador[j + 1]._valor_carta, (long int)sizeof(int), jogador[num_jogador]._id);

        if (jogador[num_jogador].Cartas_jogador[j]._valor_carta == jogador[num_jogador].Cartas_jogador[j + 1]._valor_carta - 1)
        {
            maior++;
        }
        else
        {
            maior--;
        }
    }
    return maior;
}

// Realiza a analise da mao que o jogador possui e atribui a ela os atributos correspondentes a jogada
void AnalisaJogada(Jogador *jogador, int num_jogador)
{
    if (BuscaRepeticaoNaipe(jogador, num_jogador) == 5)
    {
        // Verifica se ha um Royal Straight Flush
        if (AnalisaOrdemFlush(jogador, num_jogador) == 4)
        {
            jogador[num_jogador]._tipo_de_mao = 1;
            jogador[num_jogador]._tipo_jogada = "RSF";
        }
        // Verifica se ha um Straight Flush
        else if (AnalisaOrdemFlush(jogador, num_jogador) == -4)
        {
            jogador[num_jogador]._tipo_de_mao = 2;
            jogador[num_jogador]._tipo_jogada = "SF";
        }
        // Verifica se ha um Flush
        else
        {
            jogador[num_jogador]._tipo_de_mao = 5;
            jogador[num_jogador]._tipo_jogada = "F";
        }
    }
    // Verifica se ha alguma repetição
    else if (BuscaRepeticaoValor(jogador, num_jogador) > 0)
    {
        // Verifica se é um Full House
        if (BuscaRepeticaoValor(jogador, num_jogador) == 5)
        {
            jogador[num_jogador]._tipo_de_mao = 4;
            jogador[num_jogador]._tipo_jogada = "FH";
        }
        // Verifica se é um Four of a kind
        else if (BuscaRepeticaoValor(jogador, num_jogador) == 10)
        {
            jogador[num_jogador]._tipo_de_mao = 3;
            jogador[num_jogador]._tipo_jogada = "FK";
        }
        // Verifica se é um Three of a kind
        else if (BuscaRepeticaoValor(jogador, num_jogador) == 3)
        {
            jogador[num_jogador]._tipo_de_mao = 7;
            jogador[num_jogador]._tipo_jogada = "TK";
        }
        // Verifica se é Two Pairs
        else if (BuscaRepeticaoValor(jogador, num_jogador) == 4)
        {
            jogador[num_jogador]._tipo_de_mao = 8;
            jogador[num_jogador]._tipo_jogada = "TP";
        }
        // Verifica se é One Pair
        else if (BuscaRepeticaoValor(jogador, num_jogador) == 2)
        {
            jogador[num_jogador]._tipo_de_mao = 9;
            jogador[num_jogador]._tipo_jogada = "OP";
        }
    }
    // Verifica se é Straight
    else if (AnalisaOrdemCrescente(jogador, num_jogador) == 5)
    {
        jogador[num_jogador]._tipo_de_mao = 6;
        jogador[num_jogador]._tipo_jogada = "S";
    }
    // Não pasou em nenhum caso High Card
    else
    {
        jogador[num_jogador]._tipo_de_mao = 10;
        jogador[num_jogador]._tipo_jogada = "HC";
    }
}

// Busca e atribui o valor das cartas repetidas
void BuscaRepeticaoDeCarta(Jogador *jogador, int num_jogador)
{
    int i, repetido = 1;

    for (i = 0; i < 5; i++)
    {
        leMemLog((long int)jogador[num_jogador].Cartas_jogador[i]._valor_carta, (long int)sizeof(int), jogador[num_jogador]._id);
        // leMemLog((long int)jogador[num_jogador].Cartas_jogador[i + 1]._valor_carta, (long int)sizeof(int), jogador[num_jogador]._id);

        if (jogador[num_jogador].Cartas_jogador[i]._valor_carta == jogador[num_jogador].Cartas_jogador[i + 1]._valor_carta)
        {
            repetido++;
        }
        else
        {
            if (repetido == 4)
            {
                jogador[num_jogador]._valor_quarterto = jogador[num_jogador].Cartas_jogador[i]._valor_carta;
            }
            else if (repetido == 3)
            {
                jogador[num_jogador]._valor_trinca = jogador[num_jogador].Cartas_jogador[i]._valor_carta;
            }
            else if (repetido == 2)
            {
                if (jogador[num_jogador]._valor_par_1 == -1)
                {
                    jogador[num_jogador]._valor_par_1 = jogador[num_jogador].Cartas_jogador[i]._valor_carta;
                }
                else
                {
                    jogador[num_jogador]._valor_par_2 = jogador[num_jogador].Cartas_jogador[i]._valor_carta;
                }
            }
            repetido = 1;
        }
    }
}

// Busca e atribui o valor das cartas repetidas
int BuscaRepeticaoDeMao(Jogador *jogador, int tipo_retorno, int qtde_jog)
{
    int i, repetido = 1, final = 1, mao_anterior = 11, pos_jog1 = -1, pos_jog2 = -1, pos_jog3 = -1, pos_jog4 = -1;

    for (i = 0; i < qtde_jog; i++)
    {
        leMemLog((long int)jogador[i]._tipo_de_mao, (long int)sizeof(int), jogador[i]._id);
        leMemLog((long int)jogador[i + 1]._tipo_de_mao, (long int)sizeof(int), jogador[i + 1]._id);

        if (jogador[i]._tipo_de_mao == jogador[i + 1]._tipo_de_mao && (i + 1) < qtde_jog &&
            jogador[i]._tipo_de_mao <= 10 &&
            jogador[i + 1]._tipo_de_mao <= 10)
        {
            repetido++;
        }
        else
        {
            if (repetido == 2)
            {
                if (jogador[i]._tipo_de_mao < mao_anterior)
                {
                    final = repetido;
                    mao_anterior = jogador[i]._tipo_de_mao;
                    pos_jog1 = i;
                }
            }
            if (repetido == 2)
            {
                if (jogador[i]._tipo_de_mao < mao_anterior)
                {
                    final = repetido;
                    mao_anterior = jogador[i]._tipo_de_mao;
                    pos_jog1 = i - 1;
                    pos_jog2 = i;
                }
            }
            else if (repetido == 3)
            {
                if (jogador[i]._tipo_de_mao < mao_anterior)
                {
                    final = repetido;
                    mao_anterior = jogador[i]._tipo_de_mao;
                    pos_jog1 = i - 2;
                    pos_jog2 = i - 1;
                    pos_jog3 = i;
                }
            }
            else if (repetido == 4)
            {
                if (jogador[i]._tipo_de_mao < mao_anterior)
                {
                    final = repetido;
                    mao_anterior = jogador[i]._tipo_de_mao;
                    pos_jog1 = i - 3;
                    pos_jog2 = i - 2;
                    pos_jog3 = i - 1;
                    pos_jog4 = i;
                }
            }
            repetido = 1;
        }
    }

    if (tipo_retorno == 0)
        return mao_anterior;
    else if (tipo_retorno == 1)
        return final;
    else if (tipo_retorno == 2)
        return pos_jog1;
    else if (tipo_retorno == 3)
        return pos_jog2;
    else if (tipo_retorno == 4)
        return pos_jog3;
    else
        return pos_jog4;
}

// Faz a resolução do empate dos jogadores e retorna o vencedor do desempate se ele ocorrer
int ResolveEmpate(Jogador *jogador, int jog_a, int jog_b)
{
    // Empate de dois RSF ou SF o  empate permanece
    if (jogador[jog_a]._tipo_de_mao == 1 || jogador[jog_a]._tipo_de_mao == 2)
    {
        return 3;
    }
    // Empate de FK
    else if (jogador[jog_a]._tipo_de_mao == 3)
    {
        BuscaRepeticaoDeCarta(jogador, jog_a);
        BuscaRepeticaoDeCarta(jogador, jog_b);
        if (jogador[jog_a]._valor_quarterto > jogador[jog_b]._valor_quarterto)
        {
            return 1;
        }
        else if (jogador[jog_a]._valor_quarterto < jogador[jog_b]._valor_quarterto)
        {
            return 2;
        }
    }
    // Empate de FH
    else if (jogador[jog_a]._tipo_de_mao == 4)
    {
        BuscaRepeticaoDeCarta(jogador, jog_a);
        BuscaRepeticaoDeCarta(jogador, jog_b);
        if (jogador[jog_a]._valor_trinca > jogador[jog_b]._valor_trinca)
        {
            return 1;
        }
        else if (jogador[jog_a]._valor_trinca < jogador[jog_b]._valor_trinca)
        {
            return 2;
        }
        else
        {
            if (jogador[jog_a]._valor_par_1 > jogador[jog_b]._valor_par_1)
            {
                return 1;
            }
            else if (jogador[jog_a]._valor_par_1 < jogador[jog_b]._valor_par_1)
            {
                return 2;
            }
        }
    }
    // Empate de TK
    else if (jogador[jog_a]._tipo_de_mao == 7)
    {
        BuscaRepeticaoDeCarta(jogador, jog_a);
        BuscaRepeticaoDeCarta(jogador, jog_b);
        if (jogador[jog_a]._valor_trinca > jogador[jog_b]._valor_trinca)
        {
            return 1;
        }
        else if (jogador[jog_a]._valor_trinca < jogador[jog_b]._valor_trinca)
        {
            return 2;
        }
    }
    // Empate de TP
    else if (jogador[jog_a]._tipo_de_mao == 8)
    {
        BuscaRepeticaoDeCarta(jogador, jog_a);
        BuscaRepeticaoDeCarta(jogador, jog_b);
        if (jogador[jog_a]._valor_par_1 > jogador[jog_b]._valor_par_1)
        {
            return 1;
        }
        else if (jogador[jog_a]._valor_par_1 < jogador[jog_b]._valor_par_1)
        {
            return 2;
        }
        else
        {
            if (jogador[jog_a]._valor_par_2 > jogador[jog_b]._valor_par_2)
            {
                return 1;
            }
            else if (jogador[jog_a]._valor_par_2 < jogador[jog_b]._valor_par_2)
            {
                return 2;
            }
        }
    }
    // Empate de OP
    else if (jogador[jog_a]._tipo_de_mao == 9)
    {
        BuscaRepeticaoDeCarta(jogador, jog_a);
        BuscaRepeticaoDeCarta(jogador, jog_b);
        if (jogador[jog_a]._valor_par_1 > jogador[jog_b]._valor_par_1)
        {
            return 1;
        }
        else if (jogador[jog_b]._valor_par_1 > jogador[jog_a]._valor_par_1)
        {
            return 2;
        }
    }
    // Empate de HC, F, S ou não passou em nenhum dos casos especificos de empate e a maior carta ira determinar o vencedor
    else
    {
        if (jogador[jog_a].Cartas_jogador[4]._valor_carta > jogador[jog_b].Cartas_jogador[4]._valor_carta)
        {
            return 1;
        }
        else if (jogador[jog_b].Cartas_jogador[4]._valor_carta > jogador[jog_a].Cartas_jogador[4]._valor_carta)
        {
            return 2;
        }
        else if (jogador[jog_b].Cartas_jogador[4]._valor_carta == jogador[jog_a].Cartas_jogador[4]._valor_carta)
        {
            return 3;
        }
    }
    return 0;
}

// Realiza a anulacao da varivel ganhou partida dos jogadores
void LimpaGP(Jogador *jogador, int num_jogadores)
{
    for (int i = 0; i < num_jogadores; i++)
    {
        jogador[i]._ganhou_partida = -1;
    }
}

// Percorre por todos os jogadores e analisa qual deles possui a melhor mão e retorna a posição dele
string VenceuPartida(Jogador *jogador, int num_jogadores, int pote, int qtde_jog)
{
    string posicao_ganhador = jogador[0]._nome, resultado = "1 " + to_string(pote) + " " + jogador[0]._tipo_jogada + " " + jogador[0]._nome;
    int ganhador = jogador[0]._tipo_de_mao, Mao_ganhadora, Num_empate = -2, empate_posicao_1 = -1, empate_posicao_2 = -1, empate_posicao_3 = -1, empate_posicao_4 = -1;

    // Inicializa as variaves que determinam qual o tipo da mao, a quantidade de empates e as posicoes dos jogadores no empate
    Mao_ganhadora = BuscaRepeticaoDeMao(jogador, 0, qtde_jog);
    Num_empate = BuscaRepeticaoDeMao(jogador, 1, qtde_jog);
    empate_posicao_1 = BuscaRepeticaoDeMao(jogador, 2, qtde_jog);
    empate_posicao_2 = BuscaRepeticaoDeMao(jogador, 3, qtde_jog);
    empate_posicao_3 = BuscaRepeticaoDeMao(jogador, 4, qtde_jog);
    empate_posicao_4 = BuscaRepeticaoDeMao(jogador, 5, qtde_jog);

    for (int i = 1; i < num_jogadores; i++)
    {
        leMemLog((long int)jogador[i]._tipo_de_mao, (long int)sizeof(int), jogador[i]._id);

        if (jogador[i]._tipo_de_mao < ganhador &&
            jogador[i]._tipo_de_mao < Mao_ganhadora)
        {
            if (Mao_ganhadora == -1 || (jogador[i]._tipo_de_mao < Mao_ganhadora && Mao_ganhadora != -1))
            {
                posicao_ganhador = jogador[i]._nome;
                ganhador = jogador[i]._tipo_de_mao;
                resultado = "1 " + to_string(pote) + " " + jogador[i]._tipo_jogada + " " + jogador[i]._nome;
                LimpaGP(jogador, num_jogadores);
                jogador[i]._ganhou_partida = 1;

                ESCREVEMEMLOG((long int)jogador[i]._ganhou_partida, (long int)sizeof(int), jogador[i]._id);
            }
        }
        else if (Num_empate == 2 && Mao_ganhadora <= ganhador)
        {
            if (ResolveEmpate(jogador, empate_posicao_1, empate_posicao_2) == 1)
            {
                resultado = "1 " + to_string(pote) + " " + jogador[empate_posicao_1]._tipo_jogada + " " + jogador[empate_posicao_1]._nome;
                LimpaGP(jogador, num_jogadores);
                jogador[empate_posicao_1]._ganhou_partida = 1;

                ESCREVEMEMLOG((long int)jogador[empate_posicao_1]._ganhou_partida, (long int)sizeof(int), jogador[empate_posicao_1]._id);
            }
            else if (ResolveEmpate(jogador, empate_posicao_1, empate_posicao_2) == 2)
            {
                resultado = "1 " + to_string(pote) + " " + jogador[empate_posicao_2]._tipo_jogada + " " + jogador[empate_posicao_2]._nome;
                LimpaGP(jogador, num_jogadores);
                jogador[empate_posicao_2]._ganhou_partida = 1;

                ESCREVEMEMLOG((long int)jogador[empate_posicao_2]._ganhou_partida, (long int)sizeof(int), jogador[empate_posicao_2]._id);
            }
            else if (ResolveEmpate(jogador, empate_posicao_1, empate_posicao_2) == 3)
            {
                resultado = "2 " + to_string(pote) + " " + jogador[empate_posicao_1]._tipo_jogada + " " + jogador[empate_posicao_2 + 1]._nome + jogador[empate_posicao_1]._nome;
                LimpaGP(jogador, num_jogadores);
                jogador[empate_posicao_1]._ganhou_partida = 1;
                jogador[empate_posicao_2]._ganhou_partida = 1;

                ESCREVEMEMLOG((long int)jogador[empate_posicao_1]._ganhou_partida, (long int)sizeof(int), jogador[empate_posicao_1]._id);
                ESCREVEMEMLOG((long int)jogador[empate_posicao_2]._ganhou_partida, (long int)sizeof(int), jogador[empate_posicao_2]._id);
            }
        }
        else if (Num_empate == 3 && Mao_ganhadora <= ganhador)
        {
            if (ResolveEmpate(jogador, empate_posicao_1, empate_posicao_2) == 1 &&
                ResolveEmpate(jogador, empate_posicao_1, empate_posicao_3) == 1)
            {
                resultado = "1 " + to_string(pote) + " " + jogador[empate_posicao_1]._tipo_jogada + " " + jogador[empate_posicao_1]._nome;
                LimpaGP(jogador, num_jogadores);
                jogador[empate_posicao_1]._ganhou_partida = 1;

                ESCREVEMEMLOG((long int)jogador[empate_posicao_1]._ganhou_partida, (long int)sizeof(int), jogador[empate_posicao_1]._id);
            }
            else if (ResolveEmpate(jogador, empate_posicao_1, empate_posicao_2) == 2 &&
                     ResolveEmpate(jogador, empate_posicao_2, empate_posicao_3) == 1)
            {
                resultado = "1 " + to_string(pote) + " " + jogador[empate_posicao_2]._tipo_jogada + " " + jogador[empate_posicao_2]._nome;
                LimpaGP(jogador, num_jogadores);
                jogador[empate_posicao_2]._ganhou_partida = 1;

                ESCREVEMEMLOG((long int)jogador[empate_posicao_2]._ganhou_partida, (long int)sizeof(int), jogador[empate_posicao_2]._id);
            }
            else if (ResolveEmpate(jogador, empate_posicao_1, empate_posicao_3) == 2 &&
                     ResolveEmpate(jogador, empate_posicao_2, empate_posicao_3) == 2)
            {
                resultado = "1 " + to_string(pote) + " " + jogador[empate_posicao_3]._tipo_jogada + " " + jogador[empate_posicao_3]._nome;
                LimpaGP(jogador, num_jogadores);
                jogador[empate_posicao_3]._ganhou_partida = 1;

                ESCREVEMEMLOG((long int)jogador[empate_posicao_3]._ganhou_partida, (long int)sizeof(int), jogador[empate_posicao_3]._id);
            }
            else if (ResolveEmpate(jogador, empate_posicao_1, empate_posicao_2) == 3 &&
                     ResolveEmpate(jogador, empate_posicao_2, empate_posicao_3) == 3)
            {
                resultado = "3 " + to_string(pote) + " " + jogador[empate_posicao_1]._tipo_jogada + " " + jogador[empate_posicao_1]._nome + jogador[empate_posicao_2]._nome + jogador[empate_posicao_3]._nome;
                LimpaGP(jogador, num_jogadores);
                jogador[empate_posicao_1]._ganhou_partida = 1;
                jogador[empate_posicao_2]._ganhou_partida = 1;
                jogador[empate_posicao_3]._ganhou_partida = 1;

                ESCREVEMEMLOG((long int)jogador[empate_posicao_1]._ganhou_partida, (long int)sizeof(int), jogador[empate_posicao_1]._id);
                ESCREVEMEMLOG((long int)jogador[empate_posicao_2]._ganhou_partida, (long int)sizeof(int), jogador[empate_posicao_2]._id);
                ESCREVEMEMLOG((long int)jogador[empate_posicao_3]._ganhou_partida, (long int)sizeof(int), jogador[empate_posicao_3]._id);
            }
        }
        else if (Num_empate == 4 && Mao_ganhadora <= ganhador)
        {
            if (ResolveEmpate(jogador, empate_posicao_1, empate_posicao_2) == 1 &&
                ResolveEmpate(jogador, empate_posicao_1, empate_posicao_3) == 1 &&
                ResolveEmpate(jogador, empate_posicao_1, empate_posicao_4) == 1)
            {
                resultado = "1 " + to_string(pote) + " " + jogador[empate_posicao_1]._tipo_jogada + " " + jogador[empate_posicao_1]._nome;
                LimpaGP(jogador, num_jogadores);
                jogador[empate_posicao_1]._ganhou_partida = 1;

                ESCREVEMEMLOG((long int)jogador[empate_posicao_1]._ganhou_partida, (long int)sizeof(int), jogador[empate_posicao_1]._id);
            }
            else if (ResolveEmpate(jogador, empate_posicao_1, empate_posicao_2) == 2 &&
                     ResolveEmpate(jogador, empate_posicao_2, empate_posicao_3) == 1 &&
                     ResolveEmpate(jogador, empate_posicao_2, empate_posicao_4) == 1)
            {
                resultado = "1 " + to_string(pote) + " " + jogador[empate_posicao_2]._tipo_jogada + " " + jogador[empate_posicao_2]._nome;
                LimpaGP(jogador, num_jogadores);
                jogador[empate_posicao_2]._ganhou_partida = 1;

                ESCREVEMEMLOG((long int)jogador[empate_posicao_2]._ganhou_partida, (long int)sizeof(int), jogador[empate_posicao_2]._id);
            }
            else if (ResolveEmpate(jogador, empate_posicao_1, empate_posicao_3) == 2 &&
                     ResolveEmpate(jogador, empate_posicao_2, empate_posicao_3) == 2 &&
                     ResolveEmpate(jogador, empate_posicao_3, empate_posicao_4) == 1)
            {
                resultado = "1 " + to_string(pote) + " " + jogador[empate_posicao_3]._tipo_jogada + " " + jogador[empate_posicao_3]._nome;
                LimpaGP(jogador, num_jogadores);
                jogador[empate_posicao_3]._ganhou_partida = 1;

                ESCREVEMEMLOG((long int)jogador[empate_posicao_3]._ganhou_partida, (long int)sizeof(int), jogador[empate_posicao_3]._id);
            }
            else if (ResolveEmpate(jogador, empate_posicao_1, empate_posicao_4) == 2 &&
                     ResolveEmpate(jogador, empate_posicao_2, empate_posicao_4) == 2 &&
                     ResolveEmpate(jogador, empate_posicao_3, empate_posicao_4) == 2)
            {
                resultado = "1 " + to_string(pote) + " " + jogador[empate_posicao_4]._tipo_jogada + " " + jogador[empate_posicao_4]._nome;
                LimpaGP(jogador, num_jogadores);
                jogador[empate_posicao_4]._ganhou_partida = 1;
                ESCREVEMEMLOG((long int)jogador[empate_posicao_4]._ganhou_partida, (long int)sizeof(int), jogador[empate_posicao_4]._id);
            }
            else if (ResolveEmpate(jogador, empate_posicao_1, empate_posicao_2) == 3 &&
                     ResolveEmpate(jogador, empate_posicao_2, empate_posicao_3) == 3 &&
                     ResolveEmpate(jogador, empate_posicao_3, empate_posicao_4) == 3)
            {
                resultado = "4 " + to_string(pote) + " " + jogador[empate_posicao_1]._tipo_jogada + " " + jogador[empate_posicao_1]._nome + jogador[empate_posicao_2]._nome + jogador[empate_posicao_3]._nome + jogador[empate_posicao_4]._nome;
                LimpaGP(jogador, num_jogadores);
                jogador[empate_posicao_1]._ganhou_partida = 1;
                jogador[empate_posicao_2]._ganhou_partida = 1;
                jogador[empate_posicao_3]._ganhou_partida = 1;
                jogador[empate_posicao_4]._ganhou_partida = 1;

                ESCREVEMEMLOG((long int)jogador[empate_posicao_1]._ganhou_partida, (long int)sizeof(int), jogador[empate_posicao_1]._id);
                ESCREVEMEMLOG((long int)jogador[empate_posicao_2]._ganhou_partida, (long int)sizeof(int), jogador[empate_posicao_2]._id);
                ESCREVEMEMLOG((long int)jogador[empate_posicao_3]._ganhou_partida, (long int)sizeof(int), jogador[empate_posicao_3]._id);
                ESCREVEMEMLOG((long int)jogador[empate_posicao_4]._ganhou_partida, (long int)sizeof(int), jogador[empate_posicao_4]._id);
            }
        }
    }

    return resultado;
}