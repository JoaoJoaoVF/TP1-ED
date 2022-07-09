#include "partida.hpp"

void ExecutaPartida()
{
    // Cria o pote do jogo
    Pote *Pote_rodada = new Pote;
    Baralho *BaralhoCompleto = new Baralho;

    // Inicialização de variaveis usadas ao longo do codigo
    int rodadas, jogadores, qtd_rodadas = 0, dinheiro_jogadores = 0, num_jogadores = 0, pingo_jogadores = 0, aposta_jogador = 0, valor_carta = 0, i, pingo, sanidade = 0;
    char nome_jogador[100], naipe_carta;
    string nome_jogador_lido;

    // abre o arquivo contendo as rodadas e o da saida
    FILE *entrada = fopen("entrada.txt", "r");
    erroAssert(entrada != NULL, "Não foi possivel abrir o arquivo");
    ofstream resultado("saida.txt");

    // realiza a leitura da quantidades de rodadas e o dinheiro de cada jogador da partida
    fscanf(entrada, "%d %d", &qtd_rodadas, &dinheiro_jogadores);
    erroAssert(dinheiro_jogadores > 0, "Dinheiro dos jogadores deve ser maior que 0");
    erroAssert(qtd_rodadas > 0, "O numero de rodadas deve ser maior que 0");

    // Realiza a primeira leitura do numero dos jogadores e do pingo de cada um deles
    fscanf(entrada, "%d %d", &num_jogadores, &pingo_jogadores);
    erroAssert(num_jogadores > 0, "O numero de jogadores deve ser maior que 0");
    avisoAssert(pingo_jogadores > 49, "O pingo do jogador deve ser multiplo de 50");

    // Caso o pingo seja menor que 50 a rodada é invalidada
    if (aposta_jogador % 50 != 0)
    {
        sanidade = 1;
    }

    Jogador *Meu_jogador = new Jogador[num_jogadores];

    // define variaveis axuliares para o primeiro numero de rodadas, jogadores e pingo
    rodadas = qtd_rodadas;
    jogadores = num_jogadores;
    pingo = pingo_jogadores;

    // Loop das rodadas
    for (i = 0; i < rodadas; i++)
    {
        // inicia todas as posicoes da matriz baralho como 0
        PopulaBaralho(BaralhoCompleto);

        //  variavel que guarda a saida vencedora contendo o numero de vencedores, o valor do montante, a mao vencedora e o nome(s) do(s) vencedor(es)
        string jog_ganhador = " ";

        // cria o Pote e inicializa o montante com o valor 0
        criaPote(Pote_rodada, i);

        // realiza a leitura do numero de jogadores e do pingo dos jogadores da rodada, em caso de não ser a primeira vez que o laço é executado
        if (i != 0)
        {
            // Atribui a sainidade do jogador como aceitavel
            sanidade = 0;

            fscanf(entrada, "%d %d", &num_jogadores, &pingo_jogadores);
            erroAssert(num_jogadores <= jogadores, "O numero de jogadores não pode ser maior do que o da primeira rodada");
            avisoAssert(pingo_jogadores > 49, "O pingo do jogador deve ser multiplo de 50");

            pingo = pingo_jogadores;
        }

        // Caso o pingo seja menor que 50 a rodada é invalidada
        if (pingo_jogadores < 50)
        {
            sanidade = 1;
        }

        // Realiza a Invalidação das cartas das rodadas anteriores
        LimpaDadosJogador(Meu_jogador, jogadores);

        // Loop dos jogadores
        for (int j = 0; j < num_jogadores; j++)
        {

            // realiza a leitura do nome do jogadore e da sua aposta
            fscanf(entrada, "%[^0-9] %d", nome_jogador, &aposta_jogador);
            avisoAssert(aposta_jogador % 50 == 0, "A aposta do jogador deve ser multiplo de 50");

            // invalida a rodada se a aposta nao for multipla de 50
            if (aposta_jogador % 50 != 0)
            {
                sanidade = 1;
            }

            // Inicializa a variavel que determina a posição do jogador
            int posicao_jogador = j;

            // Encontra em que posicao o jogador se encontra e retorna ela, em caso de nao ser a primeira rodada
            if (i > 0)
            {
                posicao_jogador = EncontraJogador(Meu_jogador, nome_jogador, jogadores);
                erroAssert(posicao_jogador > -1, "Jogador não faz parte do jogo");
            }

            // converte o nome lido para uma string e atribui-o e o id do jogador
            nome_jogador_lido = converterJogadorString(nome_jogador);
            Meu_jogador[posicao_jogador]._nome = nome_jogador_lido;
            Meu_jogador[posicao_jogador]._id = posicao_jogador;

            // atribui o dinheiro para cada jogador, somente se estiver na primeira rodada
            if (i == 0)
            {
                Meu_jogador[posicao_jogador]._dinheiro = dinheiro_jogadores;
            }

            // Loop que faz a leitura e inicialização das cartas na mão do jogador
            for (int cards = 0; cards < 5; cards++)
            {
                fscanf(entrada, "%d %s", &valor_carta, &naipe_carta);
                avisoAssert(valor_carta < 14, "Valor de Carta invalido!");
                avisoAssert(valor_carta > 0, "Valor de Carta invalido!");

                sanidade = VerificaRepeticaoCarta(BaralhoCompleto, valor_carta, naipe_carta);

                Meu_jogador[posicao_jogador].Cartas_jogador[cards]._carta = converterCartaString(valor_carta, naipe_carta);
                Meu_jogador[posicao_jogador].Cartas_jogador[cards]._valor_carta = valor_carta;
                Meu_jogador[posicao_jogador].Cartas_jogador[cards]._naipe_carta = naipe_carta;

                ESCREVEMEMLOG((long int)Meu_jogador[posicao_jogador].Cartas_jogador[cards]._valor_carta, (long int)sizeof(int), Meu_jogador[posicao_jogador]._id);
                ESCREVEMEMLOG((long int)Meu_jogador[posicao_jogador].Cartas_jogador[cards]._naipe_carta, (long int)sizeof(char), Meu_jogador[posicao_jogador]._id);
                ESCREVEMEMLOG((long int)Meu_jogador[posicao_jogador].Cartas_jogador[cards]._carta[0], (long int)Meu_jogador[posicao_jogador].Cartas_jogador[cards]._carta.length() * sizeof(char), Meu_jogador[posicao_jogador]._id);

                // invalida a rodada caso algum valor de carta seja invalido
                if (valor_carta > 13 || valor_carta < 0)
                {
                    sanidade = 1;
                }
            }

            // Verifica se o jogador possui dinheiro suficiente para realizar a adição no pote do pingo e aposta
            if (Meu_jogador[posicao_jogador]._dinheiro > 1 && Meu_jogador[posicao_jogador]._dinheiro > pingo + aposta_jogador)
            {
                // Realiza a adição da aposta de cada jogador no pote e subtrai o da aposta do jogador
                adicionaAposta(Pote_rodada, aposta_jogador);
                Meu_jogador[posicao_jogador]._dinheiro -= aposta_jogador;
            }
            else
            {
                // atribui a sanidade do jogador como invalida
                sanidade = 1;
            }

            // realiza a ordenação das cartas do jogador
            Ordena(Meu_jogador, posicao_jogador);

            // Analisa qual o tipo de mao o jogador possui
            AnalisaJogada(Meu_jogador, posicao_jogador);
        }

        // Verifica se os jogadores estao sãos
        if (sanidade == 0)
        {
            // Realiza a adição do pingo de cada jogador no pote e subtrai o valor do pingo
            adicionaPingo(Meu_jogador, Pote_rodada, pingo, jogadores);

            // Realiza a Analise de quem venceu a partida e realiza a escrita no arquivo da saida do reultado
            jog_ganhador = VenceuPartida(Meu_jogador, jogadores, GetMontante(Pote_rodada), jogadores);
            resultado << jog_ganhador << endl;

            // Atribui os ganhos do jogador vencedor da rodada
            AtribuiGanhosVencedor(Meu_jogador, jogadores, GetMontante(Pote_rodada));
        }
        // Cancela a rodada e retorna que a Rodada esta invalida em caso do teste de sanidade resultar num jogador insano
        else
        {
            resultado << "0 0 I" << endl;
        }
    }

    // realiza a escrita no arquivo saida
    resultado << "####";

    // Ordena os jogadores em ordem do que ganhou mais para o que ganhou menos
    OrdenaJogadores(Meu_jogador, jogadores);

    // escreve os dados dos outros jogadores no arquivo e os mesmos imprime na tela
    for (int as = 0; as < jogadores; as++)
    {
        leMemLog((long int)Meu_jogador[as]._dinheiro, (long int)sizeof(int), Meu_jogador[as]._id);
        resultado << Meu_jogador[as]._nome << Meu_jogador[as]._dinheiro;
    }

    // faz o fechamento dos arquivos de entrada e saida, alem da liberação da alocação
    resultado.close();
    fclose(entrada);
    delete[] Meu_jogador;
    delete Pote_rodada;
    delete BaralhoCompleto;
}