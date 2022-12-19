#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct{ // struct que vai receber os dados dos jogadores
    char nome[10];
    int idade;
    char sexo[10];
    char cor[10];
    int pontos;
}dados;

void info(dados *dados); //protótipo da função para pegar os dados dos jogadores
void cor(); //protótipo da função para sortear a cor da peça do primeiro jogador
void preencher(char *tab[8][8]); //protótipo da função que vai preencher o tabuleiro
void imprimir (char *tab [8][8]);//protótipo da função que vai imprimir o tabuleiro
void posicoes_preto (char *tab[8][8]);//protótipo da função que vai mostrar as posiçoes da peça preta
void posicoes_branco(char *tab[8][8]); //protótipo da função que vai mostrar as posições da peça branca
void jogada (char *tab[8][8]); //protótipo da função
void limpeza (char *tab[8][8]); //protótipo da função que vai limpar o tabuleiro
void troca_preto (char *tab[8][8]);//protótipo da função que vai trocra a cor da peça
void troca_branco(char *tab[8][8]);//protótipo da função que vai trocra a cor da peça
void contagem_pecas (char *tab[8][8]); //protótipo da função que vai contar as peças
void resultado(char *tab[8][8]);//protótipo da função que vai mostrar o vencedor

int main(){ //início função principal
    setlocale (LC_ALL, "Portuguese");
    dados dados [2];//struct do tipo dados
    int op;//variável que vai receber a opção do menu
    char tab[8][8];//variável tabuleiro
    int cor = rand () %2;//sorteio cor
    int contP, contB;

    printf ("----Bem-vindo ao jogo Othello----");
    printf ("\n[1] Jogar");
    printf ("\n[2] Sobre do Jogo");
    printf ("\n[3] Sair do Jogo\n");
    scanf ("%d", &op);

    switch (op)
    {
        case 1:
        printf ("Sorteio peça jogador 1.\nInformações:\n[0]Branca\n[1]Preta\n");
        printf ("%d", cor);
        for (int k=0; k<2; k++)
        {
            printf ("\n**Insira seus dados**\n");
            printf ("Nome: ");
            scanf ("%s", &dados[k].nome);
            printf ("Idade: ");
            scanf ("%d", &dados[k].idade);
            printf ("Sexo: ");
            scanf ("%s", &dados[k].sexo);
            printf ("Cor da peça: ");
            scanf ("%s", &dados[k].cor);
        }
        printf ("\nComeça o jogador com a peça PRETA. Divirta-se!!\n");
        jogada(tab);
        resultado(tab);

        for (int k=0; k<2; k++)
        {
            dados[0].pontos = contP;
            dados[1].pontos = contB;
            printf("Nome: %s\nIdade: %d\nSexo: %s\nCor: %s\nPontos: %d", dados[k].nome, dados[k].idade, dados[k].sexo, dados[k].cor, dados[k].pontos);
        }
        break;

        case 2:
            printf ("Othello também conhecido como Reversi é um jogo para dois jogadores, jogado em um Tabuleiro de 8x8 onde inicialmente são colocadas quatro peças ao centro, duas de cada cor em diagonais onde a peça preta faz sempre o primeiro movimento e os jogadores jogam alternadamente, o jogo tem como meta capturar as peças adversárias e transformá-las nas da sua cor, vence quem tiver mais peças ao seu favor no final da partida. O jogo acaba quando não há mais casas a se jogarem dentro do tabuleiro ou quando não houver mais jogadas possíveis dentro das regras para ambos os jogadores");
        break;

        case 3:
            printf ("Saindo");
        break;

        default:
            printf ("Insira uma opção válida!");
    }
    return 0;
}
void preencher (char *tab [8][8]) //função que vai preencher o tabuleiro
{
    int i, j;
    for (i=0; i<8; i++)
    {
        for (j=0; j<8; j++)
        {
            if ((i==3 && j==4) | (i==4 && j ==3))
            {
                tab[i][j] = 'B';
            }
            else if ((i==3 && j== 3) | (i==4 && j==4))
            {
                tab[i][j] = 'P';
            }
            else
                tab[i][j] = '.';
        }
    }
}
void imprimir (char *tab[8][8])//função que vai imprimir o tabuleiro
{
    int i, j;
    for (i=0; i<8; i++)
    {
        for (j=0; j<8; j++)
        {
            printf (" %c ", tab[i][j]);
        }
    printf ("\n");
    }
}
void posicoes_preto(char *tab[8][8])//função que vai mostrar as posições pra peça preta
{
    int i, j;
    for (i=0; i<8; i++)//esquerda
    {
        for (j=0; j<8; j++)
        {
            if (tab[i][j] == 'P' && tab[i][j-4] == 'B')
            {
                tab[i][j-4] = 'B';
            }
            else if (tab[i][j] == 'P' && tab[i][j-3] ==  'B')
            {
                if (tab[i][j-2] = 'B')
                {
                    if (tab[i][j-1] = 'B')
                    {
                        tab[i][j-4] = 'x';
                    }
                }
            }
            else if (tab[i][j] == 'P' && tab[i][j-2] ==  'B')
            {
                if (tab[i][j-1])
                {
                   tab[i][j-3] = 'x';
                }
            }
            else if (tab[i][j] == 'P' && tab[i][j-1] ==  'B')
            {
                tab[i][j-2] = 'x';
            }
            else if (tab[i][j] == 'P' && tab[i][j-1] ==  'B')
            {
                tab[i][j-2] = '.';
            }
        }
    }
    for (i=0; i<8; i++)//direita
    {
        for (j=0; j<8; j++)
        {
            if (tab[i][j] == 'P' && tab[i][j+4] == 'B')
            {
                tab[i][j+4] = 'B';
            }
            else if(tab[i][j] == 'P' && tab[i][j+3] == 'B')
            {
                if (tab[i][j+2] = 'B')
                {
                    if (tab[i][j+1] = 'B')
                    {
                        tab[i][j+4] = 'x';
                    }
                }

            }
            else if(tab[i][j] == 'P' && tab[i][j+2] == 'B')
            {
                if (tab[i][j+1])
                {
                    tab[i][j+3] = 'x';
                }
            }
            else if(tab[i][j] == 'P' && tab[i][j+1] == 'B')
            {
                tab[i][j+2] = 'x';
            }
            else if (tab[i][j] == 'P' && tab[i][j+1] == '.')
            {
                tab[i][j+2] = '.';
            }
        }
    }
    for (i=0; i<8; i++)//pra cima
    {
        for (j=0; j<8; j++)
        {
            if (tab[i][j] == 'P' && tab[i-4][j] == 'B')
            {
                tab[i-4][j] = 'B';
            }
            else if(tab[i][j] == 'P' && tab[i-3][j] == 'B')
            {
                if (tab[i-2][j] = 'B')
                {
                    if (tab[i-1][j] = 'B')
                    {
                        tab[i-4][j] = 'x';
                    }
                }
            }
            else if(tab[i][j] == 'P' && tab[i-2][j] == 'B')
            {
                if (tab[i-1][j] = 'B')
                {
                   tab[i-3][j] = 'x';
                }
            }
            else if(tab[i][j] == 'P' && tab[i-1][j] == 'B')
            {
                tab[i-2][j] = 'x';
            }
            else if (tab[i][j] == 'P' && tab[i-1][j] == '.')
            {
                tab[i-2][j] = '.';
            }
        }
    }
    for (i=0; i<8; i++)//pra baixo
    {
        for (j=0; j<8; j++)
        {
            if (tab[i][j] == 'P' && tab[i+4][j] == 'B')
            {
                tab[i+4][j] = 'B';
            }
            else if(tab[i][j] == 'P' && tab[i+3][j] == 'B')
            {
                if (tab[i+2][j] = 'B')
                {
                    if (tab[i+1][j] = 'B')
                    {
                        tab[i+4][j] = 'x';
                    }
                }
            }
            else if(tab[i][j] == 'P' && tab[i+2][j] == 'B')
            {
                if (tab[i+1][j])
                {
                    tab[i+3][j] = 'x';
                }

            }
            else if(tab[i][j] == 'P' && tab[i+1][j] == 'B')
            {
                tab[i+2][j] = 'x';
            }
            else if (tab[i][j] == 'P' && tab[i+1][j] == '.')
            {
                tab[i+2][j] = '.';
            }
        }
    }
    for (i=0; i<8; i++)//diagonal principal
    {
        for (j=0; j<8; j++)
        {
            if (tab[i][j] == 'P' && tab[i+4][j+4] == 'B')//baixo
            {
                tab[i+4][j+4] = 'B';

            }
            else if (tab[i][j] == 'P' && tab[i-4][j-4] == 'B')//cima
            {
                if (tab[i-3][j-3] = 'B')
                {
                    if (tab[i-2][j-2] = 'B')
                    {
                        if (tab[i-1][j-1] = 'B')
                        {
                              tab[i-4][j-4] = 'x';
                        }
                    }
                }
            }
            else if (tab[i][j] == 'P' && tab[i+3][j+3] ==  'B')//baixo
            {
                if (tab[i+2][j+2] = 'B')
                {
                    if (tab[i+1][j+1] = 'B')
                    {
                        tab[i+4][j+4] = 'x';
                    }
                }
            }
            else if (tab[i][j] == 'P' && tab[i-3][j-3] == 'B')//cima
            {
                if (tab[i-2][j-2]= 'B')
                {
                    if (tab[i-1][j-1] = 'B')
                    {
                        tab[i-4][j-4] = 'x';
                    }
                }
            }
            else if (tab[i][j] == 'P' && tab[i+2][j+2] ==  'B')//baixo
            {
                if (tab[i+1][j+1] = 'B')
                {
                    tab[i+3][j+3] = 'x';
                }
            }
            else if (tab[i][j] == 'P' && tab[i-2][j-2] ==  'B')//cima
            {
                if (tab[i-1][j-1]='B')
                {
                    tab[i-3][j-3] = 'x';
                }
            }
            else if (tab[i][j] == 'P' && tab[i+1][j+1] ==  'B')//baixo
            {
                tab[i+2][j+2] = 'x';
            }
            else if (tab[i][j] == 'P' && tab[i-1][j-1] ==  'B')//cima
            {
                tab[i-2][j-2] = 'x';
            }
            else if (tab[i][j] == 'P' && tab[i+1][j+1] ==  'B')//baixo
            {
                tab[i+2][j+2] = '.';
            }
        }
    }
    for (i=0; i<8; i++)//diagonal secundária
    {
        for (j=0; j<8; j++)
        {
            if (tab[i][j] == 'P' && tab[i-4][j+4] == 'B') //cima
            {
                tab[i-4][j+4] = 'B';

            }
            else if (tab[i][j] == 'P' && tab[i+4][j-4] == 'B')//baixo
            {
                if (tab[i+3][j-3] = 'B')
                {
                    if (tab[i+2][j-2] = 'B')
                    {
                        if (tab[i+1][j-1] = 'B')
                        {
                              tab[i+4][j-4] = 'x';
                        }
                    }
                }
            }
            else if (tab[i][j] == 'P' && tab[i-3][j+3] ==  'B')//cima
            {
                if (tab[i-2][j+2] = 'B')
                {
                    if (tab[i-1][j+1] = 'B')
                    {
                        tab[i-4][j+4] = 'x';
                    }
                }
            }
            else if (tab[i][j] == 'P' && tab[i+3][j-3] == 'B')//baixo
            {
                if (tab[i+2][j-2]= 'B')
                {
                    if (tab[i+1][j-1] = 'B')
                    {
                        tab[i+4][j-4] = 'x';
                    }
                }
            }
            else if (tab[i][j] == 'P' && tab[i-2][j+2] ==  'B')//cima
            {
                if (tab[i-1][j+1] = 'B')
                {
                    tab[i-3][j+3] = 'x';
                }
            }
            else if (tab[i][j] == 'P' && tab[i+2][j-2] ==  'B')//baixo
            {
                if (tab[i+1][j-1]='B')
                {
                    tab[i+3][j-3] = 'x';
                }
            }
            else if (tab[i][j] == 'P' && tab[i-1][j+1] ==  'B')//cima
            {
                tab[i-2][j+2] = 'x';
            }
            else if (tab[i][j] == 'P' && tab[i+1][j-1] ==  'B')//baixo
            {
                tab[i+2][j-2] = 'x';
            }
            else if (tab[i][j] == 'P' && tab[i-1][j+1] ==  'B')//cima
            {
                tab[i-2][j+2] = '.';
            }
        }
    }
}
void posicoes_branco(char *tab[8][8])//função que vai mostrar as posições pra peça branca
{
    int i, j;
    for (i=0; i<8; i++)//esquerda
    {
        for (j=0; j<8; j++)
        {
            if (tab[i][j] == 'B' && tab[i][j-4] == 'P')
            {
                tab[i][j-4] = 'P';

            }
            else if (tab[i][j] == 'B' && tab[i][j-3] ==  'P')
            {
                if (tab[i][j-2] = 'P')
                {
                    if (tab[i][j-1] = 'P')
                    {
                        tab[i][j-4] = 'x';
                    }
                }
            }
            else if (tab[i][j] == 'B' && tab[i][j-2] ==  'P')
            {
                if (tab[i][j-1] = 'P')
                {
                    tab[i][j-3] = 'x';
                }
            }
            else if (tab[i][j] == 'B' && tab[i][j-1] ==  'P')
            {
                tab[i][j-2] = 'x';
            }
            else if (tab[i][j] == 'B' && tab[i][j-1] ==  'P')
            {
                tab[i][j-2] = '.';
            }
        }
    }
    for (i=0; i<8; i++)//direita
    {
        for (j=0; j<8; j++)
        {
            if (tab[i][j] == 'B' && tab[i][j+4] == 'P')
            {
                tab[i][j+4] = 'P';
            }
            else if(tab[i][j] == 'B' && tab[i][j+3] == 'P')
            {
                if (tab[i][j+2] = 'P')
                {
                    if (tab[i][j+1] = 'P')
                    {
                        tab[i][j+4] = 'x';
                    }
                }
            }
            else if(tab[i][j] == 'B' && tab[i][j+2] == 'P')
            {
                if (tab[i][j+1] = 'P')
                {
                    tab[i][j+3] = 'x';
                }
            }
            else if(tab[i][j] == 'B' && tab[i][j+1] == 'P')
            {
                tab[i][j+2] = 'x';
            }
            else if (tab[i][j] == 'B' && tab[i][j+1] == '.')
            {
                tab[i][j+2] = '.';
            }
        }
    }
    for (i=0; i<8; i++)//pra cima
    {
        for (j=0; j<8; j++)
        {
            if (tab[i][j] == 'B' && tab[i-4][j] == 'P')
            {
                tab[i-4][j] = 'P';
            }
            else if(tab[i][j] == 'B' && tab[i-3][j] == 'P')
            {
                if (tab[i-3][j] = 'P')
                {
                    if (tab[i-2][j] = 'P')
                    {
                        if (tab[i-1][j] = 'P')
                        {
                             tab[i-4][j] = 'x';
                        }
                    }
                }
            }
            else if(tab[i][j] == 'B' && tab[i-2][j] == 'P')
            {
                if (tab[i-1][j] = 'P')
                {
                    tab[i-3][j] = 'x';
                }
            }
            else if(tab[i][j] == 'B' && tab[i-1][j] == 'P')
            {
                tab[i-2][j] = 'x';
            }
            else if (tab[i][j] == 'B' && tab[i-1][j] == '.')
            {
                tab[i-2][j] = '.';
            }
        }
    }
    for (i=0; i<8; i++)//pra baixo
    {
        for (j=0; j<8; j++)
        {
            if (tab[i][j] == 'B' && tab[i+4][j] == 'P')
            {
                tab[i+4][j] = 'P';
            }
            else if(tab[i][j] == 'B' && tab[i+3][j] == 'P')
            {
                if (tab[i+3][j] = 'P')
                {
                    if (tab[i+2][j] = 'P')
                    {
                        if (tab[i+1][j] = 'P')
                        {
                            tab[i+4][j] = 'x';
                        }
                    }
                }
            }
            else if(tab[i][j] == 'B' && tab[i+2][j] == 'P')
            {
                if (tab[i+1][j] = 'P')
                {
                    tab[i+3][j] = 'x';
                }
            }
            else if(tab[i][j] == 'B' && tab[i+1][j] == 'P')
            {
                tab[i+2][j] = 'x';
            }
            else if (tab[i][j] == 'B' && tab[i+1][j] == '.')
            {
                tab[i+2][j] = '.';
            }
        }
    }
    for (i=0; i<8; i++)//diagonal principal
    {
        for (j=0; j<8; j++)
        {
            if (tab[i][j] == 'B' && tab[i+4][j+4] == 'P')//baixo
            {
                tab[i+4][j+4] = 'P';

            }
            else if (tab[i][j] == 'B' && tab[i-4][j-4] == 'P')//cima
            {
                if (tab[i-3][j-3] = 'P')
                {
                    if (tab[i-2][j-2] = 'P')
                    {
                        if (tab[i-1][j-1] = 'P')
                        {
                              tab[i-4][j-4] = 'x';
                        }
                    }
                }
            }

            else if (tab[i][j] == 'B' && tab[i+3][j+3] ==  'P')//baixo
            {
                if (tab[i+2][j+2] = 'P')
                {
                    if (tab[i+1][j+1] = 'P')
                    {
                        tab[i+4][j+4] = 'x';
                    }
                }
            }
            else if (tab[i][j] == 'B' && tab[i-3][j-3] == 'P')//cima
            {
                if (tab[i-2][j-2]= 'P')
                {
                    if (tab[i-1][j-1] = 'P')
                    {
                        tab[i-4][j-4] = 'x';
                    }
                }
            }
            else if (tab[i][j] == 'B' && tab[i+2][j+2] ==  'P')//baixo
            {
                if (tab[i+1][j+1] = 'P')
                {
                    tab[i+3][j+3] = 'x';
                }
            }
            else if (tab[i][j] == 'B' && tab[i-2][j-2] ==  'P')//cima
            {
                if (tab[i-1][j-1]='P')
                {
                    tab[i-3][j-3] = 'x';
                }
            }
            else if (tab[i][j] == 'B' && tab[i+1][j+1] ==  'P')//baixo
            {
                tab[i+2][j+2] = 'x';
            }
            else if (tab[i][j] == 'B' && tab[i-1][j-1] ==  'P')//cima
            {
                tab[i-2][j-2] = 'x';
            }
            else if (tab[i][j] == 'B' && tab[i+1][j+1] ==  'P')//baixo
            {
                tab[i+2][j+2] = '.';
            }
        }
    }
    for (i=0; i<8; i++)//diagonal secundária
    {
        for (j=0; j<8; j++)
        {
            if (tab[i][j] == 'B' && tab[i-4][j+4] == 'P')//cima
            {
                tab[i-4][j+4] = 'P';

            }
            else if (tab[i][j] == 'B' && tab[i+4][j-4] == 'P')//baixo
            {
                if (tab[i+3][j-3] = 'P')
                {
                    if (tab[i+2][j-2] = 'P')
                    {
                        if (tab[i+1][j-1] = 'P')
                        {
                              tab[i+4][j-4] = 'x';
                        }
                    }
                }
            }
            else if (tab[i][j] == 'B' && tab[i-3][j+3] ==  'P')//cima
            {
                if (tab[i-2][j+2] = 'P')
                {
                    if (tab[i-1][j+1] = 'P')
                    {
                        tab[i-4][j+4] = 'x';
                    }
                }
            }
            else if (tab[i][j] == 'B' && tab[i+3][j-3] == 'P')//baixo
            {
                if (tab[i+2][j-2]= 'P')
                {
                    if (tab[i+1][j-1] = 'P')
                    {
                        tab[i+4][j-4] = 'x';
                    }
                }
            }
            else if (tab[i][j] == 'B' && tab[i-2][j+2] ==  'P')//cima
            {
                if (tab[i-1][j+1] = 'P')
                {
                    tab[i-3][j+3] = 'x';
                }
            }
            else if (tab[i][j] == 'B' && tab[i+2][j-2] ==  'P')//baixo
            {
                if (tab[i+1][j-1]='P')
                {
                    tab[i+3][j-3] = 'x';
                }
            }
            else if (tab[i][j] == 'B' && tab[i-1][j+1] ==  'P')//cima
            {
                tab[i-2][j+2] = 'x';
            }
            else if (tab[i][j] == 'B' && tab[i+1][j-1] ==  'P')//baixo
            {
                tab[i+2][j-2] = 'x';
            }
            else if (tab[i][j] == 'B' && tab[i-1][j+1] ==  'P')//cima
            {
                tab[i-2][j+2] = '.';
            }
        }
    }
}

void limpeza (char *tab[8][8])
{
    int i, j;
    for (i=0; i<8; i++) //limpando
    {
        for (j=0; j<8; j++)
        {
            if (tab[i][j] == 'x')
                tab[i][j] = '.';
        }
    }
}
void contagem_pecas(char *tab[8][8])//função que vai contar as peças
{
    int i, j, contP = 0, contB=0;
    for (i=0; i<8; i++)
    {
        for (j=0; j<8; j++)
        {
            if (tab[i][j] == 'P')
            {
                contP++;
            }
            else if (tab[i][j] == 'B')
            {
                contB++;
            } else;
        }
    }
    printf ("\nPeças pretas = %d", contP);
    printf ("\nPeças brancas = %d\n", contB);
}
void troca_preto(char*tab[8][8])
{
    int linha_jogada, coluna_jogada;
    printf("Insira a linha: ");
    scanf("%d", &linha_jogada);
    printf("Insira a coluna: ");
    scanf("%d", &coluna_jogada);
    for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {

                if (tab[linha_jogada][coluna_jogada] == 'x')//para direita
                {
                    if (tab[linha_jogada][coluna_jogada + 4] == 'P')
                    {
                        tab[linha_jogada][coluna_jogada + 3] = 'P';
                        tab[linha_jogada][coluna_jogada + 2] = 'P';
                        tab[linha_jogada][coluna_jogada + 1] = 'P';
                        tab[linha_jogada][coluna_jogada] = 'P';
                    }
                    else if (tab[linha_jogada][coluna_jogada + 3] == 'P')
                    {
                        tab[linha_jogada][coluna_jogada + 2] = 'P';
                        tab[linha_jogada][coluna_jogada + 1] = 'P';
                        tab[linha_jogada][coluna_jogada] = 'P';
                    }
                    else if (tab[linha_jogada][coluna_jogada + 2] == 'P')
                    {
                        tab[linha_jogada][coluna_jogada + 1] = 'P';
                        tab[linha_jogada][coluna_jogada] = 'P';
                    }
                }
            }
        }
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {

                if (tab[linha_jogada][coluna_jogada] == 'x')//para esquerda
                {
                    if (tab[linha_jogada][coluna_jogada - 4] == 'P')
                    {
                        tab[linha_jogada][coluna_jogada - 3] = 'P';
                        tab[linha_jogada][coluna_jogada - 2] = 'P';
                        tab[linha_jogada][coluna_jogada - 1] = 'P';
                        tab[linha_jogada][coluna_jogada] = 'P';
                    }
                    else if (tab[linha_jogada][coluna_jogada - 3] == 'P')
                    {
                        tab[linha_jogada][coluna_jogada - 2] = 'P';
                        tab[linha_jogada][coluna_jogada - 1] = 'P';
                        tab[linha_jogada][coluna_jogada] = 'P';
                    }
                    else if (tab[linha_jogada][coluna_jogada - 2] == 'P')
                    {
                        tab[linha_jogada][coluna_jogada - 1] = 'P';
                        tab[linha_jogada][coluna_jogada] = 'P';
                    }
                }
            }
        }
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {

                if (tab[linha_jogada][coluna_jogada] == 'x')//para cima
                {
                    if (tab[linha_jogada - 4][coluna_jogada] == 'P')
                    {
                        tab[linha_jogada - 3][coluna_jogada] = 'P';
                        tab[linha_jogada - 2][coluna_jogada] = 'P';
                        tab[linha_jogada - 1][coluna_jogada] = 'P';
                        tab[linha_jogada][coluna_jogada] = 'P';
                    }
                    else if (tab[linha_jogada - 3][coluna_jogada] == 'P')
                    {
                        tab[linha_jogada - 2][coluna_jogada] = 'P';
                        tab[linha_jogada - 1][coluna_jogada] = 'P';
                        tab[linha_jogada][coluna_jogada] = 'P';
                    }
                    else if (tab[linha_jogada - 2][coluna_jogada] == 'P')
                    {
                        tab[linha_jogada - 1][coluna_jogada] = 'P';
                        tab[linha_jogada][coluna_jogada] = 'P';
                    }
                }
            }
        }
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {

                if (tab[linha_jogada][coluna_jogada] == 'x')//para baixo
                {
                    if (tab[linha_jogada + 4][coluna_jogada] == 'P')
                    {
                        tab[linha_jogada + 3][coluna_jogada] = 'P';
                        tab[linha_jogada + 2][coluna_jogada] = 'P';
                        tab[linha_jogada + 1][coluna_jogada] = 'P';
                        tab[linha_jogada][coluna_jogada] = 'P';
                    }
                    else if (tab[linha_jogada + 3][coluna_jogada] == 'P')
                    {
                        tab[linha_jogada + 2][coluna_jogada] = 'P';
                        tab[linha_jogada + 1][coluna_jogada] = 'P';
                        tab[linha_jogada][coluna_jogada] = 'P';
                    }
                    else if (tab[linha_jogada + 2][coluna_jogada] == 'P')
                    {
                        tab[linha_jogada + 1][coluna_jogada] = 'P';
                        tab[linha_jogada][coluna_jogada] = 'P';
                    }
                }
            }
        }
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {

                if (tab[linha_jogada][coluna_jogada] == 'x')//diagonal principal
                {
                    if (tab[linha_jogada + 4][coluna_jogada + 4] == 'P')//baixo
                    {
                        tab[linha_jogada + 3][coluna_jogada + 3] = 'P';
                        tab[linha_jogada + 2][coluna_jogada + 2] = 'P';
                        tab[linha_jogada + 1][coluna_jogada + 1] = 'P';
                        tab[linha_jogada][coluna_jogada] = 'P';
                    }
                    else if (tab[linha_jogada - 4][coluna_jogada - 4] == 'P')//cima
                    {
                        tab[linha_jogada - 3][coluna_jogada - 3] = 'P';
                        tab[linha_jogada - 2][coluna_jogada - 2] = 'P';
                        tab[linha_jogada - 1][coluna_jogada - 1] = 'P';
                        tab[linha_jogada][coluna_jogada] = 'P';
                    }
                    else if (tab[linha_jogada + 3][coluna_jogada + 3] == 'P')//baixo
                    {
                        tab[linha_jogada + 2][coluna_jogada + 2] = 'P';
                        tab[linha_jogada + 1][coluna_jogada + 1] = 'P';
                        tab[linha_jogada][coluna_jogada] = 'P';
                    }
                    else if (tab[linha_jogada - 3][coluna_jogada - 3] == 'P')//cima
                    {
                        tab[linha_jogada - 2][coluna_jogada - 2] = 'P';
                        tab[linha_jogada - 1][coluna_jogada - 1] = 'P';
                        tab[linha_jogada][coluna_jogada] = 'P';
                    }
                    else if (tab[linha_jogada + 2][coluna_jogada + 2] == 'P')//baixo
                    {
                        tab[linha_jogada + 1][coluna_jogada + 1] = 'P';
                        tab[linha_jogada][coluna_jogada] = 'P';
                    }
                    else if (tab[linha_jogada - 2][coluna_jogada - 2] == 'P')//cima
                    {
                        tab[linha_jogada - 1][coluna_jogada - 1] = 'P';
                        tab[linha_jogada][coluna_jogada] = 'P';
                    }
                }
            }
        }
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {

                if (tab[linha_jogada][coluna_jogada] == 'x')//diagonal secundária
                {
                    if (tab[linha_jogada - 4][coluna_jogada + 4] == 'P')//cima
                    {
                        tab[linha_jogada - 3][coluna_jogada + 3] = 'P';
                        tab[linha_jogada - 2][coluna_jogada + 2] = 'P';
                        tab[linha_jogada - 1][coluna_jogada + 1] = 'P';
                        tab[linha_jogada][coluna_jogada] = 'P';
                    }
                    else if (tab[linha_jogada + 4][coluna_jogada - 4] == 'P')//baixo
                    {
                        tab[linha_jogada + 3][coluna_jogada - 3] = 'P';
                        tab[linha_jogada + 2][coluna_jogada - 2] = 'P';
                        tab[linha_jogada + 1][coluna_jogada - 1] = 'P';
                        tab[linha_jogada][coluna_jogada] = 'P';
                    }
                    else if (tab[linha_jogada - 3][coluna_jogada + 3] == 'P')//cima
                    {
                        tab[linha_jogada - 2][coluna_jogada + 2] = 'P';
                        tab[linha_jogada - 1][coluna_jogada + 1] = 'P';
                        tab[linha_jogada][coluna_jogada] = 'P';
                    }
                    else if (tab[linha_jogada + 3][coluna_jogada - 3] == 'P')//baixo
                    {
                        tab[linha_jogada + 2][coluna_jogada - 2] = 'P';
                        tab[linha_jogada + 1][coluna_jogada - 1] = 'P';
                        tab[linha_jogada][coluna_jogada] = 'P';
                    }
                    else if (tab[linha_jogada - 2][coluna_jogada + 2] == 'P')//cima
                    {
                        tab[linha_jogada - 1][coluna_jogada + 1] = 'P';
                        tab[linha_jogada][coluna_jogada] = 'P';
                    }
                    else if (tab[linha_jogada + 2][coluna_jogada - 2] == 'P')//baixo
                    {
                        tab[linha_jogada + 1][coluna_jogada - 1] = 'P';
                        tab[linha_jogada][coluna_jogada] = 'P';
                    }
                }
            }
        }
}
void troca_branco(char*tab[8][8])
{
    int linha_jogada = 0, coluna_jogada = 0;
    printf("Insira a linha: ");
    scanf("%d", &linha_jogada);
    printf("Insira a coluna: ");
    scanf("%d", &coluna_jogada);
    for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {

                if (tab[linha_jogada][coluna_jogada] == 'x')//para direita
                {
                    if (tab[linha_jogada][coluna_jogada + 4] == 'B')
                    {
                        tab[linha_jogada][coluna_jogada + 3] = 'B';
                        tab[linha_jogada][coluna_jogada + 2] = 'B';
                        tab[linha_jogada][coluna_jogada + 1] = 'B';
                        tab[linha_jogada][coluna_jogada] = 'B';
                    }
                    else if (tab[linha_jogada][coluna_jogada + 3] == 'B')
                    {
                        tab[linha_jogada][coluna_jogada + 2] = 'B';
                        tab[linha_jogada][coluna_jogada + 1] = 'B';
                        tab[linha_jogada][coluna_jogada] = 'B';
                    }
                    else if (tab[linha_jogada][coluna_jogada + 2] == 'B')
                    {
                        tab[linha_jogada][coluna_jogada + 1] = 'B';
                        tab[linha_jogada][coluna_jogada] = 'B';
                    }
                }
            }
        }
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {

                if (tab[linha_jogada][coluna_jogada] == 'x')//para esquerda
                {
                    if (tab[linha_jogada][coluna_jogada - 4] == 'B')
                    {
                        tab[linha_jogada][coluna_jogada - 3] = 'B';
                        tab[linha_jogada][coluna_jogada - 2] = 'B';
                        tab[linha_jogada][coluna_jogada - 1] = 'B';
                        tab[linha_jogada][coluna_jogada] = 'B';
                    }
                    else if (tab[linha_jogada][coluna_jogada - 3] == 'B')
                    {
                        tab[linha_jogada][coluna_jogada - 2] = 'B';
                        tab[linha_jogada][coluna_jogada - 1] = 'B';
                        tab[linha_jogada][coluna_jogada] = 'B';
                    }
                    else if (tab[linha_jogada][coluna_jogada - 2] == 'B')
                    {
                        tab[linha_jogada][coluna_jogada - 1] = 'B';
                        tab[linha_jogada][coluna_jogada] = 'B';
                    }
                }
            }
        }
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {

                if (tab[linha_jogada][coluna_jogada] == 'x')//para cima
                {
                    if (tab[linha_jogada - 4][coluna_jogada] == 'B')
                    {
                        tab[linha_jogada - 3][coluna_jogada] = 'B';
                        tab[linha_jogada - 2][coluna_jogada] = 'B';
                        tab[linha_jogada - 1][coluna_jogada] = 'B';
                        tab[linha_jogada][coluna_jogada] = 'B';
                    }
                    else if (tab[linha_jogada - 3][coluna_jogada] == 'B')
                    {
                        tab[linha_jogada - 2][coluna_jogada] = 'B';
                        tab[linha_jogada - 1][coluna_jogada] = 'B';
                        tab[linha_jogada][coluna_jogada] = 'B';
                    }
                    else if (tab[linha_jogada - 2][coluna_jogada] == 'B')
                    {
                        tab[linha_jogada - 1][coluna_jogada] = 'B';
                        tab[linha_jogada][coluna_jogada] = 'B';
                    }
                }
            }
        }
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {

                if (tab[linha_jogada][coluna_jogada] == 'x')//para baixo
                {
                    if (tab[linha_jogada + 4][coluna_jogada] == 'B')
                    {
                        tab[linha_jogada + 3][coluna_jogada] = 'B';
                        tab[linha_jogada + 2][coluna_jogada] = 'B';
                        tab[linha_jogada + 1][coluna_jogada] = 'B';
                        tab[linha_jogada][coluna_jogada] = 'B';
                    }
                    else if (tab[linha_jogada + 3][coluna_jogada] == 'B')
                    {
                        tab[linha_jogada + 2][coluna_jogada] = 'B';
                        tab[linha_jogada + 1][coluna_jogada] = 'B';
                        tab[linha_jogada][coluna_jogada] = 'B';
                    }
                    else if (tab[linha_jogada + 2][coluna_jogada] == 'B')
                    {
                        tab[linha_jogada + 1][coluna_jogada] = 'B';
                        tab[linha_jogada][coluna_jogada] = 'B';
                    }
                }
            }
        }
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {

                if (tab[linha_jogada][coluna_jogada] == 'x')//diagonal principal
                {
                    if (tab[linha_jogada + 4][coluna_jogada + 4] == 'B')//baixo
                    {
                        tab[linha_jogada + 3][coluna_jogada + 3] = 'B';
                        tab[linha_jogada + 2][coluna_jogada + 2] = 'B';
                        tab[linha_jogada + 1][coluna_jogada + 1] = 'B';
                        tab[linha_jogada][coluna_jogada] = 'B';
                    }
                    else if (tab[linha_jogada - 4][coluna_jogada - 4] == 'B')//cima
                    {
                        tab[linha_jogada - 3][coluna_jogada - 3] = 'B';
                        tab[linha_jogada - 2][coluna_jogada - 2] = 'B';
                        tab[linha_jogada - 1][coluna_jogada - 1] = 'B';
                        tab[linha_jogada][coluna_jogada] = 'B';
                    }
                    else if (tab[linha_jogada + 3][coluna_jogada + 3] == 'B')//baixo
                    {
                        tab[linha_jogada + 2][coluna_jogada + 2] = 'B';
                        tab[linha_jogada + 1][coluna_jogada + 1] = 'B';
                        tab[linha_jogada][coluna_jogada] = 'B';
                    }
                    else if (tab[linha_jogada - 3][coluna_jogada - 3] == 'B')//cima
                    {
                        tab[linha_jogada - 2][coluna_jogada - 2] = 'B';
                        tab[linha_jogada - 1][coluna_jogada - 1] = 'B';
                        tab[linha_jogada][coluna_jogada] = 'B';
                    }
                    else if (tab[linha_jogada + 2][coluna_jogada + 2] == 'B')//baixo
                    {
                        tab[linha_jogada + 1][coluna_jogada + 1] = 'B';
                        tab[linha_jogada][coluna_jogada] = 'B';
                    }
                    else if (tab[linha_jogada - 2][coluna_jogada - 2] == 'B')//cima
                    {
                        tab[linha_jogada - 1][coluna_jogada - 1] = 'B';
                        tab[linha_jogada][coluna_jogada] = 'B';
                    }
                }
            }
        }
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {

                if (tab[linha_jogada][coluna_jogada] == 'x')//diagonal secundária
                {
                    if (tab[linha_jogada - 4][coluna_jogada + 4] == 'B')//cima
                    {
                        tab[linha_jogada - 3][coluna_jogada + 3] = 'B';
                        tab[linha_jogada - 2][coluna_jogada + 2] = 'B';
                        tab[linha_jogada - 1][coluna_jogada + 1] = 'B';
                        tab[linha_jogada][coluna_jogada] = 'B';
                    }
                    else if (tab[linha_jogada + 4][coluna_jogada - 4] == 'B')//baixo
                    {
                        tab[linha_jogada + 3][coluna_jogada - 3] = 'B';
                        tab[linha_jogada + 2][coluna_jogada - 2] = 'B';
                        tab[linha_jogada + 1][coluna_jogada - 1] = 'B';
                        tab[linha_jogada][coluna_jogada] = 'B';
                    }
                    else if (tab[linha_jogada - 3][coluna_jogada + 3] == 'B')//cima
                    {
                        tab[linha_jogada - 2][coluna_jogada + 2] = 'B';
                        tab[linha_jogada - 1][coluna_jogada + 1] = 'B';
                        tab[linha_jogada][coluna_jogada] = 'B';
                    }
                    else if (tab[linha_jogada + 3][coluna_jogada - 3] == 'B')//baixo
                    {
                        tab[linha_jogada + 2][coluna_jogada - 2] = 'B';
                        tab[linha_jogada + 1][coluna_jogada - 1] = 'B';
                        tab[linha_jogada][coluna_jogada] = 'B';
                    }
                    else if (tab[linha_jogada - 2][coluna_jogada + 2] == 'B')//cima
                    {
                        tab[linha_jogada - 1][coluna_jogada + 1] = 'B';
                        tab[linha_jogada][coluna_jogada] = 'B';
                    }
                    else if (tab[linha_jogada + 2][coluna_jogada - 2] == 'B')//baixo
                    {
                        tab[linha_jogada + 1][coluna_jogada - 1] = 'B';
                        tab[linha_jogada][coluna_jogada] = 'B';
                    }
                }
            }
        }
}
void jogada (char *tab[8][8])
{
    int contX;
    preencher (tab);
    for (int i=0; i<8; i++)//parada do jogo
    {
        for (int j=0; j<8; j++)
        {
            if (tab[i][j] == 'x')
                contX++;
        }
    }
    do{//jogo
        printf ("\nJOGADA PEÇA PRETA\n");
        posicoes_preto(tab);
        imprimir(tab);
        troca_preto(tab);
        contagem_pecas(tab);
        limpeza (tab);
        printf ("\nJOGADA PEÇA BRANCA\n");
        posicoes_branco(tab);
        imprimir (tab);
        troca_branco(tab);
        contagem_pecas(tab);
        limpeza(tab);
    }while (contX<1);
}
void resultado(char *tab[8][8])
{
    int contB, contP;
    int vencedor;
    contagem_pecas(tab);
    if (contP>contB)
    {
        printf ("PEÇA PRETA");
    }
    if (contB>contP)
    {
        printf ("PEÇA BRANCA");
    }
    if (contP == contB)
    {
        printf ("EMPATADOS");
    }
}

