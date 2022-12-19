#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{ // struct que vai receber os dados
   int matricula;
   char nome[50];
   float n1, n2, n3;
   float nota_final;
}dados;

void sequencial (dados *estudante, int cont); //prot�tipo da fun��o de busca atrav�s da matr�cula
void ordenacao (dados *estudante, int cont); //prot�tipo da fun��o de ordena��o de acordo com a matr�cula
void media (dados *estudante, int cont); //prot�tipo da fun��o pra calcular a m�dia
void maior_valor (dados *estudante, int cont); //prot�tipo da fun��o que vai encontrar o maior valor
void menor_valor (dados *estudante, int cont); //prot�tipo da fun��o que vai encontrar o menor valor
void aprovados (dados *estudante, int cont); //pr�totipo da fun��o que vai encontrar a quantidade de aprovados e a m�dia geral
//*estudante = ponteiro para a struct dados alunos
//int cont = vari�vel contadora


int main(){ // in�cio da fun��o principal

    int c, qt=1; // quantidade de linhas do arquivo, come�ou com 1 para contar a �ltima linha
    int i, op; // i = contadora op = op��es do menu
    int editar, posicao_editar=0;

    FILE *arq; // ponteiro para abrir o arquivo

    arq = fopen ("alunos.txt", "r"); // abrindo o arquivo

    if (arq == NULL)
        printf ("ERRO");

    while ((c = fgetc(arq)) != EOF) // contando as linhas do arquivo
    {
        if (c == '\n')
            qt++;
    }
    fclose (arq); //fechando o arquivo
    printf("%d", qt);
    dados *alunos = (dados *)malloc(qt*sizeof(dados)); // aloca��o de mem�ria por causa da quantidade de structs

    arq = fopen ("alunos.txt", "r"); // abrindo o arquivo pra fazer a leitura dos dados
    //leitura dos dados do arquivo
    for (i=0; i<qt; i++)
    {
        fscanf (arq, "%d", &alunos[i].matricula);
        fscanf (arq, "%s", alunos[i].nome);
        fscanf (arq, "%f", &alunos[i].n1);
        fscanf (arq, "%f", &alunos[i].n2);
        fscanf (arq, "%f", &alunos[i].n3);

    }
    fclose (arq); // fechando o arquivo

    do{ //menu pro usu�rio escolher uma op��o
        printf ("\nEscolha uma opcao:\n");
        printf ("1-Imprimir os elementos do arranjo\n");
        printf ("2-Imprimir apenas os nomes dos alunos\n");
        printf ("3-Imprimir os nomes dos alunos e suas respectivas nota final\n");
        printf ("4-Buscar os dados de um aluno usando a busca sequencial\n");
        printf ("5-Imprimir os alunos ordenados de acordo com sua matricula\n");
        printf ("6-Editar as notas de um aluno, para isso e necessario que se busque os dados do aluno\n");
        printf ("7-Imprimir a matricula, nome e nota final do aluno que obteve a maior nota de todas\n");
        printf ("8-Imprimir a matricula, nome e nota final do aluno que obteve a menor nota de todas\n");
        printf ("9-Imprimir quantos alunos foram aprovados e quantos alunos foram reprovados, imprima ainda a media geral\n");
        printf ("0-Sair do programa\n");
        scanf ("%d", &op);
        printf("\n");

        media (alunos, qt); // chamando a fun��o m�dia para que seja poss�vel imprimir a m�dia nas fun��es necess�rias

        switch (op) // comando switch para executar a op��o que usu�rio escolheu
        {
            case 1: //imprimir os elementos do arranjo
            for (i=0; i<qt; i++)
            {
                printf ("\nMatricula: %d", alunos[i].matricula);
                printf ("\nNome: %s", alunos[i].nome);
                printf ("\nNota 1: %0.1f\nNota 2: %0.1f\nNota 3: %0.1f", alunos[i].n1, alunos[i].n2, alunos[i].n3);
                printf ("\n");
            }
            break;

            case 2: // imprimir os nomes
                for (i=0; i<qt; i++)
                {
                    printf ("\n%s", alunos[i].nome);
                }
            break;

            case 3: // imprimir a media e nome dos alunos
                media (alunos, qt);
                for (i=0; i<qt; i++)
                    printf ("\n\nNome: %s\nNota final: %0.2f\n", alunos[i].nome, alunos[i].nota_final);
            break;

            case 4:
                sequencial (alunos, qt); //chamando a fun��o de busca atrav�s da matr�cula
            break;

            case 5:
                ordenacao (alunos, qt); // chamando a fun��o de ordena��o
                for (i=0; i<qt; i++)
                    printf ("\nMatricula: %d\nNome: %s\nNota 1: %0.2f\nNota 2: %0.2f\nNota 3: %0.2f\n", alunos[i].matricula, alunos[i].nome, alunos[i].n1, alunos[i].n2, alunos[i].n3);
            break;

            case 6:
                printf ("Insira a matricula do aluno que deseja editar as notas: ");
                scanf ("%d", &editar);
                for (i=0; i<qt; i++)
                {
                    if (alunos[i].matricula == editar) //encontrando a matr�cula
                    {
                        posicao_editar = i;
                    }
                }
                printf ("Nova nota 1:"); //editando as notas
                scanf ("%f", &alunos[posicao_editar].n1);
                printf ("Nova nota 2:");
                scanf ("%f", &alunos[posicao_editar].n2);
                printf ("Nova nota 3: ");
                scanf ("%f", &alunos[posicao_editar].n3);
            break;

            case 7:
                maior_valor (alunos, qt); //chamando fun��o que vai encontrar o maior valor

            break;

            case 8:
                menor_valor (alunos, qt); // chamando fun��o que vai encontrar o menor valor
            break;

            case 9:
                aprovados (alunos, qt); //chamando fun��o que vai mostrar a quantidade de aprovados e media geral
            break;

            case 0:
                ordenacao (alunos, qt);
                FILE *arquivo_novo; // ponteiro pro novo arquivo
                arquivo_novo = fopen ("arquivo_novo.txt", "w"); // abrindo novo arquivo

                if (arquivo_novo == NULL)
                {
                    printf ("ERRO");
                }

                for (i=0; i<qt; i++) //escrevendo no arquivo
                {
                    fprintf (arquivo_novo, "\n\t%d\t%s\t%0.2f\t%0.2f\t%0.2f\t%0.2f", alunos[i].matricula, alunos[i].nome, alunos[i].n1, alunos[i].n2, alunos[i].n3, alunos[i].nota_final);
                }
                // /n � para pular linha e /t para dar espa�o entre as informa��es

                fclose (arquivo_novo); //fechando o arquivo
                printf ("Saindo...");
            break;

            default:
                printf ("Insira uma opcao valida!");
        }


        }while (op!=0);


return 0;
}
void media (dados *estudante, int cont) // fun��o para calcular a m�dia
{
    int i;
    for (i=0; i<cont; i++)
    {
        estudante[i].nota_final = (estudante[i].n1+estudante[i].n2+estudante[i].n3)/3.0;
    }
}

void sequencial(dados *estudante, int cont) // fun��o para realizar a busca do aluno pelo numero da matricula
{
    int procurar, i=0;
    int encontrado = 0;//falso
    printf ("Digite o numero da matricula que deseja encontrar: ");
    scanf ("%d", &procurar);

    while (i<cont && !encontrado) // comando while para realizar a busca sequencial
    {
        if (estudante[i].matricula == procurar)
        {
            encontrado = 1;
        } else
            i++;
    }

    if (encontrado)
    {
      printf ("Matriculado. Seguem os dados do aluno:\nNome: %s\nNota 1: %0.2f\nNota 2: %0.2f\nNota 3: %0.2f\n", estudante[i].nome, estudante[i].n1, estudante[i].n2, estudante[i].n3);
    } else
    {
        printf ("Nao matriculado");
    }
}

void ordenacao (dados *estudante, int cont) // fun��o para ordenar de acordo com a matricula, bubble sort
{
    dados aux;
    int i, j;

    for (i= 1; i< cont; i ++)
    {
        aux = estudante[i];

        for (j = i; (j>0) && (aux.matricula < estudante[j-1].matricula); j--)
        {
            estudante[j] = estudante[j-1];
        }
        estudante[j]=aux;
    }
}

void maior_valor (dados *estudante, int cont) // fun��o para encontrar maior valor
{
    int k, i;
    float maior1=0, maior2=0, maior3=0;
    int posicao =0, posicao1=0, posicao2=0, posicao3=0;

    for (k=0; k<cont; k++) // comandos for para que seja poss�vel percorrer as notas de todos os alunos
    {
        for (i=0; i<cont; i++)
        {

            if (estudante[i].n1 > maior1)
            {
                maior1 = estudante[i].n1;
                posicao1 = i;
            }else;

            if (estudante[i].n2 > maior2)
            {
                maior2 = estudante[i].n2;
                posicao2 = i;
            } else;

            if (estudante[i].n3 > maior3)
            {
                maior3 = estudante[i].n3;
                posicao3 = i;
            } else;
        }
    }

    if (maior1 > maior2) //definindo a maior nota
    {
        posicao = posicao1;
    }
    if (maior1 > maior3)
    {
        posicao = posicao1;
    }
    if (maior2 > maior1)
    {
        posicao = posicao2;
    }
    if (maior2 > maior3)
    {
        posicao = posicao2;
    }
    if (maior3 > maior1)
    {
        posicao = posicao3;
    }
    if (maior3 > maior2)
    {
        posicao = posicao3;
    }

    printf ("Matricula: %d\nNome: %s\nNota final: %0.2f\n", estudante[posicao].matricula, estudante[posicao].nome, estudante[posicao].nota_final);
}

void menor_valor (dados *estudante, int cont) //fun��o para encontrar o menor valor
{
    int k, i;
    float menor1=999, menor2=999, menor3=999;
    int posicao =0, posicao1=0, posicao2=0, posicao3=0;

    for (k=0; k<cont; k++) //comandos for para percorrer as notas de todos os alunos e encontrar a menor
    {
        for (i=0; i<cont; i++)
        {

            if (menor1>estudante[i].n1)
            {
                menor1 = estudante[i].n1;
                posicao1 = i;
            } else;
            if (menor2>estudante[i].n2)
            {
                menor2 = estudante[i].n2;
                posicao2 = i;
            } else;
            if (menor3>estudante[i].n3)
            {
                menor3 = estudante[i].n3;
                posicao3 = i;
            }else;
        }
    }
    if (menor1<menor2 && menor1<menor3) // definindo a menor
    {
        posicao = posicao1;
    }
    if (menor2<menor1 && menor2<menor3)
    {
        posicao = posicao2;
    }
    if (menor3<menor1 && menor3<menor2)
    {
        posicao = posicao3;
    }

    printf ("Matricula: %d\nNome: %s\nNota final: %0.2f\n", estudante[posicao].matricula, estudante[posicao].nome, estudante[posicao].nota_final);
}

void aprovados (dados *estudante, int cont) // fun��o para definir a quantidade de aprovados e m�dia geral
{
    int i, ap=0;
    float soma=0;
    float media_geral;
    int rp=0;

    for (i=0; i<cont; i++)
    {
        soma += estudante[i].nota_final;
        media_geral = soma/cont;

        if (estudante[i].nota_final >= 6)
        {
            ap++; //aprovados
        }
    }
    rp = cont - ap;//quantidade de alunos - aprovados = reprovados

    printf ("%d alunos aprovados\n", ap);
    printf ("%d alunos reprovados\n", rp);
    printf ("Media geral = %0.2f\n", media_geral);
}
